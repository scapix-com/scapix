/*
	scapix/link/java/object_impl.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_OBJECT_IMPL_H
#define SCAPIX_LINK_JAVA_OBJECT_IMPL_H

#include <cassert>
#include <type_traits>
#include <scapix/meta/string.h>
#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/detail/api.h>
#include <scapix/link/java/fwd/ref.h>
#include <scapix/link/java/fwd/class.h>

namespace scapix::link::java {

template <typename ClassName>
class object_impl
{
public:

	using class_name = ClassName;
	using base_classes = std::tuple<>;
	using handle_type = jobject;

	// call_method

	template <typename Name, typename Type, typename ...Args>
	auto call_method(Args&&... args) const
	{
		return call_method<Type>(method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	auto call_method(jmethodID id, Args&&... args) const
	{
		return detail::api::call<Type>::method(handle(), id, std::forward<Args>(args)...);
	}

	// call_nonvirtual_method

	template <typename Name, typename Type, typename ...Args>
	auto call_nonvirtual_method(Args&&... args) const
	{
		return call_nonvirtual_method<Type>(method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	auto call_nonvirtual_method(jmethodID id, Args&&... args) const;

	// call_static_method

	template <typename Name, typename Type, typename ...Args>
	static auto call_static_method(Args&&... args)
	{
		return call_static_method<Type>(static_method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static auto call_static_method(jmethodID id, Args&&... args);

	// new_object

	template <typename Type, typename ...Args>
	static local_ref<object_impl> new_object(Args&&... args)
	{
		return new_object<Type>(method_id<SCAPIX_META_STRING("<init>"), Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static local_ref<object_impl> new_object(jmethodID id, Args&&... args);

	// field

	template <typename Name, typename Type>
	Type get_field() const
	{
		return detail::api::get_field<Type>(handle(), field_id<Name, Type>());
	}

	template <typename Name, typename Type>
	void set_field(Type value) const
	{
		detail::api::set_field<Type>(handle(), field_id<Name, Type>(), value);
	}

	// static field

	template <typename Name, typename Type>
	static Type get_static_field();

	template <typename Name, typename Type>
	static void set_static_field(Type value);

	//jmethodID FromReflectedMethod(jobject method);
	//jfieldID FromReflectedField(jobject field);
	//jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic);
	//jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic);

	static ref<class_> class_object();

protected:

	object_impl(handle_type h) : handle_(h) {}
	handle_type handle() const { return handle_; }

private:

	template <typename Name, typename Type>
	static jmethodID method_id();

	template <typename Name, typename Type>
	static jmethodID static_method_id();

	template <typename Name, typename Type>
	static jfieldID field_id();

	template <typename Name, typename Type>
	static jfieldID static_field_id();

	handle_type handle_;

};

} // namespace scapix::link::java

#include <scapix/link/java/class.h>
#include <scapix/link/java/cast.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/link/java/class_loader.h>
#include <scapix/mpv/replace.h>
#endif

namespace scapix::link::java {

template <typename ClassName>
template <typename Type, typename ...Args>
inline auto object_impl<ClassName>::call_nonvirtual_method(jmethodID id, Args&&... args) const
{
	return detail::api::call<Type>::nonvirtual_method(handle(), class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName>
template <typename Type, typename ...Args>
inline auto object_impl<ClassName>::call_static_method(jmethodID id, Args&&... args)
{
	return detail::api::call<Type>::static_method(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName>
template <typename Type, typename ...Args>
inline local_ref<object_impl<ClassName>> object_impl<ClassName>::new_object(jmethodID id, Args&&... args)
{
	return detail::api::call<Type>::template new_object<object_impl>(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName>
template <typename Name, typename Type>
inline Type object_impl<ClassName>::get_static_field()
{
	return detail::api::get_static_field<Type>(class_object().handle(), static_field_id<Name, Type>());
}

template <typename ClassName>
template <typename Name, typename Type>
inline void object_impl<ClassName>::set_static_field(Type value)
{
	detail::api::set_static_field<Type>(class_object().handle(), static_field_id<Name, Type>(), value);
}

template <typename ClassName>
inline ref<class_> object_impl<ClassName>::class_object()
{
// Destructed after JNI_OnUnload, when JNI calls (like DeleteGlobalRef) do not work.
//	static const global_ref<class_> cls(class_::find_class(meta::c_str_v<ClassName>));

#ifdef SCAPIX_CACHE_CLASS_LOADER
	static const ref<class_> cls(global_ref<class_>(class_loader::find_class(meta::c_str_v<mpv::replace<ClassName, '/', '.'>>)).release());
#else
	static const ref<class_> cls(global_ref<class_>(class_::find_class(meta::c_str_v<ClassName>)).release());
#endif

	return cls;
}

template <typename ClassName>
template <typename Name, typename Type>
inline jmethodID object_impl<ClassName>::method_id()
{
	static const jmethodID id(class_object()->get_method_id<Name, Type>());
	return id;
}

template <typename ClassName>
template <typename Name, typename Type>
inline jmethodID object_impl<ClassName>::static_method_id()
{
	static const jmethodID id(class_object()->get_static_method_id<Name, Type>());
	return id;
}

template <typename ClassName>
template <typename Name, typename Type>
inline jfieldID object_impl<ClassName>::field_id()
{
	static const jfieldID id(class_object()->get_field_id<Name, Type>());
	return id;
}

template <typename ClassName>
template <typename Name, typename Type>
inline jfieldID object_impl<ClassName>::static_field_id()
{
	static const jfieldID id(class_object()->get_static_field_id<Name, Type>());
	return id;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_OBJECT_IMPL_H

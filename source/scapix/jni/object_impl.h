/*
	scapix/jni/object_impl.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_OBJECT_IMPL_H
#define SCAPIX_JNI_OBJECT_IMPL_H

#include <utility>
#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/type_traits.h>
#include <scapix/jni/detail/api.h>
#include <scapix/jni/fwd/ref.h>
#include <scapix/jni/fwd/class.h>

namespace scapix::jni {

template <fixed_string ClassName>
class object_impl
{
public:

	static constexpr auto class_name = ClassName;
	using base_classes = std::tuple<>;
	using handle_type = jobject;

	// call_method

	template <fixed_string Name, typename Type, typename ...Args>
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

	template <fixed_string Name, typename Type, typename ...Args>
	auto call_nonvirtual_method(Args&&... args) const
	{
		return call_nonvirtual_method<Type>(method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	auto call_nonvirtual_method(jmethodID id, Args&&... args) const
	{
		return detail::api::call<Type>::nonvirtual_method(handle(), class_object().handle(), id, std::forward<Args>(args)...);
	}

	// call_static_method

	template <fixed_string Name, typename Type, typename ...Args>
	static auto call_static_method(Args&&... args)
	{
		return call_static_method<Type>(static_method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static auto call_static_method(jmethodID id, Args&&... args)
	{
		return detail::api::call<Type>::static_method(class_object().handle(), id, std::forward<Args>(args)...);
	}

	// new_object

	template <typename Type, typename ...Args>
	static local_ref<object_impl> new_object(Args&&... args)
	{
		return new_object<Type>(method_id<"<init>", Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static local_ref<object_impl> new_object(jmethodID id, Args&&... args)
	{
		return detail::api::call<Type>::template new_object<object_impl>(class_object().handle(), id, std::forward<Args>(args)...);
	}

	// field

	template <fixed_string Name, typename Type>
	Type get_field() const
	{
		return detail::api::get_field<Type>(handle(), field_id<Name, Type>());
	}

	template <fixed_string Name, typename Type>
	void set_field(Type value) const
	{
		detail::api::set_field<Type>(handle(), field_id<Name, Type>(), value);
	}

	// static field

	template <fixed_string Name, typename Type>
	static Type get_static_field()
	{
		return detail::api::get_static_field<Type>(class_object().handle(), static_field_id<Name, Type>());
	}

	template <fixed_string Name, typename Type>
	static void set_static_field(Type value)
	{
		detail::api::set_static_field<Type>(class_object().handle(), static_field_id<Name, Type>(), value);
	}

	//jmethodID FromReflectedMethod(jobject method);
	//jfieldID FromReflectedField(jobject field);
	//jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic);
	//jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic);

	static ref<class_> class_object();

protected:

	object_impl(handle_type h) : handle_(h) {}
	handle_type handle() const { return handle_; }

private:

	template <fixed_string Name, typename Type>
	static jmethodID method_id();

	template <fixed_string Name, typename Type>
	static jmethodID static_method_id();

	template <fixed_string Name, typename Type>
	static jfieldID field_id();

	template <fixed_string Name, typename Type>
	static jfieldID static_field_id();

	handle_type handle_;

};

} // namespace scapix::jni

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/jni/class_loader.h>
#else
#include <scapix/jni/class.h>
#endif

namespace scapix::jni {

template <fixed_string ClassName>
inline ref<class_> object_impl<ClassName>::class_object()
{

#ifdef SCAPIX_CACHE_CLASS_LOADER
	static const static_global_ref<class_> cls(class_loader::find_class(ClassName.replace('/', '.')));
#else
	static const static_global_ref<class_> cls(class_::find_class(ClassName));
#endif

	return cls;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jmethodID object_impl<ClassName>::method_id()
{
	static const jmethodID id(class_object()->get_method_id<Name, Type>());
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jmethodID object_impl<ClassName>::static_method_id()
{
	static const jmethodID id(class_object()->get_static_method_id<Name, Type>());
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jfieldID object_impl<ClassName>::field_id()
{
	static const jfieldID id(class_object()->get_field_id<Name, Type>());
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jfieldID object_impl<ClassName>::static_field_id()
{
	static const jfieldID id(class_object()->get_static_field_id<Name, Type>());
	return id;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_OBJECT_IMPL_H

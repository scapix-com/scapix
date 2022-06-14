/*
	scapix/link/java/object.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_OBJECT_H
#define SCAPIX_LINK_JAVA_OBJECT_H

#include <cassert>
#include <type_traits>
#include <scapix/meta/string.h>
#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/detail/exception.h>
#include <scapix/link/java/detail/api.h>

namespace scapix::link::java {

class class_;

// fix: already defined in ref.h

//template <typename ClassName = SCAPIX_META_STRING("java/lang/Object"), typename HandleType = jobject>
//class object;

template <typename ClassName, typename HandleType>
class object
{
public:

	typedef object object_type;
	typedef ClassName class_name;
	typedef HandleType handle_type;

	static_assert(std::is_base_of_v<std::remove_pointer_t<jobject>, std::remove_pointer_t<handle_type>>, "Unknown JNI object handle type");

	// for consistency with link::java::object_base

	object& native() { return *this; }
	const object& native() const { return *this; }

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
	static local_ref<object_type> new_object(Args&&... args)
	{
		return new_object<Type>(method_id<SCAPIX_META_STRING("<init>"), Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static local_ref<object_type> new_object(jmethodID id, Args&&... args);

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

	template <typename Name, typename Type>
	static Type get_static_field();

	template <typename Name, typename Type>
	static void set_static_field(Type value);

	template <typename T>
	jboolean is_instance_of() const
	{
		return is_instance_of(T::class_object());
	}

	jboolean is_instance_of(ref<class_> cls) const;

	// MSC (as of 2017 15.9) fails if is_same_object defined here.

	template <typename C1, typename H1, typename C2, typename H2>
	friend jboolean is_same_object(const object<C1, H1>& a, const object<C2, H2>& b);

	local_ref<class_> get_object_class() const noexcept;

	//jmethodID FromReflectedMethod(jobject method);
	//jfieldID FromReflectedField(jobject field);
	//jobject ToReflectedMethod(jclass cls, jmethodID methodID, jboolean isStatic);
	//jobject ToReflectedField(jclass cls, jfieldID fieldID, jboolean isStatic);

	static ref<class_> class_object();

private:

	template <typename Name, typename Type>
	static jmethodID method_id();

	template <typename Name, typename Type>
	static jmethodID static_method_id();

	template <typename Name, typename Type>
	static jfieldID field_id();

	template <typename Name, typename Type>
	static jfieldID static_field_id();

protected:

	object(handle_type h) : handle_(h) {}

	handle_type handle() const { return handle_; }

private:

	handle_type handle_;

};

template <typename C1, typename H1, typename C2, typename H2>
inline jboolean is_same_object(const object<C1, H1>& a, const object<C2, H2>& b)
{
	return detail::env()->IsSameObject(a.handle(), b.handle());
}

} // namespace scapix::link::java

#include <scapix/link/java/class.h>
#include <scapix/link/java/string.h>
#include <scapix/link/java/throwable.h>
#include <scapix/link/java/byte_buffer.h>
#include <scapix/link/java/array.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/link/java/class_loader.h>
#include <scapix/mpv/replace.h>
#endif

namespace scapix::link::java {

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline auto object<ClassName, HandleType>::call_nonvirtual_method(jmethodID id, Args&&... args) const
{
	return detail::api::call<Type>::nonvirtual_method(handle(), class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline auto object<ClassName, HandleType>::call_static_method(jmethodID id, Args&&... args)
{
	return detail::api::call<Type>::static_method(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline local_ref<object<ClassName, HandleType>> object<ClassName, HandleType>::new_object(jmethodID id, Args&&... args)
{
	return detail::api::call<Type>::template new_object<object>(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline Type object<ClassName, HandleType>::get_static_field()
{
	return detail::api::get_static_field<Type>(class_object().handle(), static_field_id<Name, Type>());
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline void object<ClassName, HandleType>::set_static_field(Type value)
{
	detail::api::set_static_field<Type>(class_object().handle(), static_field_id<Name, Type>(), value);
}

template <typename ClassName, typename HandleType>
inline jboolean object<ClassName, HandleType>::is_instance_of(ref<class_> cls) const
{
	return detail::env()->IsInstanceOf(handle(), cls.handle());
}

template <typename ClassName, typename HandleType>
inline local_ref<class_> object<ClassName, HandleType>::get_object_class() const noexcept
{
	return local_ref<class_>(detail::env()->GetObjectClass(handle()));
}

template <typename ClassName, typename HandleType>
inline ref<class_> object<ClassName, HandleType>::class_object()
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

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jmethodID object<ClassName, HandleType>::method_id()
{
	static const jmethodID id(class_object()->get_method_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jmethodID object<ClassName, HandleType>::static_method_id()
{
	static const jmethodID id(class_object()->get_static_method_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jfieldID object<ClassName, HandleType>::field_id()
{
	static const jfieldID id(class_object()->get_field_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jfieldID object<ClassName, HandleType>::static_field_id()
{
	static const jfieldID id(class_object()->get_static_field_id<Name, Type>());
	return id;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_OBJECT_H

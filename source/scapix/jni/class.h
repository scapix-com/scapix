/*
	scapix/jni/class.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/jni/object_impl.h>

#ifndef SCAPIX_JNI_CLASS_H
#define SCAPIX_JNI_CLASS_H

#include <scapix/jni/object.h>
#include <scapix/jni/signature.h>
#include <scapix/jni/detail/exception.h>

namespace scapix::jni {

class class_ : public object<"java/lang/Class">
{
public:

	static local_ref<class_> define_class(const char* name, ref<object<"java/lang/ClassLoader">> loader, const jbyte* buf, jsize size)
	{
		return detail::check_result<class_>(detail::env()->DefineClass(name, loader.handle(), buf, size));
	}

	static local_ref<class_> find_class(const char* name)
	{
		return detail::check_result<class_>(detail::env()->FindClass(name));
	}

	local_ref<class_> get_super_class() const
	{
		return detail::check_result<class_>(detail::env()->GetSuperclass(handle()));
	}

	jboolean is_assignable_from(ref<class_> source) const noexcept
	{
		return detail::env()->IsAssignableFrom(source.handle(), handle());
	}

	template <fixed_string Name, typename Type>
	jfieldID get_field_id() const
	{
		return get_field_id(Name, signature_v<Type>);
	}

	template <fixed_string Name, typename Type>
	jfieldID get_static_field_id() const
	{
		return get_static_field_id(Name, signature_v<Type>);
	}

	template <fixed_string Name, typename Type>
	jmethodID get_method_id() const
	{
		return get_method_id(Name, signature_v<Type>);
	}

	template <fixed_string Name, typename Type>
	jmethodID get_static_method_id() const
	{
		return get_static_method_id(Name, signature_v<Type>);
	}

	jfieldID get_field_id(const char* name, const char* sig) const
	{
		return detail::api::get_field_id(handle(), name, sig);
	}

	jfieldID get_static_field_id(const char* name, const char* sig) const
	{
		return detail::api::get_static_field_id(handle(), name, sig);
	}

	jmethodID get_method_id(const char* name, const char* sig) const
	{
		return detail::api::get_method_id(handle(), name, sig);
	}

	jmethodID get_static_method_id(const char* name, const char* sig) const
	{
		return detail::api::get_static_method_id(handle(), name, sig);
	}

	void register_natives(const JNINativeMethod* methods, jint count) const
	{
		detail::api::register_natives(handle(), methods, count);
	}

	template <int N>
	void register_natives(const JNINativeMethod(&methods)[N]) const
	{
		register_natives(methods, N);
	}

	jint unregister_natives() const
	{
		return detail::api::unregister_natives(handle());
	}

	jint throw_new(const char* message) const
	{
		return detail::api::throw_new(handle(), message);
	}

protected:

	class_(handle_type h) : object(h) {}

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_CLASS_H

/*
	scapix/jni/class.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
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

	jfieldID get_field_id(const char* name, const char* sig) const
	{
		return detail::check_result(detail::env()->GetFieldID(handle(), name, sig));
	}

	jfieldID get_static_field_id(const char* name, const char* sig) const
	{
		return detail::check_result(detail::env()->GetStaticFieldID(handle(), name, sig));
	}

	jmethodID get_method_id(const char* name, const char* sig) const
	{
		return detail::check_result(detail::env()->GetMethodID(handle(), name, sig));
	}

	jmethodID get_static_method_id(const char* name, const char* sig) const
	{
		return detail::check_result(detail::env()->GetStaticMethodID(handle(), name, sig));
	}

	void register_natives(const JNINativeMethod* methods, jint count) const
	{
		detail::check_result(detail::env()->RegisterNatives(handle(), methods, count));
	}

	template <int N>
	void register_natives(const JNINativeMethod(&methods)[N]) const
	{
		register_natives(methods, N);
	}

	jint unregister_natives() const
	{
		return detail::env()->UnregisterNatives(handle());
	}

	jint throw_new(const char* message) const
	{
		return detail::env()->ThrowNew(handle(), message);
	}

	static jmethodID from_reflected_method(ref<object<"java/lang/reflect/Executable">> method)
	{
		return detail::env()->FromReflectedMethod(method.handle());
	}

	static jfieldID from_reflected_field(ref<object<"java/lang/reflect/Field">> field)
	{
		return detail::env()->FromReflectedField(field.handle());
	}

	ref<object<"java/lang/reflect/Executable">> to_reflected_method(jmethodID id, bool is_static)
	{
		jobject method = detail::env()->ToReflectedMethod(handle(), id, is_static);
		detail::check_exception();
		return local_ref<object<"java/lang/reflect/Executable">>(method);
	}

	ref<object<"java/lang/reflect/Field">> to_reflected_field(jfieldID id, bool is_static)
	{
		jobject field = detail::env()->ToReflectedField(handle(), id, is_static);
		detail::check_exception();
		return local_ref<object<"java/lang/reflect/Field">>(field);
	}

protected:

	class_(handle_type h) : object(h) {}

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_CLASS_H

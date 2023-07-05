/*
	scapix/link/java/class.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/link/java/object_impl.h>

#ifndef SCAPIX_LINK_JAVA_CLASS_H
#define SCAPIX_LINK_JAVA_CLASS_H

#include <scapix/link/java/object.h>
#include <scapix/link/java/signature.h>
#include <scapix/link/java/detail/exception.h>

namespace scapix::link::java {

class class_ : public object<SCAPIX_META_STRING("java/lang/Class")>
{
public:

	static local_ref<class_> define_class(const char* name, ref<SCAPIX_META_STRING("java/lang/ClassLoader")> loader, const jbyte* buf, jsize size)
	{
		jclass cls = detail::env()->DefineClass(name, loader.handle(), buf, size);
		detail::check_exception(cls);
		return local_ref<class_>(cls);
	}

	static local_ref<class_> find_class(const char* name)
	{
		jclass cls = detail::env()->FindClass(name);
		detail::check_exception(cls);
		return local_ref<class_>(cls);
	}

	local_ref<class_> get_super_class() const
	{
		jclass cls = detail::env()->GetSuperclass(handle());
		detail::check_exception(cls);
		return local_ref<class_>(cls);
	}

	jboolean is_assignable_from(ref<class_> source) const noexcept
	{
		return detail::env()->IsAssignableFrom(source.handle(), handle());
	}

	template <typename Name, typename Type>
	jfieldID get_field_id() const
	{
		return get_field_id(meta::c_str_v<Name>, meta::c_str_v<signature_t<Type>>);
	}

	template <typename Name, typename Type>
	jfieldID get_static_field_id() const
	{
		return get_static_field_id(meta::c_str_v<Name>, meta::c_str_v<signature_t<Type>>);
	}

	template <typename Name, typename Type>
	jmethodID get_method_id() const
	{
		return get_method_id(meta::c_str_v<Name>, meta::c_str_v<signature_t<Type>>);
	}

	template <typename Name, typename Type>
	jmethodID get_static_method_id() const
	{
		return get_static_method_id(meta::c_str_v<Name>, meta::c_str_v<signature_t<Type>>);
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

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_CLASS_H

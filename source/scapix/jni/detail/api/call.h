/*
	scapix/jni/detail/api/call.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_API_CALL_H
#define SCAPIX_JNI_DETAIL_API_CALL_H

#include <scapix/jni/detail/api/type.h>
#include <scapix/jni/detail/exception.h>
#include <scapix/jni/ref.h>

namespace scapix::jni::detail::api {

template <typename T>
struct call;

template <typename R, typename ...Args>
struct call<R(Args...)>
{
	static R method(jobject obj, jmethodID id, Args... args)
	{
		check_exception_nested_on_destroy check;
		return type<R>::call_method(obj, id, arg(args)...);
	}

	static R nonvirtual_method(jobject obj, jclass cls, jmethodID id, Args... args)
	{
		check_exception_nested_on_destroy check;
		return type<R>::call_nonvirtual_method(obj, cls, id, arg(args)...);
	}

	static R static_method(jclass cls, jmethodID id, Args... args)
	{
		check_exception_nested_on_destroy check;
		return type<R>::call_static_method(cls, id, arg(args)...);
	}

	template <typename T>
	static local_ref<T> new_object(jclass cls, jmethodID id, Args... args)
	{
		return check_result_nested<T>(env()->NewObject(cls, id, arg(args)...));
	}

private:

	template <typename T, scope Scope>
	static jobject  arg(const jni::ref<T, Scope>& v) { return v.handle(); }

	static jboolean arg(jboolean v) { return v; }
	static jbyte    arg(jbyte v)    { return v; }
	static jchar    arg(jchar v)    { return v; }
	static jshort   arg(jshort v)   { return v; }
	static jint     arg(jint v)     { return v; }
	static jlong    arg(jlong v)    { return v; }
	static jfloat   arg(jfloat v)   { return v; }
	static jdouble  arg(jdouble v)  { return v; }
};

} // namespace scapix::jni::detail::api

#endif // SCAPIX_JNI_DETAIL_API_CALL_H

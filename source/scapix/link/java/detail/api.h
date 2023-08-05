/*
	scapix/link/java/detail/api.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_API_H
#define SCAPIX_LINK_JAVA_DETAIL_API_H

#include <scapix/link/java/detail/api/array.h>
#include <scapix/link/java/detail/api/ref.h>
#include <scapix/link/java/detail/api/string.h>
#include <scapix/link/java/detail/api/type.h>
#include <scapix/link/java/detail/exception.h>

namespace scapix::link::java::detail::api {

// It is possible to allow creating ref<T> for incomplete T from jobject handle (but quite painfull).
// This would allow moving all api calls using ref<class_>, ref<string>, ref<throwable>, etc. to "api.h".

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
	static java::ref<T> new_object(jclass cls, jmethodID id, Args... args)
	{
		return check_exception_nested(type<java::ref<T>>::new_object(cls, id, arg(args)...));
	}

private:

	template <typename T, scope Scope>
	static jobject  arg(const java::ref<T, Scope>& v) { return v.handle(); }

	static jboolean arg(jboolean v) { return v; }
	static jbyte    arg(jbyte v)    { return v; }
	static jchar    arg(jchar v)    { return v; }
	static jshort   arg(jshort v)   { return v; }
	static jint     arg(jint v)     { return v; }
	static jlong    arg(jlong v)    { return v; }
	static jfloat   arg(jfloat v)   { return v; }
	static jdouble  arg(jdouble v)  { return v; }
};

inline jfieldID get_field_id(jclass cls, const char* name, const char* sig)
{
	return check_exception(env()->GetFieldID(cls, name, sig));
}

inline jfieldID get_static_field_id(jclass cls, const char* name, const char* sig)
{
	return check_exception(env()->GetStaticFieldID(cls, name, sig));
}

inline jmethodID get_method_id(jclass cls, const char* name, const char* sig)
{
	return check_exception(env()->GetMethodID(cls, name, sig));
}

inline jmethodID get_static_method_id(jclass cls, const char* name, const char* sig)
{
	return check_exception(env()->GetStaticMethodID(cls, name, sig));
}

inline void register_natives(jclass cls, const JNINativeMethod* methods, jint count)
{
	check_exception(env()->RegisterNatives(cls, methods, count));
}

inline jint unregister_natives(jclass cls) noexcept
{
	return env()->UnregisterNatives(cls);
}

inline jint throw_new(jclass cls, const char* message) noexcept
{
	return env()->ThrowNew(cls, message);
}

template <typename T>
inline T get_field(jobject obj, jfieldID id) noexcept
{
	return type<T>::get_field(obj, id);
}

template <typename T>
inline void set_field(jobject obj, jfieldID id, T value) noexcept
{
	return type<T>::set_field(obj, id, value);
}

template <typename T>
inline T get_static_field(jclass cls, jfieldID id) noexcept
{
	return type<T>::get_static_field(cls, id);
}

template <typename T>
inline void set_static_field(jclass cls, jfieldID id, T value) noexcept
{
	type<T>::set_static_field(cls, id, value);
}

inline jsize get_array_length(jarray array) noexcept
{
	return env()->GetArrayLength(array);
}

// primitive array

template <typename T>
inline local_ref<T[]> new_array(jsize len)
{
	return local_ref<T[]>(check_exception(type<T>::new_array(len)));
}

template <typename T, lock Lock>
inline T* get_array_elements(java::ref<T[]> obj, jboolean* is_copy) noexcept
{
	return check_exception(array<T, Lock>::get_array_elements(obj.handle(), is_copy));
}

template <typename T, lock Lock>
inline void release_array_elements(java::ref<T[]> obj, T* elems, jint mode) noexcept
{
	array<T, Lock>::release_array_elements(obj.handle(), elems, mode);
}

template <typename T>
inline void get_array_region(java::ref<T[]> obj, jsize start, jsize len, T* buf)
{
	type<T>::get_array_region(obj.handle(), start, len, buf);
	check_exception();
}

template <typename T>
inline void set_array_region(java::ref<T[]> obj, jsize start, jsize len, const T* buf)
{
	type<T>::set_array_region(obj.handle(), start, len, buf);
	check_exception();
}

// object array

template <typename T>
inline local_ref<T[]> new_array(jsize len, java::ref<T> init)
{
	return check_exception(type<java::ref<T>>::new_array(len, init));
}

template <typename T>
inline local_ref<T> get_array_element(java::ref<T[]> obj, jsize index)
{
	check_exception_on_destroy check;
	return type<java::ref<T>>::get_array_element(obj, index);
}

template <typename T>
inline void set_array_element(java::ref<T[]> obj, jsize index, java::ref<T> value)
{
	type<java::ref<T>>::set_array_element(obj, index, value);
	check_exception();
}

// string

inline jstring new_string(const jchar* buf, jsize len) noexcept
{
	return env()->NewString(buf, len);
}

inline jstring new_string(const char* buf) noexcept
{
	return env()->NewStringUTF(buf);
}

template <typename Char>
inline jsize get_string_length(jstring str) noexcept
{
	return string<Char>::length(str);
}

template <typename Char, lock Lock>
inline const Char* get_string_chars(jstring str, jboolean* is_copy) noexcept
{
	return string<Char, Lock>::get_chars(str, is_copy);
}

template <typename Char, lock Lock>
inline void release_string_chars(jstring str, const Char* chars) noexcept
{
	string<Char, Lock>::release_chars(str, chars);
}

template <typename Char>
inline void get_string_region(jstring str, jsize start, jsize len, Char* buf)
{
	string<Char>::get_region(str, start, len, buf);
	check_exception();
}

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_H

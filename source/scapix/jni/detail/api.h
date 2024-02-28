/*
	scapix/jni/detail/api.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_API_H
#define SCAPIX_JNI_DETAIL_API_H

#include <scapix/jni/detail/api/array.h>
#include <scapix/jni/detail/api/ref.h>
#include <scapix/jni/detail/api/string.h>
#include <scapix/jni/detail/api/type.h>
#include <scapix/jni/detail/exception.h>
#include <scapix/jni/fwd/object_impl.h>
#include <scapix/jni/fwd/throwable.h>

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

// method and field id

inline jfieldID get_field_id(jclass cls, const char* name, const char* sig)
{
	return check_result(env()->GetFieldID(cls, name, sig));
}

inline jfieldID get_static_field_id(jclass cls, const char* name, const char* sig)
{
	return check_result(env()->GetStaticFieldID(cls, name, sig));
}

inline jmethodID get_method_id(jclass cls, const char* name, const char* sig)
{
	return check_result(env()->GetMethodID(cls, name, sig));
}

inline jmethodID get_static_method_id(jclass cls, const char* name, const char* sig)
{
	return check_result(env()->GetStaticMethodID(cls, name, sig));
}

// native methods

inline void register_natives(jclass cls, const JNINativeMethod* methods, jint count)
{
	check_result(env()->RegisterNatives(cls, methods, count));
}

inline jint unregister_natives(jclass cls) noexcept
{
	return env()->UnregisterNatives(cls);
}

// exception

inline jint throw_new(jclass cls, const char* message) noexcept
{
	return env()->ThrowNew(cls, message);
}

inline local_ref<jni::throwable> exception_occurred() noexcept
{
	return local_ref<jni::throwable>(env()->ExceptionOccurred());
}

// field

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

// array

inline jsize get_array_length(jarray array) noexcept
{
	return env()->GetArrayLength(array);
}

// primitive array

template <typename T>
inline local_ref<T[]> new_array(jsize len)
{
	return check_result<T[]>(type<T>::new_array(len));
}

template <typename T, lock Lock>
inline T* get_array_elements(jni::ref<T[]> obj, jboolean* is_copy) noexcept
{
	return check_result(array<T, Lock>::get_array_elements(obj.handle(), is_copy));
}

template <typename T, lock Lock>
inline void release_array_elements(jni::ref<T[]> obj, T* elems, jint mode) noexcept
{
	array<T, Lock>::release_array_elements(obj.handle(), elems, mode);
}

template <typename T>
inline void get_array_region(jni::ref<T[]> obj, jsize start, jsize len, T* buf)
{
	type<T>::get_array_region(obj.handle(), start, len, buf);
	check_exception();
}

template <typename T>
inline void set_array_region(jni::ref<T[]> obj, jsize start, jsize len, const T* buf)
{
	type<T>::set_array_region(obj.handle(), start, len, buf);
	check_exception();
}

// object array

template <typename T>
inline local_ref<T[]> new_array(jsize len, jni::ref<T> init)
{
	return check_result<T[]>(env()->NewObjectArray(len, object_impl<class_name_v<T>>::class_object().handle(), init.handle()));
}

template <typename T>
inline local_ref<T> get_array_element(jni::ref<T[]> array, jsize index)
{
	jobject element = env()->GetObjectArrayElement(array.handle(), index);
	check_exception();
	return local_ref<T>(element);
}

template <typename T>
inline void set_array_element(jni::ref<T[]> array, jsize index, jni::ref<T> value)
{
	env()->SetObjectArrayElement(array.handle(), index, value.handle());
	check_exception();
}

// string

inline local_ref<jni::string> new_string(const jchar* buf, jsize len)
{
	jstring str = env()->NewString(buf, len);
	check_exception();
	return local_ref<jni::string>(str);
}

inline local_ref<jni::string> new_string(const char* buf)
{
	jstring str = env()->NewStringUTF(buf);
	check_exception();
	return local_ref<jni::string>(str);
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

} // namespace scapix::jni::detail::api

#endif // SCAPIX_JNI_DETAIL_API_H

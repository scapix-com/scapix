/*
	scapix/jni/detail/api/array.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_API_ARRAY_H
#define SCAPIX_JNI_DETAIL_API_ARRAY_H

#include <scapix/jni/lock.h>
#include <scapix/jni/detail/api/type.h>

namespace scapix::jni::detail::api {

template <typename T, lock Lock>
struct array;

template <typename T>
struct array<T, lock::noncritical>
{
	static T* get_array_elements(handle_type_t<T[]> obj, jboolean* is_copy) { return type<T>::get_array_elements(obj, is_copy); }
	static void release_array_elements(handle_type_t<T[]> obj, T* elems, jint mode) { type<T>::release_array_elements(obj, elems, mode); }
};

template <typename T>
struct array<T, lock::critical>
{
	static T* get_array_elements(handle_type_t<T[]> obj, jboolean* is_copy) { return static_cast<T*>(env()->GetPrimitiveArrayCritical(obj, is_copy)); }
	static void release_array_elements(handle_type_t<T[]> obj, T* elems, jint mode) { env()->ReleasePrimitiveArrayCritical(obj, elems, mode); }
};

} // namespace scapix::jni::detail::api

#endif // SCAPIX_JNI_DETAIL_API_ARRAY_H

/*
	scapix/link/java/detail/api/array.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_API_ARRAY_H
#define SCAPIX_LINK_JAVA_DETAIL_API_ARRAY_H

#include <scapix/link/java/lock.h>
#include <scapix/link/java/detail/api/type.h>

namespace scapix::link::java::detail::api {

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

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_ARRAY_H

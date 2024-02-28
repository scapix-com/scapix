/*
	scapix/jni/object_traits.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_OBJECT_TRAITS_H
#define SCAPIX_JNI_OBJECT_TRAITS_H

#include <scapix/jni/detail/util.h>

namespace scapix::jni {

// object_traits
// Specialized to provide traits for incomplete object type.
// Otherwise, uses traits from (complete) object type.

template <typename T>
struct object_traits
{
	static constexpr auto class_name = detail::befriend<T, object_traits>::class_name;
	using base_classes = typename detail::befriend<T, object_traits>::base_classes;
};

template <typename T>
constexpr auto class_name_v = object_traits<T>::class_name;

template <typename T>
using base_classes_t = typename object_traits<T>::base_classes;

} // namespace scapix::jni

#endif // SCAPIX_JNI_OBJECT_TRAITS_H

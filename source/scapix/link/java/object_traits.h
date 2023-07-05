/*
	scapix/link/java/object_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_OBJECT_TRAITS_H
#define SCAPIX_LINK_JAVA_OBJECT_TRAITS_H

#include <scapix/link/java/detail/util.h>

namespace scapix::link::java {

// object_traits
//
// Specialized to provide traits for incomplete object type.
// Otherwise, uses traits from (complete) object type.

template <typename T>
struct object_traits
{
	using class_name = typename detail::befriend<T, object_traits>::class_name;
	using base_classes = typename detail::befriend<T, object_traits>::base_classes;
};

// class_name
//
// Note: class_name currently also used by java::bridge for a somewhat different purpose:
// specialized for C++ types to get class name of related java type.

template <typename T>
struct class_name
{
	using type = typename object_traits<T>::class_name;
};

template <typename T>
using class_name_t = typename class_name<T>::type;

// base_classes

template <typename T>
struct base_classes
{
	using type = typename object_traits<T>::base_classes;
};

template <typename T>
using base_classes_t = typename base_classes<T>::type;

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_OBJECT_TRAITS_H

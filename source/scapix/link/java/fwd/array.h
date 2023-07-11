/*
	scapix/link/java/fwd/array.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_ARRAY_H
#define SCAPIX_LINK_JAVA_FWD_ARRAY_H

#include <tuple>
#include <scapix/link/java/object_traits.h>
#include <scapix/link/java/fwd/object.h>
#include <scapix/link/java/fwd/signature.h>

namespace scapix::link::java {

template <typename T, typename = void>
class array;

template <typename T>
struct object_traits<array<T>>
{
	using class_name = signature_t<array<T>>;
	using base_classes = std::tuple<object<>>;
};

template <typename T>
struct object_traits<T[]> : object_traits<array<T>>
{
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_ARRAY_H

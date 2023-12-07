/*
	scapix/link/java/fwd/throwable.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_THROWABLE_H
#define SCAPIX_LINK_JAVA_FWD_THROWABLE_H

#include <tuple>
#include <scapix/meta/string.h>
#include <scapix/link/java/object_traits.h>
#include <scapix/link/java/fwd/object.h>

namespace scapix::link::java {

class throwable;

template<>
struct object_traits<throwable>
{
	using class_name = SCAPIX_META_STRING("java/lang/Throwable");
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_THROWABLE_H

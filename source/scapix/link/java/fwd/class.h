/*
	scapix/link/java/fwd/class.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_CLASS_H
#define SCAPIX_LINK_JAVA_FWD_CLASS_H

#include <tuple>
#include <scapix/meta/string.h>
#include <scapix/link/java/object_traits.h>
#include <scapix/link/java/fwd/object.h>

namespace scapix::link::java {

class class_;

template<>
struct object_traits<class_>
{
	using class_name = SCAPIX_META_STRING("java/lang/Class");
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_CLASS_H

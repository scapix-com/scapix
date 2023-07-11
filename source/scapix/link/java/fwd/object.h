/*
	scapix/link/java/fwd/object.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_OBJECT_H
#define SCAPIX_LINK_JAVA_FWD_OBJECT_H

#include <tuple>
#include <scapix/meta/string.h>
#include <scapix/link/java/object_traits.h>

namespace scapix::link::java {

template <typename ClassName = SCAPIX_META_STRING("java/lang/Object"), typename ...Bases>
class object;

template <typename ClassName, typename ...Bases>
struct object_traits<object<ClassName, Bases...>>
{
	using class_name = ClassName;
	using base_classes = std::tuple<Bases...>;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_OBJECT_H

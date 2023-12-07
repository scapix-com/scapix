/*
	scapix/link/java/fwd/ref.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_REF_H
#define SCAPIX_LINK_JAVA_FWD_REF_H

#include <scapix/link/java/detail/api/ref.h>
#include <scapix/link/java/fwd/object.h>

namespace scapix::link::java {

using scope = detail::api::scope;

template <typename T = object<>, scope Scope = scope::generic>
class ref;

template <typename T, typename ...Params>
struct generic_type;

template <typename T, typename Extends = object<>>
struct generic;

//template <typename T>
//struct extends;

//template <typename T>
//struct super;

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_REF_H

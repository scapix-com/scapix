/*
	scapix/jni/fwd/ref.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_REF_H
#define SCAPIX_LINK_JAVA_FWD_REF_H

#include <scapix/jni/detail/api/ref.h>
#include <scapix/jni/fwd/object.h>

namespace scapix::jni {

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

} // namespace scapix::jni

#endif // SCAPIX_LINK_JAVA_FWD_REF_H

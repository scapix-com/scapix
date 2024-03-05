/*
	scapix/jni/fwd/ref.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_REF_H
#define SCAPIX_JNI_FWD_REF_H

#include <scapix/jni/detail/api/ref.h>
#include <scapix/jni/fwd/object.h>

namespace scapix::jni {

using scope = detail::api::scope;

template <typename T = object<>, scope Scope = scope::generic>
class ref;

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_REF_H

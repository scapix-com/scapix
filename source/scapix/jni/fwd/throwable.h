/*
	scapix/jni/fwd/throwable.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_THROWABLE_H
#define SCAPIX_JNI_FWD_THROWABLE_H

#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/object.h>

namespace scapix::jni {

class throwable;

template<>
struct object_traits<throwable>
{
	static constexpr fixed_string class_name = "java/lang/Throwable";
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_THROWABLE_H

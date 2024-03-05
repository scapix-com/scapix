/*
	scapix/jni/fwd/array.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_ARRAY_H
#define SCAPIX_JNI_FWD_ARRAY_H

#include <tuple>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/object.h>
#include <scapix/jni/fwd/signature.h>

namespace scapix::jni {

template <typename T>
class array;

template <typename T>
struct object_traits<array<T>>
{
	static constexpr auto class_name = signature_v<array<T>>;
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_ARRAY_H

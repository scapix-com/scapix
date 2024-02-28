/*
	scapix/jni/fwd/byte_buffer.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_BYTE_BUFFER_H
#define SCAPIX_JNI_FWD_BYTE_BUFFER_H

#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/object.h>

namespace scapix::jni {

class byte_buffer;

template<>
struct object_traits<byte_buffer>
{
	static constexpr auto class_name = "java/nio/ByteBuffer";
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_BYTE_BUFFER_H

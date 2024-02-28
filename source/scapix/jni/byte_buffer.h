/*
	scapix/jni/byte_buffer.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_BYTE_BUFFER_H
#define SCAPIX_JNI_BYTE_BUFFER_H

#include <scapix/jni/object.h>

namespace scapix::jni {

class byte_buffer : public object<"java/nio/ByteBuffer">
{
public:

	static local_ref<byte_buffer> new_direct(void* address, jlong capacity)
	{
		jobject buf = detail::env()->NewDirectByteBuffer(address, capacity);
		detail::check_exception();
		return local_ref<byte_buffer>(buf);
	}

	void* direct_address() const
	{
		return detail::env()->GetDirectBufferAddress(handle());
	}

	jlong direct_capacity() const
	{
		return detail::env()->GetDirectBufferCapacity(handle());
	}

protected:

	byte_buffer(handle_type h) : object(h) {}

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_BYTE_BUFFER_H

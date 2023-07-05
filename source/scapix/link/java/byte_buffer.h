/*
	scapix/link/java/byte_buffer.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_BYTE_BUFFER_H
#define SCAPIX_LINK_JAVA_BYTE_BUFFER_H

#include <scapix/link/java/object.h>

namespace scapix::link::java {

class byte_buffer : public object<SCAPIX_META_STRING("java/nio/ByteBuffer")>
{
public:

	static local_ref<byte_buffer> new_direct(void* address, jlong capacity)
	{
		return local_ref<byte_buffer>(detail::env()->NewDirectByteBuffer(address, capacity));
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

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_BYTE_BUFFER_H

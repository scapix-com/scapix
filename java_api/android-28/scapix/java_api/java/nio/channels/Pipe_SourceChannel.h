// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/nio/channels/spi/AbstractSelectableChannel.h>
#include <scapix/java_api/java/nio/channels/ReadableByteChannel.h>
#include <scapix/java_api/java/nio/channels/ScatteringByteChannel.h>

#ifndef SCAPIX_JAVA_NIO_CHANNELS_PIPE_SOURCECHANNEL_H
#define SCAPIX_JAVA_NIO_CHANNELS_PIPE_SOURCECHANNEL_H

namespace scapix::java_api {


namespace java::nio::channels {

class Pipe_SourceChannel : public object_base<SCAPIX_META_STRING("java/nio/channels/Pipe$SourceChannel"),
	java::nio::channels::spi::AbstractSelectableChannel,
	java::nio::channels::ReadableByteChannel,
	java::nio::channels::ScatteringByteChannel>
{
public:

	jint validOps();

protected:

	Pipe_SourceChannel(handle_type h) : base_(h) {}

};

} // namespace java::nio::channels
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::nio::channels {

inline jint Pipe_SourceChannel::validOps() { return call_method<SCAPIX_META_STRING("validOps"), jint>(); }

} // namespace java::nio::channels
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_CHANNELS_PIPE_SOURCECHANNEL_H
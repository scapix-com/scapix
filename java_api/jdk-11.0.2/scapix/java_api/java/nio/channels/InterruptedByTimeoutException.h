// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/IOException.h>

#ifndef SCAPIX_JAVA_NIO_CHANNELS_INTERRUPTEDBYTIMEOUTEXCEPTION_H
#define SCAPIX_JAVA_NIO_CHANNELS_INTERRUPTEDBYTIMEOUTEXCEPTION_H

namespace scapix::java_api {
namespace java::nio::channels {

class InterruptedByTimeoutException : public object_base<SCAPIX_META_STRING("java/nio/channels/InterruptedByTimeoutException"),
	java::io::IOException>
{
public:

	static ref<InterruptedByTimeoutException> new_object();

protected:

	InterruptedByTimeoutException(handle_type h) : base_(h) {}

};

} // namespace java::nio::channels
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::nio::channels {

inline ref<InterruptedByTimeoutException> InterruptedByTimeoutException::new_object() { return base_::new_object(); }

} // namespace java::nio::channels
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_CHANNELS_INTERRUPTEDBYTIMEOUTEXCEPTION_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/net/SocketException.h>

#ifndef SCAPIX_JAVA_NET_PORTUNREACHABLEEXCEPTION_H
#define SCAPIX_JAVA_NET_PORTUNREACHABLEEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::net {

class PortUnreachableException : public object_base<SCAPIX_META_STRING("java/net/PortUnreachableException"),
	java::net::SocketException>
{
public:

	static ref<PortUnreachableException> new_object(ref<java::lang::String> msg);
	static ref<PortUnreachableException> new_object();

protected:

	PortUnreachableException(handle_type h) : base_(h) {}

};

} // namespace java::net
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::net {

inline ref<PortUnreachableException> PortUnreachableException::new_object(ref<java::lang::String> msg) { return base_::new_object(msg); }
inline ref<PortUnreachableException> PortUnreachableException::new_object() { return base_::new_object(); }

} // namespace java::net
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NET_PORTUNREACHABLEEXCEPTION_H

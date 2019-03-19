// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/InterruptedIOException.h>

#ifndef SCAPIX_ORG_APACHE_HTTP_CONN_CONNECTTIMEOUTEXCEPTION_H
#define SCAPIX_ORG_APACHE_HTTP_CONN_CONNECTTIMEOUTEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace org::apache::http::conn {

class ConnectTimeoutException : public object_base<SCAPIX_META_STRING("org/apache/http/conn/ConnectTimeoutException"),
	java::io::InterruptedIOException>
{
public:

	static ref<ConnectTimeoutException> new_object();
	static ref<ConnectTimeoutException> new_object(ref<java::lang::String> message);

protected:

	ConnectTimeoutException(handle_type h) : base_(h) {}

};

} // namespace org::apache::http::conn
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace org::apache::http::conn {

inline ref<ConnectTimeoutException> ConnectTimeoutException::new_object() { return base_::new_object(); }
inline ref<ConnectTimeoutException> ConnectTimeoutException::new_object(ref<java::lang::String> message) { return base_::new_object(message); }

} // namespace org::apache::http::conn
} // namespace scapix::java_api

#endif // SCAPIX_ORG_APACHE_HTTP_CONN_CONNECTTIMEOUTEXCEPTION_H
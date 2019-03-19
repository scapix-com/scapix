// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/javax/net/ssl/SSLException.h>

#ifndef SCAPIX_JAVAX_NET_SSL_SSLHANDSHAKEEXCEPTION_H
#define SCAPIX_JAVAX_NET_SSL_SSLHANDSHAKEEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace javax::net::ssl {

class SSLHandshakeException : public object_base<SCAPIX_META_STRING("javax/net/ssl/SSLHandshakeException"),
	javax::net::ssl::SSLException>
{
public:

	static ref<SSLHandshakeException> new_object(ref<java::lang::String> reason);

protected:

	SSLHandshakeException(handle_type h) : base_(h) {}

};

} // namespace javax::net::ssl
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace javax::net::ssl {

inline ref<SSLHandshakeException> SSLHandshakeException::new_object(ref<java::lang::String> reason) { return base_::new_object(reason); }

} // namespace javax::net::ssl
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_NET_SSL_SSLHANDSHAKEEXCEPTION_H
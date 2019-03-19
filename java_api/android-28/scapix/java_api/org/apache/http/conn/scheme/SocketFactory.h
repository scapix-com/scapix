// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ORG_APACHE_HTTP_CONN_SCHEME_SOCKETFACTORY_H
#define SCAPIX_ORG_APACHE_HTTP_CONN_SCHEME_SOCKETFACTORY_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::net { class InetAddress; }
namespace java::net { class Socket; }
namespace org::apache::http::params { class HttpParams; }

namespace org::apache::http::conn::scheme {

class SocketFactory : public object_base<SCAPIX_META_STRING("org/apache/http/conn/scheme/SocketFactory"),
	java::lang::Object>
{
public:

	ref<java::net::Socket> createSocket();
	ref<java::net::Socket> connectSocket(ref<java::net::Socket> p1, ref<java::lang::String> p2, jint p3, ref<java::net::InetAddress> p4, jint p5, ref<org::apache::http::params::HttpParams> p6);
	jboolean isSecure(ref<java::net::Socket> p1);

protected:

	SocketFactory(handle_type h) : base_(h) {}

};

} // namespace org::apache::http::conn::scheme
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/net/InetAddress.h>
#include <scapix/java_api/java/net/Socket.h>
#include <scapix/java_api/org/apache/http/params/HttpParams.h>

namespace scapix::java_api {
namespace org::apache::http::conn::scheme {

inline ref<java::net::Socket> SocketFactory::createSocket() { return call_method<SCAPIX_META_STRING("createSocket"), ref<java::net::Socket>>(); }
inline ref<java::net::Socket> SocketFactory::connectSocket(ref<java::net::Socket> p1, ref<java::lang::String> p2, jint p3, ref<java::net::InetAddress> p4, jint p5, ref<org::apache::http::params::HttpParams> p6) { return call_method<SCAPIX_META_STRING("connectSocket"), ref<java::net::Socket>>(p1, p2, p3, p4, p5, p6); }
inline jboolean SocketFactory::isSecure(ref<java::net::Socket> p1) { return call_method<SCAPIX_META_STRING("isSecure"), jboolean>(p1); }

} // namespace org::apache::http::conn::scheme
} // namespace scapix::java_api

#endif // SCAPIX_ORG_APACHE_HTTP_CONN_SCHEME_SOCKETFACTORY_H
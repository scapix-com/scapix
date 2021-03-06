// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_NET_URLSTREAMHANDLERFACTORY_H
#define SCAPIX_JAVA_NET_URLSTREAMHANDLERFACTORY_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::net { class URLStreamHandler; }

namespace java::net {

class URLStreamHandlerFactory : public object_base<SCAPIX_META_STRING("java/net/URLStreamHandlerFactory"),
	java::lang::Object>
{
public:

	ref<java::net::URLStreamHandler> createURLStreamHandler(ref<java::lang::String> p1);

protected:

	URLStreamHandlerFactory(handle_type h) : base_(h) {}

};

} // namespace java::net
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/net/URLStreamHandler.h>

namespace scapix::java_api {
namespace java::net {

inline ref<java::net::URLStreamHandler> URLStreamHandlerFactory::createURLStreamHandler(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createURLStreamHandler"), ref<java::net::URLStreamHandler>>(p1); }

} // namespace java::net
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NET_URLSTREAMHANDLERFACTORY_H

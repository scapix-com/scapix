// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/org/apache/http/conn/ssl/AbstractVerifier.h>

#ifndef SCAPIX_ORG_APACHE_HTTP_CONN_SSL_ALLOWALLHOSTNAMEVERIFIER_H
#define SCAPIX_ORG_APACHE_HTTP_CONN_SSL_ALLOWALLHOSTNAMEVERIFIER_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace org::apache::http::conn::ssl {

class AllowAllHostnameVerifier : public object_base<SCAPIX_META_STRING("org/apache/http/conn/ssl/AllowAllHostnameVerifier"),
	org::apache::http::conn::ssl::AbstractVerifier>
{
public:

	static ref<AllowAllHostnameVerifier> new_object();
	void verify(ref<java::lang::String> host, ref<link::java::array<java::lang::String>> cns, ref<link::java::array<java::lang::String>> subjectAlts);
	ref<java::lang::String> toString();

protected:

	AllowAllHostnameVerifier(handle_type h) : base_(h) {}

};

} // namespace org::apache::http::conn::ssl
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace org::apache::http::conn::ssl {

inline ref<AllowAllHostnameVerifier> AllowAllHostnameVerifier::new_object() { return base_::new_object(); }
inline void AllowAllHostnameVerifier::verify(ref<java::lang::String> host, ref<link::java::array<java::lang::String>> cns, ref<link::java::array<java::lang::String>> subjectAlts) { return call_method<SCAPIX_META_STRING("verify"), void>(host, cns, subjectAlts); }
inline ref<java::lang::String> AllowAllHostnameVerifier::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace org::apache::http::conn::ssl
} // namespace scapix::java_api

#endif // SCAPIX_ORG_APACHE_HTTP_CONN_SSL_ALLOWALLHOSTNAMEVERIFIER_H
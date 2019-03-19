// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_SECURITY_CERT_CERTPATH_H
#define SCAPIX_JAVA_SECURITY_CERT_CERTPATH_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::util { class Iterator; }
namespace java::util { class List; }

namespace java::security::cert {

class CertPath : public object_base<SCAPIX_META_STRING("java/security/cert/CertPath"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	ref<java::lang::String> getType();
	ref<java::util::Iterator> getEncodings();
	jboolean equals(ref<java::lang::Object> other);
	jint hashCode();
	ref<java::lang::String> toString();
	ref<link::java::array<jbyte>> getEncoded();
	ref<link::java::array<jbyte>> getEncoded(ref<java::lang::String> p1);
	ref<java::util::List> getCertificates();

protected:

	CertPath(handle_type h) : base_(h) {}

};

} // namespace java::security::cert
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Iterator.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace java::security::cert {

inline ref<java::lang::String> CertPath::getType() { return call_method<SCAPIX_META_STRING("getType"), ref<java::lang::String>>(); }
inline ref<java::util::Iterator> CertPath::getEncodings() { return call_method<SCAPIX_META_STRING("getEncodings"), ref<java::util::Iterator>>(); }
inline jboolean CertPath::equals(ref<java::lang::Object> other) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(other); }
inline jint CertPath::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> CertPath::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline ref<link::java::array<jbyte>> CertPath::getEncoded() { return call_method<SCAPIX_META_STRING("getEncoded"), ref<link::java::array<jbyte>>>(); }
inline ref<link::java::array<jbyte>> CertPath::getEncoded(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("getEncoded"), ref<link::java::array<jbyte>>>(p1); }
inline ref<java::util::List> CertPath::getCertificates() { return call_method<SCAPIX_META_STRING("getCertificates"), ref<java::util::List>>(); }

} // namespace java::security::cert
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CERT_CERTPATH_H
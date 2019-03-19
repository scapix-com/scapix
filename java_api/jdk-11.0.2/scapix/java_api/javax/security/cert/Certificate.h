// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVAX_SECURITY_CERT_CERTIFICATE_H
#define SCAPIX_JAVAX_SECURITY_CERT_CERTIFICATE_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::security { class PublicKey; }

namespace javax::security::cert {

class Certificate : public object_base<SCAPIX_META_STRING("javax/security/cert/Certificate"),
	java::lang::Object>
{
public:

	static ref<Certificate> new_object();
	jboolean equals(ref<java::lang::Object> other);
	jint hashCode();
	ref<link::java::array<jbyte>> getEncoded();
	void verify(ref<java::security::PublicKey> p1);
	void verify(ref<java::security::PublicKey> p1, ref<java::lang::String> p2);
	ref<java::lang::String> toString();
	ref<java::security::PublicKey> getPublicKey();

protected:

	Certificate(handle_type h) : base_(h) {}

};

} // namespace javax::security::cert
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/security/PublicKey.h>

namespace scapix::java_api {
namespace javax::security::cert {

inline ref<Certificate> Certificate::new_object() { return base_::new_object(); }
inline jboolean Certificate::equals(ref<java::lang::Object> other) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(other); }
inline jint Certificate::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<link::java::array<jbyte>> Certificate::getEncoded() { return call_method<SCAPIX_META_STRING("getEncoded"), ref<link::java::array<jbyte>>>(); }
inline void Certificate::verify(ref<java::security::PublicKey> p1) { return call_method<SCAPIX_META_STRING("verify"), void>(p1); }
inline void Certificate::verify(ref<java::security::PublicKey> p1, ref<java::lang::String> p2) { return call_method<SCAPIX_META_STRING("verify"), void>(p1, p2); }
inline ref<java::lang::String> Certificate::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline ref<java::security::PublicKey> Certificate::getPublicKey() { return call_method<SCAPIX_META_STRING("getPublicKey"), ref<java::security::PublicKey>>(); }

} // namespace javax::security::cert
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_SECURITY_CERT_CERTIFICATE_H
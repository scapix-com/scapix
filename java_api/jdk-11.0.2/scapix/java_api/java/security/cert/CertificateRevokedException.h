// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/security/cert/CertificateException.h>

#ifndef SCAPIX_JAVA_SECURITY_CERT_CERTIFICATEREVOKEDEXCEPTION_H
#define SCAPIX_JAVA_SECURITY_CERT_CERTIFICATEREVOKEDEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::security::cert { class CRLReason; }
namespace java::util { class Date; }
namespace java::util { class Map; }
namespace javax::security::auth::x500 { class X500Principal; }

namespace java::security::cert {

class CertificateRevokedException : public object_base<SCAPIX_META_STRING("java/security/cert/CertificateRevokedException"),
	java::security::cert::CertificateException>
{
public:

	static ref<CertificateRevokedException> new_object(ref<java::util::Date> revocationDate, ref<java::security::cert::CRLReason> reason, ref<javax::security::auth::x500::X500Principal> authority, ref<java::util::Map> extensions);
	ref<java::util::Date> getRevocationDate();
	ref<java::security::cert::CRLReason> getRevocationReason();
	ref<javax::security::auth::x500::X500Principal> getAuthorityName();
	ref<java::util::Date> getInvalidityDate();
	ref<java::util::Map> getExtensions();
	ref<java::lang::String> getMessage();

protected:

	CertificateRevokedException(handle_type h) : base_(h) {}

};

} // namespace java::security::cert
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/security/cert/CRLReason.h>
#include <scapix/java_api/java/util/Date.h>
#include <scapix/java_api/java/util/Map.h>
#include <scapix/java_api/javax/security/auth/x500/X500Principal.h>

namespace scapix::java_api {
namespace java::security::cert {

inline ref<CertificateRevokedException> CertificateRevokedException::new_object(ref<java::util::Date> revocationDate, ref<java::security::cert::CRLReason> reason, ref<javax::security::auth::x500::X500Principal> authority, ref<java::util::Map> extensions) { return base_::new_object(revocationDate, reason, authority, extensions); }
inline ref<java::util::Date> CertificateRevokedException::getRevocationDate() { return call_method<SCAPIX_META_STRING("getRevocationDate"), ref<java::util::Date>>(); }
inline ref<java::security::cert::CRLReason> CertificateRevokedException::getRevocationReason() { return call_method<SCAPIX_META_STRING("getRevocationReason"), ref<java::security::cert::CRLReason>>(); }
inline ref<javax::security::auth::x500::X500Principal> CertificateRevokedException::getAuthorityName() { return call_method<SCAPIX_META_STRING("getAuthorityName"), ref<javax::security::auth::x500::X500Principal>>(); }
inline ref<java::util::Date> CertificateRevokedException::getInvalidityDate() { return call_method<SCAPIX_META_STRING("getInvalidityDate"), ref<java::util::Date>>(); }
inline ref<java::util::Map> CertificateRevokedException::getExtensions() { return call_method<SCAPIX_META_STRING("getExtensions"), ref<java::util::Map>>(); }
inline ref<java::lang::String> CertificateRevokedException::getMessage() { return call_method<SCAPIX_META_STRING("getMessage"), ref<java::lang::String>>(); }

} // namespace java::security::cert
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CERT_CERTIFICATEREVOKEDEXCEPTION_H

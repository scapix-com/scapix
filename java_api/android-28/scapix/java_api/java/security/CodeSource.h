// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_SECURITY_CODESOURCE_H
#define SCAPIX_JAVA_SECURITY_CODESOURCE_H

namespace scapix::java_api {

namespace java::net { class URL; }
namespace java::security { class CodeSigner; }
namespace java::security::cert { class Certificate; }

namespace java::security {

class CodeSource : public object_base<SCAPIX_META_STRING("java/security/CodeSource"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<CodeSource> new_object(ref<java::net::URL> url, ref<link::java::array<java::security::cert::Certificate>> certs);
	static ref<CodeSource> new_object(ref<java::net::URL> url, ref<link::java::array<java::security::CodeSigner>> signers);
	ref<java::net::URL> getLocation();
	ref<link::java::array<java::security::cert::Certificate>> getCertificates();
	ref<link::java::array<java::security::CodeSigner>> getCodeSigners();
	jboolean implies(ref<java::security::CodeSource> codesource);

protected:

	CodeSource(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/net/URL.h>
#include <scapix/java_api/java/security/CodeSigner.h>
#include <scapix/java_api/java/security/cert/Certificate.h>

namespace scapix::java_api {
namespace java::security {

inline ref<CodeSource> CodeSource::new_object(ref<java::net::URL> url, ref<link::java::array<java::security::cert::Certificate>> certs) { return base_::new_object(url, certs); }
inline ref<CodeSource> CodeSource::new_object(ref<java::net::URL> url, ref<link::java::array<java::security::CodeSigner>> signers) { return base_::new_object(url, signers); }
inline ref<java::net::URL> CodeSource::getLocation() { return call_method<SCAPIX_META_STRING("getLocation"), ref<java::net::URL>>(); }
inline ref<link::java::array<java::security::cert::Certificate>> CodeSource::getCertificates() { return call_method<SCAPIX_META_STRING("getCertificates"), ref<link::java::array<java::security::cert::Certificate>>>(); }
inline ref<link::java::array<java::security::CodeSigner>> CodeSource::getCodeSigners() { return call_method<SCAPIX_META_STRING("getCodeSigners"), ref<link::java::array<java::security::CodeSigner>>>(); }
inline jboolean CodeSource::implies(ref<java::security::CodeSource> codesource) { return call_method<SCAPIX_META_STRING("implies"), jboolean>(codesource); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CODESOURCE_H
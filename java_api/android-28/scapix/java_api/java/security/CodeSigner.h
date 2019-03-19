// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_SECURITY_CODESIGNER_H
#define SCAPIX_JAVA_SECURITY_CODESIGNER_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::security { class Timestamp; }
namespace java::security::cert { class CertPath; }

namespace java::security {

class CodeSigner : public object_base<SCAPIX_META_STRING("java/security/CodeSigner"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<CodeSigner> new_object(ref<java::security::cert::CertPath> signerCertPath, ref<java::security::Timestamp> timestamp);
	ref<java::security::cert::CertPath> getSignerCertPath();
	ref<java::security::Timestamp> getTimestamp();
	jint hashCode();
	jboolean equals(ref<java::lang::Object> obj);
	ref<java::lang::String> toString();

protected:

	CodeSigner(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/security/Timestamp.h>
#include <scapix/java_api/java/security/cert/CertPath.h>

namespace scapix::java_api {
namespace java::security {

inline ref<CodeSigner> CodeSigner::new_object(ref<java::security::cert::CertPath> signerCertPath, ref<java::security::Timestamp> timestamp) { return base_::new_object(signerCertPath, timestamp); }
inline ref<java::security::cert::CertPath> CodeSigner::getSignerCertPath() { return call_method<SCAPIX_META_STRING("getSignerCertPath"), ref<java::security::cert::CertPath>>(); }
inline ref<java::security::Timestamp> CodeSigner::getTimestamp() { return call_method<SCAPIX_META_STRING("getTimestamp"), ref<java::security::Timestamp>>(); }
inline jint CodeSigner::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean CodeSigner::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline ref<java::lang::String> CodeSigner::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CODESIGNER_H
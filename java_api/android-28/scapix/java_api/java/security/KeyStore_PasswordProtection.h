// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/KeyStore_ProtectionParameter.h>
#include <scapix/java_api/javax/security/auth/Destroyable.h>

#ifndef SCAPIX_JAVA_SECURITY_KEYSTORE_PASSWORDPROTECTION_H
#define SCAPIX_JAVA_SECURITY_KEYSTORE_PASSWORDPROTECTION_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::security::spec { class AlgorithmParameterSpec; }

namespace java::security {

class KeyStore_PasswordProtection : public object_base<SCAPIX_META_STRING("java/security/KeyStore$PasswordProtection"),
	java::lang::Object,
	java::security::KeyStore_ProtectionParameter,
	javax::security::auth::Destroyable>
{
public:

	static ref<KeyStore_PasswordProtection> new_object(ref<link::java::array<jchar>> password);
	static ref<KeyStore_PasswordProtection> new_object(ref<link::java::array<jchar>> password, ref<java::lang::String> protectionAlgorithm, ref<java::security::spec::AlgorithmParameterSpec> protectionParameters);
	ref<java::lang::String> getProtectionAlgorithm();
	ref<java::security::spec::AlgorithmParameterSpec> getProtectionParameters();
	ref<link::java::array<jchar>> getPassword();
	void destroy();
	jboolean isDestroyed();

protected:

	KeyStore_PasswordProtection(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/security/spec/AlgorithmParameterSpec.h>

namespace scapix::java_api {
namespace java::security {

inline ref<KeyStore_PasswordProtection> KeyStore_PasswordProtection::new_object(ref<link::java::array<jchar>> password) { return base_::new_object(password); }
inline ref<KeyStore_PasswordProtection> KeyStore_PasswordProtection::new_object(ref<link::java::array<jchar>> password, ref<java::lang::String> protectionAlgorithm, ref<java::security::spec::AlgorithmParameterSpec> protectionParameters) { return base_::new_object(password, protectionAlgorithm, protectionParameters); }
inline ref<java::lang::String> KeyStore_PasswordProtection::getProtectionAlgorithm() { return call_method<SCAPIX_META_STRING("getProtectionAlgorithm"), ref<java::lang::String>>(); }
inline ref<java::security::spec::AlgorithmParameterSpec> KeyStore_PasswordProtection::getProtectionParameters() { return call_method<SCAPIX_META_STRING("getProtectionParameters"), ref<java::security::spec::AlgorithmParameterSpec>>(); }
inline ref<link::java::array<jchar>> KeyStore_PasswordProtection::getPassword() { return call_method<SCAPIX_META_STRING("getPassword"), ref<link::java::array<jchar>>>(); }
inline void KeyStore_PasswordProtection::destroy() { return call_method<SCAPIX_META_STRING("destroy"), void>(); }
inline jboolean KeyStore_PasswordProtection::isDestroyed() { return call_method<SCAPIX_META_STRING("isDestroyed"), jboolean>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_KEYSTORE_PASSWORDPROTECTION_H

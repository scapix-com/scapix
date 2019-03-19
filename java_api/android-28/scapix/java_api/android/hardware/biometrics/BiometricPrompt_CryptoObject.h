// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_HARDWARE_BIOMETRICS_BIOMETRICPROMPT_CRYPTOOBJECT_H
#define SCAPIX_ANDROID_HARDWARE_BIOMETRICS_BIOMETRICPROMPT_CRYPTOOBJECT_H

namespace scapix::java_api {

namespace java::security { class Signature; }
namespace javax::crypto { class Cipher; }
namespace javax::crypto { class Mac; }

namespace android::hardware::biometrics {

class BiometricPrompt_CryptoObject : public object_base<SCAPIX_META_STRING("android/hardware/biometrics/BiometricPrompt$CryptoObject"),
	java::lang::Object>
{
public:

	static ref<BiometricPrompt_CryptoObject> new_object(ref<java::security::Signature> signature);
	static ref<BiometricPrompt_CryptoObject> new_object(ref<javax::crypto::Cipher> cipher);
	static ref<BiometricPrompt_CryptoObject> new_object(ref<javax::crypto::Mac> mac);
	ref<java::security::Signature> getSignature();
	ref<javax::crypto::Cipher> getCipher();
	ref<javax::crypto::Mac> getMac();

protected:

	BiometricPrompt_CryptoObject(handle_type h) : base_(h) {}

};

} // namespace android::hardware::biometrics
} // namespace scapix::java_api

#include <scapix/java_api/java/security/Signature.h>
#include <scapix/java_api/javax/crypto/Cipher.h>
#include <scapix/java_api/javax/crypto/Mac.h>

namespace scapix::java_api {
namespace android::hardware::biometrics {

inline ref<BiometricPrompt_CryptoObject> BiometricPrompt_CryptoObject::new_object(ref<java::security::Signature> signature) { return base_::new_object(signature); }
inline ref<BiometricPrompt_CryptoObject> BiometricPrompt_CryptoObject::new_object(ref<javax::crypto::Cipher> cipher) { return base_::new_object(cipher); }
inline ref<BiometricPrompt_CryptoObject> BiometricPrompt_CryptoObject::new_object(ref<javax::crypto::Mac> mac) { return base_::new_object(mac); }
inline ref<java::security::Signature> BiometricPrompt_CryptoObject::getSignature() { return call_method<SCAPIX_META_STRING("getSignature"), ref<java::security::Signature>>(); }
inline ref<javax::crypto::Cipher> BiometricPrompt_CryptoObject::getCipher() { return call_method<SCAPIX_META_STRING("getCipher"), ref<javax::crypto::Cipher>>(); }
inline ref<javax::crypto::Mac> BiometricPrompt_CryptoObject::getMac() { return call_method<SCAPIX_META_STRING("getMac"), ref<javax::crypto::Mac>>(); }

} // namespace android::hardware::biometrics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_HARDWARE_BIOMETRICS_BIOMETRICPROMPT_CRYPTOOBJECT_H
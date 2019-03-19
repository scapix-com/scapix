// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SECURITY_KEYPAIRGENERATORSPI_H
#define SCAPIX_JAVA_SECURITY_KEYPAIRGENERATORSPI_H

namespace scapix::java_api {

namespace java::security { class KeyPair; }
namespace java::security { class SecureRandom; }
namespace java::security::spec { class AlgorithmParameterSpec; }

namespace java::security {

class KeyPairGeneratorSpi : public object_base<SCAPIX_META_STRING("java/security/KeyPairGeneratorSpi"),
	java::lang::Object>
{
public:

	static ref<KeyPairGeneratorSpi> new_object();
	void initialize(jint p1, ref<java::security::SecureRandom> p2);
	void initialize(ref<java::security::spec::AlgorithmParameterSpec> params, ref<java::security::SecureRandom> random);
	ref<java::security::KeyPair> generateKeyPair();

protected:

	KeyPairGeneratorSpi(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/security/KeyPair.h>
#include <scapix/java_api/java/security/SecureRandom.h>
#include <scapix/java_api/java/security/spec/AlgorithmParameterSpec.h>

namespace scapix::java_api {
namespace java::security {

inline ref<KeyPairGeneratorSpi> KeyPairGeneratorSpi::new_object() { return base_::new_object(); }
inline void KeyPairGeneratorSpi::initialize(jint p1, ref<java::security::SecureRandom> p2) { return call_method<SCAPIX_META_STRING("initialize"), void>(p1, p2); }
inline void KeyPairGeneratorSpi::initialize(ref<java::security::spec::AlgorithmParameterSpec> params, ref<java::security::SecureRandom> random) { return call_method<SCAPIX_META_STRING("initialize"), void>(params, random); }
inline ref<java::security::KeyPair> KeyPairGeneratorSpi::generateKeyPair() { return call_method<SCAPIX_META_STRING("generateKeyPair"), ref<java::security::KeyPair>>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_KEYPAIRGENERATORSPI_H
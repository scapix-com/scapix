// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/spec/AlgorithmParameterSpec.h>

#ifndef SCAPIX_JAVA_SECURITY_SPEC_RSAKEYGENPARAMETERSPEC_H
#define SCAPIX_JAVA_SECURITY_SPEC_RSAKEYGENPARAMETERSPEC_H

namespace scapix::java_api {

namespace java::math { class BigInteger; }

namespace java::security::spec {

class RSAKeyGenParameterSpec : public object_base<SCAPIX_META_STRING("java/security/spec/RSAKeyGenParameterSpec"),
	java::lang::Object,
	java::security::spec::AlgorithmParameterSpec>
{
public:

	static ref<java::math::BigInteger> F0_();
	static ref<java::math::BigInteger> F4_();

	static ref<RSAKeyGenParameterSpec> new_object(jint keysize, ref<java::math::BigInteger> publicExponent);
	jint getKeysize();
	ref<java::math::BigInteger> getPublicExponent();

protected:

	RSAKeyGenParameterSpec(handle_type h) : base_(h) {}

};

} // namespace java::security::spec
} // namespace scapix::java_api

#include <scapix/java_api/java/math/BigInteger.h>

namespace scapix::java_api {
namespace java::security::spec {

inline ref<java::math::BigInteger> RSAKeyGenParameterSpec::F0_() { return get_static_field<SCAPIX_META_STRING("F0"), ref<java::math::BigInteger>>(); }
inline ref<java::math::BigInteger> RSAKeyGenParameterSpec::F4_() { return get_static_field<SCAPIX_META_STRING("F4"), ref<java::math::BigInteger>>(); }
inline ref<RSAKeyGenParameterSpec> RSAKeyGenParameterSpec::new_object(jint keysize, ref<java::math::BigInteger> publicExponent) { return base_::new_object(keysize, publicExponent); }
inline jint RSAKeyGenParameterSpec::getKeysize() { return call_method<SCAPIX_META_STRING("getKeysize"), jint>(); }
inline ref<java::math::BigInteger> RSAKeyGenParameterSpec::getPublicExponent() { return call_method<SCAPIX_META_STRING("getPublicExponent"), ref<java::math::BigInteger>>(); }

} // namespace java::security::spec
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_SPEC_RSAKEYGENPARAMETERSPEC_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/spec/AlgorithmParameterSpec.h>

#ifndef SCAPIX_JAVAX_CRYPTO_SPEC_OAEPPARAMETERSPEC_H
#define SCAPIX_JAVAX_CRYPTO_SPEC_OAEPPARAMETERSPEC_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace javax::crypto::spec { class PSource; }

namespace javax::crypto::spec {

class OAEPParameterSpec : public object_base<SCAPIX_META_STRING("javax/crypto/spec/OAEPParameterSpec"),
	java::lang::Object,
	java::security::spec::AlgorithmParameterSpec>
{
public:

	static ref<javax::crypto::spec::OAEPParameterSpec> DEFAULT_();

	static ref<OAEPParameterSpec> new_object(ref<java::lang::String> mdName, ref<java::lang::String> mgfName, ref<java::security::spec::AlgorithmParameterSpec> mgfSpec, ref<javax::crypto::spec::PSource> pSrc);
	ref<java::lang::String> getDigestAlgorithm();
	ref<java::lang::String> getMGFAlgorithm();
	ref<java::security::spec::AlgorithmParameterSpec> getMGFParameters();
	ref<javax::crypto::spec::PSource> getPSource();

protected:

	OAEPParameterSpec(handle_type h) : base_(h) {}

};

} // namespace javax::crypto::spec
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/javax/crypto/spec/PSource.h>

namespace scapix::java_api {
namespace javax::crypto::spec {

inline ref<javax::crypto::spec::OAEPParameterSpec> OAEPParameterSpec::DEFAULT_() { return get_static_field<SCAPIX_META_STRING("DEFAULT"), ref<javax::crypto::spec::OAEPParameterSpec>>(); }
inline ref<OAEPParameterSpec> OAEPParameterSpec::new_object(ref<java::lang::String> mdName, ref<java::lang::String> mgfName, ref<java::security::spec::AlgorithmParameterSpec> mgfSpec, ref<javax::crypto::spec::PSource> pSrc) { return base_::new_object(mdName, mgfName, mgfSpec, pSrc); }
inline ref<java::lang::String> OAEPParameterSpec::getDigestAlgorithm() { return call_method<SCAPIX_META_STRING("getDigestAlgorithm"), ref<java::lang::String>>(); }
inline ref<java::lang::String> OAEPParameterSpec::getMGFAlgorithm() { return call_method<SCAPIX_META_STRING("getMGFAlgorithm"), ref<java::lang::String>>(); }
inline ref<java::security::spec::AlgorithmParameterSpec> OAEPParameterSpec::getMGFParameters() { return call_method<SCAPIX_META_STRING("getMGFParameters"), ref<java::security::spec::AlgorithmParameterSpec>>(); }
inline ref<javax::crypto::spec::PSource> OAEPParameterSpec::getPSource() { return call_method<SCAPIX_META_STRING("getPSource"), ref<javax::crypto::spec::PSource>>(); }

} // namespace javax::crypto::spec
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_CRYPTO_SPEC_OAEPPARAMETERSPEC_H
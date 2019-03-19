// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SECURITY_ALGORITHMPARAMETERGENERATORSPI_H
#define SCAPIX_JAVA_SECURITY_ALGORITHMPARAMETERGENERATORSPI_H

namespace scapix::java_api {
namespace java::security {

class AlgorithmParameterGeneratorSpi : public object_base<SCAPIX_META_STRING("java/security/AlgorithmParameterGeneratorSpi"),
	java::lang::Object>
{
public:

	static ref<AlgorithmParameterGeneratorSpi> new_object();

protected:

	AlgorithmParameterGeneratorSpi(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::security {

inline ref<AlgorithmParameterGeneratorSpi> AlgorithmParameterGeneratorSpi::new_object() { return base_::new_object(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_ALGORITHMPARAMETERGENERATORSPI_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SECURITY_SIGNATURESPI_H
#define SCAPIX_JAVA_SECURITY_SIGNATURESPI_H

namespace scapix::java_api {
namespace java::security {

class SignatureSpi : public object_base<SCAPIX_META_STRING("java/security/SignatureSpi"),
	java::lang::Object>
{
public:

	static ref<SignatureSpi> new_object();
	ref<java::lang::Object> clone();

protected:

	SignatureSpi(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::security {

inline ref<SignatureSpi> SignatureSpi::new_object() { return base_::new_object(); }
inline ref<java::lang::Object> SignatureSpi::clone() { return call_method<SCAPIX_META_STRING("clone"), ref<java::lang::Object>>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_SIGNATURESPI_H
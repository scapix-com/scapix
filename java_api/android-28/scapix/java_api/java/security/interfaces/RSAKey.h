// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SECURITY_INTERFACES_RSAKEY_H
#define SCAPIX_JAVA_SECURITY_INTERFACES_RSAKEY_H

namespace scapix::java_api {

namespace java::math { class BigInteger; }

namespace java::security::interfaces {

class RSAKey : public object_base<SCAPIX_META_STRING("java/security/interfaces/RSAKey"),
	java::lang::Object>
{
public:

	ref<java::math::BigInteger> getModulus();

protected:

	RSAKey(handle_type h) : base_(h) {}

};

} // namespace java::security::interfaces
} // namespace scapix::java_api

#include <scapix/java_api/java/math/BigInteger.h>

namespace scapix::java_api {
namespace java::security::interfaces {

inline ref<java::math::BigInteger> RSAKey::getModulus() { return call_method<SCAPIX_META_STRING("getModulus"), ref<java::math::BigInteger>>(); }

} // namespace java::security::interfaces
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_INTERFACES_RSAKEY_H
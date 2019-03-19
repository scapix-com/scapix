// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/interfaces/DSAKey.h>
#include <scapix/java_api/java/security/PublicKey.h>

#ifndef SCAPIX_JAVA_SECURITY_INTERFACES_DSAPUBLICKEY_H
#define SCAPIX_JAVA_SECURITY_INTERFACES_DSAPUBLICKEY_H

namespace scapix::java_api {

namespace java::math { class BigInteger; }

namespace java::security::interfaces {

class DSAPublicKey : public object_base<SCAPIX_META_STRING("java/security/interfaces/DSAPublicKey"),
	java::lang::Object,
	java::security::interfaces::DSAKey,
	java::security::PublicKey>
{
public:

	static jlong serialVersionUID();

	ref<java::math::BigInteger> getY();

protected:

	DSAPublicKey(handle_type h) : base_(h) {}

};

} // namespace java::security::interfaces
} // namespace scapix::java_api

#include <scapix/java_api/java/math/BigInteger.h>

namespace scapix::java_api {
namespace java::security::interfaces {

inline jlong DSAPublicKey::serialVersionUID() { return get_static_field<SCAPIX_META_STRING("serialVersionUID"), jlong>(); }
inline ref<java::math::BigInteger> DSAPublicKey::getY() { return call_method<SCAPIX_META_STRING("getY"), ref<java::math::BigInteger>>(); }

} // namespace java::security::interfaces
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_INTERFACES_DSAPUBLICKEY_H
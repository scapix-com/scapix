// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_SECURITY_KEYPAIR_H
#define SCAPIX_JAVA_SECURITY_KEYPAIR_H

namespace scapix::java_api {

namespace java::security { class PrivateKey; }
namespace java::security { class PublicKey; }

namespace java::security {

class KeyPair : public object_base<SCAPIX_META_STRING("java/security/KeyPair"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<KeyPair> new_object(ref<java::security::PublicKey> publicKey, ref<java::security::PrivateKey> privateKey);
	ref<java::security::PublicKey> getPublic();
	ref<java::security::PrivateKey> getPrivate();

protected:

	KeyPair(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/security/PrivateKey.h>
#include <scapix/java_api/java/security/PublicKey.h>

namespace scapix::java_api {
namespace java::security {

inline ref<KeyPair> KeyPair::new_object(ref<java::security::PublicKey> publicKey, ref<java::security::PrivateKey> privateKey) { return base_::new_object(publicKey, privateKey); }
inline ref<java::security::PublicKey> KeyPair::getPublic() { return call_method<SCAPIX_META_STRING("getPublic"), ref<java::security::PublicKey>>(); }
inline ref<java::security::PrivateKey> KeyPair::getPrivate() { return call_method<SCAPIX_META_STRING("getPrivate"), ref<java::security::PrivateKey>>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_KEYPAIR_H
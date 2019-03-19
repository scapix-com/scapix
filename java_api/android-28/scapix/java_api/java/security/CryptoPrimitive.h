// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_JAVA_SECURITY_CRYPTOPRIMITIVE_H
#define SCAPIX_JAVA_SECURITY_CRYPTOPRIMITIVE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::security {

class CryptoPrimitive : public object_base<SCAPIX_META_STRING("java/security/CryptoPrimitive"),
	java::lang::Enum>
{
public:

	static ref<java::security::CryptoPrimitive> MESSAGE_DIGEST_();
	static ref<java::security::CryptoPrimitive> SECURE_RANDOM_();
	static ref<java::security::CryptoPrimitive> BLOCK_CIPHER_();
	static ref<java::security::CryptoPrimitive> STREAM_CIPHER_();
	static ref<java::security::CryptoPrimitive> MAC_();
	static ref<java::security::CryptoPrimitive> KEY_WRAP_();
	static ref<java::security::CryptoPrimitive> PUBLIC_KEY_ENCRYPTION_();
	static ref<java::security::CryptoPrimitive> SIGNATURE_();
	static ref<java::security::CryptoPrimitive> KEY_ENCAPSULATION_();
	static ref<java::security::CryptoPrimitive> KEY_AGREEMENT_();

	static ref<link::java::array<java::security::CryptoPrimitive>> values();
	static ref<java::security::CryptoPrimitive> valueOf(ref<java::lang::String> name);

protected:

	CryptoPrimitive(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::security {

inline ref<java::security::CryptoPrimitive> CryptoPrimitive::MESSAGE_DIGEST_() { return get_static_field<SCAPIX_META_STRING("MESSAGE_DIGEST"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::SECURE_RANDOM_() { return get_static_field<SCAPIX_META_STRING("SECURE_RANDOM"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::BLOCK_CIPHER_() { return get_static_field<SCAPIX_META_STRING("BLOCK_CIPHER"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::STREAM_CIPHER_() { return get_static_field<SCAPIX_META_STRING("STREAM_CIPHER"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::MAC_() { return get_static_field<SCAPIX_META_STRING("MAC"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::KEY_WRAP_() { return get_static_field<SCAPIX_META_STRING("KEY_WRAP"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::PUBLIC_KEY_ENCRYPTION_() { return get_static_field<SCAPIX_META_STRING("PUBLIC_KEY_ENCRYPTION"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::SIGNATURE_() { return get_static_field<SCAPIX_META_STRING("SIGNATURE"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::KEY_ENCAPSULATION_() { return get_static_field<SCAPIX_META_STRING("KEY_ENCAPSULATION"), ref<java::security::CryptoPrimitive>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::KEY_AGREEMENT_() { return get_static_field<SCAPIX_META_STRING("KEY_AGREEMENT"), ref<java::security::CryptoPrimitive>>(); }
inline ref<link::java::array<java::security::CryptoPrimitive>> CryptoPrimitive::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<java::security::CryptoPrimitive>>>(); }
inline ref<java::security::CryptoPrimitive> CryptoPrimitive::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<java::security::CryptoPrimitive>>(name); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CRYPTOPRIMITIVE_H
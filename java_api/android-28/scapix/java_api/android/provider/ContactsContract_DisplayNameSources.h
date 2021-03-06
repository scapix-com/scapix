// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_DISPLAYNAMESOURCES_H
#define SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_DISPLAYNAMESOURCES_H

namespace scapix::java_api {


namespace android::provider {

class ContactsContract_DisplayNameSources : public object_base<SCAPIX_META_STRING("android/provider/ContactsContract$DisplayNameSources"),
	java::lang::Object>
{
public:

	static jint EMAIL_();
	static jint NICKNAME_();
	static jint ORGANIZATION_();
	static jint PHONE_();
	static jint STRUCTURED_NAME_();
	static jint STRUCTURED_PHONETIC_NAME_();
	static jint UNDEFINED_();


protected:

	ContactsContract_DisplayNameSources(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::provider {

inline jint ContactsContract_DisplayNameSources::EMAIL_() { return get_static_field<SCAPIX_META_STRING("EMAIL"), jint>(); }
inline jint ContactsContract_DisplayNameSources::NICKNAME_() { return get_static_field<SCAPIX_META_STRING("NICKNAME"), jint>(); }
inline jint ContactsContract_DisplayNameSources::ORGANIZATION_() { return get_static_field<SCAPIX_META_STRING("ORGANIZATION"), jint>(); }
inline jint ContactsContract_DisplayNameSources::PHONE_() { return get_static_field<SCAPIX_META_STRING("PHONE"), jint>(); }
inline jint ContactsContract_DisplayNameSources::STRUCTURED_NAME_() { return get_static_field<SCAPIX_META_STRING("STRUCTURED_NAME"), jint>(); }
inline jint ContactsContract_DisplayNameSources::STRUCTURED_PHONETIC_NAME_() { return get_static_field<SCAPIX_META_STRING("STRUCTURED_PHONETIC_NAME"), jint>(); }
inline jint ContactsContract_DisplayNameSources::UNDEFINED_() { return get_static_field<SCAPIX_META_STRING("UNDEFINED"), jint>(); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_DISPLAYNAMESOURCES_H

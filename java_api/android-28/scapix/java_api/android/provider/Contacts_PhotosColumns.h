// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOSCOLUMNS_H
#define SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOSCOLUMNS_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::provider {

class Contacts_PhotosColumns : public object_base<SCAPIX_META_STRING("android/provider/Contacts$PhotosColumns"),
	java::lang::Object>
{
public:

	static ref<java::lang::String> DATA_();
	static ref<java::lang::String> DOWNLOAD_REQUIRED_();
	static ref<java::lang::String> EXISTS_ON_SERVER_();
	static ref<java::lang::String> LOCAL_VERSION_();
	static ref<java::lang::String> PERSON_ID_();
	static ref<java::lang::String> SYNC_ERROR_();


protected:

	Contacts_PhotosColumns(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<java::lang::String> Contacts_PhotosColumns::DATA_() { return get_static_field<SCAPIX_META_STRING("DATA"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Contacts_PhotosColumns::DOWNLOAD_REQUIRED_() { return get_static_field<SCAPIX_META_STRING("DOWNLOAD_REQUIRED"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Contacts_PhotosColumns::EXISTS_ON_SERVER_() { return get_static_field<SCAPIX_META_STRING("EXISTS_ON_SERVER"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Contacts_PhotosColumns::LOCAL_VERSION_() { return get_static_field<SCAPIX_META_STRING("LOCAL_VERSION"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Contacts_PhotosColumns::PERSON_ID_() { return get_static_field<SCAPIX_META_STRING("PERSON_ID"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Contacts_PhotosColumns::SYNC_ERROR_() { return get_static_field<SCAPIX_META_STRING("SYNC_ERROR"), ref<java::lang::String>>(); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOSCOLUMNS_H
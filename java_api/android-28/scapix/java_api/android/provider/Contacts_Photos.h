// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/provider/BaseColumns.h>
#include <scapix/java_api/android/provider/Contacts_PhotosColumns.h>

#ifndef SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOS_H
#define SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOS_H

namespace scapix::java_api {

namespace android::net { class Uri; }
namespace java::lang { class String; }

namespace android::provider {

class Contacts_Photos : public object_base<SCAPIX_META_STRING("android/provider/Contacts$Photos"),
	java::lang::Object,
	android::provider::BaseColumns,
	android::provider::Contacts_PhotosColumns>
{
public:

	static ref<java::lang::String> CONTENT_DIRECTORY_();
	static ref<android::net::Uri> CONTENT_URI_();
	static ref<java::lang::String> DEFAULT_SORT_ORDER_();


protected:

	Contacts_Photos(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<java::lang::String> Contacts_Photos::CONTENT_DIRECTORY_() { return get_static_field<SCAPIX_META_STRING("CONTENT_DIRECTORY"), ref<java::lang::String>>(); }
inline ref<android::net::Uri> Contacts_Photos::CONTENT_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_URI"), ref<android::net::Uri>>(); }
inline ref<java::lang::String> Contacts_Photos::DEFAULT_SORT_ORDER_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_SORT_ORDER"), ref<java::lang::String>>(); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_CONTACTS_PHOTOS_H
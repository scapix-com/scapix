// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/provider/BaseColumns.h>

#ifndef SCAPIX_ANDROID_PROVIDER_TELEPHONY_MMSSMS_H
#define SCAPIX_ANDROID_PROVIDER_TELEPHONY_MMSSMS_H

namespace scapix::java_api {

namespace android::net { class Uri; }
namespace java::lang { class String; }
namespace android::provider { class Telephony_MmsSms_PendingMessages; }

namespace android::provider {

class Telephony_MmsSms : public object_base<SCAPIX_META_STRING("android/provider/Telephony$MmsSms"),
	java::lang::Object,
	android::provider::BaseColumns>
{
public:

	using PendingMessages = Telephony_MmsSms_PendingMessages;

	static ref<android::net::Uri> CONTENT_CONVERSATIONS_URI_();
	static ref<android::net::Uri> CONTENT_DRAFT_URI_();
	static ref<android::net::Uri> CONTENT_FILTER_BYPHONE_URI_();
	static ref<android::net::Uri> CONTENT_LOCKED_URI_();
	static ref<android::net::Uri> CONTENT_UNDELIVERED_URI_();
	static ref<android::net::Uri> CONTENT_URI_();
	static jint ERR_TYPE_GENERIC_();
	static jint ERR_TYPE_GENERIC_PERMANENT_();
	static jint ERR_TYPE_MMS_PROTO_PERMANENT_();
	static jint ERR_TYPE_MMS_PROTO_TRANSIENT_();
	static jint ERR_TYPE_SMS_PROTO_PERMANENT_();
	static jint ERR_TYPE_SMS_PROTO_TRANSIENT_();
	static jint ERR_TYPE_TRANSPORT_FAILURE_();
	static jint MMS_PROTO_();
	static jint NO_ERROR_();
	static ref<android::net::Uri> SEARCH_URI_();
	static jint SMS_PROTO_();
	static ref<java::lang::String> TYPE_DISCRIMINATOR_COLUMN_();


protected:

	Telephony_MmsSms(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_CONVERSATIONS_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_CONVERSATIONS_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_DRAFT_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_DRAFT_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_FILTER_BYPHONE_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_FILTER_BYPHONE_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_LOCKED_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_LOCKED_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_UNDELIVERED_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_UNDELIVERED_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> Telephony_MmsSms::CONTENT_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_URI"), ref<android::net::Uri>>(); }
inline jint Telephony_MmsSms::ERR_TYPE_GENERIC_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_GENERIC"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_GENERIC_PERMANENT_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_GENERIC_PERMANENT"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_MMS_PROTO_PERMANENT_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_MMS_PROTO_PERMANENT"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_MMS_PROTO_TRANSIENT_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_MMS_PROTO_TRANSIENT"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_SMS_PROTO_PERMANENT_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_SMS_PROTO_PERMANENT"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_SMS_PROTO_TRANSIENT_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_SMS_PROTO_TRANSIENT"), jint>(); }
inline jint Telephony_MmsSms::ERR_TYPE_TRANSPORT_FAILURE_() { return get_static_field<SCAPIX_META_STRING("ERR_TYPE_TRANSPORT_FAILURE"), jint>(); }
inline jint Telephony_MmsSms::MMS_PROTO_() { return get_static_field<SCAPIX_META_STRING("MMS_PROTO"), jint>(); }
inline jint Telephony_MmsSms::NO_ERROR_() { return get_static_field<SCAPIX_META_STRING("NO_ERROR"), jint>(); }
inline ref<android::net::Uri> Telephony_MmsSms::SEARCH_URI_() { return get_static_field<SCAPIX_META_STRING("SEARCH_URI"), ref<android::net::Uri>>(); }
inline jint Telephony_MmsSms::SMS_PROTO_() { return get_static_field<SCAPIX_META_STRING("SMS_PROTO"), jint>(); }
inline ref<java::lang::String> Telephony_MmsSms::TYPE_DISCRIMINATOR_COLUMN_() { return get_static_field<SCAPIX_META_STRING("TYPE_DISCRIMINATOR_COLUMN"), ref<java::lang::String>>(); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_TELEPHONY_MMSSMS_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_TELEPHONY_MBMS_DOWNLOADREQUEST_BUILDER_H
#define SCAPIX_ANDROID_TELEPHONY_MBMS_DOWNLOADREQUEST_BUILDER_H

namespace scapix::java_api {

namespace android::content { class Intent; }
namespace android::net { class Uri; }
namespace android::telephony::mbms { class DownloadRequest; }
namespace android::telephony::mbms { class FileServiceInfo; }

namespace android::telephony::mbms {

class DownloadRequest_Builder : public object_base<SCAPIX_META_STRING("android/telephony/mbms/DownloadRequest$Builder"),
	java::lang::Object>
{
public:

	static ref<DownloadRequest_Builder> new_object(ref<android::net::Uri> sourceUri, ref<android::net::Uri> destinationUri);
	static ref<android::telephony::mbms::DownloadRequest_Builder> fromDownloadRequest(ref<android::telephony::mbms::DownloadRequest> other);
	static ref<android::telephony::mbms::DownloadRequest_Builder> fromSerializedRequest(ref<link::java::array<jbyte>> data);
	ref<android::telephony::mbms::DownloadRequest_Builder> setServiceInfo(ref<android::telephony::mbms::FileServiceInfo> serviceInfo);
	ref<android::telephony::mbms::DownloadRequest_Builder> setSubscriptionId(jint subscriptionId);
	ref<android::telephony::mbms::DownloadRequest_Builder> setAppIntent(ref<android::content::Intent> intent);
	ref<android::telephony::mbms::DownloadRequest> build();

protected:

	DownloadRequest_Builder(handle_type h) : base_(h) {}

};

} // namespace android::telephony::mbms
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/android/telephony/mbms/DownloadRequest.h>
#include <scapix/java_api/android/telephony/mbms/FileServiceInfo.h>

namespace scapix::java_api {
namespace android::telephony::mbms {

inline ref<DownloadRequest_Builder> DownloadRequest_Builder::new_object(ref<android::net::Uri> sourceUri, ref<android::net::Uri> destinationUri) { return base_::new_object(sourceUri, destinationUri); }
inline ref<android::telephony::mbms::DownloadRequest_Builder> DownloadRequest_Builder::fromDownloadRequest(ref<android::telephony::mbms::DownloadRequest> other) { return call_static_method<SCAPIX_META_STRING("fromDownloadRequest"), ref<android::telephony::mbms::DownloadRequest_Builder>>(other); }
inline ref<android::telephony::mbms::DownloadRequest_Builder> DownloadRequest_Builder::fromSerializedRequest(ref<link::java::array<jbyte>> data) { return call_static_method<SCAPIX_META_STRING("fromSerializedRequest"), ref<android::telephony::mbms::DownloadRequest_Builder>>(data); }
inline ref<android::telephony::mbms::DownloadRequest_Builder> DownloadRequest_Builder::setServiceInfo(ref<android::telephony::mbms::FileServiceInfo> serviceInfo) { return call_method<SCAPIX_META_STRING("setServiceInfo"), ref<android::telephony::mbms::DownloadRequest_Builder>>(serviceInfo); }
inline ref<android::telephony::mbms::DownloadRequest_Builder> DownloadRequest_Builder::setSubscriptionId(jint subscriptionId) { return call_method<SCAPIX_META_STRING("setSubscriptionId"), ref<android::telephony::mbms::DownloadRequest_Builder>>(subscriptionId); }
inline ref<android::telephony::mbms::DownloadRequest_Builder> DownloadRequest_Builder::setAppIntent(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("setAppIntent"), ref<android::telephony::mbms::DownloadRequest_Builder>>(intent); }
inline ref<android::telephony::mbms::DownloadRequest> DownloadRequest_Builder::build() { return call_method<SCAPIX_META_STRING("build"), ref<android::telephony::mbms::DownloadRequest>>(); }

} // namespace android::telephony::mbms
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TELEPHONY_MBMS_DOWNLOADREQUEST_BUILDER_H
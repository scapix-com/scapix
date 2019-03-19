// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/AutoCloseable.h>

#ifndef SCAPIX_ANDROID_DRM_DRMMANAGERCLIENT_H
#define SCAPIX_ANDROID_DRM_DRMMANAGERCLIENT_H

namespace scapix::java_api {

namespace android::content { class ContentValues; }
namespace android::content { class Context; }
namespace android::drm { class DrmConvertedStatus; }
namespace android::drm { class DrmInfo; }
namespace android::drm { class DrmInfoRequest; }
namespace android::drm { class DrmManagerClient_OnErrorListener; }
namespace android::drm { class DrmManagerClient_OnEventListener; }
namespace android::drm { class DrmManagerClient_OnInfoListener; }
namespace android::drm { class DrmRights; }
namespace android::net { class Uri; }
namespace java::lang { class String; }

namespace android::drm {

class DrmManagerClient : public object_base<SCAPIX_META_STRING("android/drm/DrmManagerClient"),
	java::lang::Object,
	java::lang::AutoCloseable>
{
public:

	using OnInfoListener = DrmManagerClient_OnInfoListener;
	using OnEventListener = DrmManagerClient_OnEventListener;
	using OnErrorListener = DrmManagerClient_OnErrorListener;

	static jint ERROR_NONE_();
	static jint ERROR_UNKNOWN_();

	static ref<DrmManagerClient> new_object(ref<android::content::Context> context);
	void close();
	void release();
	void setOnInfoListener(ref<android::drm::DrmManagerClient_OnInfoListener> infoListener);
	void setOnEventListener(ref<android::drm::DrmManagerClient_OnEventListener> eventListener);
	void setOnErrorListener(ref<android::drm::DrmManagerClient_OnErrorListener> errorListener);
	ref<link::java::array<java::lang::String>> getAvailableDrmEngines();
	ref<android::content::ContentValues> getConstraints(ref<java::lang::String> path, jint action);
	ref<android::content::ContentValues> getMetadata(ref<java::lang::String> path);
	ref<android::content::ContentValues> getConstraints(ref<android::net::Uri> uri, jint action);
	ref<android::content::ContentValues> getMetadata(ref<android::net::Uri> uri);
	jint saveRights(ref<android::drm::DrmRights> drmRights, ref<java::lang::String> rightsPath, ref<java::lang::String> contentPath);
	jboolean canHandle(ref<java::lang::String> path, ref<java::lang::String> mimeType);
	jboolean canHandle(ref<android::net::Uri> uri, ref<java::lang::String> mimeType);
	jint processDrmInfo(ref<android::drm::DrmInfo> drmInfo);
	ref<android::drm::DrmInfo> acquireDrmInfo(ref<android::drm::DrmInfoRequest> drmInfoRequest);
	jint acquireRights(ref<android::drm::DrmInfoRequest> drmInfoRequest);
	jint getDrmObjectType(ref<java::lang::String> path, ref<java::lang::String> mimeType);
	jint getDrmObjectType(ref<android::net::Uri> uri, ref<java::lang::String> mimeType);
	ref<java::lang::String> getOriginalMimeType(ref<java::lang::String> path);
	ref<java::lang::String> getOriginalMimeType(ref<android::net::Uri> uri);
	jint checkRightsStatus(ref<java::lang::String> path);
	jint checkRightsStatus(ref<android::net::Uri> uri);
	jint checkRightsStatus(ref<java::lang::String> path, jint action);
	jint checkRightsStatus(ref<android::net::Uri> uri, jint action);
	jint removeRights(ref<java::lang::String> path);
	jint removeRights(ref<android::net::Uri> uri);
	jint removeAllRights();
	jint openConvertSession(ref<java::lang::String> mimeType);
	ref<android::drm::DrmConvertedStatus> convertData(jint convertId, ref<link::java::array<jbyte>> inputData);
	ref<android::drm::DrmConvertedStatus> closeConvertSession(jint convertId);

protected:

	DrmManagerClient(handle_type h) : base_(h) {}

};

} // namespace android::drm
} // namespace scapix::java_api

#include <scapix/java_api/android/content/ContentValues.h>
#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/drm/DrmConvertedStatus.h>
#include <scapix/java_api/android/drm/DrmInfo.h>
#include <scapix/java_api/android/drm/DrmInfoRequest.h>
#include <scapix/java_api/android/drm/DrmManagerClient_OnErrorListener.h>
#include <scapix/java_api/android/drm/DrmManagerClient_OnEventListener.h>
#include <scapix/java_api/android/drm/DrmManagerClient_OnInfoListener.h>
#include <scapix/java_api/android/drm/DrmRights.h>
#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::drm {

inline jint DrmManagerClient::ERROR_NONE_() { return get_static_field<SCAPIX_META_STRING("ERROR_NONE"), jint>(); }
inline jint DrmManagerClient::ERROR_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("ERROR_UNKNOWN"), jint>(); }
inline ref<DrmManagerClient> DrmManagerClient::new_object(ref<android::content::Context> context) { return base_::new_object(context); }
inline void DrmManagerClient::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }
inline void DrmManagerClient::release() { return call_method<SCAPIX_META_STRING("release"), void>(); }
inline void DrmManagerClient::setOnInfoListener(ref<android::drm::DrmManagerClient_OnInfoListener> infoListener) { return call_method<SCAPIX_META_STRING("setOnInfoListener"), void>(infoListener); }
inline void DrmManagerClient::setOnEventListener(ref<android::drm::DrmManagerClient_OnEventListener> eventListener) { return call_method<SCAPIX_META_STRING("setOnEventListener"), void>(eventListener); }
inline void DrmManagerClient::setOnErrorListener(ref<android::drm::DrmManagerClient_OnErrorListener> errorListener) { return call_method<SCAPIX_META_STRING("setOnErrorListener"), void>(errorListener); }
inline ref<link::java::array<java::lang::String>> DrmManagerClient::getAvailableDrmEngines() { return call_method<SCAPIX_META_STRING("getAvailableDrmEngines"), ref<link::java::array<java::lang::String>>>(); }
inline ref<android::content::ContentValues> DrmManagerClient::getConstraints(ref<java::lang::String> path, jint action) { return call_method<SCAPIX_META_STRING("getConstraints"), ref<android::content::ContentValues>>(path, action); }
inline ref<android::content::ContentValues> DrmManagerClient::getMetadata(ref<java::lang::String> path) { return call_method<SCAPIX_META_STRING("getMetadata"), ref<android::content::ContentValues>>(path); }
inline ref<android::content::ContentValues> DrmManagerClient::getConstraints(ref<android::net::Uri> uri, jint action) { return call_method<SCAPIX_META_STRING("getConstraints"), ref<android::content::ContentValues>>(uri, action); }
inline ref<android::content::ContentValues> DrmManagerClient::getMetadata(ref<android::net::Uri> uri) { return call_method<SCAPIX_META_STRING("getMetadata"), ref<android::content::ContentValues>>(uri); }
inline jint DrmManagerClient::saveRights(ref<android::drm::DrmRights> drmRights, ref<java::lang::String> rightsPath, ref<java::lang::String> contentPath) { return call_method<SCAPIX_META_STRING("saveRights"), jint>(drmRights, rightsPath, contentPath); }
inline jboolean DrmManagerClient::canHandle(ref<java::lang::String> path, ref<java::lang::String> mimeType) { return call_method<SCAPIX_META_STRING("canHandle"), jboolean>(path, mimeType); }
inline jboolean DrmManagerClient::canHandle(ref<android::net::Uri> uri, ref<java::lang::String> mimeType) { return call_method<SCAPIX_META_STRING("canHandle"), jboolean>(uri, mimeType); }
inline jint DrmManagerClient::processDrmInfo(ref<android::drm::DrmInfo> drmInfo) { return call_method<SCAPIX_META_STRING("processDrmInfo"), jint>(drmInfo); }
inline ref<android::drm::DrmInfo> DrmManagerClient::acquireDrmInfo(ref<android::drm::DrmInfoRequest> drmInfoRequest) { return call_method<SCAPIX_META_STRING("acquireDrmInfo"), ref<android::drm::DrmInfo>>(drmInfoRequest); }
inline jint DrmManagerClient::acquireRights(ref<android::drm::DrmInfoRequest> drmInfoRequest) { return call_method<SCAPIX_META_STRING("acquireRights"), jint>(drmInfoRequest); }
inline jint DrmManagerClient::getDrmObjectType(ref<java::lang::String> path, ref<java::lang::String> mimeType) { return call_method<SCAPIX_META_STRING("getDrmObjectType"), jint>(path, mimeType); }
inline jint DrmManagerClient::getDrmObjectType(ref<android::net::Uri> uri, ref<java::lang::String> mimeType) { return call_method<SCAPIX_META_STRING("getDrmObjectType"), jint>(uri, mimeType); }
inline ref<java::lang::String> DrmManagerClient::getOriginalMimeType(ref<java::lang::String> path) { return call_method<SCAPIX_META_STRING("getOriginalMimeType"), ref<java::lang::String>>(path); }
inline ref<java::lang::String> DrmManagerClient::getOriginalMimeType(ref<android::net::Uri> uri) { return call_method<SCAPIX_META_STRING("getOriginalMimeType"), ref<java::lang::String>>(uri); }
inline jint DrmManagerClient::checkRightsStatus(ref<java::lang::String> path) { return call_method<SCAPIX_META_STRING("checkRightsStatus"), jint>(path); }
inline jint DrmManagerClient::checkRightsStatus(ref<android::net::Uri> uri) { return call_method<SCAPIX_META_STRING("checkRightsStatus"), jint>(uri); }
inline jint DrmManagerClient::checkRightsStatus(ref<java::lang::String> path, jint action) { return call_method<SCAPIX_META_STRING("checkRightsStatus"), jint>(path, action); }
inline jint DrmManagerClient::checkRightsStatus(ref<android::net::Uri> uri, jint action) { return call_method<SCAPIX_META_STRING("checkRightsStatus"), jint>(uri, action); }
inline jint DrmManagerClient::removeRights(ref<java::lang::String> path) { return call_method<SCAPIX_META_STRING("removeRights"), jint>(path); }
inline jint DrmManagerClient::removeRights(ref<android::net::Uri> uri) { return call_method<SCAPIX_META_STRING("removeRights"), jint>(uri); }
inline jint DrmManagerClient::removeAllRights() { return call_method<SCAPIX_META_STRING("removeAllRights"), jint>(); }
inline jint DrmManagerClient::openConvertSession(ref<java::lang::String> mimeType) { return call_method<SCAPIX_META_STRING("openConvertSession"), jint>(mimeType); }
inline ref<android::drm::DrmConvertedStatus> DrmManagerClient::convertData(jint convertId, ref<link::java::array<jbyte>> inputData) { return call_method<SCAPIX_META_STRING("convertData"), ref<android::drm::DrmConvertedStatus>>(convertId, inputData); }
inline ref<android::drm::DrmConvertedStatus> DrmManagerClient::closeConvertSession(jint convertId) { return call_method<SCAPIX_META_STRING("closeConvertSession"), ref<android::drm::DrmConvertedStatus>>(convertId); }

} // namespace android::drm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_DRM_DRMMANAGERCLIENT_H
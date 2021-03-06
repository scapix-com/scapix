// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_DRM_DRMCONVERTEDSTATUS_H
#define SCAPIX_ANDROID_DRM_DRMCONVERTEDSTATUS_H

namespace scapix::java_api {
namespace android::drm {

class DrmConvertedStatus : public object_base<SCAPIX_META_STRING("android/drm/DrmConvertedStatus"),
	java::lang::Object>
{
public:

	static jint STATUS_ERROR_();
	static jint STATUS_INPUTDATA_ERROR_();
	static jint STATUS_OK_();
	ref<link::java::array<jbyte>> convertedData();
	jint offset();
	jint statusCode();

	static ref<DrmConvertedStatus> new_object(jint statusCode, ref<link::java::array<jbyte>> convertedData, jint offset);

protected:

	DrmConvertedStatus(handle_type h) : base_(h) {}

};

} // namespace android::drm
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::drm {

inline jint DrmConvertedStatus::STATUS_ERROR_() { return get_static_field<SCAPIX_META_STRING("STATUS_ERROR"), jint>(); }
inline jint DrmConvertedStatus::STATUS_INPUTDATA_ERROR_() { return get_static_field<SCAPIX_META_STRING("STATUS_INPUTDATA_ERROR"), jint>(); }
inline jint DrmConvertedStatus::STATUS_OK_() { return get_static_field<SCAPIX_META_STRING("STATUS_OK"), jint>(); }
inline ref<link::java::array<jbyte>> DrmConvertedStatus::convertedData() { return get_field<SCAPIX_META_STRING("convertedData"), ref<link::java::array<jbyte>>>(); }
inline jint DrmConvertedStatus::offset() { return get_field<SCAPIX_META_STRING("offset"), jint>(); }
inline jint DrmConvertedStatus::statusCode() { return get_field<SCAPIX_META_STRING("statusCode"), jint>(); }
inline ref<DrmConvertedStatus> DrmConvertedStatus::new_object(jint statusCode, ref<link::java::array<jbyte>> convertedData, jint offset) { return base_::new_object(statusCode, convertedData, offset); }

} // namespace android::drm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_DRM_DRMCONVERTEDSTATUS_H

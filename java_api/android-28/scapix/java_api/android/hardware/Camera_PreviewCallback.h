// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_HARDWARE_CAMERA_PREVIEWCALLBACK_H
#define SCAPIX_ANDROID_HARDWARE_CAMERA_PREVIEWCALLBACK_H

namespace scapix::java_api {

namespace android::hardware { class Camera; }

namespace android::hardware {

class Camera_PreviewCallback : public object_base<SCAPIX_META_STRING("android/hardware/Camera$PreviewCallback"),
	java::lang::Object>
{
public:

	void onPreviewFrame(ref<link::java::array<jbyte>> p1, ref<android::hardware::Camera> p2);

protected:

	Camera_PreviewCallback(handle_type h) : base_(h) {}

};

} // namespace android::hardware
} // namespace scapix::java_api

#include <scapix/java_api/android/hardware/Camera.h>

namespace scapix::java_api {
namespace android::hardware {

inline void Camera_PreviewCallback::onPreviewFrame(ref<link::java::array<jbyte>> p1, ref<android::hardware::Camera> p2) { return call_method<SCAPIX_META_STRING("onPreviewFrame"), void>(p1, p2); }

} // namespace android::hardware
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_HARDWARE_CAMERA_PREVIEWCALLBACK_H
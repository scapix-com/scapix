// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_VIEW_INPUTEVENT_H
#define SCAPIX_ANDROID_VIEW_INPUTEVENT_H

namespace scapix::java_api {

namespace android::os { class Parcelable_Creator; }
namespace android::view { class InputDevice; }

namespace android::view {

class InputEvent : public object_base<SCAPIX_META_STRING("android/view/InputEvent"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	jint getDeviceId();
	ref<android::view::InputDevice> getDevice();
	jint getSource();
	jboolean isFromSource(jint source);
	jlong getEventTime();
	jint describeContents();

protected:

	InputEvent(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/android/view/InputDevice.h>

namespace scapix::java_api {
namespace android::view {

inline ref<android::os::Parcelable_Creator> InputEvent::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint InputEvent::getDeviceId() { return call_method<SCAPIX_META_STRING("getDeviceId"), jint>(); }
inline ref<android::view::InputDevice> InputEvent::getDevice() { return call_method<SCAPIX_META_STRING("getDevice"), ref<android::view::InputDevice>>(); }
inline jint InputEvent::getSource() { return call_method<SCAPIX_META_STRING("getSource"), jint>(); }
inline jboolean InputEvent::isFromSource(jint source) { return call_method<SCAPIX_META_STRING("isFromSource"), jboolean>(source); }
inline jlong InputEvent::getEventTime() { return call_method<SCAPIX_META_STRING("getEventTime"), jlong>(); }
inline jint InputEvent::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_INPUTEVENT_H
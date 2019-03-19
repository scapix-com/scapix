// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_GESTUREDETECTOR_ONDOUBLETAPLISTENER_H
#define SCAPIX_ANDROID_VIEW_GESTUREDETECTOR_ONDOUBLETAPLISTENER_H

namespace scapix::java_api {

namespace android::view { class MotionEvent; }

namespace android::view {

class GestureDetector_OnDoubleTapListener : public object_base<SCAPIX_META_STRING("android/view/GestureDetector$OnDoubleTapListener"),
	java::lang::Object>
{
public:

	jboolean onSingleTapConfirmed(ref<android::view::MotionEvent> p1);
	jboolean onDoubleTap(ref<android::view::MotionEvent> p1);
	jboolean onDoubleTapEvent(ref<android::view::MotionEvent> p1);

protected:

	GestureDetector_OnDoubleTapListener(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/view/MotionEvent.h>

namespace scapix::java_api {
namespace android::view {

inline jboolean GestureDetector_OnDoubleTapListener::onSingleTapConfirmed(ref<android::view::MotionEvent> p1) { return call_method<SCAPIX_META_STRING("onSingleTapConfirmed"), jboolean>(p1); }
inline jboolean GestureDetector_OnDoubleTapListener::onDoubleTap(ref<android::view::MotionEvent> p1) { return call_method<SCAPIX_META_STRING("onDoubleTap"), jboolean>(p1); }
inline jboolean GestureDetector_OnDoubleTapListener::onDoubleTapEvent(ref<android::view::MotionEvent> p1) { return call_method<SCAPIX_META_STRING("onDoubleTapEvent"), jboolean>(p1); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_GESTUREDETECTOR_ONDOUBLETAPLISTENER_H
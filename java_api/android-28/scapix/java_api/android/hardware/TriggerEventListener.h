// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_HARDWARE_TRIGGEREVENTLISTENER_H
#define SCAPIX_ANDROID_HARDWARE_TRIGGEREVENTLISTENER_H

namespace scapix::java_api {

namespace android::hardware { class TriggerEvent; }

namespace android::hardware {

class TriggerEventListener : public object_base<SCAPIX_META_STRING("android/hardware/TriggerEventListener"),
	java::lang::Object>
{
public:

	static ref<TriggerEventListener> new_object();
	void onTrigger(ref<android::hardware::TriggerEvent> p1);

protected:

	TriggerEventListener(handle_type h) : base_(h) {}

};

} // namespace android::hardware
} // namespace scapix::java_api

#include <scapix/java_api/android/hardware/TriggerEvent.h>

namespace scapix::java_api {
namespace android::hardware {

inline ref<TriggerEventListener> TriggerEventListener::new_object() { return base_::new_object(); }
inline void TriggerEventListener::onTrigger(ref<android::hardware::TriggerEvent> p1) { return call_method<SCAPIX_META_STRING("onTrigger"), void>(p1); }

} // namespace android::hardware
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_HARDWARE_TRIGGEREVENTLISTENER_H
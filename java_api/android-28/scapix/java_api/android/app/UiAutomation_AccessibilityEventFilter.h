// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_APP_UIAUTOMATION_ACCESSIBILITYEVENTFILTER_H
#define SCAPIX_ANDROID_APP_UIAUTOMATION_ACCESSIBILITYEVENTFILTER_H

namespace scapix::java_api {

namespace android::view::accessibility { class AccessibilityEvent; }

namespace android::app {

class UiAutomation_AccessibilityEventFilter : public object_base<SCAPIX_META_STRING("android/app/UiAutomation$AccessibilityEventFilter"),
	java::lang::Object>
{
public:

	jboolean accept(ref<android::view::accessibility::AccessibilityEvent> p1);

protected:

	UiAutomation_AccessibilityEventFilter(handle_type h) : base_(h) {}

};

} // namespace android::app
} // namespace scapix::java_api

#include <scapix/java_api/android/view/accessibility/AccessibilityEvent.h>

namespace scapix::java_api {
namespace android::app {

inline jboolean UiAutomation_AccessibilityEventFilter::accept(ref<android::view::accessibility::AccessibilityEvent> p1) { return call_method<SCAPIX_META_STRING("accept"), jboolean>(p1); }

} // namespace android::app
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_UIAUTOMATION_ACCESSIBILITYEVENTFILTER_H
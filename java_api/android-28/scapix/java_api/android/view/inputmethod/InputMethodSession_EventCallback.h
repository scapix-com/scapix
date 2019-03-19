// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_EVENTCALLBACK_H
#define SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_EVENTCALLBACK_H

namespace scapix::java_api {


namespace android::view::inputmethod {

class InputMethodSession_EventCallback : public object_base<SCAPIX_META_STRING("android/view/inputmethod/InputMethodSession$EventCallback"),
	java::lang::Object>
{
public:

	void finishedEvent(jint p1, jboolean p2);

protected:

	InputMethodSession_EventCallback(handle_type h) : base_(h) {}

};

} // namespace android::view::inputmethod
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::view::inputmethod {

inline void InputMethodSession_EventCallback::finishedEvent(jint p1, jboolean p2) { return call_method<SCAPIX_META_STRING("finishedEvent"), void>(p1, p2); }

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_EVENTCALLBACK_H
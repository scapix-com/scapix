// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/Service.h>
#include <scapix/java_api/android/view/KeyEvent_Callback.h>

#ifndef SCAPIX_ANDROID_INPUTMETHODSERVICE_ABSTRACTINPUTMETHODSERVICE_H
#define SCAPIX_ANDROID_INPUTMETHODSERVICE_ABSTRACTINPUTMETHODSERVICE_H

namespace scapix::java_api {

namespace android::content { class Intent; }
namespace android::inputmethodservice { class AbstractInputMethodService_AbstractInputMethodImpl; }
namespace android::inputmethodservice { class AbstractInputMethodService_AbstractInputMethodSessionImpl; }
namespace android::os { class IBinder; }
namespace android::view { class KeyEvent_DispatcherState; }
namespace android::view { class MotionEvent; }

namespace android::inputmethodservice {

class AbstractInputMethodService : public object_base<SCAPIX_META_STRING("android/inputmethodservice/AbstractInputMethodService"),
	android::app::Service,
	android::view::KeyEvent_Callback>
{
public:

	using AbstractInputMethodSessionImpl = AbstractInputMethodService_AbstractInputMethodSessionImpl;
	using AbstractInputMethodImpl = AbstractInputMethodService_AbstractInputMethodImpl;

	static ref<AbstractInputMethodService> new_object();
	ref<android::view::KeyEvent_DispatcherState> getKeyDispatcherState();
	ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodImpl> onCreateInputMethodInterface();
	ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodSessionImpl> onCreateInputMethodSessionInterface();
	ref<android::os::IBinder> onBind(ref<android::content::Intent> intent);
	jboolean onTrackballEvent(ref<android::view::MotionEvent> event);
	jboolean onGenericMotionEvent(ref<android::view::MotionEvent> event);

protected:

	AbstractInputMethodService(handle_type h) : base_(h) {}

};

} // namespace android::inputmethodservice
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/inputmethodservice/AbstractInputMethodService_AbstractInputMethodImpl.h>
#include <scapix/java_api/android/inputmethodservice/AbstractInputMethodService_AbstractInputMethodSessionImpl.h>
#include <scapix/java_api/android/os/IBinder.h>
#include <scapix/java_api/android/view/KeyEvent_DispatcherState.h>
#include <scapix/java_api/android/view/MotionEvent.h>

namespace scapix::java_api {
namespace android::inputmethodservice {

inline ref<AbstractInputMethodService> AbstractInputMethodService::new_object() { return base_::new_object(); }
inline ref<android::view::KeyEvent_DispatcherState> AbstractInputMethodService::getKeyDispatcherState() { return call_method<SCAPIX_META_STRING("getKeyDispatcherState"), ref<android::view::KeyEvent_DispatcherState>>(); }
inline ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodImpl> AbstractInputMethodService::onCreateInputMethodInterface() { return call_method<SCAPIX_META_STRING("onCreateInputMethodInterface"), ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodImpl>>(); }
inline ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodSessionImpl> AbstractInputMethodService::onCreateInputMethodSessionInterface() { return call_method<SCAPIX_META_STRING("onCreateInputMethodSessionInterface"), ref<android::inputmethodservice::AbstractInputMethodService_AbstractInputMethodSessionImpl>>(); }
inline ref<android::os::IBinder> AbstractInputMethodService::onBind(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("onBind"), ref<android::os::IBinder>>(intent); }
inline jboolean AbstractInputMethodService::onTrackballEvent(ref<android::view::MotionEvent> event) { return call_method<SCAPIX_META_STRING("onTrackballEvent"), jboolean>(event); }
inline jboolean AbstractInputMethodService::onGenericMotionEvent(ref<android::view::MotionEvent> event) { return call_method<SCAPIX_META_STRING("onGenericMotionEvent"), jboolean>(event); }

} // namespace android::inputmethodservice
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_INPUTMETHODSERVICE_ABSTRACTINPUTMETHODSERVICE_H
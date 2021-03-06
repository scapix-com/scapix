// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_H
#define SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_H

namespace scapix::java_api {

namespace android::graphics { class Rect; }
namespace android::os { class Bundle; }
namespace android::view { class KeyEvent; }
namespace android::view { class MotionEvent; }
namespace android::view::inputmethod { class CompletionInfo; }
namespace android::view::inputmethod { class CursorAnchorInfo; }
namespace android::view::inputmethod { class ExtractedText; }
namespace android::view::inputmethod { class InputMethodSession_EventCallback; }
namespace java::lang { class String; }

namespace android::view::inputmethod {

class InputMethodSession : public object_base<SCAPIX_META_STRING("android/view/inputmethod/InputMethodSession"),
	java::lang::Object>
{
public:

	using EventCallback = InputMethodSession_EventCallback;

	void finishInput();
	void updateSelection(jint p1, jint p2, jint p3, jint p4, jint p5, jint p6);
	void viewClicked(jboolean p1);
	void updateCursor(ref<android::graphics::Rect> p1);
	void displayCompletions(ref<link::java::array<android::view::inputmethod::CompletionInfo>> p1);
	void updateExtractedText(jint p1, ref<android::view::inputmethod::ExtractedText> p2);
	void dispatchKeyEvent(jint p1, ref<android::view::KeyEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3);
	void dispatchTrackballEvent(jint p1, ref<android::view::MotionEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3);
	void dispatchGenericMotionEvent(jint p1, ref<android::view::MotionEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3);
	void appPrivateCommand(ref<java::lang::String> p1, ref<android::os::Bundle> p2);
	void toggleSoftInput(jint p1, jint p2);
	void updateCursorAnchorInfo(ref<android::view::inputmethod::CursorAnchorInfo> p1);

protected:

	InputMethodSession(handle_type h) : base_(h) {}

};

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#include <scapix/java_api/android/graphics/Rect.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/view/KeyEvent.h>
#include <scapix/java_api/android/view/MotionEvent.h>
#include <scapix/java_api/android/view/inputmethod/CompletionInfo.h>
#include <scapix/java_api/android/view/inputmethod/CursorAnchorInfo.h>
#include <scapix/java_api/android/view/inputmethod/ExtractedText.h>
#include <scapix/java_api/android/view/inputmethod/InputMethodSession_EventCallback.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::view::inputmethod {

inline void InputMethodSession::finishInput() { return call_method<SCAPIX_META_STRING("finishInput"), void>(); }
inline void InputMethodSession::updateSelection(jint p1, jint p2, jint p3, jint p4, jint p5, jint p6) { return call_method<SCAPIX_META_STRING("updateSelection"), void>(p1, p2, p3, p4, p5, p6); }
inline void InputMethodSession::viewClicked(jboolean p1) { return call_method<SCAPIX_META_STRING("viewClicked"), void>(p1); }
inline void InputMethodSession::updateCursor(ref<android::graphics::Rect> p1) { return call_method<SCAPIX_META_STRING("updateCursor"), void>(p1); }
inline void InputMethodSession::displayCompletions(ref<link::java::array<android::view::inputmethod::CompletionInfo>> p1) { return call_method<SCAPIX_META_STRING("displayCompletions"), void>(p1); }
inline void InputMethodSession::updateExtractedText(jint p1, ref<android::view::inputmethod::ExtractedText> p2) { return call_method<SCAPIX_META_STRING("updateExtractedText"), void>(p1, p2); }
inline void InputMethodSession::dispatchKeyEvent(jint p1, ref<android::view::KeyEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3) { return call_method<SCAPIX_META_STRING("dispatchKeyEvent"), void>(p1, p2, p3); }
inline void InputMethodSession::dispatchTrackballEvent(jint p1, ref<android::view::MotionEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3) { return call_method<SCAPIX_META_STRING("dispatchTrackballEvent"), void>(p1, p2, p3); }
inline void InputMethodSession::dispatchGenericMotionEvent(jint p1, ref<android::view::MotionEvent> p2, ref<android::view::inputmethod::InputMethodSession_EventCallback> p3) { return call_method<SCAPIX_META_STRING("dispatchGenericMotionEvent"), void>(p1, p2, p3); }
inline void InputMethodSession::appPrivateCommand(ref<java::lang::String> p1, ref<android::os::Bundle> p2) { return call_method<SCAPIX_META_STRING("appPrivateCommand"), void>(p1, p2); }
inline void InputMethodSession::toggleSoftInput(jint p1, jint p2) { return call_method<SCAPIX_META_STRING("toggleSoftInput"), void>(p1, p2); }
inline void InputMethodSession::updateCursorAnchorInfo(ref<android::view::inputmethod::CursorAnchorInfo> p1) { return call_method<SCAPIX_META_STRING("updateCursorAnchorInfo"), void>(p1); }

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSESSION_H

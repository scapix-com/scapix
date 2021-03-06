// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_SPEECH_RECOGNITIONLISTENER_H
#define SCAPIX_ANDROID_SPEECH_RECOGNITIONLISTENER_H

namespace scapix::java_api {

namespace android::os { class Bundle; }

namespace android::speech {

class RecognitionListener : public object_base<SCAPIX_META_STRING("android/speech/RecognitionListener"),
	java::lang::Object>
{
public:

	void onReadyForSpeech(ref<android::os::Bundle> p1);
	void onBeginningOfSpeech();
	void onRmsChanged(jfloat p1);
	void onBufferReceived(ref<link::java::array<jbyte>> p1);
	void onEndOfSpeech();
	void onError(jint p1);
	void onResults(ref<android::os::Bundle> p1);
	void onPartialResults(ref<android::os::Bundle> p1);
	void onEvent(jint p1, ref<android::os::Bundle> p2);

protected:

	RecognitionListener(handle_type h) : base_(h) {}

};

} // namespace android::speech
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Bundle.h>

namespace scapix::java_api {
namespace android::speech {

inline void RecognitionListener::onReadyForSpeech(ref<android::os::Bundle> p1) { return call_method<SCAPIX_META_STRING("onReadyForSpeech"), void>(p1); }
inline void RecognitionListener::onBeginningOfSpeech() { return call_method<SCAPIX_META_STRING("onBeginningOfSpeech"), void>(); }
inline void RecognitionListener::onRmsChanged(jfloat p1) { return call_method<SCAPIX_META_STRING("onRmsChanged"), void>(p1); }
inline void RecognitionListener::onBufferReceived(ref<link::java::array<jbyte>> p1) { return call_method<SCAPIX_META_STRING("onBufferReceived"), void>(p1); }
inline void RecognitionListener::onEndOfSpeech() { return call_method<SCAPIX_META_STRING("onEndOfSpeech"), void>(); }
inline void RecognitionListener::onError(jint p1) { return call_method<SCAPIX_META_STRING("onError"), void>(p1); }
inline void RecognitionListener::onResults(ref<android::os::Bundle> p1) { return call_method<SCAPIX_META_STRING("onResults"), void>(p1); }
inline void RecognitionListener::onPartialResults(ref<android::os::Bundle> p1) { return call_method<SCAPIX_META_STRING("onPartialResults"), void>(p1); }
inline void RecognitionListener::onEvent(jint p1, ref<android::os::Bundle> p2) { return call_method<SCAPIX_META_STRING("onEvent"), void>(p1, p2); }

} // namespace android::speech
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_SPEECH_RECOGNITIONLISTENER_H

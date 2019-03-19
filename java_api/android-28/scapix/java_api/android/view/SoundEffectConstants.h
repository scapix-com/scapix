// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_SOUNDEFFECTCONSTANTS_H
#define SCAPIX_ANDROID_VIEW_SOUNDEFFECTCONSTANTS_H

namespace scapix::java_api {
namespace android::view {

class SoundEffectConstants : public object_base<SCAPIX_META_STRING("android/view/SoundEffectConstants"),
	java::lang::Object>
{
public:

	static jint CLICK_();
	static jint NAVIGATION_DOWN_();
	static jint NAVIGATION_LEFT_();
	static jint NAVIGATION_RIGHT_();
	static jint NAVIGATION_UP_();

	static jint getContantForFocusDirection(jint direction);

protected:

	SoundEffectConstants(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::view {

inline jint SoundEffectConstants::CLICK_() { return get_static_field<SCAPIX_META_STRING("CLICK"), jint>(); }
inline jint SoundEffectConstants::NAVIGATION_DOWN_() { return get_static_field<SCAPIX_META_STRING("NAVIGATION_DOWN"), jint>(); }
inline jint SoundEffectConstants::NAVIGATION_LEFT_() { return get_static_field<SCAPIX_META_STRING("NAVIGATION_LEFT"), jint>(); }
inline jint SoundEffectConstants::NAVIGATION_RIGHT_() { return get_static_field<SCAPIX_META_STRING("NAVIGATION_RIGHT"), jint>(); }
inline jint SoundEffectConstants::NAVIGATION_UP_() { return get_static_field<SCAPIX_META_STRING("NAVIGATION_UP"), jint>(); }
inline jint SoundEffectConstants::getContantForFocusDirection(jint direction) { return call_static_method<SCAPIX_META_STRING("getContantForFocusDirection"), jint>(direction); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_SOUNDEFFECTCONSTANTS_H
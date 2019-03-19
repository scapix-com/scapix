// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOFX_PRESETREVERB_SETTINGS_H
#define SCAPIX_ANDROID_MEDIA_AUDIOFX_PRESETREVERB_SETTINGS_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::media::audiofx {

class PresetReverb_Settings : public object_base<SCAPIX_META_STRING("android/media/audiofx/PresetReverb$Settings"),
	java::lang::Object>
{
public:

	jshort preset();
	void preset(jshort);

	static ref<PresetReverb_Settings> new_object();
	static ref<PresetReverb_Settings> new_object(ref<java::lang::String> settings);
	ref<java::lang::String> toString();

protected:

	PresetReverb_Settings(handle_type h) : base_(h) {}

};

} // namespace android::media::audiofx
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::media::audiofx {

inline jshort PresetReverb_Settings::preset() { return get_field<SCAPIX_META_STRING("preset"), jshort>(); }
inline void PresetReverb_Settings::preset(jshort v) { set_field<SCAPIX_META_STRING("preset"), jshort>(v); }
inline ref<PresetReverb_Settings> PresetReverb_Settings::new_object() { return base_::new_object(); }
inline ref<PresetReverb_Settings> PresetReverb_Settings::new_object(ref<java::lang::String> settings) { return base_::new_object(settings); }
inline ref<java::lang::String> PresetReverb_Settings::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::media::audiofx
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOFX_PRESETREVERB_SETTINGS_H
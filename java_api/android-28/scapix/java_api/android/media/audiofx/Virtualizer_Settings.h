// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOFX_VIRTUALIZER_SETTINGS_H
#define SCAPIX_ANDROID_MEDIA_AUDIOFX_VIRTUALIZER_SETTINGS_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::media::audiofx {

class Virtualizer_Settings : public object_base<SCAPIX_META_STRING("android/media/audiofx/Virtualizer$Settings"),
	java::lang::Object>
{
public:

	jshort strength();
	void strength(jshort);

	static ref<Virtualizer_Settings> new_object();
	static ref<Virtualizer_Settings> new_object(ref<java::lang::String> settings);
	ref<java::lang::String> toString();

protected:

	Virtualizer_Settings(handle_type h) : base_(h) {}

};

} // namespace android::media::audiofx
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::media::audiofx {

inline jshort Virtualizer_Settings::strength() { return get_field<SCAPIX_META_STRING("strength"), jshort>(); }
inline void Virtualizer_Settings::strength(jshort v) { set_field<SCAPIX_META_STRING("strength"), jshort>(v); }
inline ref<Virtualizer_Settings> Virtualizer_Settings::new_object() { return base_::new_object(); }
inline ref<Virtualizer_Settings> Virtualizer_Settings::new_object(ref<java::lang::String> settings) { return base_::new_object(settings); }
inline ref<java::lang::String> Virtualizer_Settings::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::media::audiofx
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOFX_VIRTUALIZER_SETTINGS_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOFX_AUDIOEFFECT_H
#define SCAPIX_ANDROID_MEDIA_AUDIOFX_AUDIOEFFECT_H

namespace scapix::java_api {

namespace android::media::audiofx { class AudioEffect_Descriptor; }
namespace android::media::audiofx { class AudioEffect_OnControlStatusChangeListener; }
namespace android::media::audiofx { class AudioEffect_OnEnableStatusChangeListener; }
namespace java::lang { class String; }
namespace java::util { class UUID; }

namespace android::media::audiofx {

class AudioEffect : public object_base<SCAPIX_META_STRING("android/media/audiofx/AudioEffect"),
	java::lang::Object>
{
public:

	using OnEnableStatusChangeListener = AudioEffect_OnEnableStatusChangeListener;
	using OnControlStatusChangeListener = AudioEffect_OnControlStatusChangeListener;
	using Descriptor = AudioEffect_Descriptor;

	static ref<java::lang::String> ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION_();
	static ref<java::lang::String> ACTION_DISPLAY_AUDIO_EFFECT_CONTROL_PANEL_();
	static ref<java::lang::String> ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION_();
	static jint ALREADY_EXISTS_();
	static jint CONTENT_TYPE_GAME_();
	static jint CONTENT_TYPE_MOVIE_();
	static jint CONTENT_TYPE_MUSIC_();
	static jint CONTENT_TYPE_VOICE_();
	static ref<java::lang::String> EFFECT_AUXILIARY_();
	static ref<java::lang::String> EFFECT_INSERT_();
	static ref<java::util::UUID> EFFECT_TYPE_AEC_();
	static ref<java::util::UUID> EFFECT_TYPE_AGC_();
	static ref<java::util::UUID> EFFECT_TYPE_BASS_BOOST_();
	static ref<java::util::UUID> EFFECT_TYPE_DYNAMICS_PROCESSING_();
	static ref<java::util::UUID> EFFECT_TYPE_ENV_REVERB_();
	static ref<java::util::UUID> EFFECT_TYPE_EQUALIZER_();
	static ref<java::util::UUID> EFFECT_TYPE_LOUDNESS_ENHANCER_();
	static ref<java::util::UUID> EFFECT_TYPE_NS_();
	static ref<java::util::UUID> EFFECT_TYPE_PRESET_REVERB_();
	static ref<java::util::UUID> EFFECT_TYPE_VIRTUALIZER_();
	static jint ERROR_();
	static jint ERROR_BAD_VALUE_();
	static jint ERROR_DEAD_OBJECT_();
	static jint ERROR_INVALID_OPERATION_();
	static jint ERROR_NO_INIT_();
	static jint ERROR_NO_MEMORY_();
	static ref<java::lang::String> EXTRA_AUDIO_SESSION_();
	static ref<java::lang::String> EXTRA_CONTENT_TYPE_();
	static ref<java::lang::String> EXTRA_PACKAGE_NAME_();
	static jint SUCCESS_();

	void release();
	ref<android::media::audiofx::AudioEffect_Descriptor> getDescriptor();
	static ref<link::java::array<android::media::audiofx::AudioEffect_Descriptor>> queryEffects();
	jint setEnabled(jboolean enabled);
	jint getId();
	jboolean getEnabled();
	jboolean hasControl();
	void setEnableStatusListener(ref<android::media::audiofx::AudioEffect_OnEnableStatusChangeListener> listener);
	void setControlStatusListener(ref<android::media::audiofx::AudioEffect_OnControlStatusChangeListener> listener);

protected:

	AudioEffect(handle_type h) : base_(h) {}

};

} // namespace android::media::audiofx
} // namespace scapix::java_api

#include <scapix/java_api/android/media/audiofx/AudioEffect_Descriptor.h>
#include <scapix/java_api/android/media/audiofx/AudioEffect_OnControlStatusChangeListener.h>
#include <scapix/java_api/android/media/audiofx/AudioEffect_OnEnableStatusChangeListener.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/UUID.h>

namespace scapix::java_api {
namespace android::media::audiofx {

inline ref<java::lang::String> AudioEffect::ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION_() { return get_static_field<SCAPIX_META_STRING("ACTION_CLOSE_AUDIO_EFFECT_CONTROL_SESSION"), ref<java::lang::String>>(); }
inline ref<java::lang::String> AudioEffect::ACTION_DISPLAY_AUDIO_EFFECT_CONTROL_PANEL_() { return get_static_field<SCAPIX_META_STRING("ACTION_DISPLAY_AUDIO_EFFECT_CONTROL_PANEL"), ref<java::lang::String>>(); }
inline ref<java::lang::String> AudioEffect::ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION_() { return get_static_field<SCAPIX_META_STRING("ACTION_OPEN_AUDIO_EFFECT_CONTROL_SESSION"), ref<java::lang::String>>(); }
inline jint AudioEffect::ALREADY_EXISTS_() { return get_static_field<SCAPIX_META_STRING("ALREADY_EXISTS"), jint>(); }
inline jint AudioEffect::CONTENT_TYPE_GAME_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE_GAME"), jint>(); }
inline jint AudioEffect::CONTENT_TYPE_MOVIE_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE_MOVIE"), jint>(); }
inline jint AudioEffect::CONTENT_TYPE_MUSIC_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE_MUSIC"), jint>(); }
inline jint AudioEffect::CONTENT_TYPE_VOICE_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE_VOICE"), jint>(); }
inline ref<java::lang::String> AudioEffect::EFFECT_AUXILIARY_() { return get_static_field<SCAPIX_META_STRING("EFFECT_AUXILIARY"), ref<java::lang::String>>(); }
inline ref<java::lang::String> AudioEffect::EFFECT_INSERT_() { return get_static_field<SCAPIX_META_STRING("EFFECT_INSERT"), ref<java::lang::String>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_AEC_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_AEC"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_AGC_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_AGC"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_BASS_BOOST_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_BASS_BOOST"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_DYNAMICS_PROCESSING_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_DYNAMICS_PROCESSING"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_ENV_REVERB_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_ENV_REVERB"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_EQUALIZER_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_EQUALIZER"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_LOUDNESS_ENHANCER_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_LOUDNESS_ENHANCER"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_NS_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_NS"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_PRESET_REVERB_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_PRESET_REVERB"), ref<java::util::UUID>>(); }
inline ref<java::util::UUID> AudioEffect::EFFECT_TYPE_VIRTUALIZER_() { return get_static_field<SCAPIX_META_STRING("EFFECT_TYPE_VIRTUALIZER"), ref<java::util::UUID>>(); }
inline jint AudioEffect::ERROR_() { return get_static_field<SCAPIX_META_STRING("ERROR"), jint>(); }
inline jint AudioEffect::ERROR_BAD_VALUE_() { return get_static_field<SCAPIX_META_STRING("ERROR_BAD_VALUE"), jint>(); }
inline jint AudioEffect::ERROR_DEAD_OBJECT_() { return get_static_field<SCAPIX_META_STRING("ERROR_DEAD_OBJECT"), jint>(); }
inline jint AudioEffect::ERROR_INVALID_OPERATION_() { return get_static_field<SCAPIX_META_STRING("ERROR_INVALID_OPERATION"), jint>(); }
inline jint AudioEffect::ERROR_NO_INIT_() { return get_static_field<SCAPIX_META_STRING("ERROR_NO_INIT"), jint>(); }
inline jint AudioEffect::ERROR_NO_MEMORY_() { return get_static_field<SCAPIX_META_STRING("ERROR_NO_MEMORY"), jint>(); }
inline ref<java::lang::String> AudioEffect::EXTRA_AUDIO_SESSION_() { return get_static_field<SCAPIX_META_STRING("EXTRA_AUDIO_SESSION"), ref<java::lang::String>>(); }
inline ref<java::lang::String> AudioEffect::EXTRA_CONTENT_TYPE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_CONTENT_TYPE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> AudioEffect::EXTRA_PACKAGE_NAME_() { return get_static_field<SCAPIX_META_STRING("EXTRA_PACKAGE_NAME"), ref<java::lang::String>>(); }
inline jint AudioEffect::SUCCESS_() { return get_static_field<SCAPIX_META_STRING("SUCCESS"), jint>(); }
inline void AudioEffect::release() { return call_method<SCAPIX_META_STRING("release"), void>(); }
inline ref<android::media::audiofx::AudioEffect_Descriptor> AudioEffect::getDescriptor() { return call_method<SCAPIX_META_STRING("getDescriptor"), ref<android::media::audiofx::AudioEffect_Descriptor>>(); }
inline ref<link::java::array<android::media::audiofx::AudioEffect_Descriptor>> AudioEffect::queryEffects() { return call_static_method<SCAPIX_META_STRING("queryEffects"), ref<link::java::array<android::media::audiofx::AudioEffect_Descriptor>>>(); }
inline jint AudioEffect::setEnabled(jboolean enabled) { return call_method<SCAPIX_META_STRING("setEnabled"), jint>(enabled); }
inline jint AudioEffect::getId() { return call_method<SCAPIX_META_STRING("getId"), jint>(); }
inline jboolean AudioEffect::getEnabled() { return call_method<SCAPIX_META_STRING("getEnabled"), jboolean>(); }
inline jboolean AudioEffect::hasControl() { return call_method<SCAPIX_META_STRING("hasControl"), jboolean>(); }
inline void AudioEffect::setEnableStatusListener(ref<android::media::audiofx::AudioEffect_OnEnableStatusChangeListener> listener) { return call_method<SCAPIX_META_STRING("setEnableStatusListener"), void>(listener); }
inline void AudioEffect::setControlStatusListener(ref<android::media::audiofx::AudioEffect_OnControlStatusChangeListener> listener) { return call_method<SCAPIX_META_STRING("setControlStatusListener"), void>(listener); }

} // namespace android::media::audiofx
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOFX_AUDIOEFFECT_H
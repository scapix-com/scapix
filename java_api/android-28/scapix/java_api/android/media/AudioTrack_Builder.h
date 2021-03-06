// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOTRACK_BUILDER_H
#define SCAPIX_ANDROID_MEDIA_AUDIOTRACK_BUILDER_H

namespace scapix::java_api {

namespace android::media { class AudioAttributes; }
namespace android::media { class AudioFormat; }
namespace android::media { class AudioTrack; }

namespace android::media {

class AudioTrack_Builder : public object_base<SCAPIX_META_STRING("android/media/AudioTrack$Builder"),
	java::lang::Object>
{
public:

	static ref<AudioTrack_Builder> new_object();
	ref<android::media::AudioTrack_Builder> setAudioAttributes(ref<android::media::AudioAttributes> attributes);
	ref<android::media::AudioTrack_Builder> setAudioFormat(ref<android::media::AudioFormat> format);
	ref<android::media::AudioTrack_Builder> setBufferSizeInBytes(jint bufferSizeInBytes);
	ref<android::media::AudioTrack_Builder> setTransferMode(jint mode);
	ref<android::media::AudioTrack_Builder> setSessionId(jint sessionId);
	ref<android::media::AudioTrack_Builder> setPerformanceMode(jint performanceMode);
	ref<android::media::AudioTrack> build();

protected:

	AudioTrack_Builder(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/AudioAttributes.h>
#include <scapix/java_api/android/media/AudioFormat.h>
#include <scapix/java_api/android/media/AudioTrack.h>

namespace scapix::java_api {
namespace android::media {

inline ref<AudioTrack_Builder> AudioTrack_Builder::new_object() { return base_::new_object(); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setAudioAttributes(ref<android::media::AudioAttributes> attributes) { return call_method<SCAPIX_META_STRING("setAudioAttributes"), ref<android::media::AudioTrack_Builder>>(attributes); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setAudioFormat(ref<android::media::AudioFormat> format) { return call_method<SCAPIX_META_STRING("setAudioFormat"), ref<android::media::AudioTrack_Builder>>(format); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setBufferSizeInBytes(jint bufferSizeInBytes) { return call_method<SCAPIX_META_STRING("setBufferSizeInBytes"), ref<android::media::AudioTrack_Builder>>(bufferSizeInBytes); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setTransferMode(jint mode) { return call_method<SCAPIX_META_STRING("setTransferMode"), ref<android::media::AudioTrack_Builder>>(mode); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setSessionId(jint sessionId) { return call_method<SCAPIX_META_STRING("setSessionId"), ref<android::media::AudioTrack_Builder>>(sessionId); }
inline ref<android::media::AudioTrack_Builder> AudioTrack_Builder::setPerformanceMode(jint performanceMode) { return call_method<SCAPIX_META_STRING("setPerformanceMode"), ref<android::media::AudioTrack_Builder>>(performanceMode); }
inline ref<android::media::AudioTrack> AudioTrack_Builder::build() { return call_method<SCAPIX_META_STRING("build"), ref<android::media::AudioTrack>>(); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOTRACK_BUILDER_H

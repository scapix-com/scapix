// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOFORMAT_BUILDER_H
#define SCAPIX_ANDROID_MEDIA_AUDIOFORMAT_BUILDER_H

namespace scapix::java_api {

namespace android::media { class AudioFormat; }

namespace android::media {

class AudioFormat_Builder : public object_base<SCAPIX_META_STRING("android/media/AudioFormat$Builder"),
	java::lang::Object>
{
public:

	static ref<AudioFormat_Builder> new_object();
	static ref<AudioFormat_Builder> new_object(ref<android::media::AudioFormat> af);
	ref<android::media::AudioFormat> build();
	ref<android::media::AudioFormat_Builder> setEncoding(jint encoding);
	ref<android::media::AudioFormat_Builder> setChannelMask(jint channelMask);
	ref<android::media::AudioFormat_Builder> setChannelIndexMask(jint channelIndexMask);
	ref<android::media::AudioFormat_Builder> setSampleRate(jint sampleRate);

protected:

	AudioFormat_Builder(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/AudioFormat.h>

namespace scapix::java_api {
namespace android::media {

inline ref<AudioFormat_Builder> AudioFormat_Builder::new_object() { return base_::new_object(); }
inline ref<AudioFormat_Builder> AudioFormat_Builder::new_object(ref<android::media::AudioFormat> af) { return base_::new_object(af); }
inline ref<android::media::AudioFormat> AudioFormat_Builder::build() { return call_method<SCAPIX_META_STRING("build"), ref<android::media::AudioFormat>>(); }
inline ref<android::media::AudioFormat_Builder> AudioFormat_Builder::setEncoding(jint encoding) { return call_method<SCAPIX_META_STRING("setEncoding"), ref<android::media::AudioFormat_Builder>>(encoding); }
inline ref<android::media::AudioFormat_Builder> AudioFormat_Builder::setChannelMask(jint channelMask) { return call_method<SCAPIX_META_STRING("setChannelMask"), ref<android::media::AudioFormat_Builder>>(channelMask); }
inline ref<android::media::AudioFormat_Builder> AudioFormat_Builder::setChannelIndexMask(jint channelIndexMask) { return call_method<SCAPIX_META_STRING("setChannelIndexMask"), ref<android::media::AudioFormat_Builder>>(channelIndexMask); }
inline ref<android::media::AudioFormat_Builder> AudioFormat_Builder::setSampleRate(jint sampleRate) { return call_method<SCAPIX_META_STRING("setSampleRate"), ref<android::media::AudioFormat_Builder>>(sampleRate); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOFORMAT_BUILDER_H
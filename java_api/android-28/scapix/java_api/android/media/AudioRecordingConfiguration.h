// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIORECORDINGCONFIGURATION_H
#define SCAPIX_ANDROID_MEDIA_AUDIORECORDINGCONFIGURATION_H

namespace scapix::java_api {

namespace android::media { class AudioDeviceInfo; }
namespace android::media { class AudioFormat; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }

namespace android::media {

class AudioRecordingConfiguration : public object_base<SCAPIX_META_STRING("android/media/AudioRecordingConfiguration"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	jint getClientAudioSource();
	jint getClientAudioSessionId();
	ref<android::media::AudioFormat> getFormat();
	ref<android::media::AudioFormat> getClientFormat();
	ref<android::media::AudioDeviceInfo> getAudioDevice();
	jint hashCode();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jboolean equals(ref<java::lang::Object> o);

protected:

	AudioRecordingConfiguration(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/AudioDeviceInfo.h>
#include <scapix/java_api/android/media/AudioFormat.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>

namespace scapix::java_api {
namespace android::media {

inline ref<android::os::Parcelable_Creator> AudioRecordingConfiguration::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint AudioRecordingConfiguration::getClientAudioSource() { return call_method<SCAPIX_META_STRING("getClientAudioSource"), jint>(); }
inline jint AudioRecordingConfiguration::getClientAudioSessionId() { return call_method<SCAPIX_META_STRING("getClientAudioSessionId"), jint>(); }
inline ref<android::media::AudioFormat> AudioRecordingConfiguration::getFormat() { return call_method<SCAPIX_META_STRING("getFormat"), ref<android::media::AudioFormat>>(); }
inline ref<android::media::AudioFormat> AudioRecordingConfiguration::getClientFormat() { return call_method<SCAPIX_META_STRING("getClientFormat"), ref<android::media::AudioFormat>>(); }
inline ref<android::media::AudioDeviceInfo> AudioRecordingConfiguration::getAudioDevice() { return call_method<SCAPIX_META_STRING("getAudioDevice"), ref<android::media::AudioDeviceInfo>>(); }
inline jint AudioRecordingConfiguration::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jint AudioRecordingConfiguration::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void AudioRecordingConfiguration::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jboolean AudioRecordingConfiguration::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIORECORDINGCONFIGURATION_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOROUTING_H
#define SCAPIX_ANDROID_MEDIA_AUDIOROUTING_H

namespace scapix::java_api {

namespace android::media { class AudioDeviceInfo; }
namespace android::media { class AudioRouting_OnRoutingChangedListener; }
namespace android::os { class Handler; }

namespace android::media {

class AudioRouting : public object_base<SCAPIX_META_STRING("android/media/AudioRouting"),
	java::lang::Object>
{
public:

	using OnRoutingChangedListener = AudioRouting_OnRoutingChangedListener;

	jboolean setPreferredDevice(ref<android::media::AudioDeviceInfo> p1);
	ref<android::media::AudioDeviceInfo> getPreferredDevice();
	ref<android::media::AudioDeviceInfo> getRoutedDevice();
	void addOnRoutingChangedListener(ref<android::media::AudioRouting_OnRoutingChangedListener> p1, ref<android::os::Handler> p2);
	void removeOnRoutingChangedListener(ref<android::media::AudioRouting_OnRoutingChangedListener> p1);

protected:

	AudioRouting(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/AudioDeviceInfo.h>
#include <scapix/java_api/android/media/AudioRouting_OnRoutingChangedListener.h>
#include <scapix/java_api/android/os/Handler.h>

namespace scapix::java_api {
namespace android::media {

inline jboolean AudioRouting::setPreferredDevice(ref<android::media::AudioDeviceInfo> p1) { return call_method<SCAPIX_META_STRING("setPreferredDevice"), jboolean>(p1); }
inline ref<android::media::AudioDeviceInfo> AudioRouting::getPreferredDevice() { return call_method<SCAPIX_META_STRING("getPreferredDevice"), ref<android::media::AudioDeviceInfo>>(); }
inline ref<android::media::AudioDeviceInfo> AudioRouting::getRoutedDevice() { return call_method<SCAPIX_META_STRING("getRoutedDevice"), ref<android::media::AudioDeviceInfo>>(); }
inline void AudioRouting::addOnRoutingChangedListener(ref<android::media::AudioRouting_OnRoutingChangedListener> p1, ref<android::os::Handler> p2) { return call_method<SCAPIX_META_STRING("addOnRoutingChangedListener"), void>(p1, p2); }
inline void AudioRouting::removeOnRoutingChangedListener(ref<android::media::AudioRouting_OnRoutingChangedListener> p1) { return call_method<SCAPIX_META_STRING("removeOnRoutingChangedListener"), void>(p1); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOROUTING_H
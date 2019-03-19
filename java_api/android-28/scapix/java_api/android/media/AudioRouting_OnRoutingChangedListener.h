// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOROUTING_ONROUTINGCHANGEDLISTENER_H
#define SCAPIX_ANDROID_MEDIA_AUDIOROUTING_ONROUTINGCHANGEDLISTENER_H

namespace scapix::java_api {

namespace android::media { class AudioRouting; }

namespace android::media {

class AudioRouting_OnRoutingChangedListener : public object_base<SCAPIX_META_STRING("android/media/AudioRouting$OnRoutingChangedListener"),
	java::lang::Object>
{
public:

	void onRoutingChanged(ref<android::media::AudioRouting> p1);

protected:

	AudioRouting_OnRoutingChangedListener(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/AudioRouting.h>

namespace scapix::java_api {
namespace android::media {

inline void AudioRouting_OnRoutingChangedListener::onRoutingChanged(ref<android::media::AudioRouting> p1) { return call_method<SCAPIX_META_STRING("onRoutingChanged"), void>(p1); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOROUTING_ONROUTINGCHANGEDLISTENER_H
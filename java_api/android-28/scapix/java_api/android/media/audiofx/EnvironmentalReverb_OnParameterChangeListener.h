// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_AUDIOFX_ENVIRONMENTALREVERB_ONPARAMETERCHANGELISTENER_H
#define SCAPIX_ANDROID_MEDIA_AUDIOFX_ENVIRONMENTALREVERB_ONPARAMETERCHANGELISTENER_H

namespace scapix::java_api {

namespace android::media::audiofx { class EnvironmentalReverb; }

namespace android::media::audiofx {

class EnvironmentalReverb_OnParameterChangeListener : public object_base<SCAPIX_META_STRING("android/media/audiofx/EnvironmentalReverb$OnParameterChangeListener"),
	java::lang::Object>
{
public:

	void onParameterChange(ref<android::media::audiofx::EnvironmentalReverb> p1, jint p2, jint p3, jint p4);

protected:

	EnvironmentalReverb_OnParameterChangeListener(handle_type h) : base_(h) {}

};

} // namespace android::media::audiofx
} // namespace scapix::java_api

#include <scapix/java_api/android/media/audiofx/EnvironmentalReverb.h>

namespace scapix::java_api {
namespace android::media::audiofx {

inline void EnvironmentalReverb_OnParameterChangeListener::onParameterChange(ref<android::media::audiofx::EnvironmentalReverb> p1, jint p2, jint p3, jint p4) { return call_method<SCAPIX_META_STRING("onParameterChange"), void>(p1, p2, p3, p4); }

} // namespace android::media::audiofx
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_AUDIOFX_ENVIRONMENTALREVERB_ONPARAMETERCHANGELISTENER_H
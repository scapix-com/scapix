// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_OS_RECOVERYSYSTEM_PROGRESSLISTENER_H
#define SCAPIX_ANDROID_OS_RECOVERYSYSTEM_PROGRESSLISTENER_H

namespace scapix::java_api {


namespace android::os {

class RecoverySystem_ProgressListener : public object_base<SCAPIX_META_STRING("android/os/RecoverySystem$ProgressListener"),
	java::lang::Object>
{
public:

	void onProgress(jint p1);

protected:

	RecoverySystem_ProgressListener(handle_type h) : base_(h) {}

};

} // namespace android::os
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::os {

inline void RecoverySystem_ProgressListener::onProgress(jint p1) { return call_method<SCAPIX_META_STRING("onProgress"), void>(p1); }

} // namespace android::os
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_RECOVERYSYSTEM_PROGRESSLISTENER_H
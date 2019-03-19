// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/Runnable.h>

#ifndef SCAPIX_ANDROID_RENDERSCRIPT_RENDERSCRIPT_RSERRORHANDLER_H
#define SCAPIX_ANDROID_RENDERSCRIPT_RENDERSCRIPT_RSERRORHANDLER_H

namespace scapix::java_api {


namespace android::renderscript {

class RenderScript_RSErrorHandler : public object_base<SCAPIX_META_STRING("android/renderscript/RenderScript$RSErrorHandler"),
	java::lang::Object,
	java::lang::Runnable>
{
public:

	static ref<RenderScript_RSErrorHandler> new_object();
	void run();

protected:

	RenderScript_RSErrorHandler(handle_type h) : base_(h) {}

};

} // namespace android::renderscript
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::renderscript {

inline ref<RenderScript_RSErrorHandler> RenderScript_RSErrorHandler::new_object() { return base_::new_object(); }
inline void RenderScript_RSErrorHandler::run() { return call_method<SCAPIX_META_STRING("run"), void>(); }

} // namespace android::renderscript
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_RENDERSCRIPT_RENDERSCRIPT_RSERRORHANDLER_H
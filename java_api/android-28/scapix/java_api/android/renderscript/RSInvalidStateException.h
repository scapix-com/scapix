// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/renderscript/RSRuntimeException.h>

#ifndef SCAPIX_ANDROID_RENDERSCRIPT_RSINVALIDSTATEEXCEPTION_H
#define SCAPIX_ANDROID_RENDERSCRIPT_RSINVALIDSTATEEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::renderscript {

class RSInvalidStateException : public object_base<SCAPIX_META_STRING("android/renderscript/RSInvalidStateException"),
	android::renderscript::RSRuntimeException>
{
public:

	static ref<RSInvalidStateException> new_object(ref<java::lang::String> string);

protected:

	RSInvalidStateException(handle_type h) : base_(h) {}

};

} // namespace android::renderscript
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::renderscript {

inline ref<RSInvalidStateException> RSInvalidStateException::new_object(ref<java::lang::String> string) { return base_::new_object(string); }

} // namespace android::renderscript
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_RENDERSCRIPT_RSINVALIDSTATEEXCEPTION_H
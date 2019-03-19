// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/text/method/ReplacementTransformationMethod.h>

#ifndef SCAPIX_ANDROID_TEXT_METHOD_SINGLELINETRANSFORMATIONMETHOD_H
#define SCAPIX_ANDROID_TEXT_METHOD_SINGLELINETRANSFORMATIONMETHOD_H

namespace scapix::java_api {
namespace android::text::method {

class SingleLineTransformationMethod : public object_base<SCAPIX_META_STRING("android/text/method/SingleLineTransformationMethod"),
	android::text::method::ReplacementTransformationMethod>
{
public:

	static ref<SingleLineTransformationMethod> new_object();
	static ref<android::text::method::SingleLineTransformationMethod> getInstance();

protected:

	SingleLineTransformationMethod(handle_type h) : base_(h) {}

};

} // namespace android::text::method
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::text::method {

inline ref<SingleLineTransformationMethod> SingleLineTransformationMethod::new_object() { return base_::new_object(); }
inline ref<android::text::method::SingleLineTransformationMethod> SingleLineTransformationMethod::getInstance() { return call_static_method<SCAPIX_META_STRING("getInstance"), ref<android::text::method::SingleLineTransformationMethod>>(); }

} // namespace android::text::method
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TEXT_METHOD_SINGLELINETRANSFORMATIONMETHOD_H
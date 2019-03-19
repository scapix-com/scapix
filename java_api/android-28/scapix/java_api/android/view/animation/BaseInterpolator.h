// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/view/animation/Interpolator.h>

#ifndef SCAPIX_ANDROID_VIEW_ANIMATION_BASEINTERPOLATOR_H
#define SCAPIX_ANDROID_VIEW_ANIMATION_BASEINTERPOLATOR_H

namespace scapix::java_api {
namespace android::view::animation {

class BaseInterpolator : public object_base<SCAPIX_META_STRING("android/view/animation/BaseInterpolator"),
	java::lang::Object,
	android::view::animation::Interpolator>
{
public:

	static ref<BaseInterpolator> new_object();

protected:

	BaseInterpolator(handle_type h) : base_(h) {}

};

} // namespace android::view::animation
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::view::animation {

inline ref<BaseInterpolator> BaseInterpolator::new_object() { return base_::new_object(); }

} // namespace android::view::animation
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_ANIMATION_BASEINTERPOLATOR_H
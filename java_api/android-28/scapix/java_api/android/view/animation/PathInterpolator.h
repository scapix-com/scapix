// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/view/animation/BaseInterpolator.h>

#ifndef SCAPIX_ANDROID_VIEW_ANIMATION_PATHINTERPOLATOR_H
#define SCAPIX_ANDROID_VIEW_ANIMATION_PATHINTERPOLATOR_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::graphics { class Path; }
namespace android::util { class AttributeSet; }

namespace android::view::animation {

class PathInterpolator : public object_base<SCAPIX_META_STRING("android/view/animation/PathInterpolator"),
	android::view::animation::BaseInterpolator>
{
public:

	static ref<PathInterpolator> new_object(ref<android::graphics::Path> path);
	static ref<PathInterpolator> new_object(jfloat controlX, jfloat controlY);
	static ref<PathInterpolator> new_object(jfloat controlX1, jfloat controlY1, jfloat controlX2, jfloat controlY2);
	static ref<PathInterpolator> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs);
	jfloat getInterpolation(jfloat t);

protected:

	PathInterpolator(handle_type h) : base_(h) {}

};

} // namespace android::view::animation
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/graphics/Path.h>
#include <scapix/java_api/android/util/AttributeSet.h>

namespace scapix::java_api {
namespace android::view::animation {

inline ref<PathInterpolator> PathInterpolator::new_object(ref<android::graphics::Path> path) { return base_::new_object(path); }
inline ref<PathInterpolator> PathInterpolator::new_object(jfloat controlX, jfloat controlY) { return base_::new_object(controlX, controlY); }
inline ref<PathInterpolator> PathInterpolator::new_object(jfloat controlX1, jfloat controlY1, jfloat controlX2, jfloat controlY2) { return base_::new_object(controlX1, controlY1, controlX2, controlY2); }
inline ref<PathInterpolator> PathInterpolator::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs) { return base_::new_object(context, attrs); }
inline jfloat PathInterpolator::getInterpolation(jfloat t) { return call_method<SCAPIX_META_STRING("getInterpolation"), jfloat>(t); }

} // namespace android::view::animation
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_ANIMATION_PATHINTERPOLATOR_H

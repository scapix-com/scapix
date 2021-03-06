// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/transition/Transition.h>

#ifndef SCAPIX_ANDROID_TRANSITION_CHANGESCROLL_H
#define SCAPIX_ANDROID_TRANSITION_CHANGESCROLL_H

namespace scapix::java_api {

namespace android::animation { class Animator; }
namespace android::content { class Context; }
namespace android::transition { class TransitionValues; }
namespace android::util { class AttributeSet; }
namespace android::view { class ViewGroup; }
namespace java::lang { class String; }

namespace android::transition {

class ChangeScroll : public object_base<SCAPIX_META_STRING("android/transition/ChangeScroll"),
	android::transition::Transition>
{
public:

	static ref<ChangeScroll> new_object();
	static ref<ChangeScroll> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs);
	void captureStartValues(ref<android::transition::TransitionValues> transitionValues);
	void captureEndValues(ref<android::transition::TransitionValues> transitionValues);
	ref<link::java::array<java::lang::String>> getTransitionProperties();
	ref<android::animation::Animator> createAnimator(ref<android::view::ViewGroup> sceneRoot, ref<android::transition::TransitionValues> startValues, ref<android::transition::TransitionValues> endValues);

protected:

	ChangeScroll(handle_type h) : base_(h) {}

};

} // namespace android::transition
} // namespace scapix::java_api

#include <scapix/java_api/android/animation/Animator.h>
#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/transition/TransitionValues.h>
#include <scapix/java_api/android/util/AttributeSet.h>
#include <scapix/java_api/android/view/ViewGroup.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::transition {

inline ref<ChangeScroll> ChangeScroll::new_object() { return base_::new_object(); }
inline ref<ChangeScroll> ChangeScroll::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs) { return base_::new_object(context, attrs); }
inline void ChangeScroll::captureStartValues(ref<android::transition::TransitionValues> transitionValues) { return call_method<SCAPIX_META_STRING("captureStartValues"), void>(transitionValues); }
inline void ChangeScroll::captureEndValues(ref<android::transition::TransitionValues> transitionValues) { return call_method<SCAPIX_META_STRING("captureEndValues"), void>(transitionValues); }
inline ref<link::java::array<java::lang::String>> ChangeScroll::getTransitionProperties() { return call_method<SCAPIX_META_STRING("getTransitionProperties"), ref<link::java::array<java::lang::String>>>(); }
inline ref<android::animation::Animator> ChangeScroll::createAnimator(ref<android::view::ViewGroup> sceneRoot, ref<android::transition::TransitionValues> startValues, ref<android::transition::TransitionValues> endValues) { return call_method<SCAPIX_META_STRING("createAnimator"), ref<android::animation::Animator>>(sceneRoot, startValues, endValues); }

} // namespace android::transition
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TRANSITION_CHANGESCROLL_H

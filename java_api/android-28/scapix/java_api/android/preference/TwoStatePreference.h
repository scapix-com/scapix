// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/preference/Preference.h>

#ifndef SCAPIX_ANDROID_PREFERENCE_TWOSTATEPREFERENCE_H
#define SCAPIX_ANDROID_PREFERENCE_TWOSTATEPREFERENCE_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::util { class AttributeSet; }
namespace java::lang { class CharSequence; }

namespace android::preference {

class TwoStatePreference : public object_base<SCAPIX_META_STRING("android/preference/TwoStatePreference"),
	android::preference::Preference>
{
public:

	static ref<TwoStatePreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr, jint defStyleRes);
	static ref<TwoStatePreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr);
	static ref<TwoStatePreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs);
	static ref<TwoStatePreference> new_object(ref<android::content::Context> context);
	void setChecked(jboolean checked);
	jboolean isChecked();
	jboolean shouldDisableDependents();
	void setSummaryOn(ref<java::lang::CharSequence> summary);
	void setSummaryOn(jint summaryResId);
	ref<java::lang::CharSequence> getSummaryOn();
	void setSummaryOff(ref<java::lang::CharSequence> summary);
	void setSummaryOff(jint summaryResId);
	ref<java::lang::CharSequence> getSummaryOff();
	jboolean getDisableDependentsState();
	void setDisableDependentsState(jboolean disableDependentsState);

protected:

	TwoStatePreference(handle_type h) : base_(h) {}

};

} // namespace android::preference
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/util/AttributeSet.h>
#include <scapix/java_api/java/lang/CharSequence.h>

namespace scapix::java_api {
namespace android::preference {

inline ref<TwoStatePreference> TwoStatePreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr, jint defStyleRes) { return base_::new_object(context, attrs, defStyleAttr, defStyleRes); }
inline ref<TwoStatePreference> TwoStatePreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr) { return base_::new_object(context, attrs, defStyleAttr); }
inline ref<TwoStatePreference> TwoStatePreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs) { return base_::new_object(context, attrs); }
inline ref<TwoStatePreference> TwoStatePreference::new_object(ref<android::content::Context> context) { return base_::new_object(context); }
inline void TwoStatePreference::setChecked(jboolean checked) { return call_method<SCAPIX_META_STRING("setChecked"), void>(checked); }
inline jboolean TwoStatePreference::isChecked() { return call_method<SCAPIX_META_STRING("isChecked"), jboolean>(); }
inline jboolean TwoStatePreference::shouldDisableDependents() { return call_method<SCAPIX_META_STRING("shouldDisableDependents"), jboolean>(); }
inline void TwoStatePreference::setSummaryOn(ref<java::lang::CharSequence> summary) { return call_method<SCAPIX_META_STRING("setSummaryOn"), void>(summary); }
inline void TwoStatePreference::setSummaryOn(jint summaryResId) { return call_method<SCAPIX_META_STRING("setSummaryOn"), void>(summaryResId); }
inline ref<java::lang::CharSequence> TwoStatePreference::getSummaryOn() { return call_method<SCAPIX_META_STRING("getSummaryOn"), ref<java::lang::CharSequence>>(); }
inline void TwoStatePreference::setSummaryOff(ref<java::lang::CharSequence> summary) { return call_method<SCAPIX_META_STRING("setSummaryOff"), void>(summary); }
inline void TwoStatePreference::setSummaryOff(jint summaryResId) { return call_method<SCAPIX_META_STRING("setSummaryOff"), void>(summaryResId); }
inline ref<java::lang::CharSequence> TwoStatePreference::getSummaryOff() { return call_method<SCAPIX_META_STRING("getSummaryOff"), ref<java::lang::CharSequence>>(); }
inline jboolean TwoStatePreference::getDisableDependentsState() { return call_method<SCAPIX_META_STRING("getDisableDependentsState"), jboolean>(); }
inline void TwoStatePreference::setDisableDependentsState(jboolean disableDependentsState) { return call_method<SCAPIX_META_STRING("setDisableDependentsState"), void>(disableDependentsState); }

} // namespace android::preference
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PREFERENCE_TWOSTATEPREFERENCE_H

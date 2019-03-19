// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/preference/DialogPreference.h>

#ifndef SCAPIX_ANDROID_PREFERENCE_EDITTEXTPREFERENCE_H
#define SCAPIX_ANDROID_PREFERENCE_EDITTEXTPREFERENCE_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::util { class AttributeSet; }
namespace android::widget { class EditText; }
namespace java::lang { class String; }

namespace android::preference {

class EditTextPreference : public object_base<SCAPIX_META_STRING("android/preference/EditTextPreference"),
	android::preference::DialogPreference>
{
public:

	static ref<EditTextPreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr, jint defStyleRes);
	static ref<EditTextPreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr);
	static ref<EditTextPreference> new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs);
	static ref<EditTextPreference> new_object(ref<android::content::Context> context);
	void setText(ref<java::lang::String> text);
	ref<java::lang::String> getText();
	jboolean shouldDisableDependents();
	ref<android::widget::EditText> getEditText();

protected:

	EditTextPreference(handle_type h) : base_(h) {}

};

} // namespace android::preference
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/util/AttributeSet.h>
#include <scapix/java_api/android/widget/EditText.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::preference {

inline ref<EditTextPreference> EditTextPreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr, jint defStyleRes) { return base_::new_object(context, attrs, defStyleAttr, defStyleRes); }
inline ref<EditTextPreference> EditTextPreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs, jint defStyleAttr) { return base_::new_object(context, attrs, defStyleAttr); }
inline ref<EditTextPreference> EditTextPreference::new_object(ref<android::content::Context> context, ref<android::util::AttributeSet> attrs) { return base_::new_object(context, attrs); }
inline ref<EditTextPreference> EditTextPreference::new_object(ref<android::content::Context> context) { return base_::new_object(context); }
inline void EditTextPreference::setText(ref<java::lang::String> text) { return call_method<SCAPIX_META_STRING("setText"), void>(text); }
inline ref<java::lang::String> EditTextPreference::getText() { return call_method<SCAPIX_META_STRING("getText"), ref<java::lang::String>>(); }
inline jboolean EditTextPreference::shouldDisableDependents() { return call_method<SCAPIX_META_STRING("shouldDisableDependents"), jboolean>(); }
inline ref<android::widget::EditText> EditTextPreference::getEditText() { return call_method<SCAPIX_META_STRING("getEditText"), ref<android::widget::EditText>>(); }

} // namespace android::preference
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PREFERENCE_EDITTEXTPREFERENCE_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSUBTYPE_H
#define SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSUBTYPE_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::content::pm { class ApplicationInfo; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace android::view::inputmethod { class InputMethodSubtype_InputMethodSubtypeBuilder; }

namespace android::view::inputmethod {

class InputMethodSubtype : public object_base<SCAPIX_META_STRING("android/view/inputmethod/InputMethodSubtype"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	using InputMethodSubtypeBuilder = InputMethodSubtype_InputMethodSubtypeBuilder;

	static ref<android::os::Parcelable_Creator> CREATOR_();

	static ref<InputMethodSubtype> new_object(jint nameId, jint iconId, ref<java::lang::String> locale, ref<java::lang::String> mode, ref<java::lang::String> extraValue, jboolean isAuxiliary, jboolean overridesImplicitlyEnabledSubtype);
	static ref<InputMethodSubtype> new_object(jint nameId, jint iconId, ref<java::lang::String> locale, ref<java::lang::String> mode, ref<java::lang::String> extraValue, jboolean isAuxiliary, jboolean overridesImplicitlyEnabledSubtype, jint id);
	jint getNameResId();
	jint getIconResId();
	ref<java::lang::String> getLocale();
	ref<java::lang::String> getLanguageTag();
	ref<java::lang::String> getMode();
	ref<java::lang::String> getExtraValue();
	jboolean isAuxiliary();
	jboolean overridesImplicitlyEnabledSubtype();
	jboolean isAsciiCapable();
	ref<java::lang::CharSequence> getDisplayName(ref<android::content::Context> context, ref<java::lang::String> packageName, ref<android::content::pm::ApplicationInfo> appInfo);
	jboolean containsExtraValueKey(ref<java::lang::String> key);
	ref<java::lang::String> getExtraValueOf(ref<java::lang::String> key);
	jint hashCode();
	jboolean equals(ref<java::lang::Object> o);
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint parcelableFlags);

protected:

	InputMethodSubtype(handle_type h) : base_(h) {}

};

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/content/pm/ApplicationInfo.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::view::inputmethod {

inline ref<android::os::Parcelable_Creator> InputMethodSubtype::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<InputMethodSubtype> InputMethodSubtype::new_object(jint nameId, jint iconId, ref<java::lang::String> locale, ref<java::lang::String> mode, ref<java::lang::String> extraValue, jboolean isAuxiliary, jboolean overridesImplicitlyEnabledSubtype) { return base_::new_object(nameId, iconId, locale, mode, extraValue, isAuxiliary, overridesImplicitlyEnabledSubtype); }
inline ref<InputMethodSubtype> InputMethodSubtype::new_object(jint nameId, jint iconId, ref<java::lang::String> locale, ref<java::lang::String> mode, ref<java::lang::String> extraValue, jboolean isAuxiliary, jboolean overridesImplicitlyEnabledSubtype, jint id) { return base_::new_object(nameId, iconId, locale, mode, extraValue, isAuxiliary, overridesImplicitlyEnabledSubtype, id); }
inline jint InputMethodSubtype::getNameResId() { return call_method<SCAPIX_META_STRING("getNameResId"), jint>(); }
inline jint InputMethodSubtype::getIconResId() { return call_method<SCAPIX_META_STRING("getIconResId"), jint>(); }
inline ref<java::lang::String> InputMethodSubtype::getLocale() { return call_method<SCAPIX_META_STRING("getLocale"), ref<java::lang::String>>(); }
inline ref<java::lang::String> InputMethodSubtype::getLanguageTag() { return call_method<SCAPIX_META_STRING("getLanguageTag"), ref<java::lang::String>>(); }
inline ref<java::lang::String> InputMethodSubtype::getMode() { return call_method<SCAPIX_META_STRING("getMode"), ref<java::lang::String>>(); }
inline ref<java::lang::String> InputMethodSubtype::getExtraValue() { return call_method<SCAPIX_META_STRING("getExtraValue"), ref<java::lang::String>>(); }
inline jboolean InputMethodSubtype::isAuxiliary() { return call_method<SCAPIX_META_STRING("isAuxiliary"), jboolean>(); }
inline jboolean InputMethodSubtype::overridesImplicitlyEnabledSubtype() { return call_method<SCAPIX_META_STRING("overridesImplicitlyEnabledSubtype"), jboolean>(); }
inline jboolean InputMethodSubtype::isAsciiCapable() { return call_method<SCAPIX_META_STRING("isAsciiCapable"), jboolean>(); }
inline ref<java::lang::CharSequence> InputMethodSubtype::getDisplayName(ref<android::content::Context> context, ref<java::lang::String> packageName, ref<android::content::pm::ApplicationInfo> appInfo) { return call_method<SCAPIX_META_STRING("getDisplayName"), ref<java::lang::CharSequence>>(context, packageName, appInfo); }
inline jboolean InputMethodSubtype::containsExtraValueKey(ref<java::lang::String> key) { return call_method<SCAPIX_META_STRING("containsExtraValueKey"), jboolean>(key); }
inline ref<java::lang::String> InputMethodSubtype::getExtraValueOf(ref<java::lang::String> key) { return call_method<SCAPIX_META_STRING("getExtraValueOf"), ref<java::lang::String>>(key); }
inline jint InputMethodSubtype::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean InputMethodSubtype::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jint InputMethodSubtype::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void InputMethodSubtype::writeToParcel(ref<android::os::Parcel> dest, jint parcelableFlags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, parcelableFlags); }

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_INPUTMETHOD_INPUTMETHODSUBTYPE_H
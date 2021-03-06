// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_VIEW_INPUTMETHOD_EXTRACTEDTEXT_H
#define SCAPIX_ANDROID_VIEW_INPUTMETHOD_EXTRACTEDTEXT_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class CharSequence; }

namespace android::view::inputmethod {

class ExtractedText : public object_base<SCAPIX_META_STRING("android/view/inputmethod/ExtractedText"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint FLAG_SELECTING_();
	static jint FLAG_SINGLE_LINE_();
	jint flags();
	void flags(jint);
	ref<java::lang::CharSequence> hint();
	void hint(ref<java::lang::CharSequence>);
	jint partialEndOffset();
	void partialEndOffset(jint);
	jint partialStartOffset();
	void partialStartOffset(jint);
	jint selectionEnd();
	void selectionEnd(jint);
	jint selectionStart();
	void selectionStart(jint);
	jint startOffset();
	void startOffset(jint);
	ref<java::lang::CharSequence> text();
	void text(ref<java::lang::CharSequence>);

	static ref<ExtractedText> new_object();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jint describeContents();

protected:

	ExtractedText(handle_type h) : base_(h) {}

};

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/CharSequence.h>

namespace scapix::java_api {
namespace android::view::inputmethod {

inline ref<android::os::Parcelable_Creator> ExtractedText::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint ExtractedText::FLAG_SELECTING_() { return get_static_field<SCAPIX_META_STRING("FLAG_SELECTING"), jint>(); }
inline jint ExtractedText::FLAG_SINGLE_LINE_() { return get_static_field<SCAPIX_META_STRING("FLAG_SINGLE_LINE"), jint>(); }
inline jint ExtractedText::flags() { return get_field<SCAPIX_META_STRING("flags"), jint>(); }
inline void ExtractedText::flags(jint v) { set_field<SCAPIX_META_STRING("flags"), jint>(v); }
inline ref<java::lang::CharSequence> ExtractedText::hint() { return get_field<SCAPIX_META_STRING("hint"), ref<java::lang::CharSequence>>(); }
inline void ExtractedText::hint(ref<java::lang::CharSequence> v) { set_field<SCAPIX_META_STRING("hint"), ref<java::lang::CharSequence>>(v); }
inline jint ExtractedText::partialEndOffset() { return get_field<SCAPIX_META_STRING("partialEndOffset"), jint>(); }
inline void ExtractedText::partialEndOffset(jint v) { set_field<SCAPIX_META_STRING("partialEndOffset"), jint>(v); }
inline jint ExtractedText::partialStartOffset() { return get_field<SCAPIX_META_STRING("partialStartOffset"), jint>(); }
inline void ExtractedText::partialStartOffset(jint v) { set_field<SCAPIX_META_STRING("partialStartOffset"), jint>(v); }
inline jint ExtractedText::selectionEnd() { return get_field<SCAPIX_META_STRING("selectionEnd"), jint>(); }
inline void ExtractedText::selectionEnd(jint v) { set_field<SCAPIX_META_STRING("selectionEnd"), jint>(v); }
inline jint ExtractedText::selectionStart() { return get_field<SCAPIX_META_STRING("selectionStart"), jint>(); }
inline void ExtractedText::selectionStart(jint v) { set_field<SCAPIX_META_STRING("selectionStart"), jint>(v); }
inline jint ExtractedText::startOffset() { return get_field<SCAPIX_META_STRING("startOffset"), jint>(); }
inline void ExtractedText::startOffset(jint v) { set_field<SCAPIX_META_STRING("startOffset"), jint>(v); }
inline ref<java::lang::CharSequence> ExtractedText::text() { return get_field<SCAPIX_META_STRING("text"), ref<java::lang::CharSequence>>(); }
inline void ExtractedText::text(ref<java::lang::CharSequence> v) { set_field<SCAPIX_META_STRING("text"), ref<java::lang::CharSequence>>(v); }
inline ref<ExtractedText> ExtractedText::new_object() { return base_::new_object(); }
inline void ExtractedText::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jint ExtractedText::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }

} // namespace android::view::inputmethod
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_INPUTMETHOD_EXTRACTEDTEXT_H

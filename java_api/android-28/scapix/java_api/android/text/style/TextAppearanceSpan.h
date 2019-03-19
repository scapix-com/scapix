// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/text/style/MetricAffectingSpan.h>
#include <scapix/java_api/android/text/ParcelableSpan.h>

#ifndef SCAPIX_ANDROID_TEXT_STYLE_TEXTAPPEARANCESPAN_H
#define SCAPIX_ANDROID_TEXT_STYLE_TEXTAPPEARANCESPAN_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::content::res { class ColorStateList; }
namespace android::os { class Parcel; }
namespace android::text { class TextPaint; }
namespace java::lang { class String; }

namespace android::text::style {

class TextAppearanceSpan : public object_base<SCAPIX_META_STRING("android/text/style/TextAppearanceSpan"),
	android::text::style::MetricAffectingSpan,
	android::text::ParcelableSpan>
{
public:

	static ref<TextAppearanceSpan> new_object(ref<android::content::Context> context, jint appearance);
	static ref<TextAppearanceSpan> new_object(ref<android::content::Context> context, jint appearance, jint colorList);
	static ref<TextAppearanceSpan> new_object(ref<java::lang::String> family, jint style, jint size, ref<android::content::res::ColorStateList> color, ref<android::content::res::ColorStateList> linkColor);
	static ref<TextAppearanceSpan> new_object(ref<android::os::Parcel> src);
	jint getSpanTypeId();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	ref<java::lang::String> getFamily();
	ref<android::content::res::ColorStateList> getTextColor();
	ref<android::content::res::ColorStateList> getLinkTextColor();
	jint getTextSize();
	jint getTextStyle();
	void updateDrawState(ref<android::text::TextPaint> ds);
	void updateMeasureState(ref<android::text::TextPaint> ds);

protected:

	TextAppearanceSpan(handle_type h) : base_(h) {}

};

} // namespace android::text::style
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/content/res/ColorStateList.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/text/TextPaint.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::text::style {

inline ref<TextAppearanceSpan> TextAppearanceSpan::new_object(ref<android::content::Context> context, jint appearance) { return base_::new_object(context, appearance); }
inline ref<TextAppearanceSpan> TextAppearanceSpan::new_object(ref<android::content::Context> context, jint appearance, jint colorList) { return base_::new_object(context, appearance, colorList); }
inline ref<TextAppearanceSpan> TextAppearanceSpan::new_object(ref<java::lang::String> family, jint style, jint size, ref<android::content::res::ColorStateList> color, ref<android::content::res::ColorStateList> linkColor) { return base_::new_object(family, style, size, color, linkColor); }
inline ref<TextAppearanceSpan> TextAppearanceSpan::new_object(ref<android::os::Parcel> src) { return base_::new_object(src); }
inline jint TextAppearanceSpan::getSpanTypeId() { return call_method<SCAPIX_META_STRING("getSpanTypeId"), jint>(); }
inline jint TextAppearanceSpan::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void TextAppearanceSpan::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline ref<java::lang::String> TextAppearanceSpan::getFamily() { return call_method<SCAPIX_META_STRING("getFamily"), ref<java::lang::String>>(); }
inline ref<android::content::res::ColorStateList> TextAppearanceSpan::getTextColor() { return call_method<SCAPIX_META_STRING("getTextColor"), ref<android::content::res::ColorStateList>>(); }
inline ref<android::content::res::ColorStateList> TextAppearanceSpan::getLinkTextColor() { return call_method<SCAPIX_META_STRING("getLinkTextColor"), ref<android::content::res::ColorStateList>>(); }
inline jint TextAppearanceSpan::getTextSize() { return call_method<SCAPIX_META_STRING("getTextSize"), jint>(); }
inline jint TextAppearanceSpan::getTextStyle() { return call_method<SCAPIX_META_STRING("getTextStyle"), jint>(); }
inline void TextAppearanceSpan::updateDrawState(ref<android::text::TextPaint> ds) { return call_method<SCAPIX_META_STRING("updateDrawState"), void>(ds); }
inline void TextAppearanceSpan::updateMeasureState(ref<android::text::TextPaint> ds) { return call_method<SCAPIX_META_STRING("updateMeasureState"), void>(ds); }

} // namespace android::text::style
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TEXT_STYLE_TEXTAPPEARANCESPAN_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_PAINT_H
#define SCAPIX_ANDROID_GRAPHICS_PAINT_H

namespace scapix::java_api {

namespace android::graphics { class ColorFilter; }
namespace android::graphics { class MaskFilter; }
namespace android::graphics { class Paint_Align; }
namespace android::graphics { class Paint_Cap; }
namespace android::graphics { class Paint_FontMetrics; }
namespace android::graphics { class Paint_FontMetricsInt; }
namespace android::graphics { class Paint_Join; }
namespace android::graphics { class Paint_Style; }
namespace android::graphics { class Path; }
namespace android::graphics { class PathEffect; }
namespace android::graphics { class Rect; }
namespace android::graphics { class Shader; }
namespace android::graphics { class Typeface; }
namespace android::graphics { class Xfermode; }
namespace android::os { class LocaleList; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::util { class Locale; }

namespace android::graphics {

class Paint : public object_base<SCAPIX_META_STRING("android/graphics/Paint"),
	java::lang::Object>
{
public:

	using Style = Paint_Style;
	using Join = Paint_Join;
	using FontMetricsInt = Paint_FontMetricsInt;
	using FontMetrics = Paint_FontMetrics;
	using Cap = Paint_Cap;
	using Align = Paint_Align;

	static jint ANTI_ALIAS_FLAG_();
	static jint DEV_KERN_TEXT_FLAG_();
	static jint DITHER_FLAG_();
	static jint EMBEDDED_BITMAP_TEXT_FLAG_();
	static jint FAKE_BOLD_TEXT_FLAG_();
	static jint FILTER_BITMAP_FLAG_();
	static jint HINTING_OFF_();
	static jint HINTING_ON_();
	static jint LINEAR_TEXT_FLAG_();
	static jint STRIKE_THRU_TEXT_FLAG_();
	static jint SUBPIXEL_TEXT_FLAG_();
	static jint UNDERLINE_TEXT_FLAG_();

	static ref<Paint> new_object();
	static ref<Paint> new_object(jint flags);
	static ref<Paint> new_object(ref<android::graphics::Paint> paint);
	void reset();
	void set(ref<android::graphics::Paint> src);
	jint getFlags();
	void setFlags(jint flags);
	jint getHinting();
	void setHinting(jint mode);
	jboolean isAntiAlias();
	void setAntiAlias(jboolean aa);
	jboolean isDither();
	void setDither(jboolean dither);
	jboolean isLinearText();
	void setLinearText(jboolean linearText);
	jboolean isSubpixelText();
	void setSubpixelText(jboolean subpixelText);
	jboolean isUnderlineText();
	void setUnderlineText(jboolean underlineText);
	jboolean isStrikeThruText();
	void setStrikeThruText(jboolean strikeThruText);
	jboolean isFakeBoldText();
	void setFakeBoldText(jboolean fakeBoldText);
	jboolean isFilterBitmap();
	void setFilterBitmap(jboolean filter);
	ref<android::graphics::Paint_Style> getStyle();
	void setStyle(ref<android::graphics::Paint_Style> style);
	jint getColor();
	void setColor(jint color);
	jint getAlpha();
	void setAlpha(jint a);
	void setARGB(jint a, jint r, jint g, jint b);
	jfloat getStrokeWidth();
	void setStrokeWidth(jfloat width);
	jfloat getStrokeMiter();
	void setStrokeMiter(jfloat miter);
	ref<android::graphics::Paint_Cap> getStrokeCap();
	void setStrokeCap(ref<android::graphics::Paint_Cap> cap);
	ref<android::graphics::Paint_Join> getStrokeJoin();
	void setStrokeJoin(ref<android::graphics::Paint_Join> join);
	jboolean getFillPath(ref<android::graphics::Path> src, ref<android::graphics::Path> dst);
	ref<android::graphics::Shader> getShader();
	ref<android::graphics::Shader> setShader(ref<android::graphics::Shader> shader);
	ref<android::graphics::ColorFilter> getColorFilter();
	ref<android::graphics::ColorFilter> setColorFilter(ref<android::graphics::ColorFilter> filter);
	ref<android::graphics::Xfermode> getXfermode();
	ref<android::graphics::Xfermode> setXfermode(ref<android::graphics::Xfermode> xfermode);
	ref<android::graphics::PathEffect> getPathEffect();
	ref<android::graphics::PathEffect> setPathEffect(ref<android::graphics::PathEffect> effect);
	ref<android::graphics::MaskFilter> getMaskFilter();
	ref<android::graphics::MaskFilter> setMaskFilter(ref<android::graphics::MaskFilter> maskfilter);
	ref<android::graphics::Typeface> getTypeface();
	ref<android::graphics::Typeface> setTypeface(ref<android::graphics::Typeface> typeface);
	void setShadowLayer(jfloat radius, jfloat dx, jfloat dy, jint shadowColor);
	void clearShadowLayer();
	ref<android::graphics::Paint_Align> getTextAlign();
	void setTextAlign(ref<android::graphics::Paint_Align> align);
	ref<java::util::Locale> getTextLocale();
	ref<android::os::LocaleList> getTextLocales();
	void setTextLocale(ref<java::util::Locale> locale);
	void setTextLocales(ref<android::os::LocaleList> locales);
	jboolean isElegantTextHeight();
	void setElegantTextHeight(jboolean elegant);
	jfloat getTextSize();
	void setTextSize(jfloat textSize);
	jfloat getTextScaleX();
	void setTextScaleX(jfloat scaleX);
	jfloat getTextSkewX();
	void setTextSkewX(jfloat skewX);
	jfloat getLetterSpacing();
	void setLetterSpacing(jfloat letterSpacing);
	ref<java::lang::String> getFontFeatureSettings();
	void setFontFeatureSettings(ref<java::lang::String> settings);
	ref<java::lang::String> getFontVariationSettings();
	jboolean setFontVariationSettings(ref<java::lang::String> fontVariationSettings);
	jfloat ascent();
	jfloat descent();
	jfloat getFontMetrics(ref<android::graphics::Paint_FontMetrics> metrics);
	ref<android::graphics::Paint_FontMetrics> getFontMetrics();
	jint getFontMetricsInt(ref<android::graphics::Paint_FontMetricsInt> fmi);
	ref<android::graphics::Paint_FontMetricsInt> getFontMetricsInt();
	jfloat getFontSpacing();
	jfloat measureText(ref<link::java::array<jchar>> text, jint index, jint count);
	jfloat measureText(ref<java::lang::String> text, jint start, jint end);
	jfloat measureText(ref<java::lang::String> text);
	jfloat measureText(ref<java::lang::CharSequence> text, jint start, jint end);
	jint breakText(ref<link::java::array<jchar>> text, jint index, jint count, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth);
	jint breakText(ref<java::lang::CharSequence> text, jint start, jint end, jboolean measureForwards, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth);
	jint breakText(ref<java::lang::String> text, jboolean measureForwards, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth);
	jint getTextWidths(ref<link::java::array<jchar>> text, jint index, jint count, ref<link::java::array<jfloat>> widths);
	jint getTextWidths(ref<java::lang::CharSequence> text, jint start, jint end, ref<link::java::array<jfloat>> widths);
	jint getTextWidths(ref<java::lang::String> text, jint start, jint end, ref<link::java::array<jfloat>> widths);
	jint getTextWidths(ref<java::lang::String> text, ref<link::java::array<jfloat>> widths);
	void getTextPath(ref<link::java::array<jchar>> text, jint index, jint count, jfloat x, jfloat y, ref<android::graphics::Path> path);
	void getTextPath(ref<java::lang::String> text, jint start, jint end, jfloat x, jfloat y, ref<android::graphics::Path> path);
	void getTextBounds(ref<java::lang::String> text, jint start, jint end, ref<android::graphics::Rect> bounds);
	void getTextBounds(ref<link::java::array<jchar>> text, jint index, jint count, ref<android::graphics::Rect> bounds);
	jboolean hasGlyph(ref<java::lang::String> string);
	jfloat getRunAdvance(ref<link::java::array<jchar>> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jint offset);
	jfloat getRunAdvance(ref<java::lang::CharSequence> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jint offset);
	jint getOffsetForAdvance(ref<link::java::array<jchar>> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jfloat advance);
	jint getOffsetForAdvance(ref<java::lang::CharSequence> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jfloat advance);
	jboolean equalsForTextMeasurement(ref<android::graphics::Paint> other);

protected:

	Paint(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/android/graphics/ColorFilter.h>
#include <scapix/java_api/android/graphics/MaskFilter.h>
#include <scapix/java_api/android/graphics/Paint_Align.h>
#include <scapix/java_api/android/graphics/Paint_Cap.h>
#include <scapix/java_api/android/graphics/Paint_FontMetrics.h>
#include <scapix/java_api/android/graphics/Paint_FontMetricsInt.h>
#include <scapix/java_api/android/graphics/Paint_Join.h>
#include <scapix/java_api/android/graphics/Paint_Style.h>
#include <scapix/java_api/android/graphics/Path.h>
#include <scapix/java_api/android/graphics/PathEffect.h>
#include <scapix/java_api/android/graphics/Rect.h>
#include <scapix/java_api/android/graphics/Shader.h>
#include <scapix/java_api/android/graphics/Typeface.h>
#include <scapix/java_api/android/graphics/Xfermode.h>
#include <scapix/java_api/android/os/LocaleList.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Locale.h>

namespace scapix::java_api {
namespace android::graphics {

inline jint Paint::ANTI_ALIAS_FLAG_() { return get_static_field<SCAPIX_META_STRING("ANTI_ALIAS_FLAG"), jint>(); }
inline jint Paint::DEV_KERN_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("DEV_KERN_TEXT_FLAG"), jint>(); }
inline jint Paint::DITHER_FLAG_() { return get_static_field<SCAPIX_META_STRING("DITHER_FLAG"), jint>(); }
inline jint Paint::EMBEDDED_BITMAP_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("EMBEDDED_BITMAP_TEXT_FLAG"), jint>(); }
inline jint Paint::FAKE_BOLD_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("FAKE_BOLD_TEXT_FLAG"), jint>(); }
inline jint Paint::FILTER_BITMAP_FLAG_() { return get_static_field<SCAPIX_META_STRING("FILTER_BITMAP_FLAG"), jint>(); }
inline jint Paint::HINTING_OFF_() { return get_static_field<SCAPIX_META_STRING("HINTING_OFF"), jint>(); }
inline jint Paint::HINTING_ON_() { return get_static_field<SCAPIX_META_STRING("HINTING_ON"), jint>(); }
inline jint Paint::LINEAR_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("LINEAR_TEXT_FLAG"), jint>(); }
inline jint Paint::STRIKE_THRU_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("STRIKE_THRU_TEXT_FLAG"), jint>(); }
inline jint Paint::SUBPIXEL_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("SUBPIXEL_TEXT_FLAG"), jint>(); }
inline jint Paint::UNDERLINE_TEXT_FLAG_() { return get_static_field<SCAPIX_META_STRING("UNDERLINE_TEXT_FLAG"), jint>(); }
inline ref<Paint> Paint::new_object() { return base_::new_object(); }
inline ref<Paint> Paint::new_object(jint flags) { return base_::new_object(flags); }
inline ref<Paint> Paint::new_object(ref<android::graphics::Paint> paint) { return base_::new_object(paint); }
inline void Paint::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }
inline void Paint::set(ref<android::graphics::Paint> src) { return call_method<SCAPIX_META_STRING("set"), void>(src); }
inline jint Paint::getFlags() { return call_method<SCAPIX_META_STRING("getFlags"), jint>(); }
inline void Paint::setFlags(jint flags) { return call_method<SCAPIX_META_STRING("setFlags"), void>(flags); }
inline jint Paint::getHinting() { return call_method<SCAPIX_META_STRING("getHinting"), jint>(); }
inline void Paint::setHinting(jint mode) { return call_method<SCAPIX_META_STRING("setHinting"), void>(mode); }
inline jboolean Paint::isAntiAlias() { return call_method<SCAPIX_META_STRING("isAntiAlias"), jboolean>(); }
inline void Paint::setAntiAlias(jboolean aa) { return call_method<SCAPIX_META_STRING("setAntiAlias"), void>(aa); }
inline jboolean Paint::isDither() { return call_method<SCAPIX_META_STRING("isDither"), jboolean>(); }
inline void Paint::setDither(jboolean dither) { return call_method<SCAPIX_META_STRING("setDither"), void>(dither); }
inline jboolean Paint::isLinearText() { return call_method<SCAPIX_META_STRING("isLinearText"), jboolean>(); }
inline void Paint::setLinearText(jboolean linearText) { return call_method<SCAPIX_META_STRING("setLinearText"), void>(linearText); }
inline jboolean Paint::isSubpixelText() { return call_method<SCAPIX_META_STRING("isSubpixelText"), jboolean>(); }
inline void Paint::setSubpixelText(jboolean subpixelText) { return call_method<SCAPIX_META_STRING("setSubpixelText"), void>(subpixelText); }
inline jboolean Paint::isUnderlineText() { return call_method<SCAPIX_META_STRING("isUnderlineText"), jboolean>(); }
inline void Paint::setUnderlineText(jboolean underlineText) { return call_method<SCAPIX_META_STRING("setUnderlineText"), void>(underlineText); }
inline jboolean Paint::isStrikeThruText() { return call_method<SCAPIX_META_STRING("isStrikeThruText"), jboolean>(); }
inline void Paint::setStrikeThruText(jboolean strikeThruText) { return call_method<SCAPIX_META_STRING("setStrikeThruText"), void>(strikeThruText); }
inline jboolean Paint::isFakeBoldText() { return call_method<SCAPIX_META_STRING("isFakeBoldText"), jboolean>(); }
inline void Paint::setFakeBoldText(jboolean fakeBoldText) { return call_method<SCAPIX_META_STRING("setFakeBoldText"), void>(fakeBoldText); }
inline jboolean Paint::isFilterBitmap() { return call_method<SCAPIX_META_STRING("isFilterBitmap"), jboolean>(); }
inline void Paint::setFilterBitmap(jboolean filter) { return call_method<SCAPIX_META_STRING("setFilterBitmap"), void>(filter); }
inline ref<android::graphics::Paint_Style> Paint::getStyle() { return call_method<SCAPIX_META_STRING("getStyle"), ref<android::graphics::Paint_Style>>(); }
inline void Paint::setStyle(ref<android::graphics::Paint_Style> style) { return call_method<SCAPIX_META_STRING("setStyle"), void>(style); }
inline jint Paint::getColor() { return call_method<SCAPIX_META_STRING("getColor"), jint>(); }
inline void Paint::setColor(jint color) { return call_method<SCAPIX_META_STRING("setColor"), void>(color); }
inline jint Paint::getAlpha() { return call_method<SCAPIX_META_STRING("getAlpha"), jint>(); }
inline void Paint::setAlpha(jint a) { return call_method<SCAPIX_META_STRING("setAlpha"), void>(a); }
inline void Paint::setARGB(jint a, jint r, jint g, jint b) { return call_method<SCAPIX_META_STRING("setARGB"), void>(a, r, g, b); }
inline jfloat Paint::getStrokeWidth() { return call_method<SCAPIX_META_STRING("getStrokeWidth"), jfloat>(); }
inline void Paint::setStrokeWidth(jfloat width) { return call_method<SCAPIX_META_STRING("setStrokeWidth"), void>(width); }
inline jfloat Paint::getStrokeMiter() { return call_method<SCAPIX_META_STRING("getStrokeMiter"), jfloat>(); }
inline void Paint::setStrokeMiter(jfloat miter) { return call_method<SCAPIX_META_STRING("setStrokeMiter"), void>(miter); }
inline ref<android::graphics::Paint_Cap> Paint::getStrokeCap() { return call_method<SCAPIX_META_STRING("getStrokeCap"), ref<android::graphics::Paint_Cap>>(); }
inline void Paint::setStrokeCap(ref<android::graphics::Paint_Cap> cap) { return call_method<SCAPIX_META_STRING("setStrokeCap"), void>(cap); }
inline ref<android::graphics::Paint_Join> Paint::getStrokeJoin() { return call_method<SCAPIX_META_STRING("getStrokeJoin"), ref<android::graphics::Paint_Join>>(); }
inline void Paint::setStrokeJoin(ref<android::graphics::Paint_Join> join) { return call_method<SCAPIX_META_STRING("setStrokeJoin"), void>(join); }
inline jboolean Paint::getFillPath(ref<android::graphics::Path> src, ref<android::graphics::Path> dst) { return call_method<SCAPIX_META_STRING("getFillPath"), jboolean>(src, dst); }
inline ref<android::graphics::Shader> Paint::getShader() { return call_method<SCAPIX_META_STRING("getShader"), ref<android::graphics::Shader>>(); }
inline ref<android::graphics::Shader> Paint::setShader(ref<android::graphics::Shader> shader) { return call_method<SCAPIX_META_STRING("setShader"), ref<android::graphics::Shader>>(shader); }
inline ref<android::graphics::ColorFilter> Paint::getColorFilter() { return call_method<SCAPIX_META_STRING("getColorFilter"), ref<android::graphics::ColorFilter>>(); }
inline ref<android::graphics::ColorFilter> Paint::setColorFilter(ref<android::graphics::ColorFilter> filter) { return call_method<SCAPIX_META_STRING("setColorFilter"), ref<android::graphics::ColorFilter>>(filter); }
inline ref<android::graphics::Xfermode> Paint::getXfermode() { return call_method<SCAPIX_META_STRING("getXfermode"), ref<android::graphics::Xfermode>>(); }
inline ref<android::graphics::Xfermode> Paint::setXfermode(ref<android::graphics::Xfermode> xfermode) { return call_method<SCAPIX_META_STRING("setXfermode"), ref<android::graphics::Xfermode>>(xfermode); }
inline ref<android::graphics::PathEffect> Paint::getPathEffect() { return call_method<SCAPIX_META_STRING("getPathEffect"), ref<android::graphics::PathEffect>>(); }
inline ref<android::graphics::PathEffect> Paint::setPathEffect(ref<android::graphics::PathEffect> effect) { return call_method<SCAPIX_META_STRING("setPathEffect"), ref<android::graphics::PathEffect>>(effect); }
inline ref<android::graphics::MaskFilter> Paint::getMaskFilter() { return call_method<SCAPIX_META_STRING("getMaskFilter"), ref<android::graphics::MaskFilter>>(); }
inline ref<android::graphics::MaskFilter> Paint::setMaskFilter(ref<android::graphics::MaskFilter> maskfilter) { return call_method<SCAPIX_META_STRING("setMaskFilter"), ref<android::graphics::MaskFilter>>(maskfilter); }
inline ref<android::graphics::Typeface> Paint::getTypeface() { return call_method<SCAPIX_META_STRING("getTypeface"), ref<android::graphics::Typeface>>(); }
inline ref<android::graphics::Typeface> Paint::setTypeface(ref<android::graphics::Typeface> typeface) { return call_method<SCAPIX_META_STRING("setTypeface"), ref<android::graphics::Typeface>>(typeface); }
inline void Paint::setShadowLayer(jfloat radius, jfloat dx, jfloat dy, jint shadowColor) { return call_method<SCAPIX_META_STRING("setShadowLayer"), void>(radius, dx, dy, shadowColor); }
inline void Paint::clearShadowLayer() { return call_method<SCAPIX_META_STRING("clearShadowLayer"), void>(); }
inline ref<android::graphics::Paint_Align> Paint::getTextAlign() { return call_method<SCAPIX_META_STRING("getTextAlign"), ref<android::graphics::Paint_Align>>(); }
inline void Paint::setTextAlign(ref<android::graphics::Paint_Align> align) { return call_method<SCAPIX_META_STRING("setTextAlign"), void>(align); }
inline ref<java::util::Locale> Paint::getTextLocale() { return call_method<SCAPIX_META_STRING("getTextLocale"), ref<java::util::Locale>>(); }
inline ref<android::os::LocaleList> Paint::getTextLocales() { return call_method<SCAPIX_META_STRING("getTextLocales"), ref<android::os::LocaleList>>(); }
inline void Paint::setTextLocale(ref<java::util::Locale> locale) { return call_method<SCAPIX_META_STRING("setTextLocale"), void>(locale); }
inline void Paint::setTextLocales(ref<android::os::LocaleList> locales) { return call_method<SCAPIX_META_STRING("setTextLocales"), void>(locales); }
inline jboolean Paint::isElegantTextHeight() { return call_method<SCAPIX_META_STRING("isElegantTextHeight"), jboolean>(); }
inline void Paint::setElegantTextHeight(jboolean elegant) { return call_method<SCAPIX_META_STRING("setElegantTextHeight"), void>(elegant); }
inline jfloat Paint::getTextSize() { return call_method<SCAPIX_META_STRING("getTextSize"), jfloat>(); }
inline void Paint::setTextSize(jfloat textSize) { return call_method<SCAPIX_META_STRING("setTextSize"), void>(textSize); }
inline jfloat Paint::getTextScaleX() { return call_method<SCAPIX_META_STRING("getTextScaleX"), jfloat>(); }
inline void Paint::setTextScaleX(jfloat scaleX) { return call_method<SCAPIX_META_STRING("setTextScaleX"), void>(scaleX); }
inline jfloat Paint::getTextSkewX() { return call_method<SCAPIX_META_STRING("getTextSkewX"), jfloat>(); }
inline void Paint::setTextSkewX(jfloat skewX) { return call_method<SCAPIX_META_STRING("setTextSkewX"), void>(skewX); }
inline jfloat Paint::getLetterSpacing() { return call_method<SCAPIX_META_STRING("getLetterSpacing"), jfloat>(); }
inline void Paint::setLetterSpacing(jfloat letterSpacing) { return call_method<SCAPIX_META_STRING("setLetterSpacing"), void>(letterSpacing); }
inline ref<java::lang::String> Paint::getFontFeatureSettings() { return call_method<SCAPIX_META_STRING("getFontFeatureSettings"), ref<java::lang::String>>(); }
inline void Paint::setFontFeatureSettings(ref<java::lang::String> settings) { return call_method<SCAPIX_META_STRING("setFontFeatureSettings"), void>(settings); }
inline ref<java::lang::String> Paint::getFontVariationSettings() { return call_method<SCAPIX_META_STRING("getFontVariationSettings"), ref<java::lang::String>>(); }
inline jboolean Paint::setFontVariationSettings(ref<java::lang::String> fontVariationSettings) { return call_method<SCAPIX_META_STRING("setFontVariationSettings"), jboolean>(fontVariationSettings); }
inline jfloat Paint::ascent() { return call_method<SCAPIX_META_STRING("ascent"), jfloat>(); }
inline jfloat Paint::descent() { return call_method<SCAPIX_META_STRING("descent"), jfloat>(); }
inline jfloat Paint::getFontMetrics(ref<android::graphics::Paint_FontMetrics> metrics) { return call_method<SCAPIX_META_STRING("getFontMetrics"), jfloat>(metrics); }
inline ref<android::graphics::Paint_FontMetrics> Paint::getFontMetrics() { return call_method<SCAPIX_META_STRING("getFontMetrics"), ref<android::graphics::Paint_FontMetrics>>(); }
inline jint Paint::getFontMetricsInt(ref<android::graphics::Paint_FontMetricsInt> fmi) { return call_method<SCAPIX_META_STRING("getFontMetricsInt"), jint>(fmi); }
inline ref<android::graphics::Paint_FontMetricsInt> Paint::getFontMetricsInt() { return call_method<SCAPIX_META_STRING("getFontMetricsInt"), ref<android::graphics::Paint_FontMetricsInt>>(); }
inline jfloat Paint::getFontSpacing() { return call_method<SCAPIX_META_STRING("getFontSpacing"), jfloat>(); }
inline jfloat Paint::measureText(ref<link::java::array<jchar>> text, jint index, jint count) { return call_method<SCAPIX_META_STRING("measureText"), jfloat>(text, index, count); }
inline jfloat Paint::measureText(ref<java::lang::String> text, jint start, jint end) { return call_method<SCAPIX_META_STRING("measureText"), jfloat>(text, start, end); }
inline jfloat Paint::measureText(ref<java::lang::String> text) { return call_method<SCAPIX_META_STRING("measureText"), jfloat>(text); }
inline jfloat Paint::measureText(ref<java::lang::CharSequence> text, jint start, jint end) { return call_method<SCAPIX_META_STRING("measureText"), jfloat>(text, start, end); }
inline jint Paint::breakText(ref<link::java::array<jchar>> text, jint index, jint count, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth) { return call_method<SCAPIX_META_STRING("breakText"), jint>(text, index, count, maxWidth, measuredWidth); }
inline jint Paint::breakText(ref<java::lang::CharSequence> text, jint start, jint end, jboolean measureForwards, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth) { return call_method<SCAPIX_META_STRING("breakText"), jint>(text, start, end, measureForwards, maxWidth, measuredWidth); }
inline jint Paint::breakText(ref<java::lang::String> text, jboolean measureForwards, jfloat maxWidth, ref<link::java::array<jfloat>> measuredWidth) { return call_method<SCAPIX_META_STRING("breakText"), jint>(text, measureForwards, maxWidth, measuredWidth); }
inline jint Paint::getTextWidths(ref<link::java::array<jchar>> text, jint index, jint count, ref<link::java::array<jfloat>> widths) { return call_method<SCAPIX_META_STRING("getTextWidths"), jint>(text, index, count, widths); }
inline jint Paint::getTextWidths(ref<java::lang::CharSequence> text, jint start, jint end, ref<link::java::array<jfloat>> widths) { return call_method<SCAPIX_META_STRING("getTextWidths"), jint>(text, start, end, widths); }
inline jint Paint::getTextWidths(ref<java::lang::String> text, jint start, jint end, ref<link::java::array<jfloat>> widths) { return call_method<SCAPIX_META_STRING("getTextWidths"), jint>(text, start, end, widths); }
inline jint Paint::getTextWidths(ref<java::lang::String> text, ref<link::java::array<jfloat>> widths) { return call_method<SCAPIX_META_STRING("getTextWidths"), jint>(text, widths); }
inline void Paint::getTextPath(ref<link::java::array<jchar>> text, jint index, jint count, jfloat x, jfloat y, ref<android::graphics::Path> path) { return call_method<SCAPIX_META_STRING("getTextPath"), void>(text, index, count, x, y, path); }
inline void Paint::getTextPath(ref<java::lang::String> text, jint start, jint end, jfloat x, jfloat y, ref<android::graphics::Path> path) { return call_method<SCAPIX_META_STRING("getTextPath"), void>(text, start, end, x, y, path); }
inline void Paint::getTextBounds(ref<java::lang::String> text, jint start, jint end, ref<android::graphics::Rect> bounds) { return call_method<SCAPIX_META_STRING("getTextBounds"), void>(text, start, end, bounds); }
inline void Paint::getTextBounds(ref<link::java::array<jchar>> text, jint index, jint count, ref<android::graphics::Rect> bounds) { return call_method<SCAPIX_META_STRING("getTextBounds"), void>(text, index, count, bounds); }
inline jboolean Paint::hasGlyph(ref<java::lang::String> string) { return call_method<SCAPIX_META_STRING("hasGlyph"), jboolean>(string); }
inline jfloat Paint::getRunAdvance(ref<link::java::array<jchar>> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jint offset) { return call_method<SCAPIX_META_STRING("getRunAdvance"), jfloat>(text, start, end, contextStart, contextEnd, isRtl, offset); }
inline jfloat Paint::getRunAdvance(ref<java::lang::CharSequence> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jint offset) { return call_method<SCAPIX_META_STRING("getRunAdvance"), jfloat>(text, start, end, contextStart, contextEnd, isRtl, offset); }
inline jint Paint::getOffsetForAdvance(ref<link::java::array<jchar>> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jfloat advance) { return call_method<SCAPIX_META_STRING("getOffsetForAdvance"), jint>(text, start, end, contextStart, contextEnd, isRtl, advance); }
inline jint Paint::getOffsetForAdvance(ref<java::lang::CharSequence> text, jint start, jint end, jint contextStart, jint contextEnd, jboolean isRtl, jfloat advance) { return call_method<SCAPIX_META_STRING("getOffsetForAdvance"), jint>(text, start, end, contextStart, contextEnd, isRtl, advance); }
inline jboolean Paint::equalsForTextMeasurement(ref<android::graphics::Paint> other) { return call_method<SCAPIX_META_STRING("equalsForTextMeasurement"), jboolean>(other); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_PAINT_H

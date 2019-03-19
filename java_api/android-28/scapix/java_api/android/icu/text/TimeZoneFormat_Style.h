// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_ICU_TEXT_TIMEZONEFORMAT_STYLE_H
#define SCAPIX_ANDROID_ICU_TEXT_TIMEZONEFORMAT_STYLE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::icu::text {

class TimeZoneFormat_Style : public object_base<SCAPIX_META_STRING("android/icu/text/TimeZoneFormat$Style"),
	java::lang::Enum>
{
public:

	static ref<android::icu::text::TimeZoneFormat_Style> GENERIC_LOCATION_();
	static ref<android::icu::text::TimeZoneFormat_Style> GENERIC_LONG_();
	static ref<android::icu::text::TimeZoneFormat_Style> GENERIC_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> SPECIFIC_LONG_();
	static ref<android::icu::text::TimeZoneFormat_Style> SPECIFIC_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> LOCALIZED_GMT_();
	static ref<android::icu::text::TimeZoneFormat_Style> LOCALIZED_GMT_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_LOCAL_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_FIXED_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_LOCAL_FIXED_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_FULL_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_BASIC_LOCAL_FULL_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_EXTENDED_FIXED_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_EXTENDED_LOCAL_FIXED_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_EXTENDED_FULL_();
	static ref<android::icu::text::TimeZoneFormat_Style> ISO_EXTENDED_LOCAL_FULL_();
	static ref<android::icu::text::TimeZoneFormat_Style> ZONE_ID_();
	static ref<android::icu::text::TimeZoneFormat_Style> ZONE_ID_SHORT_();
	static ref<android::icu::text::TimeZoneFormat_Style> EXEMPLAR_LOCATION_();

	static ref<link::java::array<android::icu::text::TimeZoneFormat_Style>> values();
	static ref<android::icu::text::TimeZoneFormat_Style> valueOf(ref<java::lang::String> name);

protected:

	TimeZoneFormat_Style(handle_type h) : base_(h) {}

};

} // namespace android::icu::text
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::icu::text {

inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::GENERIC_LOCATION_() { return get_static_field<SCAPIX_META_STRING("GENERIC_LOCATION"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::GENERIC_LONG_() { return get_static_field<SCAPIX_META_STRING("GENERIC_LONG"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::GENERIC_SHORT_() { return get_static_field<SCAPIX_META_STRING("GENERIC_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::SPECIFIC_LONG_() { return get_static_field<SCAPIX_META_STRING("SPECIFIC_LONG"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::SPECIFIC_SHORT_() { return get_static_field<SCAPIX_META_STRING("SPECIFIC_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::LOCALIZED_GMT_() { return get_static_field<SCAPIX_META_STRING("LOCALIZED_GMT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::LOCALIZED_GMT_SHORT_() { return get_static_field<SCAPIX_META_STRING("LOCALIZED_GMT_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_SHORT_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_LOCAL_SHORT_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_LOCAL_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_FIXED_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_FIXED"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_LOCAL_FIXED_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_LOCAL_FIXED"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_FULL_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_FULL"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_BASIC_LOCAL_FULL_() { return get_static_field<SCAPIX_META_STRING("ISO_BASIC_LOCAL_FULL"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_EXTENDED_FIXED_() { return get_static_field<SCAPIX_META_STRING("ISO_EXTENDED_FIXED"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_EXTENDED_LOCAL_FIXED_() { return get_static_field<SCAPIX_META_STRING("ISO_EXTENDED_LOCAL_FIXED"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_EXTENDED_FULL_() { return get_static_field<SCAPIX_META_STRING("ISO_EXTENDED_FULL"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ISO_EXTENDED_LOCAL_FULL_() { return get_static_field<SCAPIX_META_STRING("ISO_EXTENDED_LOCAL_FULL"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ZONE_ID_() { return get_static_field<SCAPIX_META_STRING("ZONE_ID"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::ZONE_ID_SHORT_() { return get_static_field<SCAPIX_META_STRING("ZONE_ID_SHORT"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::EXEMPLAR_LOCATION_() { return get_static_field<SCAPIX_META_STRING("EXEMPLAR_LOCATION"), ref<android::icu::text::TimeZoneFormat_Style>>(); }
inline ref<link::java::array<android::icu::text::TimeZoneFormat_Style>> TimeZoneFormat_Style::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::icu::text::TimeZoneFormat_Style>>>(); }
inline ref<android::icu::text::TimeZoneFormat_Style> TimeZoneFormat_Style::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::icu::text::TimeZoneFormat_Style>>(name); }

} // namespace android::icu::text
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_TEXT_TIMEZONEFORMAT_STYLE_H
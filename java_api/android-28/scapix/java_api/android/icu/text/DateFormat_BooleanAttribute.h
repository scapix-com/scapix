// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_ICU_TEXT_DATEFORMAT_BOOLEANATTRIBUTE_H
#define SCAPIX_ANDROID_ICU_TEXT_DATEFORMAT_BOOLEANATTRIBUTE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::icu::text {

class DateFormat_BooleanAttribute : public object_base<SCAPIX_META_STRING("android/icu/text/DateFormat$BooleanAttribute"),
	java::lang::Enum>
{
public:

	static ref<android::icu::text::DateFormat_BooleanAttribute> PARSE_ALLOW_WHITESPACE_();
	static ref<android::icu::text::DateFormat_BooleanAttribute> PARSE_ALLOW_NUMERIC_();
	static ref<android::icu::text::DateFormat_BooleanAttribute> PARSE_MULTIPLE_PATTERNS_FOR_MATCH_();
	static ref<android::icu::text::DateFormat_BooleanAttribute> PARSE_PARTIAL_LITERAL_MATCH_();
	static ref<android::icu::text::DateFormat_BooleanAttribute> PARSE_PARTIAL_MATCH_();

	static ref<link::java::array<android::icu::text::DateFormat_BooleanAttribute>> values();
	static ref<android::icu::text::DateFormat_BooleanAttribute> valueOf(ref<java::lang::String> name);

protected:

	DateFormat_BooleanAttribute(handle_type h) : base_(h) {}

};

} // namespace android::icu::text
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::icu::text {

inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::PARSE_ALLOW_WHITESPACE_() { return get_static_field<SCAPIX_META_STRING("PARSE_ALLOW_WHITESPACE"), ref<android::icu::text::DateFormat_BooleanAttribute>>(); }
inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::PARSE_ALLOW_NUMERIC_() { return get_static_field<SCAPIX_META_STRING("PARSE_ALLOW_NUMERIC"), ref<android::icu::text::DateFormat_BooleanAttribute>>(); }
inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::PARSE_MULTIPLE_PATTERNS_FOR_MATCH_() { return get_static_field<SCAPIX_META_STRING("PARSE_MULTIPLE_PATTERNS_FOR_MATCH"), ref<android::icu::text::DateFormat_BooleanAttribute>>(); }
inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::PARSE_PARTIAL_LITERAL_MATCH_() { return get_static_field<SCAPIX_META_STRING("PARSE_PARTIAL_LITERAL_MATCH"), ref<android::icu::text::DateFormat_BooleanAttribute>>(); }
inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::PARSE_PARTIAL_MATCH_() { return get_static_field<SCAPIX_META_STRING("PARSE_PARTIAL_MATCH"), ref<android::icu::text::DateFormat_BooleanAttribute>>(); }
inline ref<link::java::array<android::icu::text::DateFormat_BooleanAttribute>> DateFormat_BooleanAttribute::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::icu::text::DateFormat_BooleanAttribute>>>(); }
inline ref<android::icu::text::DateFormat_BooleanAttribute> DateFormat_BooleanAttribute::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::icu::text::DateFormat_BooleanAttribute>>(name); }

} // namespace android::icu::text
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_TEXT_DATEFORMAT_BOOLEANATTRIBUTE_H

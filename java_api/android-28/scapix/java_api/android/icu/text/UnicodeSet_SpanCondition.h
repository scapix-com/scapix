// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_ICU_TEXT_UNICODESET_SPANCONDITION_H
#define SCAPIX_ANDROID_ICU_TEXT_UNICODESET_SPANCONDITION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::icu::text {

class UnicodeSet_SpanCondition : public object_base<SCAPIX_META_STRING("android/icu/text/UnicodeSet$SpanCondition"),
	java::lang::Enum>
{
public:

	static ref<android::icu::text::UnicodeSet_SpanCondition> NOT_CONTAINED_();
	static ref<android::icu::text::UnicodeSet_SpanCondition> CONTAINED_();
	static ref<android::icu::text::UnicodeSet_SpanCondition> SIMPLE_();
	static ref<android::icu::text::UnicodeSet_SpanCondition> CONDITION_COUNT_();

	static ref<link::java::array<android::icu::text::UnicodeSet_SpanCondition>> values();
	static ref<android::icu::text::UnicodeSet_SpanCondition> valueOf(ref<java::lang::String> name);

protected:

	UnicodeSet_SpanCondition(handle_type h) : base_(h) {}

};

} // namespace android::icu::text
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::icu::text {

inline ref<android::icu::text::UnicodeSet_SpanCondition> UnicodeSet_SpanCondition::NOT_CONTAINED_() { return get_static_field<SCAPIX_META_STRING("NOT_CONTAINED"), ref<android::icu::text::UnicodeSet_SpanCondition>>(); }
inline ref<android::icu::text::UnicodeSet_SpanCondition> UnicodeSet_SpanCondition::CONTAINED_() { return get_static_field<SCAPIX_META_STRING("CONTAINED"), ref<android::icu::text::UnicodeSet_SpanCondition>>(); }
inline ref<android::icu::text::UnicodeSet_SpanCondition> UnicodeSet_SpanCondition::SIMPLE_() { return get_static_field<SCAPIX_META_STRING("SIMPLE"), ref<android::icu::text::UnicodeSet_SpanCondition>>(); }
inline ref<android::icu::text::UnicodeSet_SpanCondition> UnicodeSet_SpanCondition::CONDITION_COUNT_() { return get_static_field<SCAPIX_META_STRING("CONDITION_COUNT"), ref<android::icu::text::UnicodeSet_SpanCondition>>(); }
inline ref<link::java::array<android::icu::text::UnicodeSet_SpanCondition>> UnicodeSet_SpanCondition::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::icu::text::UnicodeSet_SpanCondition>>>(); }
inline ref<android::icu::text::UnicodeSet_SpanCondition> UnicodeSet_SpanCondition::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::icu::text::UnicodeSet_SpanCondition>>(name); }

} // namespace android::icu::text
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_TEXT_UNICODESET_SPANCONDITION_H
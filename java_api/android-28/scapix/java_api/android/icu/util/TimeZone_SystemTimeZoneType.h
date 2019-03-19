// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_ICU_UTIL_TIMEZONE_SYSTEMTIMEZONETYPE_H
#define SCAPIX_ANDROID_ICU_UTIL_TIMEZONE_SYSTEMTIMEZONETYPE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::icu::util {

class TimeZone_SystemTimeZoneType : public object_base<SCAPIX_META_STRING("android/icu/util/TimeZone$SystemTimeZoneType"),
	java::lang::Enum>
{
public:

	static ref<android::icu::util::TimeZone_SystemTimeZoneType> ANY_();
	static ref<android::icu::util::TimeZone_SystemTimeZoneType> CANONICAL_();
	static ref<android::icu::util::TimeZone_SystemTimeZoneType> CANONICAL_LOCATION_();

	static ref<link::java::array<android::icu::util::TimeZone_SystemTimeZoneType>> values();
	static ref<android::icu::util::TimeZone_SystemTimeZoneType> valueOf(ref<java::lang::String> name);

protected:

	TimeZone_SystemTimeZoneType(handle_type h) : base_(h) {}

};

} // namespace android::icu::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::icu::util {

inline ref<android::icu::util::TimeZone_SystemTimeZoneType> TimeZone_SystemTimeZoneType::ANY_() { return get_static_field<SCAPIX_META_STRING("ANY"), ref<android::icu::util::TimeZone_SystemTimeZoneType>>(); }
inline ref<android::icu::util::TimeZone_SystemTimeZoneType> TimeZone_SystemTimeZoneType::CANONICAL_() { return get_static_field<SCAPIX_META_STRING("CANONICAL"), ref<android::icu::util::TimeZone_SystemTimeZoneType>>(); }
inline ref<android::icu::util::TimeZone_SystemTimeZoneType> TimeZone_SystemTimeZoneType::CANONICAL_LOCATION_() { return get_static_field<SCAPIX_META_STRING("CANONICAL_LOCATION"), ref<android::icu::util::TimeZone_SystemTimeZoneType>>(); }
inline ref<link::java::array<android::icu::util::TimeZone_SystemTimeZoneType>> TimeZone_SystemTimeZoneType::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::icu::util::TimeZone_SystemTimeZoneType>>>(); }
inline ref<android::icu::util::TimeZone_SystemTimeZoneType> TimeZone_SystemTimeZoneType::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::icu::util::TimeZone_SystemTimeZoneType>>(name); }

} // namespace android::icu::util
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_UTIL_TIMEZONE_SYSTEMTIMEZONETYPE_H
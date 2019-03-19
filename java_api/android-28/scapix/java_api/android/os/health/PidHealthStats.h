// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_OS_HEALTH_PIDHEALTHSTATS_H
#define SCAPIX_ANDROID_OS_HEALTH_PIDHEALTHSTATS_H

namespace scapix::java_api {
namespace android::os::health {

class PidHealthStats : public object_base<SCAPIX_META_STRING("android/os/health/PidHealthStats"),
	java::lang::Object>
{
public:

	static jint MEASUREMENT_WAKE_NESTING_COUNT_();
	static jint MEASUREMENT_WAKE_START_MS_();
	static jint MEASUREMENT_WAKE_SUM_MS_();


protected:

	PidHealthStats(handle_type h) : base_(h) {}

};

} // namespace android::os::health
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::os::health {

inline jint PidHealthStats::MEASUREMENT_WAKE_NESTING_COUNT_() { return get_static_field<SCAPIX_META_STRING("MEASUREMENT_WAKE_NESTING_COUNT"), jint>(); }
inline jint PidHealthStats::MEASUREMENT_WAKE_START_MS_() { return get_static_field<SCAPIX_META_STRING("MEASUREMENT_WAKE_START_MS"), jint>(); }
inline jint PidHealthStats::MEASUREMENT_WAKE_SUM_MS_() { return get_static_field<SCAPIX_META_STRING("MEASUREMENT_WAKE_SUM_MS"), jint>(); }

} // namespace android::os::health
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_HEALTH_PIDHEALTHSTATS_H
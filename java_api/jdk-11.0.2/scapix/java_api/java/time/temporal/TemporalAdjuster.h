// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_TIME_TEMPORAL_TEMPORALADJUSTER_H
#define SCAPIX_JAVA_TIME_TEMPORAL_TEMPORALADJUSTER_H

namespace scapix::java_api {

namespace java::time::temporal { class Temporal; }

namespace java::time::temporal {

class TemporalAdjuster : public object_base<SCAPIX_META_STRING("java/time/temporal/TemporalAdjuster"),
	java::lang::Object>
{
public:

	ref<java::time::temporal::Temporal> adjustInto(ref<java::time::temporal::Temporal> p1);

protected:

	TemporalAdjuster(handle_type h) : base_(h) {}

};

} // namespace java::time::temporal
} // namespace scapix::java_api

#include <scapix/java_api/java/time/temporal/Temporal.h>

namespace scapix::java_api {
namespace java::time::temporal {

inline ref<java::time::temporal::Temporal> TemporalAdjuster::adjustInto(ref<java::time::temporal::Temporal> p1) { return call_method<SCAPIX_META_STRING("adjustInto"), ref<java::time::temporal::Temporal>>(p1); }

} // namespace java::time::temporal
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TIME_TEMPORAL_TEMPORALADJUSTER_H

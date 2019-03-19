// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/function/LongConsumer.h>
#include <scapix/java_api/java/util/function/IntConsumer.h>

#ifndef SCAPIX_JAVA_UTIL_LONGSUMMARYSTATISTICS_H
#define SCAPIX_JAVA_UTIL_LONGSUMMARYSTATISTICS_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::util {

class LongSummaryStatistics : public object_base<SCAPIX_META_STRING("java/util/LongSummaryStatistics"),
	java::lang::Object,
	java::util::function::LongConsumer,
	java::util::function::IntConsumer>
{
public:

	static ref<LongSummaryStatistics> new_object();
	void accept(jint value);
	void accept(jlong value);
	void combine(ref<java::util::LongSummaryStatistics> other);
	jlong getCount();
	jlong getSum();
	jlong getMin();
	jlong getMax();
	jdouble getAverage();
	ref<java::lang::String> toString();

protected:

	LongSummaryStatistics(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::util {

inline ref<LongSummaryStatistics> LongSummaryStatistics::new_object() { return base_::new_object(); }
inline void LongSummaryStatistics::accept(jint value) { return call_method<SCAPIX_META_STRING("accept"), void>(value); }
inline void LongSummaryStatistics::accept(jlong value) { return call_method<SCAPIX_META_STRING("accept"), void>(value); }
inline void LongSummaryStatistics::combine(ref<java::util::LongSummaryStatistics> other) { return call_method<SCAPIX_META_STRING("combine"), void>(other); }
inline jlong LongSummaryStatistics::getCount() { return call_method<SCAPIX_META_STRING("getCount"), jlong>(); }
inline jlong LongSummaryStatistics::getSum() { return call_method<SCAPIX_META_STRING("getSum"), jlong>(); }
inline jlong LongSummaryStatistics::getMin() { return call_method<SCAPIX_META_STRING("getMin"), jlong>(); }
inline jlong LongSummaryStatistics::getMax() { return call_method<SCAPIX_META_STRING("getMax"), jlong>(); }
inline jdouble LongSummaryStatistics::getAverage() { return call_method<SCAPIX_META_STRING("getAverage"), jdouble>(); }
inline ref<java::lang::String> LongSummaryStatistics::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_LONGSUMMARYSTATISTICS_H
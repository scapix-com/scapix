// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_UTIL_CONCURRENT_CYCLICBARRIER_H
#define SCAPIX_JAVA_UTIL_CONCURRENT_CYCLICBARRIER_H

namespace scapix::java_api {

namespace java::lang { class Runnable; }
namespace java::util::concurrent { class TimeUnit; }

namespace java::util::concurrent {

class CyclicBarrier : public object_base<SCAPIX_META_STRING("java/util/concurrent/CyclicBarrier"),
	java::lang::Object>
{
public:

	static ref<CyclicBarrier> new_object(jint parties, ref<java::lang::Runnable> barrierAction);
	static ref<CyclicBarrier> new_object(jint parties);
	jint getParties();
	jint await();
	jint await(jlong timeout, ref<java::util::concurrent::TimeUnit> p2);
	jboolean isBroken();
	void reset();
	jint getNumberWaiting();

protected:

	CyclicBarrier(handle_type h) : base_(h) {}

};

} // namespace java::util::concurrent
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Runnable.h>
#include <scapix/java_api/java/util/concurrent/TimeUnit.h>

namespace scapix::java_api {
namespace java::util::concurrent {

inline ref<CyclicBarrier> CyclicBarrier::new_object(jint parties, ref<java::lang::Runnable> barrierAction) { return base_::new_object(parties, barrierAction); }
inline ref<CyclicBarrier> CyclicBarrier::new_object(jint parties) { return base_::new_object(parties); }
inline jint CyclicBarrier::getParties() { return call_method<SCAPIX_META_STRING("getParties"), jint>(); }
inline jint CyclicBarrier::await() { return call_method<SCAPIX_META_STRING("await"), jint>(); }
inline jint CyclicBarrier::await(jlong timeout, ref<java::util::concurrent::TimeUnit> p2) { return call_method<SCAPIX_META_STRING("await"), jint>(timeout, p2); }
inline jboolean CyclicBarrier::isBroken() { return call_method<SCAPIX_META_STRING("isBroken"), jboolean>(); }
inline void CyclicBarrier::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }
inline jint CyclicBarrier::getNumberWaiting() { return call_method<SCAPIX_META_STRING("getNumberWaiting"), jint>(); }

} // namespace java::util::concurrent
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_CONCURRENT_CYCLICBARRIER_H

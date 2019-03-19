// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/stream/Sink_OfLong.h>

#ifndef SCAPIX_JAVA_UTIL_STREAM_SINK_CHAINEDLONG_H
#define SCAPIX_JAVA_UTIL_STREAM_SINK_CHAINEDLONG_H

namespace scapix::java_api {

namespace java::util::stream { class Sink; }

namespace java::util::stream {

class Sink_ChainedLong : public object_base<SCAPIX_META_STRING("java/util/stream/Sink$ChainedLong"),
	java::lang::Object,
	java::util::stream::Sink_OfLong>
{
public:

	static ref<Sink_ChainedLong> new_object(ref<java::util::stream::Sink> downstream);
	void begin(jlong size);
	void end();
	jboolean cancellationRequested();

protected:

	Sink_ChainedLong(handle_type h) : base_(h) {}

};

} // namespace java::util::stream
} // namespace scapix::java_api

#include <scapix/java_api/java/util/stream/Sink.h>

namespace scapix::java_api {
namespace java::util::stream {

inline ref<Sink_ChainedLong> Sink_ChainedLong::new_object(ref<java::util::stream::Sink> downstream) { return base_::new_object(downstream); }
inline void Sink_ChainedLong::begin(jlong size) { return call_method<SCAPIX_META_STRING("begin"), void>(size); }
inline void Sink_ChainedLong::end() { return call_method<SCAPIX_META_STRING("end"), void>(); }
inline jboolean Sink_ChainedLong::cancellationRequested() { return call_method<SCAPIX_META_STRING("cancellationRequested"), jboolean>(); }

} // namespace java::util::stream
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_STREAM_SINK_CHAINEDLONG_H
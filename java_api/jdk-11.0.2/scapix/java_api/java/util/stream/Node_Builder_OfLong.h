// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/stream/Node_Builder.h>
#include <scapix/java_api/java/util/stream/Sink_OfLong.h>

#ifndef SCAPIX_JAVA_UTIL_STREAM_NODE_BUILDER_OFLONG_H
#define SCAPIX_JAVA_UTIL_STREAM_NODE_BUILDER_OFLONG_H

namespace scapix::java_api {

namespace java::util::stream { class Node_OfLong; }

namespace java::util::stream {

class Node_Builder_OfLong : public object_base<SCAPIX_META_STRING("java/util/stream/Node$Builder$OfLong"),
	java::lang::Object,
	java::util::stream::Node_Builder,
	java::util::stream::Sink_OfLong>
{
public:

	ref<java::util::stream::Node_OfLong> build();

protected:

	Node_Builder_OfLong(handle_type h) : base_(h) {}

};

} // namespace java::util::stream
} // namespace scapix::java_api

#include <scapix/java_api/java/util/stream/Node_OfLong.h>

namespace scapix::java_api {
namespace java::util::stream {

inline ref<java::util::stream::Node_OfLong> Node_Builder_OfLong::build() { return call_method<SCAPIX_META_STRING("build"), ref<java::util::stream::Node_OfLong>>(); }

} // namespace java::util::stream
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_STREAM_NODE_BUILDER_OFLONG_H

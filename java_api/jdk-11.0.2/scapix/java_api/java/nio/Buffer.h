// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_NIO_BUFFER_H
#define SCAPIX_JAVA_NIO_BUFFER_H

namespace scapix::java_api {
namespace java::nio {

class Buffer : public object_base<SCAPIX_META_STRING("java/nio/Buffer"),
	java::lang::Object>
{
public:

	jint capacity();
	jint position();
	ref<java::nio::Buffer> position(jint newPosition);
	jint limit();
	ref<java::nio::Buffer> limit(jint newLimit);
	ref<java::nio::Buffer> mark();
	ref<java::nio::Buffer> reset();
	ref<java::nio::Buffer> clear();
	ref<java::nio::Buffer> flip();
	ref<java::nio::Buffer> rewind();
	jint remaining();
	jboolean hasRemaining();
	jboolean isReadOnly();
	jboolean hasArray();
	ref<java::lang::Object> array();
	jint arrayOffset();
	jboolean isDirect();
	ref<java::nio::Buffer> slice();
	ref<java::nio::Buffer> duplicate();

protected:

	Buffer(handle_type h) : base_(h) {}

};

} // namespace java::nio
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::nio {

inline jint Buffer::capacity() { return call_method<SCAPIX_META_STRING("capacity"), jint>(); }
inline jint Buffer::position() { return call_method<SCAPIX_META_STRING("position"), jint>(); }
inline ref<java::nio::Buffer> Buffer::position(jint newPosition) { return call_method<SCAPIX_META_STRING("position"), ref<java::nio::Buffer>>(newPosition); }
inline jint Buffer::limit() { return call_method<SCAPIX_META_STRING("limit"), jint>(); }
inline ref<java::nio::Buffer> Buffer::limit(jint newLimit) { return call_method<SCAPIX_META_STRING("limit"), ref<java::nio::Buffer>>(newLimit); }
inline ref<java::nio::Buffer> Buffer::mark() { return call_method<SCAPIX_META_STRING("mark"), ref<java::nio::Buffer>>(); }
inline ref<java::nio::Buffer> Buffer::reset() { return call_method<SCAPIX_META_STRING("reset"), ref<java::nio::Buffer>>(); }
inline ref<java::nio::Buffer> Buffer::clear() { return call_method<SCAPIX_META_STRING("clear"), ref<java::nio::Buffer>>(); }
inline ref<java::nio::Buffer> Buffer::flip() { return call_method<SCAPIX_META_STRING("flip"), ref<java::nio::Buffer>>(); }
inline ref<java::nio::Buffer> Buffer::rewind() { return call_method<SCAPIX_META_STRING("rewind"), ref<java::nio::Buffer>>(); }
inline jint Buffer::remaining() { return call_method<SCAPIX_META_STRING("remaining"), jint>(); }
inline jboolean Buffer::hasRemaining() { return call_method<SCAPIX_META_STRING("hasRemaining"), jboolean>(); }
inline jboolean Buffer::isReadOnly() { return call_method<SCAPIX_META_STRING("isReadOnly"), jboolean>(); }
inline jboolean Buffer::hasArray() { return call_method<SCAPIX_META_STRING("hasArray"), jboolean>(); }
inline ref<java::lang::Object> Buffer::array() { return call_method<SCAPIX_META_STRING("array"), ref<java::lang::Object>>(); }
inline jint Buffer::arrayOffset() { return call_method<SCAPIX_META_STRING("arrayOffset"), jint>(); }
inline jboolean Buffer::isDirect() { return call_method<SCAPIX_META_STRING("isDirect"), jboolean>(); }
inline ref<java::nio::Buffer> Buffer::slice() { return call_method<SCAPIX_META_STRING("slice"), ref<java::nio::Buffer>>(); }
inline ref<java::nio::Buffer> Buffer::duplicate() { return call_method<SCAPIX_META_STRING("duplicate"), ref<java::nio::Buffer>>(); }

} // namespace java::nio
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_BUFFER_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/nio/ByteBuffer.h>

#ifndef SCAPIX_JAVA_NIO_HEAPBYTEBUFFER_H
#define SCAPIX_JAVA_NIO_HEAPBYTEBUFFER_H

namespace scapix::java_api {

namespace java::nio { class CharBuffer; }
namespace java::nio { class DoubleBuffer; }
namespace java::nio { class FloatBuffer; }
namespace java::nio { class IntBuffer; }
namespace java::nio { class LongBuffer; }
namespace java::nio { class ShortBuffer; }

namespace java::nio {

// private
class HeapByteBuffer : public object_base<SCAPIX_META_STRING("java/nio/HeapByteBuffer"),
	java::nio::ByteBuffer>
{
public:

	ref<java::nio::ByteBuffer> slice();
	ref<java::nio::ByteBuffer> duplicate();
	ref<java::nio::ByteBuffer> asReadOnlyBuffer();
	jbyte get();
	jbyte get(jint i);
	ref<java::nio::ByteBuffer> get(ref<link::java::array<jbyte>> dst, jint offset, jint length);
	jboolean isDirect();
	jboolean isReadOnly();
	ref<java::nio::ByteBuffer> put(jbyte x);
	ref<java::nio::ByteBuffer> put(jint i, jbyte x);
	ref<java::nio::ByteBuffer> put(ref<link::java::array<jbyte>> src, jint offset, jint length);
	ref<java::nio::ByteBuffer> put(ref<java::nio::ByteBuffer> src);
	ref<java::nio::ByteBuffer> compact();
	jchar getChar();
	jchar getChar(jint i);
	ref<java::nio::ByteBuffer> putChar(jchar x);
	ref<java::nio::ByteBuffer> putChar(jint i, jchar x);
	ref<java::nio::CharBuffer> asCharBuffer();
	jshort getShort();
	jshort getShort(jint i);
	ref<java::nio::ByteBuffer> putShort(jshort x);
	ref<java::nio::ByteBuffer> putShort(jint i, jshort x);
	ref<java::nio::ShortBuffer> asShortBuffer();
	jint getInt();
	jint getInt(jint i);
	ref<java::nio::ByteBuffer> putInt(jint x);
	ref<java::nio::ByteBuffer> putInt(jint i, jint x);
	ref<java::nio::IntBuffer> asIntBuffer();
	jlong getLong();
	jlong getLong(jint i);
	ref<java::nio::ByteBuffer> putLong(jlong x);
	ref<java::nio::ByteBuffer> putLong(jint i, jlong x);
	ref<java::nio::LongBuffer> asLongBuffer();
	jfloat getFloat();
	jfloat getFloat(jint i);
	ref<java::nio::ByteBuffer> putFloat(jfloat x);
	ref<java::nio::ByteBuffer> putFloat(jint i, jfloat x);
	ref<java::nio::FloatBuffer> asFloatBuffer();
	jdouble getDouble();
	jdouble getDouble(jint i);
	ref<java::nio::ByteBuffer> putDouble(jdouble x);
	ref<java::nio::ByteBuffer> putDouble(jint i, jdouble x);
	ref<java::nio::DoubleBuffer> asDoubleBuffer();

protected:

	HeapByteBuffer(handle_type h) : base_(h) {}

};

} // namespace java::nio
} // namespace scapix::java_api

#include <scapix/java_api/java/nio/CharBuffer.h>
#include <scapix/java_api/java/nio/DoubleBuffer.h>
#include <scapix/java_api/java/nio/FloatBuffer.h>
#include <scapix/java_api/java/nio/IntBuffer.h>
#include <scapix/java_api/java/nio/LongBuffer.h>
#include <scapix/java_api/java/nio/ShortBuffer.h>

namespace scapix::java_api {
namespace java::nio {

inline ref<java::nio::ByteBuffer> HeapByteBuffer::slice() { return call_method<SCAPIX_META_STRING("slice"), ref<java::nio::ByteBuffer>>(); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::duplicate() { return call_method<SCAPIX_META_STRING("duplicate"), ref<java::nio::ByteBuffer>>(); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::asReadOnlyBuffer() { return call_method<SCAPIX_META_STRING("asReadOnlyBuffer"), ref<java::nio::ByteBuffer>>(); }
inline jbyte HeapByteBuffer::get() { return call_method<SCAPIX_META_STRING("get"), jbyte>(); }
inline jbyte HeapByteBuffer::get(jint i) { return call_method<SCAPIX_META_STRING("get"), jbyte>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::get(ref<link::java::array<jbyte>> dst, jint offset, jint length) { return call_method<SCAPIX_META_STRING("get"), ref<java::nio::ByteBuffer>>(dst, offset, length); }
inline jboolean HeapByteBuffer::isDirect() { return call_method<SCAPIX_META_STRING("isDirect"), jboolean>(); }
inline jboolean HeapByteBuffer::isReadOnly() { return call_method<SCAPIX_META_STRING("isReadOnly"), jboolean>(); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::put(jbyte x) { return call_method<SCAPIX_META_STRING("put"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::put(jint i, jbyte x) { return call_method<SCAPIX_META_STRING("put"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::put(ref<link::java::array<jbyte>> src, jint offset, jint length) { return call_method<SCAPIX_META_STRING("put"), ref<java::nio::ByteBuffer>>(src, offset, length); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::put(ref<java::nio::ByteBuffer> src) { return call_method<SCAPIX_META_STRING("put"), ref<java::nio::ByteBuffer>>(src); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::compact() { return call_method<SCAPIX_META_STRING("compact"), ref<java::nio::ByteBuffer>>(); }
inline jchar HeapByteBuffer::getChar() { return call_method<SCAPIX_META_STRING("getChar"), jchar>(); }
inline jchar HeapByteBuffer::getChar(jint i) { return call_method<SCAPIX_META_STRING("getChar"), jchar>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putChar(jchar x) { return call_method<SCAPIX_META_STRING("putChar"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putChar(jint i, jchar x) { return call_method<SCAPIX_META_STRING("putChar"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::CharBuffer> HeapByteBuffer::asCharBuffer() { return call_method<SCAPIX_META_STRING("asCharBuffer"), ref<java::nio::CharBuffer>>(); }
inline jshort HeapByteBuffer::getShort() { return call_method<SCAPIX_META_STRING("getShort"), jshort>(); }
inline jshort HeapByteBuffer::getShort(jint i) { return call_method<SCAPIX_META_STRING("getShort"), jshort>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putShort(jshort x) { return call_method<SCAPIX_META_STRING("putShort"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putShort(jint i, jshort x) { return call_method<SCAPIX_META_STRING("putShort"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::ShortBuffer> HeapByteBuffer::asShortBuffer() { return call_method<SCAPIX_META_STRING("asShortBuffer"), ref<java::nio::ShortBuffer>>(); }
inline jint HeapByteBuffer::getInt() { return call_method<SCAPIX_META_STRING("getInt"), jint>(); }
inline jint HeapByteBuffer::getInt(jint i) { return call_method<SCAPIX_META_STRING("getInt"), jint>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putInt(jint x) { return call_method<SCAPIX_META_STRING("putInt"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putInt(jint i, jint x) { return call_method<SCAPIX_META_STRING("putInt"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::IntBuffer> HeapByteBuffer::asIntBuffer() { return call_method<SCAPIX_META_STRING("asIntBuffer"), ref<java::nio::IntBuffer>>(); }
inline jlong HeapByteBuffer::getLong() { return call_method<SCAPIX_META_STRING("getLong"), jlong>(); }
inline jlong HeapByteBuffer::getLong(jint i) { return call_method<SCAPIX_META_STRING("getLong"), jlong>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putLong(jlong x) { return call_method<SCAPIX_META_STRING("putLong"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putLong(jint i, jlong x) { return call_method<SCAPIX_META_STRING("putLong"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::LongBuffer> HeapByteBuffer::asLongBuffer() { return call_method<SCAPIX_META_STRING("asLongBuffer"), ref<java::nio::LongBuffer>>(); }
inline jfloat HeapByteBuffer::getFloat() { return call_method<SCAPIX_META_STRING("getFloat"), jfloat>(); }
inline jfloat HeapByteBuffer::getFloat(jint i) { return call_method<SCAPIX_META_STRING("getFloat"), jfloat>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putFloat(jfloat x) { return call_method<SCAPIX_META_STRING("putFloat"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putFloat(jint i, jfloat x) { return call_method<SCAPIX_META_STRING("putFloat"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::FloatBuffer> HeapByteBuffer::asFloatBuffer() { return call_method<SCAPIX_META_STRING("asFloatBuffer"), ref<java::nio::FloatBuffer>>(); }
inline jdouble HeapByteBuffer::getDouble() { return call_method<SCAPIX_META_STRING("getDouble"), jdouble>(); }
inline jdouble HeapByteBuffer::getDouble(jint i) { return call_method<SCAPIX_META_STRING("getDouble"), jdouble>(i); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putDouble(jdouble x) { return call_method<SCAPIX_META_STRING("putDouble"), ref<java::nio::ByteBuffer>>(x); }
inline ref<java::nio::ByteBuffer> HeapByteBuffer::putDouble(jint i, jdouble x) { return call_method<SCAPIX_META_STRING("putDouble"), ref<java::nio::ByteBuffer>>(i, x); }
inline ref<java::nio::DoubleBuffer> HeapByteBuffer::asDoubleBuffer() { return call_method<SCAPIX_META_STRING("asDoubleBuffer"), ref<java::nio::DoubleBuffer>>(); }

} // namespace java::nio
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_HEAPBYTEBUFFER_H
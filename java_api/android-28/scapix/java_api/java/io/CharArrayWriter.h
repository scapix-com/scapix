// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/Writer.h>

#ifndef SCAPIX_JAVA_IO_CHARARRAYWRITER_H
#define SCAPIX_JAVA_IO_CHARARRAYWRITER_H

namespace scapix::java_api {

namespace java::lang { class CharSequence; }
namespace java::lang { class String; }

namespace java::io {

class CharArrayWriter : public object_base<SCAPIX_META_STRING("java/io/CharArrayWriter"),
	java::io::Writer>
{
public:

	static ref<CharArrayWriter> new_object();
	static ref<CharArrayWriter> new_object(jint initialSize);
	void write(jint c);
	void write(ref<link::java::array<jchar>> c, jint off, jint len);
	void write(ref<java::lang::String> str, jint off, jint len);
	void writeTo(ref<java::io::Writer> out);
	ref<java::io::CharArrayWriter> append(ref<java::lang::CharSequence> csq);
	ref<java::io::CharArrayWriter> append(ref<java::lang::CharSequence> csq, jint start, jint end);
	ref<java::io::CharArrayWriter> append(jchar c);
	void reset();
	ref<link::java::array<jchar>> toCharArray();
	jint size();
	ref<java::lang::String> toString();
	void flush();
	void close();

protected:

	CharArrayWriter(handle_type h) : base_(h) {}

};

} // namespace java::io
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::io {

inline ref<CharArrayWriter> CharArrayWriter::new_object() { return base_::new_object(); }
inline ref<CharArrayWriter> CharArrayWriter::new_object(jint initialSize) { return base_::new_object(initialSize); }
inline void CharArrayWriter::write(jint c) { return call_method<SCAPIX_META_STRING("write"), void>(c); }
inline void CharArrayWriter::write(ref<link::java::array<jchar>> c, jint off, jint len) { return call_method<SCAPIX_META_STRING("write"), void>(c, off, len); }
inline void CharArrayWriter::write(ref<java::lang::String> str, jint off, jint len) { return call_method<SCAPIX_META_STRING("write"), void>(str, off, len); }
inline void CharArrayWriter::writeTo(ref<java::io::Writer> out) { return call_method<SCAPIX_META_STRING("writeTo"), void>(out); }
inline ref<java::io::CharArrayWriter> CharArrayWriter::append(ref<java::lang::CharSequence> csq) { return call_method<SCAPIX_META_STRING("append"), ref<java::io::CharArrayWriter>>(csq); }
inline ref<java::io::CharArrayWriter> CharArrayWriter::append(ref<java::lang::CharSequence> csq, jint start, jint end) { return call_method<SCAPIX_META_STRING("append"), ref<java::io::CharArrayWriter>>(csq, start, end); }
inline ref<java::io::CharArrayWriter> CharArrayWriter::append(jchar c) { return call_method<SCAPIX_META_STRING("append"), ref<java::io::CharArrayWriter>>(c); }
inline void CharArrayWriter::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }
inline ref<link::java::array<jchar>> CharArrayWriter::toCharArray() { return call_method<SCAPIX_META_STRING("toCharArray"), ref<link::java::array<jchar>>>(); }
inline jint CharArrayWriter::size() { return call_method<SCAPIX_META_STRING("size"), jint>(); }
inline ref<java::lang::String> CharArrayWriter::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline void CharArrayWriter::flush() { return call_method<SCAPIX_META_STRING("flush"), void>(); }
inline void CharArrayWriter::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }

} // namespace java::io
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_IO_CHARARRAYWRITER_H
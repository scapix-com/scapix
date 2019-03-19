// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/FilterInputStream.h>

#ifndef SCAPIX_JAVA_IO_LINENUMBERINPUTSTREAM_H
#define SCAPIX_JAVA_IO_LINENUMBERINPUTSTREAM_H

namespace scapix::java_api {

namespace java::io { class InputStream; }

namespace java::io {

class LineNumberInputStream : public object_base<SCAPIX_META_STRING("java/io/LineNumberInputStream"),
	java::io::FilterInputStream>
{
public:

	static ref<LineNumberInputStream> new_object(ref<java::io::InputStream> in);
	jint read();
	jint read(ref<link::java::array<jbyte>> b, jint off, jint len);
	jlong skip(jlong n);
	void setLineNumber(jint lineNumber);
	jint getLineNumber();
	jint available();
	void mark(jint readlimit);
	void reset();

protected:

	LineNumberInputStream(handle_type h) : base_(h) {}

};

} // namespace java::io
} // namespace scapix::java_api

#include <scapix/java_api/java/io/InputStream.h>

namespace scapix::java_api {
namespace java::io {

inline ref<LineNumberInputStream> LineNumberInputStream::new_object(ref<java::io::InputStream> in) { return base_::new_object(in); }
inline jint LineNumberInputStream::read() { return call_method<SCAPIX_META_STRING("read"), jint>(); }
inline jint LineNumberInputStream::read(ref<link::java::array<jbyte>> b, jint off, jint len) { return call_method<SCAPIX_META_STRING("read"), jint>(b, off, len); }
inline jlong LineNumberInputStream::skip(jlong n) { return call_method<SCAPIX_META_STRING("skip"), jlong>(n); }
inline void LineNumberInputStream::setLineNumber(jint lineNumber) { return call_method<SCAPIX_META_STRING("setLineNumber"), void>(lineNumber); }
inline jint LineNumberInputStream::getLineNumber() { return call_method<SCAPIX_META_STRING("getLineNumber"), jint>(); }
inline jint LineNumberInputStream::available() { return call_method<SCAPIX_META_STRING("available"), jint>(); }
inline void LineNumberInputStream::mark(jint readlimit) { return call_method<SCAPIX_META_STRING("mark"), void>(readlimit); }
inline void LineNumberInputStream::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }

} // namespace java::io
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_IO_LINENUMBERINPUTSTREAM_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/OutputStream.h>

#ifndef SCAPIX_JAVA_IO_FILTEROUTPUTSTREAM_H
#define SCAPIX_JAVA_IO_FILTEROUTPUTSTREAM_H

namespace scapix::java_api {
namespace java::io {

class FilterOutputStream : public object_base<SCAPIX_META_STRING("java/io/FilterOutputStream"),
	java::io::OutputStream>
{
public:

	static ref<FilterOutputStream> new_object(ref<java::io::OutputStream> out);
	void write(jint b);
	void write(ref<link::java::array<jbyte>> b);
	void write(ref<link::java::array<jbyte>> b, jint off, jint len);
	void flush();
	void close();

protected:

	FilterOutputStream(handle_type h) : base_(h) {}

};

} // namespace java::io
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::io {

inline ref<FilterOutputStream> FilterOutputStream::new_object(ref<java::io::OutputStream> out) { return base_::new_object(out); }
inline void FilterOutputStream::write(jint b) { return call_method<SCAPIX_META_STRING("write"), void>(b); }
inline void FilterOutputStream::write(ref<link::java::array<jbyte>> b) { return call_method<SCAPIX_META_STRING("write"), void>(b); }
inline void FilterOutputStream::write(ref<link::java::array<jbyte>> b, jint off, jint len) { return call_method<SCAPIX_META_STRING("write"), void>(b, off, len); }
inline void FilterOutputStream::flush() { return call_method<SCAPIX_META_STRING("flush"), void>(); }
inline void FilterOutputStream::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }

} // namespace java::io
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_IO_FILTEROUTPUTSTREAM_H
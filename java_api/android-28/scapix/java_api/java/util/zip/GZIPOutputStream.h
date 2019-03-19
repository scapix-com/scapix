// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/zip/DeflaterOutputStream.h>

#ifndef SCAPIX_JAVA_UTIL_ZIP_GZIPOUTPUTSTREAM_H
#define SCAPIX_JAVA_UTIL_ZIP_GZIPOUTPUTSTREAM_H

namespace scapix::java_api {

namespace java::io { class OutputStream; }

namespace java::util::zip {

class GZIPOutputStream : public object_base<SCAPIX_META_STRING("java/util/zip/GZIPOutputStream"),
	java::util::zip::DeflaterOutputStream>
{
public:

	static ref<GZIPOutputStream> new_object(ref<java::io::OutputStream> out, jint size);
	static ref<GZIPOutputStream> new_object(ref<java::io::OutputStream> out, jint size, jboolean syncFlush);
	static ref<GZIPOutputStream> new_object(ref<java::io::OutputStream> out);
	static ref<GZIPOutputStream> new_object(ref<java::io::OutputStream> out, jboolean syncFlush);
	void write(ref<link::java::array<jbyte>> buf, jint off, jint len);
	void finish();

protected:

	GZIPOutputStream(handle_type h) : base_(h) {}

};

} // namespace java::util::zip
} // namespace scapix::java_api

#include <scapix/java_api/java/io/OutputStream.h>

namespace scapix::java_api {
namespace java::util::zip {

inline ref<GZIPOutputStream> GZIPOutputStream::new_object(ref<java::io::OutputStream> out, jint size) { return base_::new_object(out, size); }
inline ref<GZIPOutputStream> GZIPOutputStream::new_object(ref<java::io::OutputStream> out, jint size, jboolean syncFlush) { return base_::new_object(out, size, syncFlush); }
inline ref<GZIPOutputStream> GZIPOutputStream::new_object(ref<java::io::OutputStream> out) { return base_::new_object(out); }
inline ref<GZIPOutputStream> GZIPOutputStream::new_object(ref<java::io::OutputStream> out, jboolean syncFlush) { return base_::new_object(out, syncFlush); }
inline void GZIPOutputStream::write(ref<link::java::array<jbyte>> buf, jint off, jint len) { return call_method<SCAPIX_META_STRING("write"), void>(buf, off, len); }
inline void GZIPOutputStream::finish() { return call_method<SCAPIX_META_STRING("finish"), void>(); }

} // namespace java::util::zip
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_ZIP_GZIPOUTPUTSTREAM_H
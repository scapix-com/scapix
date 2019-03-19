// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/FilterInputStream.h>

#ifndef SCAPIX_JAVA_UTIL_ZIP_CHECKEDINPUTSTREAM_H
#define SCAPIX_JAVA_UTIL_ZIP_CHECKEDINPUTSTREAM_H

namespace scapix::java_api {

namespace java::io { class InputStream; }
namespace java::util::zip { class Checksum; }

namespace java::util::zip {

class CheckedInputStream : public object_base<SCAPIX_META_STRING("java/util/zip/CheckedInputStream"),
	java::io::FilterInputStream>
{
public:

	static ref<CheckedInputStream> new_object(ref<java::io::InputStream> in, ref<java::util::zip::Checksum> cksum);
	jint read();
	jint read(ref<link::java::array<jbyte>> buf, jint off, jint len);
	jlong skip(jlong n);
	ref<java::util::zip::Checksum> getChecksum();

protected:

	CheckedInputStream(handle_type h) : base_(h) {}

};

} // namespace java::util::zip
} // namespace scapix::java_api

#include <scapix/java_api/java/io/InputStream.h>
#include <scapix/java_api/java/util/zip/Checksum.h>

namespace scapix::java_api {
namespace java::util::zip {

inline ref<CheckedInputStream> CheckedInputStream::new_object(ref<java::io::InputStream> in, ref<java::util::zip::Checksum> cksum) { return base_::new_object(in, cksum); }
inline jint CheckedInputStream::read() { return call_method<SCAPIX_META_STRING("read"), jint>(); }
inline jint CheckedInputStream::read(ref<link::java::array<jbyte>> buf, jint off, jint len) { return call_method<SCAPIX_META_STRING("read"), jint>(buf, off, len); }
inline jlong CheckedInputStream::skip(jlong n) { return call_method<SCAPIX_META_STRING("skip"), jlong>(n); }
inline ref<java::util::zip::Checksum> CheckedInputStream::getChecksum() { return call_method<SCAPIX_META_STRING("getChecksum"), ref<java::util::zip::Checksum>>(); }

} // namespace java::util::zip
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_ZIP_CHECKEDINPUTSTREAM_H
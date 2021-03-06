// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_UTIL_ZIP_DEFLATER_H
#define SCAPIX_JAVA_UTIL_ZIP_DEFLATER_H

namespace scapix::java_api {

namespace java::nio { class ByteBuffer; }

namespace java::util::zip {

class Deflater : public object_base<SCAPIX_META_STRING("java/util/zip/Deflater"),
	java::lang::Object>
{
public:

	static jint DEFLATED_();
	static jint NO_COMPRESSION_();
	static jint BEST_SPEED_();
	static jint BEST_COMPRESSION_();
	static jint DEFAULT_COMPRESSION_();
	static jint FILTERED_();
	static jint HUFFMAN_ONLY_();
	static jint DEFAULT_STRATEGY_();
	static jint NO_FLUSH_();
	static jint SYNC_FLUSH_();
	static jint FULL_FLUSH_();

	static ref<Deflater> new_object(jint level, jboolean nowrap);
	static ref<Deflater> new_object(jint level);
	static ref<Deflater> new_object();
	void setInput(ref<link::java::array<jbyte>> input, jint off, jint len);
	void setInput(ref<link::java::array<jbyte>> input);
	void setInput(ref<java::nio::ByteBuffer> input);
	void setDictionary(ref<link::java::array<jbyte>> dictionary, jint off, jint len);
	void setDictionary(ref<link::java::array<jbyte>> dictionary);
	void setDictionary(ref<java::nio::ByteBuffer> dictionary);
	void setStrategy(jint strategy);
	void setLevel(jint level);
	jboolean needsInput();
	void finish();
	jboolean finished();
	jint deflate(ref<link::java::array<jbyte>> output, jint off, jint len);
	jint deflate(ref<link::java::array<jbyte>> output);
	jint deflate(ref<java::nio::ByteBuffer> output);
	jint deflate(ref<link::java::array<jbyte>> output, jint off, jint len, jint flush);
	jint deflate(ref<java::nio::ByteBuffer> output, jint flush);
	jint getAdler();
	jint getTotalIn();
	jlong getBytesRead();
	jint getTotalOut();
	jlong getBytesWritten();
	void reset();
	void end();

protected:

	Deflater(handle_type h) : base_(h) {}

};

} // namespace java::util::zip
} // namespace scapix::java_api

#include <scapix/java_api/java/nio/ByteBuffer.h>

namespace scapix::java_api {
namespace java::util::zip {

inline jint Deflater::DEFLATED_() { return get_static_field<SCAPIX_META_STRING("DEFLATED"), jint>(); }
inline jint Deflater::NO_COMPRESSION_() { return get_static_field<SCAPIX_META_STRING("NO_COMPRESSION"), jint>(); }
inline jint Deflater::BEST_SPEED_() { return get_static_field<SCAPIX_META_STRING("BEST_SPEED"), jint>(); }
inline jint Deflater::BEST_COMPRESSION_() { return get_static_field<SCAPIX_META_STRING("BEST_COMPRESSION"), jint>(); }
inline jint Deflater::DEFAULT_COMPRESSION_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_COMPRESSION"), jint>(); }
inline jint Deflater::FILTERED_() { return get_static_field<SCAPIX_META_STRING("FILTERED"), jint>(); }
inline jint Deflater::HUFFMAN_ONLY_() { return get_static_field<SCAPIX_META_STRING("HUFFMAN_ONLY"), jint>(); }
inline jint Deflater::DEFAULT_STRATEGY_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_STRATEGY"), jint>(); }
inline jint Deflater::NO_FLUSH_() { return get_static_field<SCAPIX_META_STRING("NO_FLUSH"), jint>(); }
inline jint Deflater::SYNC_FLUSH_() { return get_static_field<SCAPIX_META_STRING("SYNC_FLUSH"), jint>(); }
inline jint Deflater::FULL_FLUSH_() { return get_static_field<SCAPIX_META_STRING("FULL_FLUSH"), jint>(); }
inline ref<Deflater> Deflater::new_object(jint level, jboolean nowrap) { return base_::new_object(level, nowrap); }
inline ref<Deflater> Deflater::new_object(jint level) { return base_::new_object(level); }
inline ref<Deflater> Deflater::new_object() { return base_::new_object(); }
inline void Deflater::setInput(ref<link::java::array<jbyte>> input, jint off, jint len) { return call_method<SCAPIX_META_STRING("setInput"), void>(input, off, len); }
inline void Deflater::setInput(ref<link::java::array<jbyte>> input) { return call_method<SCAPIX_META_STRING("setInput"), void>(input); }
inline void Deflater::setInput(ref<java::nio::ByteBuffer> input) { return call_method<SCAPIX_META_STRING("setInput"), void>(input); }
inline void Deflater::setDictionary(ref<link::java::array<jbyte>> dictionary, jint off, jint len) { return call_method<SCAPIX_META_STRING("setDictionary"), void>(dictionary, off, len); }
inline void Deflater::setDictionary(ref<link::java::array<jbyte>> dictionary) { return call_method<SCAPIX_META_STRING("setDictionary"), void>(dictionary); }
inline void Deflater::setDictionary(ref<java::nio::ByteBuffer> dictionary) { return call_method<SCAPIX_META_STRING("setDictionary"), void>(dictionary); }
inline void Deflater::setStrategy(jint strategy) { return call_method<SCAPIX_META_STRING("setStrategy"), void>(strategy); }
inline void Deflater::setLevel(jint level) { return call_method<SCAPIX_META_STRING("setLevel"), void>(level); }
inline jboolean Deflater::needsInput() { return call_method<SCAPIX_META_STRING("needsInput"), jboolean>(); }
inline void Deflater::finish() { return call_method<SCAPIX_META_STRING("finish"), void>(); }
inline jboolean Deflater::finished() { return call_method<SCAPIX_META_STRING("finished"), jboolean>(); }
inline jint Deflater::deflate(ref<link::java::array<jbyte>> output, jint off, jint len) { return call_method<SCAPIX_META_STRING("deflate"), jint>(output, off, len); }
inline jint Deflater::deflate(ref<link::java::array<jbyte>> output) { return call_method<SCAPIX_META_STRING("deflate"), jint>(output); }
inline jint Deflater::deflate(ref<java::nio::ByteBuffer> output) { return call_method<SCAPIX_META_STRING("deflate"), jint>(output); }
inline jint Deflater::deflate(ref<link::java::array<jbyte>> output, jint off, jint len, jint flush) { return call_method<SCAPIX_META_STRING("deflate"), jint>(output, off, len, flush); }
inline jint Deflater::deflate(ref<java::nio::ByteBuffer> output, jint flush) { return call_method<SCAPIX_META_STRING("deflate"), jint>(output, flush); }
inline jint Deflater::getAdler() { return call_method<SCAPIX_META_STRING("getAdler"), jint>(); }
inline jint Deflater::getTotalIn() { return call_method<SCAPIX_META_STRING("getTotalIn"), jint>(); }
inline jlong Deflater::getBytesRead() { return call_method<SCAPIX_META_STRING("getBytesRead"), jlong>(); }
inline jint Deflater::getTotalOut() { return call_method<SCAPIX_META_STRING("getTotalOut"), jint>(); }
inline jlong Deflater::getBytesWritten() { return call_method<SCAPIX_META_STRING("getBytesWritten"), jlong>(); }
inline void Deflater::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }
inline void Deflater::end() { return call_method<SCAPIX_META_STRING("end"), void>(); }

} // namespace java::util::zip
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_ZIP_DEFLATER_H

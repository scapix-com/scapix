// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_OPENGL_ETC1_H
#define SCAPIX_ANDROID_OPENGL_ETC1_H

namespace scapix::java_api {

namespace java::nio { class Buffer; }

namespace android::opengl {

class ETC1 : public object_base<SCAPIX_META_STRING("android/opengl/ETC1"),
	java::lang::Object>
{
public:

	static jint DECODED_BLOCK_SIZE_();
	static jint ENCODED_BLOCK_SIZE_();
	static jint ETC1_RGB8_OES_();
	static jint ETC_PKM_HEADER_SIZE_();

	static ref<ETC1> new_object();
	static void encodeBlock(ref<java::nio::Buffer> p1, jint p2, ref<java::nio::Buffer> p3);
	static void decodeBlock(ref<java::nio::Buffer> p1, ref<java::nio::Buffer> p2);
	static jint getEncodedDataSize(jint p1, jint p2);
	static void encodeImage(ref<java::nio::Buffer> p1, jint p2, jint p3, jint p4, jint p5, ref<java::nio::Buffer> p6);
	static void decodeImage(ref<java::nio::Buffer> p1, ref<java::nio::Buffer> p2, jint p3, jint p4, jint p5, jint p6);
	static void formatHeader(ref<java::nio::Buffer> p1, jint p2, jint p3);
	static jboolean isValid(ref<java::nio::Buffer> p1);
	static jint getWidth(ref<java::nio::Buffer> p1);
	static jint getHeight(ref<java::nio::Buffer> p1);

protected:

	ETC1(handle_type h) : base_(h) {}

};

} // namespace android::opengl
} // namespace scapix::java_api

#include <scapix/java_api/java/nio/Buffer.h>

namespace scapix::java_api {
namespace android::opengl {

inline jint ETC1::DECODED_BLOCK_SIZE_() { return get_static_field<SCAPIX_META_STRING("DECODED_BLOCK_SIZE"), jint>(); }
inline jint ETC1::ENCODED_BLOCK_SIZE_() { return get_static_field<SCAPIX_META_STRING("ENCODED_BLOCK_SIZE"), jint>(); }
inline jint ETC1::ETC1_RGB8_OES_() { return get_static_field<SCAPIX_META_STRING("ETC1_RGB8_OES"), jint>(); }
inline jint ETC1::ETC_PKM_HEADER_SIZE_() { return get_static_field<SCAPIX_META_STRING("ETC_PKM_HEADER_SIZE"), jint>(); }
inline ref<ETC1> ETC1::new_object() { return base_::new_object(); }
inline void ETC1::encodeBlock(ref<java::nio::Buffer> p1, jint p2, ref<java::nio::Buffer> p3) { return call_static_method<SCAPIX_META_STRING("encodeBlock"), void>(p1, p2, p3); }
inline void ETC1::decodeBlock(ref<java::nio::Buffer> p1, ref<java::nio::Buffer> p2) { return call_static_method<SCAPIX_META_STRING("decodeBlock"), void>(p1, p2); }
inline jint ETC1::getEncodedDataSize(jint p1, jint p2) { return call_static_method<SCAPIX_META_STRING("getEncodedDataSize"), jint>(p1, p2); }
inline void ETC1::encodeImage(ref<java::nio::Buffer> p1, jint p2, jint p3, jint p4, jint p5, ref<java::nio::Buffer> p6) { return call_static_method<SCAPIX_META_STRING("encodeImage"), void>(p1, p2, p3, p4, p5, p6); }
inline void ETC1::decodeImage(ref<java::nio::Buffer> p1, ref<java::nio::Buffer> p2, jint p3, jint p4, jint p5, jint p6) { return call_static_method<SCAPIX_META_STRING("decodeImage"), void>(p1, p2, p3, p4, p5, p6); }
inline void ETC1::formatHeader(ref<java::nio::Buffer> p1, jint p2, jint p3) { return call_static_method<SCAPIX_META_STRING("formatHeader"), void>(p1, p2, p3); }
inline jboolean ETC1::isValid(ref<java::nio::Buffer> p1) { return call_static_method<SCAPIX_META_STRING("isValid"), jboolean>(p1); }
inline jint ETC1::getWidth(ref<java::nio::Buffer> p1) { return call_static_method<SCAPIX_META_STRING("getWidth"), jint>(p1); }
inline jint ETC1::getHeight(ref<java::nio::Buffer> p1) { return call_static_method<SCAPIX_META_STRING("getHeight"), jint>(p1); }

} // namespace android::opengl
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OPENGL_ETC1_H

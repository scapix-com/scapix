// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_MEDIACODECLIST_H
#define SCAPIX_ANDROID_MEDIA_MEDIACODECLIST_H

namespace scapix::java_api {

namespace android::media { class MediaCodecInfo; }
namespace android::media { class MediaFormat; }
namespace java::lang { class String; }

namespace android::media {

class MediaCodecList : public object_base<SCAPIX_META_STRING("android/media/MediaCodecList"),
	java::lang::Object>
{
public:

	static jint ALL_CODECS_();
	static jint REGULAR_CODECS_();

	static ref<MediaCodecList> new_object(jint kind);
	static jint getCodecCount();
	static ref<android::media::MediaCodecInfo> getCodecInfoAt(jint index);
	ref<link::java::array<android::media::MediaCodecInfo>> getCodecInfos();
	ref<java::lang::String> findDecoderForFormat(ref<android::media::MediaFormat> format);
	ref<java::lang::String> findEncoderForFormat(ref<android::media::MediaFormat> format);

protected:

	MediaCodecList(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/MediaCodecInfo.h>
#include <scapix/java_api/android/media/MediaFormat.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::media {

inline jint MediaCodecList::ALL_CODECS_() { return get_static_field<SCAPIX_META_STRING("ALL_CODECS"), jint>(); }
inline jint MediaCodecList::REGULAR_CODECS_() { return get_static_field<SCAPIX_META_STRING("REGULAR_CODECS"), jint>(); }
inline ref<MediaCodecList> MediaCodecList::new_object(jint kind) { return base_::new_object(kind); }
inline jint MediaCodecList::getCodecCount() { return call_static_method<SCAPIX_META_STRING("getCodecCount"), jint>(); }
inline ref<android::media::MediaCodecInfo> MediaCodecList::getCodecInfoAt(jint index) { return call_static_method<SCAPIX_META_STRING("getCodecInfoAt"), ref<android::media::MediaCodecInfo>>(index); }
inline ref<link::java::array<android::media::MediaCodecInfo>> MediaCodecList::getCodecInfos() { return call_method<SCAPIX_META_STRING("getCodecInfos"), ref<link::java::array<android::media::MediaCodecInfo>>>(); }
inline ref<java::lang::String> MediaCodecList::findDecoderForFormat(ref<android::media::MediaFormat> format) { return call_method<SCAPIX_META_STRING("findDecoderForFormat"), ref<java::lang::String>>(format); }
inline ref<java::lang::String> MediaCodecList::findEncoderForFormat(ref<android::media::MediaFormat> format) { return call_method<SCAPIX_META_STRING("findEncoderForFormat"), ref<java::lang::String>>(format); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_MEDIACODECLIST_H
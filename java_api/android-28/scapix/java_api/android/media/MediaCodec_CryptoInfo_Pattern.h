// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_MEDIACODEC_CRYPTOINFO_PATTERN_H
#define SCAPIX_ANDROID_MEDIA_MEDIACODEC_CRYPTOINFO_PATTERN_H

namespace scapix::java_api {


namespace android::media {

class MediaCodec_CryptoInfo_Pattern : public object_base<SCAPIX_META_STRING("android/media/MediaCodec$CryptoInfo$Pattern"),
	java::lang::Object>
{
public:

	static ref<MediaCodec_CryptoInfo_Pattern> new_object(jint blocksToEncrypt, jint blocksToSkip);
	void set(jint blocksToEncrypt, jint blocksToSkip);
	jint getSkipBlocks();
	jint getEncryptBlocks();

protected:

	MediaCodec_CryptoInfo_Pattern(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::media {

inline ref<MediaCodec_CryptoInfo_Pattern> MediaCodec_CryptoInfo_Pattern::new_object(jint blocksToEncrypt, jint blocksToSkip) { return base_::new_object(blocksToEncrypt, blocksToSkip); }
inline void MediaCodec_CryptoInfo_Pattern::set(jint blocksToEncrypt, jint blocksToSkip) { return call_method<SCAPIX_META_STRING("set"), void>(blocksToEncrypt, blocksToSkip); }
inline jint MediaCodec_CryptoInfo_Pattern::getSkipBlocks() { return call_method<SCAPIX_META_STRING("getSkipBlocks"), jint>(); }
inline jint MediaCodec_CryptoInfo_Pattern::getEncryptBlocks() { return call_method<SCAPIX_META_STRING("getEncryptBlocks"), jint>(); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_MEDIACODEC_CRYPTOINFO_PATTERN_H
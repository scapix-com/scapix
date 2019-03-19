// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/provider/MediaStore_Audio_AudioColumns.h>

#ifndef SCAPIX_ANDROID_PROVIDER_MEDIASTORE_AUDIO_GENRES_MEMBERS_H
#define SCAPIX_ANDROID_PROVIDER_MEDIASTORE_AUDIO_GENRES_MEMBERS_H

namespace scapix::java_api {

namespace android::net { class Uri; }
namespace java::lang { class String; }

namespace android::provider {

class MediaStore_Audio_Genres_Members : public object_base<SCAPIX_META_STRING("android/provider/MediaStore$Audio$Genres$Members"),
	java::lang::Object,
	android::provider::MediaStore_Audio_AudioColumns>
{
public:

	static ref<java::lang::String> AUDIO_ID_();
	static ref<java::lang::String> CONTENT_DIRECTORY_();
	static ref<java::lang::String> DEFAULT_SORT_ORDER_();
	static ref<java::lang::String> GENRE_ID_();

	static ref<MediaStore_Audio_Genres_Members> new_object();
	static ref<android::net::Uri> getContentUri(ref<java::lang::String> volumeName, jlong genreId);

protected:

	MediaStore_Audio_Genres_Members(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<java::lang::String> MediaStore_Audio_Genres_Members::AUDIO_ID_() { return get_static_field<SCAPIX_META_STRING("AUDIO_ID"), ref<java::lang::String>>(); }
inline ref<java::lang::String> MediaStore_Audio_Genres_Members::CONTENT_DIRECTORY_() { return get_static_field<SCAPIX_META_STRING("CONTENT_DIRECTORY"), ref<java::lang::String>>(); }
inline ref<java::lang::String> MediaStore_Audio_Genres_Members::DEFAULT_SORT_ORDER_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_SORT_ORDER"), ref<java::lang::String>>(); }
inline ref<java::lang::String> MediaStore_Audio_Genres_Members::GENRE_ID_() { return get_static_field<SCAPIX_META_STRING("GENRE_ID"), ref<java::lang::String>>(); }
inline ref<MediaStore_Audio_Genres_Members> MediaStore_Audio_Genres_Members::new_object() { return base_::new_object(); }
inline ref<android::net::Uri> MediaStore_Audio_Genres_Members::getContentUri(ref<java::lang::String> volumeName, jlong genreId) { return call_static_method<SCAPIX_META_STRING("getContentUri"), ref<android::net::Uri>>(volumeName, genreId); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_MEDIASTORE_AUDIO_GENRES_MEMBERS_H
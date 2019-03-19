// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/provider/MediaStore_Images_ImageColumns.h>

#ifndef SCAPIX_ANDROID_PROVIDER_MEDIASTORE_IMAGES_MEDIA_H
#define SCAPIX_ANDROID_PROVIDER_MEDIASTORE_IMAGES_MEDIA_H

namespace scapix::java_api {

namespace android::content { class ContentResolver; }
namespace android::database { class Cursor; }
namespace android::graphics { class Bitmap; }
namespace android::net { class Uri; }
namespace java::lang { class String; }

namespace android::provider {

class MediaStore_Images_Media : public object_base<SCAPIX_META_STRING("android/provider/MediaStore$Images$Media"),
	java::lang::Object,
	android::provider::MediaStore_Images_ImageColumns>
{
public:

	static ref<java::lang::String> CONTENT_TYPE_();
	static ref<java::lang::String> DEFAULT_SORT_ORDER_();
	static ref<android::net::Uri> EXTERNAL_CONTENT_URI_();
	static ref<android::net::Uri> INTERNAL_CONTENT_URI_();

	static ref<MediaStore_Images_Media> new_object();
	static ref<android::database::Cursor> query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection);
	static ref<android::database::Cursor> query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection, ref<java::lang::String> where, ref<java::lang::String> orderBy);
	static ref<android::database::Cursor> query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection, ref<java::lang::String> selection, ref<link::java::array<java::lang::String>> selectionArgs, ref<java::lang::String> orderBy);
	static ref<android::graphics::Bitmap> getBitmap(ref<android::content::ContentResolver> cr, ref<android::net::Uri> url);
	static ref<java::lang::String> insertImage(ref<android::content::ContentResolver> cr, ref<java::lang::String> imagePath, ref<java::lang::String> name, ref<java::lang::String> description);
	static ref<java::lang::String> insertImage(ref<android::content::ContentResolver> cr, ref<android::graphics::Bitmap> source, ref<java::lang::String> title, ref<java::lang::String> description);
	static ref<android::net::Uri> getContentUri(ref<java::lang::String> volumeName);

protected:

	MediaStore_Images_Media(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/android/content/ContentResolver.h>
#include <scapix/java_api/android/database/Cursor.h>
#include <scapix/java_api/android/graphics/Bitmap.h>
#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<java::lang::String> MediaStore_Images_Media::CONTENT_TYPE_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> MediaStore_Images_Media::DEFAULT_SORT_ORDER_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_SORT_ORDER"), ref<java::lang::String>>(); }
inline ref<android::net::Uri> MediaStore_Images_Media::EXTERNAL_CONTENT_URI_() { return get_static_field<SCAPIX_META_STRING("EXTERNAL_CONTENT_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> MediaStore_Images_Media::INTERNAL_CONTENT_URI_() { return get_static_field<SCAPIX_META_STRING("INTERNAL_CONTENT_URI"), ref<android::net::Uri>>(); }
inline ref<MediaStore_Images_Media> MediaStore_Images_Media::new_object() { return base_::new_object(); }
inline ref<android::database::Cursor> MediaStore_Images_Media::query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection) { return call_static_method<SCAPIX_META_STRING("query"), ref<android::database::Cursor>>(cr, uri, projection); }
inline ref<android::database::Cursor> MediaStore_Images_Media::query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection, ref<java::lang::String> where, ref<java::lang::String> orderBy) { return call_static_method<SCAPIX_META_STRING("query"), ref<android::database::Cursor>>(cr, uri, projection, where, orderBy); }
inline ref<android::database::Cursor> MediaStore_Images_Media::query(ref<android::content::ContentResolver> cr, ref<android::net::Uri> uri, ref<link::java::array<java::lang::String>> projection, ref<java::lang::String> selection, ref<link::java::array<java::lang::String>> selectionArgs, ref<java::lang::String> orderBy) { return call_static_method<SCAPIX_META_STRING("query"), ref<android::database::Cursor>>(cr, uri, projection, selection, selectionArgs, orderBy); }
inline ref<android::graphics::Bitmap> MediaStore_Images_Media::getBitmap(ref<android::content::ContentResolver> cr, ref<android::net::Uri> url) { return call_static_method<SCAPIX_META_STRING("getBitmap"), ref<android::graphics::Bitmap>>(cr, url); }
inline ref<java::lang::String> MediaStore_Images_Media::insertImage(ref<android::content::ContentResolver> cr, ref<java::lang::String> imagePath, ref<java::lang::String> name, ref<java::lang::String> description) { return call_static_method<SCAPIX_META_STRING("insertImage"), ref<java::lang::String>>(cr, imagePath, name, description); }
inline ref<java::lang::String> MediaStore_Images_Media::insertImage(ref<android::content::ContentResolver> cr, ref<android::graphics::Bitmap> source, ref<java::lang::String> title, ref<java::lang::String> description) { return call_static_method<SCAPIX_META_STRING("insertImage"), ref<java::lang::String>>(cr, source, title, description); }
inline ref<android::net::Uri> MediaStore_Images_Media::getContentUri(ref<java::lang::String> volumeName) { return call_static_method<SCAPIX_META_STRING("getContentUri"), ref<android::net::Uri>>(volumeName); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_MEDIASTORE_IMAGES_MEDIA_H
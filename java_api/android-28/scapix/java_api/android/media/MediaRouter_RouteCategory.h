// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_MEDIAROUTER_ROUTECATEGORY_H
#define SCAPIX_ANDROID_MEDIA_MEDIAROUTER_ROUTECATEGORY_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::util { class List; }

namespace android::media {

class MediaRouter_RouteCategory : public object_base<SCAPIX_META_STRING("android/media/MediaRouter$RouteCategory"),
	java::lang::Object>
{
public:

	ref<java::lang::CharSequence> getName();
	ref<java::lang::CharSequence> getName(ref<android::content::Context> context);
	ref<java::util::List> getRoutes(ref<java::util::List> out);
	jint getSupportedTypes();
	jboolean isGroupable();
	ref<java::lang::String> toString();

protected:

	MediaRouter_RouteCategory(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::media {

inline ref<java::lang::CharSequence> MediaRouter_RouteCategory::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::CharSequence>>(); }
inline ref<java::lang::CharSequence> MediaRouter_RouteCategory::getName(ref<android::content::Context> context) { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::CharSequence>>(context); }
inline ref<java::util::List> MediaRouter_RouteCategory::getRoutes(ref<java::util::List> out) { return call_method<SCAPIX_META_STRING("getRoutes"), ref<java::util::List>>(out); }
inline jint MediaRouter_RouteCategory::getSupportedTypes() { return call_method<SCAPIX_META_STRING("getSupportedTypes"), jint>(); }
inline jboolean MediaRouter_RouteCategory::isGroupable() { return call_method<SCAPIX_META_STRING("isGroupable"), jboolean>(); }
inline ref<java::lang::String> MediaRouter_RouteCategory::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_MEDIAROUTER_ROUTECATEGORY_H
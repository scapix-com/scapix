// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_MEDIAROUTER_CALLBACK_H
#define SCAPIX_ANDROID_MEDIA_MEDIAROUTER_CALLBACK_H

namespace scapix::java_api {

namespace android::media { class MediaRouter; }
namespace android::media { class MediaRouter_RouteGroup; }
namespace android::media { class MediaRouter_RouteInfo; }

namespace android::media {

class MediaRouter_Callback : public object_base<SCAPIX_META_STRING("android/media/MediaRouter$Callback"),
	java::lang::Object>
{
public:

	static ref<MediaRouter_Callback> new_object();
	void onRouteSelected(ref<android::media::MediaRouter> p1, jint p2, ref<android::media::MediaRouter_RouteInfo> p3);
	void onRouteUnselected(ref<android::media::MediaRouter> p1, jint p2, ref<android::media::MediaRouter_RouteInfo> p3);
	void onRouteAdded(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2);
	void onRouteRemoved(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2);
	void onRouteChanged(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2);
	void onRouteGrouped(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2, ref<android::media::MediaRouter_RouteGroup> p3, jint p4);
	void onRouteUngrouped(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2, ref<android::media::MediaRouter_RouteGroup> p3);
	void onRouteVolumeChanged(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2);
	void onRoutePresentationDisplayChanged(ref<android::media::MediaRouter> router, ref<android::media::MediaRouter_RouteInfo> info);

protected:

	MediaRouter_Callback(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/MediaRouter.h>
#include <scapix/java_api/android/media/MediaRouter_RouteGroup.h>
#include <scapix/java_api/android/media/MediaRouter_RouteInfo.h>

namespace scapix::java_api {
namespace android::media {

inline ref<MediaRouter_Callback> MediaRouter_Callback::new_object() { return base_::new_object(); }
inline void MediaRouter_Callback::onRouteSelected(ref<android::media::MediaRouter> p1, jint p2, ref<android::media::MediaRouter_RouteInfo> p3) { return call_method<SCAPIX_META_STRING("onRouteSelected"), void>(p1, p2, p3); }
inline void MediaRouter_Callback::onRouteUnselected(ref<android::media::MediaRouter> p1, jint p2, ref<android::media::MediaRouter_RouteInfo> p3) { return call_method<SCAPIX_META_STRING("onRouteUnselected"), void>(p1, p2, p3); }
inline void MediaRouter_Callback::onRouteAdded(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2) { return call_method<SCAPIX_META_STRING("onRouteAdded"), void>(p1, p2); }
inline void MediaRouter_Callback::onRouteRemoved(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2) { return call_method<SCAPIX_META_STRING("onRouteRemoved"), void>(p1, p2); }
inline void MediaRouter_Callback::onRouteChanged(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2) { return call_method<SCAPIX_META_STRING("onRouteChanged"), void>(p1, p2); }
inline void MediaRouter_Callback::onRouteGrouped(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2, ref<android::media::MediaRouter_RouteGroup> p3, jint p4) { return call_method<SCAPIX_META_STRING("onRouteGrouped"), void>(p1, p2, p3, p4); }
inline void MediaRouter_Callback::onRouteUngrouped(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2, ref<android::media::MediaRouter_RouteGroup> p3) { return call_method<SCAPIX_META_STRING("onRouteUngrouped"), void>(p1, p2, p3); }
inline void MediaRouter_Callback::onRouteVolumeChanged(ref<android::media::MediaRouter> p1, ref<android::media::MediaRouter_RouteInfo> p2) { return call_method<SCAPIX_META_STRING("onRouteVolumeChanged"), void>(p1, p2); }
inline void MediaRouter_Callback::onRoutePresentationDisplayChanged(ref<android::media::MediaRouter> router, ref<android::media::MediaRouter_RouteInfo> info) { return call_method<SCAPIX_META_STRING("onRoutePresentationDisplayChanged"), void>(router, info); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_MEDIAROUTER_CALLBACK_H
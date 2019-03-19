// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_WEBKIT_GEOLOCATIONPERMISSIONS_CALLBACK_H
#define SCAPIX_ANDROID_WEBKIT_GEOLOCATIONPERMISSIONS_CALLBACK_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::webkit {

class GeolocationPermissions_Callback : public object_base<SCAPIX_META_STRING("android/webkit/GeolocationPermissions$Callback"),
	java::lang::Object>
{
public:

	void invoke(ref<java::lang::String> p1, jboolean p2, jboolean p3);

protected:

	GeolocationPermissions_Callback(handle_type h) : base_(h) {}

};

} // namespace android::webkit
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::webkit {

inline void GeolocationPermissions_Callback::invoke(ref<java::lang::String> p1, jboolean p2, jboolean p3) { return call_method<SCAPIX_META_STRING("invoke"), void>(p1, p2, p3); }

} // namespace android::webkit
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_WEBKIT_GEOLOCATIONPERMISSIONS_CALLBACK_H
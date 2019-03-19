// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/net/wifi/aware/DiscoverySession.h>

#ifndef SCAPIX_ANDROID_NET_WIFI_AWARE_SUBSCRIBEDISCOVERYSESSION_H
#define SCAPIX_ANDROID_NET_WIFI_AWARE_SUBSCRIBEDISCOVERYSESSION_H

namespace scapix::java_api {

namespace android::net::wifi::aware { class SubscribeConfig; }

namespace android::net::wifi::aware {

class SubscribeDiscoverySession : public object_base<SCAPIX_META_STRING("android/net/wifi/aware/SubscribeDiscoverySession"),
	android::net::wifi::aware::DiscoverySession>
{
public:

	void updateSubscribe(ref<android::net::wifi::aware::SubscribeConfig> subscribeConfig);

protected:

	SubscribeDiscoverySession(handle_type h) : base_(h) {}

};

} // namespace android::net::wifi::aware
} // namespace scapix::java_api

#include <scapix/java_api/android/net/wifi/aware/SubscribeConfig.h>

namespace scapix::java_api {
namespace android::net::wifi::aware {

inline void SubscribeDiscoverySession::updateSubscribe(ref<android::net::wifi::aware::SubscribeConfig> subscribeConfig) { return call_method<SCAPIX_META_STRING("updateSubscribe"), void>(subscribeConfig); }

} // namespace android::net::wifi::aware
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NET_WIFI_AWARE_SUBSCRIBEDISCOVERYSESSION_H
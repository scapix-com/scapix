// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/Service.h>

#ifndef SCAPIX_ANDROID_NET_VPNSERVICE_H
#define SCAPIX_ANDROID_NET_VPNSERVICE_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::content { class Intent; }
namespace android::net { class Network; }
namespace android::os { class IBinder; }
namespace java::lang { class String; }
namespace java::net { class DatagramSocket; }
namespace java::net { class Socket; }
namespace android::net { class VpnService_Builder; }

namespace android::net {

class VpnService : public object_base<SCAPIX_META_STRING("android/net/VpnService"),
	android::app::Service>
{
public:

	using Builder = VpnService_Builder;

	static ref<java::lang::String> SERVICE_INTERFACE_();
	static ref<java::lang::String> SERVICE_META_DATA_SUPPORTS_ALWAYS_ON_();

	static ref<VpnService> new_object();
	static ref<android::content::Intent> prepare(ref<android::content::Context> context);
	jboolean protect(jint socket);
	jboolean protect(ref<java::net::Socket> socket);
	jboolean protect(ref<java::net::DatagramSocket> socket);
	jboolean setUnderlyingNetworks(ref<link::java::array<android::net::Network>> networks);
	ref<android::os::IBinder> onBind(ref<android::content::Intent> intent);
	void onRevoke();

protected:

	VpnService(handle_type h) : base_(h) {}

};

} // namespace android::net
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/net/Network.h>
#include <scapix/java_api/android/os/IBinder.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/net/DatagramSocket.h>
#include <scapix/java_api/java/net/Socket.h>

namespace scapix::java_api {
namespace android::net {

inline ref<java::lang::String> VpnService::SERVICE_INTERFACE_() { return get_static_field<SCAPIX_META_STRING("SERVICE_INTERFACE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> VpnService::SERVICE_META_DATA_SUPPORTS_ALWAYS_ON_() { return get_static_field<SCAPIX_META_STRING("SERVICE_META_DATA_SUPPORTS_ALWAYS_ON"), ref<java::lang::String>>(); }
inline ref<VpnService> VpnService::new_object() { return base_::new_object(); }
inline ref<android::content::Intent> VpnService::prepare(ref<android::content::Context> context) { return call_static_method<SCAPIX_META_STRING("prepare"), ref<android::content::Intent>>(context); }
inline jboolean VpnService::protect(jint socket) { return call_method<SCAPIX_META_STRING("protect"), jboolean>(socket); }
inline jboolean VpnService::protect(ref<java::net::Socket> socket) { return call_method<SCAPIX_META_STRING("protect"), jboolean>(socket); }
inline jboolean VpnService::protect(ref<java::net::DatagramSocket> socket) { return call_method<SCAPIX_META_STRING("protect"), jboolean>(socket); }
inline jboolean VpnService::setUnderlyingNetworks(ref<link::java::array<android::net::Network>> networks) { return call_method<SCAPIX_META_STRING("setUnderlyingNetworks"), jboolean>(networks); }
inline ref<android::os::IBinder> VpnService::onBind(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("onBind"), ref<android::os::IBinder>>(intent); }
inline void VpnService::onRevoke() { return call_method<SCAPIX_META_STRING("onRevoke"), void>(); }

} // namespace android::net
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NET_VPNSERVICE_H
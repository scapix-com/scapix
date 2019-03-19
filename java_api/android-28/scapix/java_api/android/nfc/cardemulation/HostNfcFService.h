// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/Service.h>

#ifndef SCAPIX_ANDROID_NFC_CARDEMULATION_HOSTNFCFSERVICE_H
#define SCAPIX_ANDROID_NFC_CARDEMULATION_HOSTNFCFSERVICE_H

namespace scapix::java_api {

namespace android::content { class Intent; }
namespace android::os { class Bundle; }
namespace android::os { class IBinder; }
namespace java::lang { class String; }

namespace android::nfc::cardemulation {

class HostNfcFService : public object_base<SCAPIX_META_STRING("android/nfc/cardemulation/HostNfcFService"),
	android::app::Service>
{
public:

	static jint DEACTIVATION_LINK_LOSS_();
	static ref<java::lang::String> SERVICE_INTERFACE_();
	static ref<java::lang::String> SERVICE_META_DATA_();

	static ref<HostNfcFService> new_object();
	ref<android::os::IBinder> onBind(ref<android::content::Intent> intent);
	void sendResponsePacket(ref<link::java::array<jbyte>> responsePacket);
	ref<link::java::array<jbyte>> processNfcFPacket(ref<link::java::array<jbyte>> p1, ref<android::os::Bundle> p2);
	void onDeactivated(jint p1);

protected:

	HostNfcFService(handle_type h) : base_(h) {}

};

} // namespace android::nfc::cardemulation
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/IBinder.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::nfc::cardemulation {

inline jint HostNfcFService::DEACTIVATION_LINK_LOSS_() { return get_static_field<SCAPIX_META_STRING("DEACTIVATION_LINK_LOSS"), jint>(); }
inline ref<java::lang::String> HostNfcFService::SERVICE_INTERFACE_() { return get_static_field<SCAPIX_META_STRING("SERVICE_INTERFACE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> HostNfcFService::SERVICE_META_DATA_() { return get_static_field<SCAPIX_META_STRING("SERVICE_META_DATA"), ref<java::lang::String>>(); }
inline ref<HostNfcFService> HostNfcFService::new_object() { return base_::new_object(); }
inline ref<android::os::IBinder> HostNfcFService::onBind(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("onBind"), ref<android::os::IBinder>>(intent); }
inline void HostNfcFService::sendResponsePacket(ref<link::java::array<jbyte>> responsePacket) { return call_method<SCAPIX_META_STRING("sendResponsePacket"), void>(responsePacket); }
inline ref<link::java::array<jbyte>> HostNfcFService::processNfcFPacket(ref<link::java::array<jbyte>> p1, ref<android::os::Bundle> p2) { return call_method<SCAPIX_META_STRING("processNfcFPacket"), ref<link::java::array<jbyte>>>(p1, p2); }
inline void HostNfcFService::onDeactivated(jint p1) { return call_method<SCAPIX_META_STRING("onDeactivated"), void>(p1); }

} // namespace android::nfc::cardemulation
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NFC_CARDEMULATION_HOSTNFCFSERVICE_H
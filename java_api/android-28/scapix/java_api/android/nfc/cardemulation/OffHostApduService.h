// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/Service.h>

#ifndef SCAPIX_ANDROID_NFC_CARDEMULATION_OFFHOSTAPDUSERVICE_H
#define SCAPIX_ANDROID_NFC_CARDEMULATION_OFFHOSTAPDUSERVICE_H

namespace scapix::java_api {

namespace android::content { class Intent; }
namespace android::os { class IBinder; }
namespace java::lang { class String; }

namespace android::nfc::cardemulation {

class OffHostApduService : public object_base<SCAPIX_META_STRING("android/nfc/cardemulation/OffHostApduService"),
	android::app::Service>
{
public:

	static ref<java::lang::String> SERVICE_INTERFACE_();
	static ref<java::lang::String> SERVICE_META_DATA_();

	static ref<OffHostApduService> new_object();
	ref<android::os::IBinder> onBind(ref<android::content::Intent> p1);

protected:

	OffHostApduService(handle_type h) : base_(h) {}

};

} // namespace android::nfc::cardemulation
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/os/IBinder.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::nfc::cardemulation {

inline ref<java::lang::String> OffHostApduService::SERVICE_INTERFACE_() { return get_static_field<SCAPIX_META_STRING("SERVICE_INTERFACE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> OffHostApduService::SERVICE_META_DATA_() { return get_static_field<SCAPIX_META_STRING("SERVICE_META_DATA"), ref<java::lang::String>>(); }
inline ref<OffHostApduService> OffHostApduService::new_object() { return base_::new_object(); }
inline ref<android::os::IBinder> OffHostApduService::onBind(ref<android::content::Intent> p1) { return call_method<SCAPIX_META_STRING("onBind"), ref<android::os::IBinder>>(p1); }

} // namespace android::nfc::cardemulation
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NFC_CARDEMULATION_OFFHOSTAPDUSERVICE_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/Service.h>

#ifndef SCAPIX_ANDROID_TELECOM_INCALLSERVICE_H
#define SCAPIX_ANDROID_TELECOM_INCALLSERVICE_H

namespace scapix::java_api {

namespace android::bluetooth { class BluetoothDevice; }
namespace android::content { class Intent; }
namespace android::os { class Bundle; }
namespace android::os { class IBinder; }
namespace android::telecom { class Call; }
namespace android::telecom { class CallAudioState; }
namespace java::lang { class String; }
namespace java::util { class List; }
namespace android::telecom { class InCallService_VideoCall; }

namespace android::telecom {

class InCallService : public object_base<SCAPIX_META_STRING("android/telecom/InCallService"),
	android::app::Service>
{
public:

	using VideoCall = InCallService_VideoCall;

	static ref<java::lang::String> SERVICE_INTERFACE_();

	static ref<InCallService> new_object();
	ref<android::os::IBinder> onBind(ref<android::content::Intent> intent);
	jboolean onUnbind(ref<android::content::Intent> intent);
	ref<java::util::List> getCalls();
	jboolean canAddCall();
	ref<android::telecom::CallAudioState> getCallAudioState();
	void setMuted(jboolean state);
	void setAudioRoute(jint route);
	void requestBluetoothAudio(ref<android::bluetooth::BluetoothDevice> bluetoothDevice);
	void onCallAudioStateChanged(ref<android::telecom::CallAudioState> audioState);
	void onBringToForeground(jboolean showDialpad);
	void onCallAdded(ref<android::telecom::Call> call);
	void onCallRemoved(ref<android::telecom::Call> call);
	void onCanAddCallChanged(jboolean canAddCall);
	void onSilenceRinger();
	void onConnectionEvent(ref<android::telecom::Call> call, ref<java::lang::String> event, ref<android::os::Bundle> extras);

protected:

	InCallService(handle_type h) : base_(h) {}

};

} // namespace android::telecom
} // namespace scapix::java_api

#include <scapix/java_api/android/bluetooth/BluetoothDevice.h>
#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/IBinder.h>
#include <scapix/java_api/android/telecom/Call.h>
#include <scapix/java_api/android/telecom/CallAudioState.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::telecom {

inline ref<java::lang::String> InCallService::SERVICE_INTERFACE_() { return get_static_field<SCAPIX_META_STRING("SERVICE_INTERFACE"), ref<java::lang::String>>(); }
inline ref<InCallService> InCallService::new_object() { return base_::new_object(); }
inline ref<android::os::IBinder> InCallService::onBind(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("onBind"), ref<android::os::IBinder>>(intent); }
inline jboolean InCallService::onUnbind(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("onUnbind"), jboolean>(intent); }
inline ref<java::util::List> InCallService::getCalls() { return call_method<SCAPIX_META_STRING("getCalls"), ref<java::util::List>>(); }
inline jboolean InCallService::canAddCall() { return call_method<SCAPIX_META_STRING("canAddCall"), jboolean>(); }
inline ref<android::telecom::CallAudioState> InCallService::getCallAudioState() { return call_method<SCAPIX_META_STRING("getCallAudioState"), ref<android::telecom::CallAudioState>>(); }
inline void InCallService::setMuted(jboolean state) { return call_method<SCAPIX_META_STRING("setMuted"), void>(state); }
inline void InCallService::setAudioRoute(jint route) { return call_method<SCAPIX_META_STRING("setAudioRoute"), void>(route); }
inline void InCallService::requestBluetoothAudio(ref<android::bluetooth::BluetoothDevice> bluetoothDevice) { return call_method<SCAPIX_META_STRING("requestBluetoothAudio"), void>(bluetoothDevice); }
inline void InCallService::onCallAudioStateChanged(ref<android::telecom::CallAudioState> audioState) { return call_method<SCAPIX_META_STRING("onCallAudioStateChanged"), void>(audioState); }
inline void InCallService::onBringToForeground(jboolean showDialpad) { return call_method<SCAPIX_META_STRING("onBringToForeground"), void>(showDialpad); }
inline void InCallService::onCallAdded(ref<android::telecom::Call> call) { return call_method<SCAPIX_META_STRING("onCallAdded"), void>(call); }
inline void InCallService::onCallRemoved(ref<android::telecom::Call> call) { return call_method<SCAPIX_META_STRING("onCallRemoved"), void>(call); }
inline void InCallService::onCanAddCallChanged(jboolean canAddCall) { return call_method<SCAPIX_META_STRING("onCanAddCallChanged"), void>(canAddCall); }
inline void InCallService::onSilenceRinger() { return call_method<SCAPIX_META_STRING("onSilenceRinger"), void>(); }
inline void InCallService::onConnectionEvent(ref<android::telecom::Call> call, ref<java::lang::String> event, ref<android::os::Bundle> extras) { return call_method<SCAPIX_META_STRING("onConnectionEvent"), void>(call, event, extras); }

} // namespace android::telecom
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TELECOM_INCALLSERVICE_H
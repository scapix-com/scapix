// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHPROFILE_H
#define SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHPROFILE_H

namespace scapix::java_api {

namespace android::bluetooth { class BluetoothDevice; }
namespace java::lang { class String; }
namespace java::util { class List; }
namespace android::bluetooth { class BluetoothProfile_ServiceListener; }

namespace android::bluetooth {

class BluetoothProfile : public object_base<SCAPIX_META_STRING("android/bluetooth/BluetoothProfile"),
	java::lang::Object>
{
public:

	using ServiceListener = BluetoothProfile_ServiceListener;

	static jint A2DP_();
	static ref<java::lang::String> EXTRA_PREVIOUS_STATE_();
	static ref<java::lang::String> EXTRA_STATE_();
	static jint GATT_();
	static jint GATT_SERVER_();
	static jint HEADSET_();
	static jint HEALTH_();
	static jint HID_DEVICE_();
	static jint SAP_();
	static jint STATE_CONNECTED_();
	static jint STATE_CONNECTING_();
	static jint STATE_DISCONNECTED_();
	static jint STATE_DISCONNECTING_();

	ref<java::util::List> getConnectedDevices();
	ref<java::util::List> getDevicesMatchingConnectionStates(ref<link::java::array<jint>> p1);
	jint getConnectionState(ref<android::bluetooth::BluetoothDevice> p1);

protected:

	BluetoothProfile(handle_type h) : base_(h) {}

};

} // namespace android::bluetooth
} // namespace scapix::java_api

#include <scapix/java_api/android/bluetooth/BluetoothDevice.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::bluetooth {

inline jint BluetoothProfile::A2DP_() { return get_static_field<SCAPIX_META_STRING("A2DP"), jint>(); }
inline ref<java::lang::String> BluetoothProfile::EXTRA_PREVIOUS_STATE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_PREVIOUS_STATE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BluetoothProfile::EXTRA_STATE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_STATE"), ref<java::lang::String>>(); }
inline jint BluetoothProfile::GATT_() { return get_static_field<SCAPIX_META_STRING("GATT"), jint>(); }
inline jint BluetoothProfile::GATT_SERVER_() { return get_static_field<SCAPIX_META_STRING("GATT_SERVER"), jint>(); }
inline jint BluetoothProfile::HEADSET_() { return get_static_field<SCAPIX_META_STRING("HEADSET"), jint>(); }
inline jint BluetoothProfile::HEALTH_() { return get_static_field<SCAPIX_META_STRING("HEALTH"), jint>(); }
inline jint BluetoothProfile::HID_DEVICE_() { return get_static_field<SCAPIX_META_STRING("HID_DEVICE"), jint>(); }
inline jint BluetoothProfile::SAP_() { return get_static_field<SCAPIX_META_STRING("SAP"), jint>(); }
inline jint BluetoothProfile::STATE_CONNECTED_() { return get_static_field<SCAPIX_META_STRING("STATE_CONNECTED"), jint>(); }
inline jint BluetoothProfile::STATE_CONNECTING_() { return get_static_field<SCAPIX_META_STRING("STATE_CONNECTING"), jint>(); }
inline jint BluetoothProfile::STATE_DISCONNECTED_() { return get_static_field<SCAPIX_META_STRING("STATE_DISCONNECTED"), jint>(); }
inline jint BluetoothProfile::STATE_DISCONNECTING_() { return get_static_field<SCAPIX_META_STRING("STATE_DISCONNECTING"), jint>(); }
inline ref<java::util::List> BluetoothProfile::getConnectedDevices() { return call_method<SCAPIX_META_STRING("getConnectedDevices"), ref<java::util::List>>(); }
inline ref<java::util::List> BluetoothProfile::getDevicesMatchingConnectionStates(ref<link::java::array<jint>> p1) { return call_method<SCAPIX_META_STRING("getDevicesMatchingConnectionStates"), ref<java::util::List>>(p1); }
inline jint BluetoothProfile::getConnectionState(ref<android::bluetooth::BluetoothDevice> p1) { return call_method<SCAPIX_META_STRING("getConnectionState"), jint>(p1); }

} // namespace android::bluetooth
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHPROFILE_H

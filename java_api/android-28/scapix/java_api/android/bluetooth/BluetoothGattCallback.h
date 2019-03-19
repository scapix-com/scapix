// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHGATTCALLBACK_H
#define SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHGATTCALLBACK_H

namespace scapix::java_api {

namespace android::bluetooth { class BluetoothGatt; }
namespace android::bluetooth { class BluetoothGattCharacteristic; }
namespace android::bluetooth { class BluetoothGattDescriptor; }

namespace android::bluetooth {

class BluetoothGattCallback : public object_base<SCAPIX_META_STRING("android/bluetooth/BluetoothGattCallback"),
	java::lang::Object>
{
public:

	static ref<BluetoothGattCallback> new_object();
	void onPhyUpdate(ref<android::bluetooth::BluetoothGatt> gatt, jint txPhy, jint rxPhy, jint status);
	void onPhyRead(ref<android::bluetooth::BluetoothGatt> gatt, jint txPhy, jint rxPhy, jint status);
	void onConnectionStateChange(ref<android::bluetooth::BluetoothGatt> gatt, jint status, jint newState);
	void onServicesDiscovered(ref<android::bluetooth::BluetoothGatt> gatt, jint status);
	void onCharacteristicRead(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic, jint status);
	void onCharacteristicWrite(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic, jint status);
	void onCharacteristicChanged(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic);
	void onDescriptorRead(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattDescriptor> descriptor, jint status);
	void onDescriptorWrite(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattDescriptor> descriptor, jint status);
	void onReliableWriteCompleted(ref<android::bluetooth::BluetoothGatt> gatt, jint status);
	void onReadRemoteRssi(ref<android::bluetooth::BluetoothGatt> gatt, jint rssi, jint status);
	void onMtuChanged(ref<android::bluetooth::BluetoothGatt> gatt, jint mtu, jint status);

protected:

	BluetoothGattCallback(handle_type h) : base_(h) {}

};

} // namespace android::bluetooth
} // namespace scapix::java_api

#include <scapix/java_api/android/bluetooth/BluetoothGatt.h>
#include <scapix/java_api/android/bluetooth/BluetoothGattCharacteristic.h>
#include <scapix/java_api/android/bluetooth/BluetoothGattDescriptor.h>

namespace scapix::java_api {
namespace android::bluetooth {

inline ref<BluetoothGattCallback> BluetoothGattCallback::new_object() { return base_::new_object(); }
inline void BluetoothGattCallback::onPhyUpdate(ref<android::bluetooth::BluetoothGatt> gatt, jint txPhy, jint rxPhy, jint status) { return call_method<SCAPIX_META_STRING("onPhyUpdate"), void>(gatt, txPhy, rxPhy, status); }
inline void BluetoothGattCallback::onPhyRead(ref<android::bluetooth::BluetoothGatt> gatt, jint txPhy, jint rxPhy, jint status) { return call_method<SCAPIX_META_STRING("onPhyRead"), void>(gatt, txPhy, rxPhy, status); }
inline void BluetoothGattCallback::onConnectionStateChange(ref<android::bluetooth::BluetoothGatt> gatt, jint status, jint newState) { return call_method<SCAPIX_META_STRING("onConnectionStateChange"), void>(gatt, status, newState); }
inline void BluetoothGattCallback::onServicesDiscovered(ref<android::bluetooth::BluetoothGatt> gatt, jint status) { return call_method<SCAPIX_META_STRING("onServicesDiscovered"), void>(gatt, status); }
inline void BluetoothGattCallback::onCharacteristicRead(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic, jint status) { return call_method<SCAPIX_META_STRING("onCharacteristicRead"), void>(gatt, characteristic, status); }
inline void BluetoothGattCallback::onCharacteristicWrite(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic, jint status) { return call_method<SCAPIX_META_STRING("onCharacteristicWrite"), void>(gatt, characteristic, status); }
inline void BluetoothGattCallback::onCharacteristicChanged(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattCharacteristic> characteristic) { return call_method<SCAPIX_META_STRING("onCharacteristicChanged"), void>(gatt, characteristic); }
inline void BluetoothGattCallback::onDescriptorRead(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattDescriptor> descriptor, jint status) { return call_method<SCAPIX_META_STRING("onDescriptorRead"), void>(gatt, descriptor, status); }
inline void BluetoothGattCallback::onDescriptorWrite(ref<android::bluetooth::BluetoothGatt> gatt, ref<android::bluetooth::BluetoothGattDescriptor> descriptor, jint status) { return call_method<SCAPIX_META_STRING("onDescriptorWrite"), void>(gatt, descriptor, status); }
inline void BluetoothGattCallback::onReliableWriteCompleted(ref<android::bluetooth::BluetoothGatt> gatt, jint status) { return call_method<SCAPIX_META_STRING("onReliableWriteCompleted"), void>(gatt, status); }
inline void BluetoothGattCallback::onReadRemoteRssi(ref<android::bluetooth::BluetoothGatt> gatt, jint rssi, jint status) { return call_method<SCAPIX_META_STRING("onReadRemoteRssi"), void>(gatt, rssi, status); }
inline void BluetoothGattCallback::onMtuChanged(ref<android::bluetooth::BluetoothGatt> gatt, jint mtu, jint status) { return call_method<SCAPIX_META_STRING("onMtuChanged"), void>(gatt, mtu, status); }

} // namespace android::bluetooth
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_BLUETOOTH_BLUETOOTHGATTCALLBACK_H
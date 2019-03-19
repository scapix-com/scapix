// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_MEDIA_MIDI_MIDIMANAGER_H
#define SCAPIX_ANDROID_MEDIA_MIDI_MIDIMANAGER_H

namespace scapix::java_api {

namespace android::bluetooth { class BluetoothDevice; }
namespace android::media::midi { class MidiDeviceInfo; }
namespace android::media::midi { class MidiManager_DeviceCallback; }
namespace android::media::midi { class MidiManager_OnDeviceOpenedListener; }
namespace android::os { class Handler; }

namespace android::media::midi {

class MidiManager : public object_base<SCAPIX_META_STRING("android/media/midi/MidiManager"),
	java::lang::Object>
{
public:

	using OnDeviceOpenedListener = MidiManager_OnDeviceOpenedListener;
	using DeviceCallback = MidiManager_DeviceCallback;

	void registerDeviceCallback(ref<android::media::midi::MidiManager_DeviceCallback> callback, ref<android::os::Handler> handler);
	void unregisterDeviceCallback(ref<android::media::midi::MidiManager_DeviceCallback> callback);
	ref<link::java::array<android::media::midi::MidiDeviceInfo>> getDevices();
	void openDevice(ref<android::media::midi::MidiDeviceInfo> deviceInfo, ref<android::media::midi::MidiManager_OnDeviceOpenedListener> listener, ref<android::os::Handler> handler);
	void openBluetoothDevice(ref<android::bluetooth::BluetoothDevice> bluetoothDevice, ref<android::media::midi::MidiManager_OnDeviceOpenedListener> listener, ref<android::os::Handler> handler);

protected:

	MidiManager(handle_type h) : base_(h) {}

};

} // namespace android::media::midi
} // namespace scapix::java_api

#include <scapix/java_api/android/bluetooth/BluetoothDevice.h>
#include <scapix/java_api/android/media/midi/MidiDeviceInfo.h>
#include <scapix/java_api/android/media/midi/MidiManager_DeviceCallback.h>
#include <scapix/java_api/android/media/midi/MidiManager_OnDeviceOpenedListener.h>
#include <scapix/java_api/android/os/Handler.h>

namespace scapix::java_api {
namespace android::media::midi {

inline void MidiManager::registerDeviceCallback(ref<android::media::midi::MidiManager_DeviceCallback> callback, ref<android::os::Handler> handler) { return call_method<SCAPIX_META_STRING("registerDeviceCallback"), void>(callback, handler); }
inline void MidiManager::unregisterDeviceCallback(ref<android::media::midi::MidiManager_DeviceCallback> callback) { return call_method<SCAPIX_META_STRING("unregisterDeviceCallback"), void>(callback); }
inline ref<link::java::array<android::media::midi::MidiDeviceInfo>> MidiManager::getDevices() { return call_method<SCAPIX_META_STRING("getDevices"), ref<link::java::array<android::media::midi::MidiDeviceInfo>>>(); }
inline void MidiManager::openDevice(ref<android::media::midi::MidiDeviceInfo> deviceInfo, ref<android::media::midi::MidiManager_OnDeviceOpenedListener> listener, ref<android::os::Handler> handler) { return call_method<SCAPIX_META_STRING("openDevice"), void>(deviceInfo, listener, handler); }
inline void MidiManager::openBluetoothDevice(ref<android::bluetooth::BluetoothDevice> bluetoothDevice, ref<android::media::midi::MidiManager_OnDeviceOpenedListener> listener, ref<android::os::Handler> handler) { return call_method<SCAPIX_META_STRING("openBluetoothDevice"), void>(bluetoothDevice, listener, handler); }

} // namespace android::media::midi
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_MIDI_MIDIMANAGER_H
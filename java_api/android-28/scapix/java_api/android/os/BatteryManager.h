// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_OS_BATTERYMANAGER_H
#define SCAPIX_ANDROID_OS_BATTERYMANAGER_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::os {

class BatteryManager : public object_base<SCAPIX_META_STRING("android/os/BatteryManager"),
	java::lang::Object>
{
public:

	static ref<java::lang::String> ACTION_CHARGING_();
	static ref<java::lang::String> ACTION_DISCHARGING_();
	static jint BATTERY_HEALTH_COLD_();
	static jint BATTERY_HEALTH_DEAD_();
	static jint BATTERY_HEALTH_GOOD_();
	static jint BATTERY_HEALTH_OVERHEAT_();
	static jint BATTERY_HEALTH_OVER_VOLTAGE_();
	static jint BATTERY_HEALTH_UNKNOWN_();
	static jint BATTERY_HEALTH_UNSPECIFIED_FAILURE_();
	static jint BATTERY_PLUGGED_AC_();
	static jint BATTERY_PLUGGED_USB_();
	static jint BATTERY_PLUGGED_WIRELESS_();
	static jint BATTERY_PROPERTY_CAPACITY_();
	static jint BATTERY_PROPERTY_CHARGE_COUNTER_();
	static jint BATTERY_PROPERTY_CURRENT_AVERAGE_();
	static jint BATTERY_PROPERTY_CURRENT_NOW_();
	static jint BATTERY_PROPERTY_ENERGY_COUNTER_();
	static jint BATTERY_PROPERTY_STATUS_();
	static jint BATTERY_STATUS_CHARGING_();
	static jint BATTERY_STATUS_DISCHARGING_();
	static jint BATTERY_STATUS_FULL_();
	static jint BATTERY_STATUS_NOT_CHARGING_();
	static jint BATTERY_STATUS_UNKNOWN_();
	static ref<java::lang::String> EXTRA_BATTERY_LOW_();
	static ref<java::lang::String> EXTRA_HEALTH_();
	static ref<java::lang::String> EXTRA_ICON_SMALL_();
	static ref<java::lang::String> EXTRA_LEVEL_();
	static ref<java::lang::String> EXTRA_PLUGGED_();
	static ref<java::lang::String> EXTRA_PRESENT_();
	static ref<java::lang::String> EXTRA_SCALE_();
	static ref<java::lang::String> EXTRA_STATUS_();
	static ref<java::lang::String> EXTRA_TECHNOLOGY_();
	static ref<java::lang::String> EXTRA_TEMPERATURE_();
	static ref<java::lang::String> EXTRA_VOLTAGE_();

	jboolean isCharging();
	jint getIntProperty(jint id);
	jlong getLongProperty(jint id);
	jlong computeChargeTimeRemaining();

protected:

	BatteryManager(handle_type h) : base_(h) {}

};

} // namespace android::os
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::os {

inline ref<java::lang::String> BatteryManager::ACTION_CHARGING_() { return get_static_field<SCAPIX_META_STRING("ACTION_CHARGING"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::ACTION_DISCHARGING_() { return get_static_field<SCAPIX_META_STRING("ACTION_DISCHARGING"), ref<java::lang::String>>(); }
inline jint BatteryManager::BATTERY_HEALTH_COLD_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_COLD"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_DEAD_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_DEAD"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_GOOD_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_GOOD"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_OVERHEAT_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_OVERHEAT"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_OVER_VOLTAGE_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_OVER_VOLTAGE"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_UNKNOWN"), jint>(); }
inline jint BatteryManager::BATTERY_HEALTH_UNSPECIFIED_FAILURE_() { return get_static_field<SCAPIX_META_STRING("BATTERY_HEALTH_UNSPECIFIED_FAILURE"), jint>(); }
inline jint BatteryManager::BATTERY_PLUGGED_AC_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PLUGGED_AC"), jint>(); }
inline jint BatteryManager::BATTERY_PLUGGED_USB_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PLUGGED_USB"), jint>(); }
inline jint BatteryManager::BATTERY_PLUGGED_WIRELESS_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PLUGGED_WIRELESS"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_CAPACITY_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_CAPACITY"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_CHARGE_COUNTER_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_CHARGE_COUNTER"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_CURRENT_AVERAGE_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_CURRENT_AVERAGE"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_CURRENT_NOW_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_CURRENT_NOW"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_ENERGY_COUNTER_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_ENERGY_COUNTER"), jint>(); }
inline jint BatteryManager::BATTERY_PROPERTY_STATUS_() { return get_static_field<SCAPIX_META_STRING("BATTERY_PROPERTY_STATUS"), jint>(); }
inline jint BatteryManager::BATTERY_STATUS_CHARGING_() { return get_static_field<SCAPIX_META_STRING("BATTERY_STATUS_CHARGING"), jint>(); }
inline jint BatteryManager::BATTERY_STATUS_DISCHARGING_() { return get_static_field<SCAPIX_META_STRING("BATTERY_STATUS_DISCHARGING"), jint>(); }
inline jint BatteryManager::BATTERY_STATUS_FULL_() { return get_static_field<SCAPIX_META_STRING("BATTERY_STATUS_FULL"), jint>(); }
inline jint BatteryManager::BATTERY_STATUS_NOT_CHARGING_() { return get_static_field<SCAPIX_META_STRING("BATTERY_STATUS_NOT_CHARGING"), jint>(); }
inline jint BatteryManager::BATTERY_STATUS_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("BATTERY_STATUS_UNKNOWN"), jint>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_BATTERY_LOW_() { return get_static_field<SCAPIX_META_STRING("EXTRA_BATTERY_LOW"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_HEALTH_() { return get_static_field<SCAPIX_META_STRING("EXTRA_HEALTH"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_ICON_SMALL_() { return get_static_field<SCAPIX_META_STRING("EXTRA_ICON_SMALL"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_LEVEL_() { return get_static_field<SCAPIX_META_STRING("EXTRA_LEVEL"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_PLUGGED_() { return get_static_field<SCAPIX_META_STRING("EXTRA_PLUGGED"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_PRESENT_() { return get_static_field<SCAPIX_META_STRING("EXTRA_PRESENT"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_SCALE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_SCALE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_STATUS_() { return get_static_field<SCAPIX_META_STRING("EXTRA_STATUS"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_TECHNOLOGY_() { return get_static_field<SCAPIX_META_STRING("EXTRA_TECHNOLOGY"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_TEMPERATURE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_TEMPERATURE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BatteryManager::EXTRA_VOLTAGE_() { return get_static_field<SCAPIX_META_STRING("EXTRA_VOLTAGE"), ref<java::lang::String>>(); }
inline jboolean BatteryManager::isCharging() { return call_method<SCAPIX_META_STRING("isCharging"), jboolean>(); }
inline jint BatteryManager::getIntProperty(jint id) { return call_method<SCAPIX_META_STRING("getIntProperty"), jint>(id); }
inline jlong BatteryManager::getLongProperty(jint id) { return call_method<SCAPIX_META_STRING("getLongProperty"), jlong>(id); }
inline jlong BatteryManager::computeChargeTimeRemaining() { return call_method<SCAPIX_META_STRING("computeChargeTimeRemaining"), jlong>(); }

} // namespace android::os
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_BATTERYMANAGER_H
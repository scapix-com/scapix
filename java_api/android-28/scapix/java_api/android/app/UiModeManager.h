// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_APP_UIMODEMANAGER_H
#define SCAPIX_ANDROID_APP_UIMODEMANAGER_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::app {

class UiModeManager : public object_base<SCAPIX_META_STRING("android/app/UiModeManager"),
	java::lang::Object>
{
public:

	static ref<java::lang::String> ACTION_ENTER_CAR_MODE_();
	static void ACTION_ENTER_CAR_MODE_(ref<java::lang::String>);
	static ref<java::lang::String> ACTION_ENTER_DESK_MODE_();
	static void ACTION_ENTER_DESK_MODE_(ref<java::lang::String>);
	static ref<java::lang::String> ACTION_EXIT_CAR_MODE_();
	static void ACTION_EXIT_CAR_MODE_(ref<java::lang::String>);
	static ref<java::lang::String> ACTION_EXIT_DESK_MODE_();
	static void ACTION_EXIT_DESK_MODE_(ref<java::lang::String>);
	static jint DISABLE_CAR_MODE_GO_HOME_();
	static jint ENABLE_CAR_MODE_ALLOW_SLEEP_();
	static jint ENABLE_CAR_MODE_GO_CAR_HOME_();
	static jint MODE_NIGHT_AUTO_();
	static jint MODE_NIGHT_NO_();
	static jint MODE_NIGHT_YES_();

	void enableCarMode(jint flags);
	void disableCarMode(jint flags);
	jint getCurrentModeType();
	void setNightMode(jint mode);
	jint getNightMode();

protected:

	UiModeManager(handle_type h) : base_(h) {}

};

} // namespace android::app
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::app {

inline ref<java::lang::String> UiModeManager::ACTION_ENTER_CAR_MODE_() { return get_static_field<SCAPIX_META_STRING("ACTION_ENTER_CAR_MODE"), ref<java::lang::String>>(); }
inline void UiModeManager::ACTION_ENTER_CAR_MODE_(ref<java::lang::String> v) { set_static_field<SCAPIX_META_STRING("ACTION_ENTER_CAR_MODE"), ref<java::lang::String>>(v); }
inline ref<java::lang::String> UiModeManager::ACTION_ENTER_DESK_MODE_() { return get_static_field<SCAPIX_META_STRING("ACTION_ENTER_DESK_MODE"), ref<java::lang::String>>(); }
inline void UiModeManager::ACTION_ENTER_DESK_MODE_(ref<java::lang::String> v) { set_static_field<SCAPIX_META_STRING("ACTION_ENTER_DESK_MODE"), ref<java::lang::String>>(v); }
inline ref<java::lang::String> UiModeManager::ACTION_EXIT_CAR_MODE_() { return get_static_field<SCAPIX_META_STRING("ACTION_EXIT_CAR_MODE"), ref<java::lang::String>>(); }
inline void UiModeManager::ACTION_EXIT_CAR_MODE_(ref<java::lang::String> v) { set_static_field<SCAPIX_META_STRING("ACTION_EXIT_CAR_MODE"), ref<java::lang::String>>(v); }
inline ref<java::lang::String> UiModeManager::ACTION_EXIT_DESK_MODE_() { return get_static_field<SCAPIX_META_STRING("ACTION_EXIT_DESK_MODE"), ref<java::lang::String>>(); }
inline void UiModeManager::ACTION_EXIT_DESK_MODE_(ref<java::lang::String> v) { set_static_field<SCAPIX_META_STRING("ACTION_EXIT_DESK_MODE"), ref<java::lang::String>>(v); }
inline jint UiModeManager::DISABLE_CAR_MODE_GO_HOME_() { return get_static_field<SCAPIX_META_STRING("DISABLE_CAR_MODE_GO_HOME"), jint>(); }
inline jint UiModeManager::ENABLE_CAR_MODE_ALLOW_SLEEP_() { return get_static_field<SCAPIX_META_STRING("ENABLE_CAR_MODE_ALLOW_SLEEP"), jint>(); }
inline jint UiModeManager::ENABLE_CAR_MODE_GO_CAR_HOME_() { return get_static_field<SCAPIX_META_STRING("ENABLE_CAR_MODE_GO_CAR_HOME"), jint>(); }
inline jint UiModeManager::MODE_NIGHT_AUTO_() { return get_static_field<SCAPIX_META_STRING("MODE_NIGHT_AUTO"), jint>(); }
inline jint UiModeManager::MODE_NIGHT_NO_() { return get_static_field<SCAPIX_META_STRING("MODE_NIGHT_NO"), jint>(); }
inline jint UiModeManager::MODE_NIGHT_YES_() { return get_static_field<SCAPIX_META_STRING("MODE_NIGHT_YES"), jint>(); }
inline void UiModeManager::enableCarMode(jint flags) { return call_method<SCAPIX_META_STRING("enableCarMode"), void>(flags); }
inline void UiModeManager::disableCarMode(jint flags) { return call_method<SCAPIX_META_STRING("disableCarMode"), void>(flags); }
inline jint UiModeManager::getCurrentModeType() { return call_method<SCAPIX_META_STRING("getCurrentModeType"), jint>(); }
inline void UiModeManager::setNightMode(jint mode) { return call_method<SCAPIX_META_STRING("setNightMode"), void>(mode); }
inline jint UiModeManager::getNightMode() { return call_method<SCAPIX_META_STRING("getNightMode"), jint>(); }

} // namespace android::app
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_UIMODEMANAGER_H
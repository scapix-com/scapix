// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_HARDWARE_DISPLAY_DISPLAYMANAGER_H
#define SCAPIX_ANDROID_HARDWARE_DISPLAY_DISPLAYMANAGER_H

namespace scapix::java_api {

namespace android::hardware::display { class DisplayManager_DisplayListener; }
namespace android::hardware::display { class VirtualDisplay; }
namespace android::hardware::display { class VirtualDisplay_Callback; }
namespace android::os { class Handler; }
namespace android::view { class Display; }
namespace android::view { class Surface; }
namespace java::lang { class String; }

namespace android::hardware::display {

class DisplayManager : public object_base<SCAPIX_META_STRING("android/hardware/display/DisplayManager"),
	java::lang::Object>
{
public:

	using DisplayListener = DisplayManager_DisplayListener;

	static ref<java::lang::String> DISPLAY_CATEGORY_PRESENTATION_();
	static jint VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR_();
	static jint VIRTUAL_DISPLAY_FLAG_OWN_CONTENT_ONLY_();
	static jint VIRTUAL_DISPLAY_FLAG_PRESENTATION_();
	static jint VIRTUAL_DISPLAY_FLAG_PUBLIC_();
	static jint VIRTUAL_DISPLAY_FLAG_SECURE_();

	ref<android::view::Display> getDisplay(jint displayId);
	ref<link::java::array<android::view::Display>> getDisplays();
	ref<link::java::array<android::view::Display>> getDisplays(ref<java::lang::String> category);
	void registerDisplayListener(ref<android::hardware::display::DisplayManager_DisplayListener> listener, ref<android::os::Handler> handler);
	void unregisterDisplayListener(ref<android::hardware::display::DisplayManager_DisplayListener> listener);
	ref<android::hardware::display::VirtualDisplay> createVirtualDisplay(ref<java::lang::String> name, jint width, jint height, jint densityDpi, ref<android::view::Surface> surface, jint flags);
	ref<android::hardware::display::VirtualDisplay> createVirtualDisplay(ref<java::lang::String> name, jint width, jint height, jint densityDpi, ref<android::view::Surface> surface, jint flags, ref<android::hardware::display::VirtualDisplay_Callback> callback, ref<android::os::Handler> handler);

protected:

	DisplayManager(handle_type h) : base_(h) {}

};

} // namespace android::hardware::display
} // namespace scapix::java_api

#include <scapix/java_api/android/hardware/display/DisplayManager_DisplayListener.h>
#include <scapix/java_api/android/hardware/display/VirtualDisplay.h>
#include <scapix/java_api/android/hardware/display/VirtualDisplay_Callback.h>
#include <scapix/java_api/android/os/Handler.h>
#include <scapix/java_api/android/view/Display.h>
#include <scapix/java_api/android/view/Surface.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::hardware::display {

inline ref<java::lang::String> DisplayManager::DISPLAY_CATEGORY_PRESENTATION_() { return get_static_field<SCAPIX_META_STRING("DISPLAY_CATEGORY_PRESENTATION"), ref<java::lang::String>>(); }
inline jint DisplayManager::VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR_() { return get_static_field<SCAPIX_META_STRING("VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR"), jint>(); }
inline jint DisplayManager::VIRTUAL_DISPLAY_FLAG_OWN_CONTENT_ONLY_() { return get_static_field<SCAPIX_META_STRING("VIRTUAL_DISPLAY_FLAG_OWN_CONTENT_ONLY"), jint>(); }
inline jint DisplayManager::VIRTUAL_DISPLAY_FLAG_PRESENTATION_() { return get_static_field<SCAPIX_META_STRING("VIRTUAL_DISPLAY_FLAG_PRESENTATION"), jint>(); }
inline jint DisplayManager::VIRTUAL_DISPLAY_FLAG_PUBLIC_() { return get_static_field<SCAPIX_META_STRING("VIRTUAL_DISPLAY_FLAG_PUBLIC"), jint>(); }
inline jint DisplayManager::VIRTUAL_DISPLAY_FLAG_SECURE_() { return get_static_field<SCAPIX_META_STRING("VIRTUAL_DISPLAY_FLAG_SECURE"), jint>(); }
inline ref<android::view::Display> DisplayManager::getDisplay(jint displayId) { return call_method<SCAPIX_META_STRING("getDisplay"), ref<android::view::Display>>(displayId); }
inline ref<link::java::array<android::view::Display>> DisplayManager::getDisplays() { return call_method<SCAPIX_META_STRING("getDisplays"), ref<link::java::array<android::view::Display>>>(); }
inline ref<link::java::array<android::view::Display>> DisplayManager::getDisplays(ref<java::lang::String> category) { return call_method<SCAPIX_META_STRING("getDisplays"), ref<link::java::array<android::view::Display>>>(category); }
inline void DisplayManager::registerDisplayListener(ref<android::hardware::display::DisplayManager_DisplayListener> listener, ref<android::os::Handler> handler) { return call_method<SCAPIX_META_STRING("registerDisplayListener"), void>(listener, handler); }
inline void DisplayManager::unregisterDisplayListener(ref<android::hardware::display::DisplayManager_DisplayListener> listener) { return call_method<SCAPIX_META_STRING("unregisterDisplayListener"), void>(listener); }
inline ref<android::hardware::display::VirtualDisplay> DisplayManager::createVirtualDisplay(ref<java::lang::String> name, jint width, jint height, jint densityDpi, ref<android::view::Surface> surface, jint flags) { return call_method<SCAPIX_META_STRING("createVirtualDisplay"), ref<android::hardware::display::VirtualDisplay>>(name, width, height, densityDpi, surface, flags); }
inline ref<android::hardware::display::VirtualDisplay> DisplayManager::createVirtualDisplay(ref<java::lang::String> name, jint width, jint height, jint densityDpi, ref<android::view::Surface> surface, jint flags, ref<android::hardware::display::VirtualDisplay_Callback> callback, ref<android::os::Handler> handler) { return call_method<SCAPIX_META_STRING("createVirtualDisplay"), ref<android::hardware::display::VirtualDisplay>>(name, width, height, densityDpi, surface, flags, callback, handler); }

} // namespace android::hardware::display
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_HARDWARE_DISPLAY_DISPLAYMANAGER_H

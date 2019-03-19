// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_CONTENT_PM_LAUNCHERACTIVITYINFO_H
#define SCAPIX_ANDROID_CONTENT_PM_LAUNCHERACTIVITYINFO_H

namespace scapix::java_api {

namespace android::content { class ComponentName; }
namespace android::content::pm { class ApplicationInfo; }
namespace android::graphics::drawable { class Drawable; }
namespace android::os { class UserHandle; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }

namespace android::content::pm {

class LauncherActivityInfo : public object_base<SCAPIX_META_STRING("android/content/pm/LauncherActivityInfo"),
	java::lang::Object>
{
public:

	ref<android::content::ComponentName> getComponentName();
	ref<android::os::UserHandle> getUser();
	ref<java::lang::CharSequence> getLabel();
	ref<android::graphics::drawable::Drawable> getIcon(jint density);
	ref<android::content::pm::ApplicationInfo> getApplicationInfo();
	jlong getFirstInstallTime();
	ref<java::lang::String> getName();
	ref<android::graphics::drawable::Drawable> getBadgedIcon(jint density);

protected:

	LauncherActivityInfo(handle_type h) : base_(h) {}

};

} // namespace android::content::pm
} // namespace scapix::java_api

#include <scapix/java_api/android/content/ComponentName.h>
#include <scapix/java_api/android/content/pm/ApplicationInfo.h>
#include <scapix/java_api/android/graphics/drawable/Drawable.h>
#include <scapix/java_api/android/os/UserHandle.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::content::pm {

inline ref<android::content::ComponentName> LauncherActivityInfo::getComponentName() { return call_method<SCAPIX_META_STRING("getComponentName"), ref<android::content::ComponentName>>(); }
inline ref<android::os::UserHandle> LauncherActivityInfo::getUser() { return call_method<SCAPIX_META_STRING("getUser"), ref<android::os::UserHandle>>(); }
inline ref<java::lang::CharSequence> LauncherActivityInfo::getLabel() { return call_method<SCAPIX_META_STRING("getLabel"), ref<java::lang::CharSequence>>(); }
inline ref<android::graphics::drawable::Drawable> LauncherActivityInfo::getIcon(jint density) { return call_method<SCAPIX_META_STRING("getIcon"), ref<android::graphics::drawable::Drawable>>(density); }
inline ref<android::content::pm::ApplicationInfo> LauncherActivityInfo::getApplicationInfo() { return call_method<SCAPIX_META_STRING("getApplicationInfo"), ref<android::content::pm::ApplicationInfo>>(); }
inline jlong LauncherActivityInfo::getFirstInstallTime() { return call_method<SCAPIX_META_STRING("getFirstInstallTime"), jlong>(); }
inline ref<java::lang::String> LauncherActivityInfo::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline ref<android::graphics::drawable::Drawable> LauncherActivityInfo::getBadgedIcon(jint density) { return call_method<SCAPIX_META_STRING("getBadgedIcon"), ref<android::graphics::drawable::Drawable>>(density); }

} // namespace android::content::pm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_PM_LAUNCHERACTIVITYINFO_H
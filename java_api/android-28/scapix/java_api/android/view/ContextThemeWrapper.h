// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/content/ContextWrapper.h>

#ifndef SCAPIX_ANDROID_VIEW_CONTEXTTHEMEWRAPPER_H
#define SCAPIX_ANDROID_VIEW_CONTEXTTHEMEWRAPPER_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::content::res { class AssetManager; }
namespace android::content::res { class Configuration; }
namespace android::content::res { class Resources; }
namespace android::content::res { class Resources_Theme; }
namespace java::lang { class Object; }
namespace java::lang { class String; }

namespace android::view {

class ContextThemeWrapper : public object_base<SCAPIX_META_STRING("android/view/ContextThemeWrapper"),
	android::content::ContextWrapper>
{
public:

	static ref<ContextThemeWrapper> new_object();
	static ref<ContextThemeWrapper> new_object(ref<android::content::Context> base, jint themeResId);
	static ref<ContextThemeWrapper> new_object(ref<android::content::Context> base, ref<android::content::res::Resources_Theme> theme);
	void applyOverrideConfiguration(ref<android::content::res::Configuration> overrideConfiguration);
	ref<android::content::res::AssetManager> getAssets();
	ref<android::content::res::Resources> getResources();
	void setTheme(jint resid);
	ref<android::content::res::Resources_Theme> getTheme();
	ref<java::lang::Object> getSystemService(ref<java::lang::String> name);

protected:

	ContextThemeWrapper(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/content/res/AssetManager.h>
#include <scapix/java_api/android/content/res/Configuration.h>
#include <scapix/java_api/android/content/res/Resources.h>
#include <scapix/java_api/android/content/res/Resources_Theme.h>
#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::view {

inline ref<ContextThemeWrapper> ContextThemeWrapper::new_object() { return base_::new_object(); }
inline ref<ContextThemeWrapper> ContextThemeWrapper::new_object(ref<android::content::Context> base, jint themeResId) { return base_::new_object(base, themeResId); }
inline ref<ContextThemeWrapper> ContextThemeWrapper::new_object(ref<android::content::Context> base, ref<android::content::res::Resources_Theme> theme) { return base_::new_object(base, theme); }
inline void ContextThemeWrapper::applyOverrideConfiguration(ref<android::content::res::Configuration> overrideConfiguration) { return call_method<SCAPIX_META_STRING("applyOverrideConfiguration"), void>(overrideConfiguration); }
inline ref<android::content::res::AssetManager> ContextThemeWrapper::getAssets() { return call_method<SCAPIX_META_STRING("getAssets"), ref<android::content::res::AssetManager>>(); }
inline ref<android::content::res::Resources> ContextThemeWrapper::getResources() { return call_method<SCAPIX_META_STRING("getResources"), ref<android::content::res::Resources>>(); }
inline void ContextThemeWrapper::setTheme(jint resid) { return call_method<SCAPIX_META_STRING("setTheme"), void>(resid); }
inline ref<android::content::res::Resources_Theme> ContextThemeWrapper::getTheme() { return call_method<SCAPIX_META_STRING("getTheme"), ref<android::content::res::Resources_Theme>>(); }
inline ref<java::lang::Object> ContextThemeWrapper::getSystemService(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("getSystemService"), ref<java::lang::Object>>(name); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_CONTEXTTHEMEWRAPPER_H
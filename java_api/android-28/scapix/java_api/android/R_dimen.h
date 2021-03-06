// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_R_DIMEN_H
#define SCAPIX_ANDROID_R_DIMEN_H

namespace scapix::java_api {


namespace android {

class R_dimen : public object_base<SCAPIX_META_STRING("android/R$dimen"),
	java::lang::Object>
{
public:

	static jint app_icon_size();
	static jint dialog_min_width_major();
	static jint dialog_min_width_minor();
	static jint notification_large_icon_height();
	static jint notification_large_icon_width();
	static jint thumbnail_height();
	static jint thumbnail_width();

	static ref<R_dimen> new_object();

protected:

	R_dimen(handle_type h) : base_(h) {}

};

} // namespace android
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android {

inline jint R_dimen::app_icon_size() { return get_static_field<SCAPIX_META_STRING("app_icon_size"), jint>(); }
inline jint R_dimen::dialog_min_width_major() { return get_static_field<SCAPIX_META_STRING("dialog_min_width_major"), jint>(); }
inline jint R_dimen::dialog_min_width_minor() { return get_static_field<SCAPIX_META_STRING("dialog_min_width_minor"), jint>(); }
inline jint R_dimen::notification_large_icon_height() { return get_static_field<SCAPIX_META_STRING("notification_large_icon_height"), jint>(); }
inline jint R_dimen::notification_large_icon_width() { return get_static_field<SCAPIX_META_STRING("notification_large_icon_width"), jint>(); }
inline jint R_dimen::thumbnail_height() { return get_static_field<SCAPIX_META_STRING("thumbnail_height"), jint>(); }
inline jint R_dimen::thumbnail_width() { return get_static_field<SCAPIX_META_STRING("thumbnail_width"), jint>(); }
inline ref<R_dimen> R_dimen::new_object() { return base_::new_object(); }

} // namespace android
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_R_DIMEN_H

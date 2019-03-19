// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_APP_NOTIFICATIONCHANNELGROUP_H
#define SCAPIX_ANDROID_APP_NOTIFICATIONCHANNELGROUP_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::util { class List; }

namespace android::app {

class NotificationChannelGroup : public object_base<SCAPIX_META_STRING("android/app/NotificationChannelGroup"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	static ref<NotificationChannelGroup> new_object(ref<java::lang::String> id, ref<java::lang::CharSequence> name);
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	ref<java::lang::String> getId();
	ref<java::lang::CharSequence> getName();
	ref<java::lang::String> getDescription();
	ref<java::util::List> getChannels();
	jboolean isBlocked();
	void setDescription(ref<java::lang::String> description);
	jint describeContents();
	jboolean equals(ref<java::lang::Object> o);
	jint hashCode();
	ref<android::app::NotificationChannelGroup> clone();
	ref<java::lang::String> toString();

protected:

	NotificationChannelGroup(handle_type h) : base_(h) {}

};

} // namespace android::app
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::app {

inline ref<android::os::Parcelable_Creator> NotificationChannelGroup::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<NotificationChannelGroup> NotificationChannelGroup::new_object(ref<java::lang::String> id, ref<java::lang::CharSequence> name) { return base_::new_object(id, name); }
inline void NotificationChannelGroup::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline ref<java::lang::String> NotificationChannelGroup::getId() { return call_method<SCAPIX_META_STRING("getId"), ref<java::lang::String>>(); }
inline ref<java::lang::CharSequence> NotificationChannelGroup::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::CharSequence>>(); }
inline ref<java::lang::String> NotificationChannelGroup::getDescription() { return call_method<SCAPIX_META_STRING("getDescription"), ref<java::lang::String>>(); }
inline ref<java::util::List> NotificationChannelGroup::getChannels() { return call_method<SCAPIX_META_STRING("getChannels"), ref<java::util::List>>(); }
inline jboolean NotificationChannelGroup::isBlocked() { return call_method<SCAPIX_META_STRING("isBlocked"), jboolean>(); }
inline void NotificationChannelGroup::setDescription(ref<java::lang::String> description) { return call_method<SCAPIX_META_STRING("setDescription"), void>(description); }
inline jint NotificationChannelGroup::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline jboolean NotificationChannelGroup::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jint NotificationChannelGroup::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<android::app::NotificationChannelGroup> NotificationChannelGroup::clone() { return call_method<SCAPIX_META_STRING("clone"), ref<android::app::NotificationChannelGroup>>(); }
inline ref<java::lang::String> NotificationChannelGroup::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::app
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_NOTIFICATIONCHANNELGROUP_H
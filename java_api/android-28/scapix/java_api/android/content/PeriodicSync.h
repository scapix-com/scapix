// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_CONTENT_PERIODICSYNC_H
#define SCAPIX_ANDROID_CONTENT_PERIODICSYNC_H

namespace scapix::java_api {

namespace android::accounts { class Account; }
namespace android::os { class Bundle; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::content {

class PeriodicSync : public object_base<SCAPIX_META_STRING("android/content/PeriodicSync"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	ref<android::accounts::Account> account();
	ref<java::lang::String> authority();
	ref<android::os::Bundle> extras();
	jlong period();

	static ref<PeriodicSync> new_object(ref<android::accounts::Account> account, ref<java::lang::String> authority, ref<android::os::Bundle> extras, jlong periodInSeconds);
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jboolean equals(ref<java::lang::Object> o);
	ref<java::lang::String> toString();

protected:

	PeriodicSync(handle_type h) : base_(h) {}

};

} // namespace android::content
} // namespace scapix::java_api

#include <scapix/java_api/android/accounts/Account.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::content {

inline ref<android::os::Parcelable_Creator> PeriodicSync::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<android::accounts::Account> PeriodicSync::account() { return get_field<SCAPIX_META_STRING("account"), ref<android::accounts::Account>>(); }
inline ref<java::lang::String> PeriodicSync::authority() { return get_field<SCAPIX_META_STRING("authority"), ref<java::lang::String>>(); }
inline ref<android::os::Bundle> PeriodicSync::extras() { return get_field<SCAPIX_META_STRING("extras"), ref<android::os::Bundle>>(); }
inline jlong PeriodicSync::period() { return get_field<SCAPIX_META_STRING("period"), jlong>(); }
inline ref<PeriodicSync> PeriodicSync::new_object(ref<android::accounts::Account> account, ref<java::lang::String> authority, ref<android::os::Bundle> extras, jlong periodInSeconds) { return base_::new_object(account, authority, extras, periodInSeconds); }
inline jint PeriodicSync::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void PeriodicSync::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jboolean PeriodicSync::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline ref<java::lang::String> PeriodicSync::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::content
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_PERIODICSYNC_H
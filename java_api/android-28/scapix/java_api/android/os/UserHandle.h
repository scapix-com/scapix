// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_OS_USERHANDLE_H
#define SCAPIX_ANDROID_OS_USERHANDLE_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::os {

class UserHandle : public object_base<SCAPIX_META_STRING("android/os/UserHandle"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	static ref<UserHandle> new_object(ref<android::os::Parcel> in);
	static ref<android::os::UserHandle> getUserHandleForUid(jint uid);
	ref<java::lang::String> toString();
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> out, jint flags);
	static void writeToParcel(ref<android::os::UserHandle> h, ref<android::os::Parcel> out);
	static ref<android::os::UserHandle> readFromParcel(ref<android::os::Parcel> in);

protected:

	UserHandle(handle_type h) : base_(h) {}

};

} // namespace android::os
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::os {

inline ref<android::os::Parcelable_Creator> UserHandle::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<UserHandle> UserHandle::new_object(ref<android::os::Parcel> in) { return base_::new_object(in); }
inline ref<android::os::UserHandle> UserHandle::getUserHandleForUid(jint uid) { return call_static_method<SCAPIX_META_STRING("getUserHandleForUid"), ref<android::os::UserHandle>>(uid); }
inline ref<java::lang::String> UserHandle::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jboolean UserHandle::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint UserHandle::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jint UserHandle::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void UserHandle::writeToParcel(ref<android::os::Parcel> out, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(out, flags); }
inline void UserHandle::writeToParcel(ref<android::os::UserHandle> h, ref<android::os::Parcel> out) { return call_static_method<SCAPIX_META_STRING("writeToParcel"), void>(h, out); }
inline ref<android::os::UserHandle> UserHandle::readFromParcel(ref<android::os::Parcel> in) { return call_static_method<SCAPIX_META_STRING("readFromParcel"), ref<android::os::UserHandle>>(in); }

} // namespace android::os
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_USERHANDLE_H
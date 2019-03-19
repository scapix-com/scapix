// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_TELEPHONY_CELLINFO_H
#define SCAPIX_ANDROID_TELEPHONY_CELLINFO_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::telephony {

class CellInfo : public object_base<SCAPIX_META_STRING("android/telephony/CellInfo"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static jint CONNECTION_NONE_();
	static jint CONNECTION_PRIMARY_SERVING_();
	static jint CONNECTION_SECONDARY_SERVING_();
	static jint CONNECTION_UNKNOWN_();
	static ref<android::os::Parcelable_Creator> CREATOR_();

	jboolean isRegistered();
	jlong getTimeStamp();
	jint getCellConnectionStatus();
	jint hashCode();
	jboolean equals(ref<java::lang::Object> other);
	ref<java::lang::String> toString();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> p1, jint p2);

protected:

	CellInfo(handle_type h) : base_(h) {}

};

} // namespace android::telephony
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::telephony {

inline jint CellInfo::CONNECTION_NONE_() { return get_static_field<SCAPIX_META_STRING("CONNECTION_NONE"), jint>(); }
inline jint CellInfo::CONNECTION_PRIMARY_SERVING_() { return get_static_field<SCAPIX_META_STRING("CONNECTION_PRIMARY_SERVING"), jint>(); }
inline jint CellInfo::CONNECTION_SECONDARY_SERVING_() { return get_static_field<SCAPIX_META_STRING("CONNECTION_SECONDARY_SERVING"), jint>(); }
inline jint CellInfo::CONNECTION_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("CONNECTION_UNKNOWN"), jint>(); }
inline ref<android::os::Parcelable_Creator> CellInfo::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jboolean CellInfo::isRegistered() { return call_method<SCAPIX_META_STRING("isRegistered"), jboolean>(); }
inline jlong CellInfo::getTimeStamp() { return call_method<SCAPIX_META_STRING("getTimeStamp"), jlong>(); }
inline jint CellInfo::getCellConnectionStatus() { return call_method<SCAPIX_META_STRING("getCellConnectionStatus"), jint>(); }
inline jint CellInfo::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean CellInfo::equals(ref<java::lang::Object> other) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(other); }
inline ref<java::lang::String> CellInfo::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint CellInfo::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void CellInfo::writeToParcel(ref<android::os::Parcel> p1, jint p2) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(p1, p2); }

} // namespace android::telephony
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TELEPHONY_CELLINFO_H
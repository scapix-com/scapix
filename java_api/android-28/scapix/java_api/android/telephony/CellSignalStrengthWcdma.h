// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/telephony/CellSignalStrength.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_TELEPHONY_CELLSIGNALSTRENGTHWCDMA_H
#define SCAPIX_ANDROID_TELEPHONY_CELLSIGNALSTRENGTHWCDMA_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class Object; }
namespace java::lang { class String; }

namespace android::telephony {

class CellSignalStrengthWcdma : public object_base<SCAPIX_META_STRING("android/telephony/CellSignalStrengthWcdma"),
	android::telephony::CellSignalStrength,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	jint getLevel();
	jint getDbm();
	jint getAsuLevel();
	jint hashCode();
	jboolean equals(ref<java::lang::Object> o);
	ref<java::lang::String> toString();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jint describeContents();

protected:

	CellSignalStrengthWcdma(handle_type h) : base_(h) {}

};

} // namespace android::telephony
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::telephony {

inline ref<android::os::Parcelable_Creator> CellSignalStrengthWcdma::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint CellSignalStrengthWcdma::getLevel() { return call_method<SCAPIX_META_STRING("getLevel"), jint>(); }
inline jint CellSignalStrengthWcdma::getDbm() { return call_method<SCAPIX_META_STRING("getDbm"), jint>(); }
inline jint CellSignalStrengthWcdma::getAsuLevel() { return call_method<SCAPIX_META_STRING("getAsuLevel"), jint>(); }
inline jint CellSignalStrengthWcdma::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean CellSignalStrengthWcdma::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline ref<java::lang::String> CellSignalStrengthWcdma::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline void CellSignalStrengthWcdma::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jint CellSignalStrengthWcdma::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }

} // namespace android::telephony
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TELEPHONY_CELLSIGNALSTRENGTHWCDMA_H

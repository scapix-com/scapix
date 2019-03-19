// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_TELEPHONY_NETWORKSCANREQUEST_H
#define SCAPIX_ANDROID_TELEPHONY_NETWORKSCANREQUEST_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace android::telephony { class RadioAccessSpecifier; }
namespace java::util { class ArrayList; }

namespace android::telephony {

class NetworkScanRequest : public object_base<SCAPIX_META_STRING("android/telephony/NetworkScanRequest"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint SCAN_TYPE_ONE_SHOT_();
	static jint SCAN_TYPE_PERIODIC_();

	static ref<NetworkScanRequest> new_object(jint scanType, ref<link::java::array<android::telephony::RadioAccessSpecifier>> specifiers, jint searchPeriodicity, jint maxSearchTime, jboolean incrementalResults, jint incrementalResultsPeriodicity, ref<java::util::ArrayList> mccMncs);
	jint getScanType();
	jint getSearchPeriodicity();
	jint getMaxSearchTime();
	jboolean getIncrementalResults();
	jint getIncrementalResultsPeriodicity();
	ref<link::java::array<android::telephony::RadioAccessSpecifier>> getSpecifiers();
	ref<java::util::ArrayList> getPlmns();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jboolean equals(ref<java::lang::Object> o);
	jint hashCode();

protected:

	NetworkScanRequest(handle_type h) : base_(h) {}

};

} // namespace android::telephony
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/android/telephony/RadioAccessSpecifier.h>
#include <scapix/java_api/java/util/ArrayList.h>

namespace scapix::java_api {
namespace android::telephony {

inline ref<android::os::Parcelable_Creator> NetworkScanRequest::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint NetworkScanRequest::SCAN_TYPE_ONE_SHOT_() { return get_static_field<SCAPIX_META_STRING("SCAN_TYPE_ONE_SHOT"), jint>(); }
inline jint NetworkScanRequest::SCAN_TYPE_PERIODIC_() { return get_static_field<SCAPIX_META_STRING("SCAN_TYPE_PERIODIC"), jint>(); }
inline ref<NetworkScanRequest> NetworkScanRequest::new_object(jint scanType, ref<link::java::array<android::telephony::RadioAccessSpecifier>> specifiers, jint searchPeriodicity, jint maxSearchTime, jboolean incrementalResults, jint incrementalResultsPeriodicity, ref<java::util::ArrayList> mccMncs) { return base_::new_object(scanType, specifiers, searchPeriodicity, maxSearchTime, incrementalResults, incrementalResultsPeriodicity, mccMncs); }
inline jint NetworkScanRequest::getScanType() { return call_method<SCAPIX_META_STRING("getScanType"), jint>(); }
inline jint NetworkScanRequest::getSearchPeriodicity() { return call_method<SCAPIX_META_STRING("getSearchPeriodicity"), jint>(); }
inline jint NetworkScanRequest::getMaxSearchTime() { return call_method<SCAPIX_META_STRING("getMaxSearchTime"), jint>(); }
inline jboolean NetworkScanRequest::getIncrementalResults() { return call_method<SCAPIX_META_STRING("getIncrementalResults"), jboolean>(); }
inline jint NetworkScanRequest::getIncrementalResultsPeriodicity() { return call_method<SCAPIX_META_STRING("getIncrementalResultsPeriodicity"), jint>(); }
inline ref<link::java::array<android::telephony::RadioAccessSpecifier>> NetworkScanRequest::getSpecifiers() { return call_method<SCAPIX_META_STRING("getSpecifiers"), ref<link::java::array<android::telephony::RadioAccessSpecifier>>>(); }
inline ref<java::util::ArrayList> NetworkScanRequest::getPlmns() { return call_method<SCAPIX_META_STRING("getPlmns"), ref<java::util::ArrayList>>(); }
inline jint NetworkScanRequest::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void NetworkScanRequest::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jboolean NetworkScanRequest::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jint NetworkScanRequest::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }

} // namespace android::telephony
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TELEPHONY_NETWORKSCANREQUEST_H
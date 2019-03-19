// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_APP_JOB_JOBINFO_H
#define SCAPIX_ANDROID_APP_JOB_JOBINFO_H

namespace scapix::java_api {

namespace android::app::job { class JobInfo_TriggerContentUri; }
namespace android::content { class ClipData; }
namespace android::content { class ComponentName; }
namespace android::net { class NetworkRequest; }
namespace android::os { class Bundle; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace android::os { class PersistableBundle; }
namespace java::lang { class String; }
namespace android::app::job { class JobInfo_Builder; }

namespace android::app::job {

class JobInfo : public object_base<SCAPIX_META_STRING("android/app/job/JobInfo"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	using TriggerContentUri = JobInfo_TriggerContentUri;
	using Builder = JobInfo_Builder;

	static jint BACKOFF_POLICY_EXPONENTIAL_();
	static jint BACKOFF_POLICY_LINEAR_();
	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jlong DEFAULT_INITIAL_BACKOFF_MILLIS_();
	static jlong MAX_BACKOFF_DELAY_MILLIS_();
	static jint NETWORK_BYTES_UNKNOWN_();
	static jint NETWORK_TYPE_ANY_();
	static jint NETWORK_TYPE_CELLULAR_();
	static jint NETWORK_TYPE_METERED_();
	static jint NETWORK_TYPE_NONE_();
	static jint NETWORK_TYPE_NOT_ROAMING_();
	static jint NETWORK_TYPE_UNMETERED_();

	static jlong getMinPeriodMillis();
	static jlong getMinFlexMillis();
	jint getId();
	ref<android::os::PersistableBundle> getExtras();
	ref<android::os::Bundle> getTransientExtras();
	ref<android::content::ClipData> getClipData();
	jint getClipGrantFlags();
	ref<android::content::ComponentName> getService();
	jboolean isRequireCharging();
	jboolean isRequireBatteryNotLow();
	jboolean isRequireDeviceIdle();
	jboolean isRequireStorageNotLow();
	ref<link::java::array<android::app::job::JobInfo_TriggerContentUri>> getTriggerContentUris();
	jlong getTriggerContentUpdateDelay();
	jlong getTriggerContentMaxDelay();
	jint getNetworkType();
	ref<android::net::NetworkRequest> getRequiredNetwork();
	jlong getEstimatedNetworkDownloadBytes();
	jlong getEstimatedNetworkUploadBytes();
	jlong getMinLatencyMillis();
	jlong getMaxExecutionDelayMillis();
	jboolean isPeriodic();
	jboolean isPersisted();
	jlong getIntervalMillis();
	jlong getFlexMillis();
	jlong getInitialBackoffMillis();
	jint getBackoffPolicy();
	jboolean isImportantWhileForeground();
	jboolean isPrefetch();
	jboolean equals(ref<java::lang::Object> o);
	jint hashCode();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> out, jint flags);
	ref<java::lang::String> toString();

protected:

	JobInfo(handle_type h) : base_(h) {}

};

} // namespace android::app::job
} // namespace scapix::java_api

#include <scapix/java_api/android/app/job/JobInfo_TriggerContentUri.h>
#include <scapix/java_api/android/content/ClipData.h>
#include <scapix/java_api/android/content/ComponentName.h>
#include <scapix/java_api/android/net/NetworkRequest.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/android/os/PersistableBundle.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::app::job {

inline jint JobInfo::BACKOFF_POLICY_EXPONENTIAL_() { return get_static_field<SCAPIX_META_STRING("BACKOFF_POLICY_EXPONENTIAL"), jint>(); }
inline jint JobInfo::BACKOFF_POLICY_LINEAR_() { return get_static_field<SCAPIX_META_STRING("BACKOFF_POLICY_LINEAR"), jint>(); }
inline ref<android::os::Parcelable_Creator> JobInfo::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jlong JobInfo::DEFAULT_INITIAL_BACKOFF_MILLIS_() { return get_static_field<SCAPIX_META_STRING("DEFAULT_INITIAL_BACKOFF_MILLIS"), jlong>(); }
inline jlong JobInfo::MAX_BACKOFF_DELAY_MILLIS_() { return get_static_field<SCAPIX_META_STRING("MAX_BACKOFF_DELAY_MILLIS"), jlong>(); }
inline jint JobInfo::NETWORK_BYTES_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("NETWORK_BYTES_UNKNOWN"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_ANY_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_ANY"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_CELLULAR_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_CELLULAR"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_METERED_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_METERED"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_NONE_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_NONE"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_NOT_ROAMING_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_NOT_ROAMING"), jint>(); }
inline jint JobInfo::NETWORK_TYPE_UNMETERED_() { return get_static_field<SCAPIX_META_STRING("NETWORK_TYPE_UNMETERED"), jint>(); }
inline jlong JobInfo::getMinPeriodMillis() { return call_static_method<SCAPIX_META_STRING("getMinPeriodMillis"), jlong>(); }
inline jlong JobInfo::getMinFlexMillis() { return call_static_method<SCAPIX_META_STRING("getMinFlexMillis"), jlong>(); }
inline jint JobInfo::getId() { return call_method<SCAPIX_META_STRING("getId"), jint>(); }
inline ref<android::os::PersistableBundle> JobInfo::getExtras() { return call_method<SCAPIX_META_STRING("getExtras"), ref<android::os::PersistableBundle>>(); }
inline ref<android::os::Bundle> JobInfo::getTransientExtras() { return call_method<SCAPIX_META_STRING("getTransientExtras"), ref<android::os::Bundle>>(); }
inline ref<android::content::ClipData> JobInfo::getClipData() { return call_method<SCAPIX_META_STRING("getClipData"), ref<android::content::ClipData>>(); }
inline jint JobInfo::getClipGrantFlags() { return call_method<SCAPIX_META_STRING("getClipGrantFlags"), jint>(); }
inline ref<android::content::ComponentName> JobInfo::getService() { return call_method<SCAPIX_META_STRING("getService"), ref<android::content::ComponentName>>(); }
inline jboolean JobInfo::isRequireCharging() { return call_method<SCAPIX_META_STRING("isRequireCharging"), jboolean>(); }
inline jboolean JobInfo::isRequireBatteryNotLow() { return call_method<SCAPIX_META_STRING("isRequireBatteryNotLow"), jboolean>(); }
inline jboolean JobInfo::isRequireDeviceIdle() { return call_method<SCAPIX_META_STRING("isRequireDeviceIdle"), jboolean>(); }
inline jboolean JobInfo::isRequireStorageNotLow() { return call_method<SCAPIX_META_STRING("isRequireStorageNotLow"), jboolean>(); }
inline ref<link::java::array<android::app::job::JobInfo_TriggerContentUri>> JobInfo::getTriggerContentUris() { return call_method<SCAPIX_META_STRING("getTriggerContentUris"), ref<link::java::array<android::app::job::JobInfo_TriggerContentUri>>>(); }
inline jlong JobInfo::getTriggerContentUpdateDelay() { return call_method<SCAPIX_META_STRING("getTriggerContentUpdateDelay"), jlong>(); }
inline jlong JobInfo::getTriggerContentMaxDelay() { return call_method<SCAPIX_META_STRING("getTriggerContentMaxDelay"), jlong>(); }
inline jint JobInfo::getNetworkType() { return call_method<SCAPIX_META_STRING("getNetworkType"), jint>(); }
inline ref<android::net::NetworkRequest> JobInfo::getRequiredNetwork() { return call_method<SCAPIX_META_STRING("getRequiredNetwork"), ref<android::net::NetworkRequest>>(); }
inline jlong JobInfo::getEstimatedNetworkDownloadBytes() { return call_method<SCAPIX_META_STRING("getEstimatedNetworkDownloadBytes"), jlong>(); }
inline jlong JobInfo::getEstimatedNetworkUploadBytes() { return call_method<SCAPIX_META_STRING("getEstimatedNetworkUploadBytes"), jlong>(); }
inline jlong JobInfo::getMinLatencyMillis() { return call_method<SCAPIX_META_STRING("getMinLatencyMillis"), jlong>(); }
inline jlong JobInfo::getMaxExecutionDelayMillis() { return call_method<SCAPIX_META_STRING("getMaxExecutionDelayMillis"), jlong>(); }
inline jboolean JobInfo::isPeriodic() { return call_method<SCAPIX_META_STRING("isPeriodic"), jboolean>(); }
inline jboolean JobInfo::isPersisted() { return call_method<SCAPIX_META_STRING("isPersisted"), jboolean>(); }
inline jlong JobInfo::getIntervalMillis() { return call_method<SCAPIX_META_STRING("getIntervalMillis"), jlong>(); }
inline jlong JobInfo::getFlexMillis() { return call_method<SCAPIX_META_STRING("getFlexMillis"), jlong>(); }
inline jlong JobInfo::getInitialBackoffMillis() { return call_method<SCAPIX_META_STRING("getInitialBackoffMillis"), jlong>(); }
inline jint JobInfo::getBackoffPolicy() { return call_method<SCAPIX_META_STRING("getBackoffPolicy"), jint>(); }
inline jboolean JobInfo::isImportantWhileForeground() { return call_method<SCAPIX_META_STRING("isImportantWhileForeground"), jboolean>(); }
inline jboolean JobInfo::isPrefetch() { return call_method<SCAPIX_META_STRING("isPrefetch"), jboolean>(); }
inline jboolean JobInfo::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jint JobInfo::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jint JobInfo::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void JobInfo::writeToParcel(ref<android::os::Parcel> out, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(out, flags); }
inline ref<java::lang::String> JobInfo::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::app::job
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_JOB_JOBINFO_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_CONTENT_SYNCSTATS_H
#define SCAPIX_ANDROID_CONTENT_SYNCSTATS_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::content {

class SyncStats : public object_base<SCAPIX_META_STRING("android/content/SyncStats"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	jlong numAuthExceptions();
	void numAuthExceptions(jlong);
	jlong numConflictDetectedExceptions();
	void numConflictDetectedExceptions(jlong);
	jlong numDeletes();
	void numDeletes(jlong);
	jlong numEntries();
	void numEntries(jlong);
	jlong numInserts();
	void numInserts(jlong);
	jlong numIoExceptions();
	void numIoExceptions(jlong);
	jlong numParseExceptions();
	void numParseExceptions(jlong);
	jlong numSkippedEntries();
	void numSkippedEntries(jlong);
	jlong numUpdates();
	void numUpdates(jlong);

	static ref<SyncStats> new_object();
	static ref<SyncStats> new_object(ref<android::os::Parcel> in);
	ref<java::lang::String> toString();
	void clear();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);

protected:

	SyncStats(handle_type h) : base_(h) {}

};

} // namespace android::content
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::content {

inline ref<android::os::Parcelable_Creator> SyncStats::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jlong SyncStats::numAuthExceptions() { return get_field<SCAPIX_META_STRING("numAuthExceptions"), jlong>(); }
inline void SyncStats::numAuthExceptions(jlong v) { set_field<SCAPIX_META_STRING("numAuthExceptions"), jlong>(v); }
inline jlong SyncStats::numConflictDetectedExceptions() { return get_field<SCAPIX_META_STRING("numConflictDetectedExceptions"), jlong>(); }
inline void SyncStats::numConflictDetectedExceptions(jlong v) { set_field<SCAPIX_META_STRING("numConflictDetectedExceptions"), jlong>(v); }
inline jlong SyncStats::numDeletes() { return get_field<SCAPIX_META_STRING("numDeletes"), jlong>(); }
inline void SyncStats::numDeletes(jlong v) { set_field<SCAPIX_META_STRING("numDeletes"), jlong>(v); }
inline jlong SyncStats::numEntries() { return get_field<SCAPIX_META_STRING("numEntries"), jlong>(); }
inline void SyncStats::numEntries(jlong v) { set_field<SCAPIX_META_STRING("numEntries"), jlong>(v); }
inline jlong SyncStats::numInserts() { return get_field<SCAPIX_META_STRING("numInserts"), jlong>(); }
inline void SyncStats::numInserts(jlong v) { set_field<SCAPIX_META_STRING("numInserts"), jlong>(v); }
inline jlong SyncStats::numIoExceptions() { return get_field<SCAPIX_META_STRING("numIoExceptions"), jlong>(); }
inline void SyncStats::numIoExceptions(jlong v) { set_field<SCAPIX_META_STRING("numIoExceptions"), jlong>(v); }
inline jlong SyncStats::numParseExceptions() { return get_field<SCAPIX_META_STRING("numParseExceptions"), jlong>(); }
inline void SyncStats::numParseExceptions(jlong v) { set_field<SCAPIX_META_STRING("numParseExceptions"), jlong>(v); }
inline jlong SyncStats::numSkippedEntries() { return get_field<SCAPIX_META_STRING("numSkippedEntries"), jlong>(); }
inline void SyncStats::numSkippedEntries(jlong v) { set_field<SCAPIX_META_STRING("numSkippedEntries"), jlong>(v); }
inline jlong SyncStats::numUpdates() { return get_field<SCAPIX_META_STRING("numUpdates"), jlong>(); }
inline void SyncStats::numUpdates(jlong v) { set_field<SCAPIX_META_STRING("numUpdates"), jlong>(v); }
inline ref<SyncStats> SyncStats::new_object() { return base_::new_object(); }
inline ref<SyncStats> SyncStats::new_object(ref<android::os::Parcel> in) { return base_::new_object(in); }
inline ref<java::lang::String> SyncStats::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline void SyncStats::clear() { return call_method<SCAPIX_META_STRING("clear"), void>(); }
inline jint SyncStats::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void SyncStats::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }

} // namespace android::content
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_SYNCSTATS_H
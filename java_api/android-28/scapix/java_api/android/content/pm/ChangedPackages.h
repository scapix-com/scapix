// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_CONTENT_PM_CHANGEDPACKAGES_H
#define SCAPIX_ANDROID_CONTENT_PM_CHANGEDPACKAGES_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::util { class List; }

namespace android::content::pm {

class ChangedPackages : public object_base<SCAPIX_META_STRING("android/content/pm/ChangedPackages"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	static ref<ChangedPackages> new_object(jint sequenceNumber, ref<java::util::List> packageNames);
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jint getSequenceNumber();
	ref<java::util::List> getPackageNames();

protected:

	ChangedPackages(handle_type h) : base_(h) {}

};

} // namespace android::content::pm
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::content::pm {

inline ref<android::os::Parcelable_Creator> ChangedPackages::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<ChangedPackages> ChangedPackages::new_object(jint sequenceNumber, ref<java::util::List> packageNames) { return base_::new_object(sequenceNumber, packageNames); }
inline jint ChangedPackages::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void ChangedPackages::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jint ChangedPackages::getSequenceNumber() { return call_method<SCAPIX_META_STRING("getSequenceNumber"), jint>(); }
inline ref<java::util::List> ChangedPackages::getPackageNames() { return call_method<SCAPIX_META_STRING("getPackageNames"), ref<java::util::List>>(); }

} // namespace android::content::pm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_PM_CHANGEDPACKAGES_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_SERVICE_AUTOFILL_FILLCONTEXT_H
#define SCAPIX_ANDROID_SERVICE_AUTOFILL_FILLCONTEXT_H

namespace scapix::java_api {

namespace android::app::assist { class AssistStructure; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::service::autofill {

class FillContext : public object_base<SCAPIX_META_STRING("android/service/autofill/FillContext"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	jint getRequestId();
	ref<android::app::assist::AssistStructure> getStructure();
	ref<java::lang::String> toString();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> parcel, jint flags);

protected:

	FillContext(handle_type h) : base_(h) {}

};

} // namespace android::service::autofill
} // namespace scapix::java_api

#include <scapix/java_api/android/app/assist/AssistStructure.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::service::autofill {

inline ref<android::os::Parcelable_Creator> FillContext::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint FillContext::getRequestId() { return call_method<SCAPIX_META_STRING("getRequestId"), jint>(); }
inline ref<android::app::assist::AssistStructure> FillContext::getStructure() { return call_method<SCAPIX_META_STRING("getStructure"), ref<android::app::assist::AssistStructure>>(); }
inline ref<java::lang::String> FillContext::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint FillContext::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void FillContext::writeToParcel(ref<android::os::Parcel> parcel, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(parcel, flags); }

} // namespace android::service::autofill
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_SERVICE_AUTOFILL_FILLCONTEXT_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_TEXT_PARCELABLESPAN_H
#define SCAPIX_ANDROID_TEXT_PARCELABLESPAN_H

namespace scapix::java_api {
namespace android::text {

class ParcelableSpan : public object_base<SCAPIX_META_STRING("android/text/ParcelableSpan"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	jint getSpanTypeId();

protected:

	ParcelableSpan(handle_type h) : base_(h) {}

};

} // namespace android::text
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::text {

inline jint ParcelableSpan::getSpanTypeId() { return call_method<SCAPIX_META_STRING("getSpanTypeId"), jint>(); }

} // namespace android::text
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TEXT_PARCELABLESPAN_H
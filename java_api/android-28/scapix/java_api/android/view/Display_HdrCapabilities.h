// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_VIEW_DISPLAY_HDRCAPABILITIES_H
#define SCAPIX_ANDROID_VIEW_DISPLAY_HDRCAPABILITIES_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }

namespace android::view {

class Display_HdrCapabilities : public object_base<SCAPIX_META_STRING("android/view/Display$HdrCapabilities"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint HDR_TYPE_DOLBY_VISION_();
	static jint HDR_TYPE_HDR10_();
	static jint HDR_TYPE_HLG_();
	static jfloat INVALID_LUMINANCE_();

	ref<link::java::array<jint>> getSupportedHdrTypes();
	jfloat getDesiredMaxLuminance();
	jfloat getDesiredMaxAverageLuminance();
	jfloat getDesiredMinLuminance();
	jboolean equals(ref<java::lang::Object> other);
	jint hashCode();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jint describeContents();

protected:

	Display_HdrCapabilities(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>

namespace scapix::java_api {
namespace android::view {

inline ref<android::os::Parcelable_Creator> Display_HdrCapabilities::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint Display_HdrCapabilities::HDR_TYPE_DOLBY_VISION_() { return get_static_field<SCAPIX_META_STRING("HDR_TYPE_DOLBY_VISION"), jint>(); }
inline jint Display_HdrCapabilities::HDR_TYPE_HDR10_() { return get_static_field<SCAPIX_META_STRING("HDR_TYPE_HDR10"), jint>(); }
inline jint Display_HdrCapabilities::HDR_TYPE_HLG_() { return get_static_field<SCAPIX_META_STRING("HDR_TYPE_HLG"), jint>(); }
inline jfloat Display_HdrCapabilities::INVALID_LUMINANCE_() { return get_static_field<SCAPIX_META_STRING("INVALID_LUMINANCE"), jfloat>(); }
inline ref<link::java::array<jint>> Display_HdrCapabilities::getSupportedHdrTypes() { return call_method<SCAPIX_META_STRING("getSupportedHdrTypes"), ref<link::java::array<jint>>>(); }
inline jfloat Display_HdrCapabilities::getDesiredMaxLuminance() { return call_method<SCAPIX_META_STRING("getDesiredMaxLuminance"), jfloat>(); }
inline jfloat Display_HdrCapabilities::getDesiredMaxAverageLuminance() { return call_method<SCAPIX_META_STRING("getDesiredMaxAverageLuminance"), jfloat>(); }
inline jfloat Display_HdrCapabilities::getDesiredMinLuminance() { return call_method<SCAPIX_META_STRING("getDesiredMinLuminance"), jfloat>(); }
inline jboolean Display_HdrCapabilities::equals(ref<java::lang::Object> other) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(other); }
inline jint Display_HdrCapabilities::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline void Display_HdrCapabilities::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jint Display_HdrCapabilities::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_DISPLAY_HDRCAPABILITIES_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_CONTENT_PM_FEATUREINFO_H
#define SCAPIX_ANDROID_CONTENT_PM_FEATUREINFO_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::content::pm {

class FeatureInfo : public object_base<SCAPIX_META_STRING("android/content/pm/FeatureInfo"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint FLAG_REQUIRED_();
	static jint GL_ES_VERSION_UNDEFINED_();
	jint flags();
	void flags(jint);
	ref<java::lang::String> name();
	void name(ref<java::lang::String>);
	jint reqGlEsVersion();
	void reqGlEsVersion(jint);
	jint version();
	void version(jint);

	static ref<FeatureInfo> new_object();
	static ref<FeatureInfo> new_object(ref<android::content::pm::FeatureInfo> orig);
	ref<java::lang::String> toString();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint parcelableFlags);
	ref<java::lang::String> getGlEsVersion();

protected:

	FeatureInfo(handle_type h) : base_(h) {}

};

} // namespace android::content::pm
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::content::pm {

inline ref<android::os::Parcelable_Creator> FeatureInfo::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint FeatureInfo::FLAG_REQUIRED_() { return get_static_field<SCAPIX_META_STRING("FLAG_REQUIRED"), jint>(); }
inline jint FeatureInfo::GL_ES_VERSION_UNDEFINED_() { return get_static_field<SCAPIX_META_STRING("GL_ES_VERSION_UNDEFINED"), jint>(); }
inline jint FeatureInfo::flags() { return get_field<SCAPIX_META_STRING("flags"), jint>(); }
inline void FeatureInfo::flags(jint v) { set_field<SCAPIX_META_STRING("flags"), jint>(v); }
inline ref<java::lang::String> FeatureInfo::name() { return get_field<SCAPIX_META_STRING("name"), ref<java::lang::String>>(); }
inline void FeatureInfo::name(ref<java::lang::String> v) { set_field<SCAPIX_META_STRING("name"), ref<java::lang::String>>(v); }
inline jint FeatureInfo::reqGlEsVersion() { return get_field<SCAPIX_META_STRING("reqGlEsVersion"), jint>(); }
inline void FeatureInfo::reqGlEsVersion(jint v) { set_field<SCAPIX_META_STRING("reqGlEsVersion"), jint>(v); }
inline jint FeatureInfo::version() { return get_field<SCAPIX_META_STRING("version"), jint>(); }
inline void FeatureInfo::version(jint v) { set_field<SCAPIX_META_STRING("version"), jint>(v); }
inline ref<FeatureInfo> FeatureInfo::new_object() { return base_::new_object(); }
inline ref<FeatureInfo> FeatureInfo::new_object(ref<android::content::pm::FeatureInfo> orig) { return base_::new_object(orig); }
inline ref<java::lang::String> FeatureInfo::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint FeatureInfo::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void FeatureInfo::writeToParcel(ref<android::os::Parcel> dest, jint parcelableFlags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, parcelableFlags); }
inline ref<java::lang::String> FeatureInfo::getGlEsVersion() { return call_method<SCAPIX_META_STRING("getGlEsVersion"), ref<java::lang::String>>(); }

} // namespace android::content::pm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_PM_FEATUREINFO_H
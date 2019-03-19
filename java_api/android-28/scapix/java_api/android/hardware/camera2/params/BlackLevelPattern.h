// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_HARDWARE_CAMERA2_PARAMS_BLACKLEVELPATTERN_H
#define SCAPIX_ANDROID_HARDWARE_CAMERA2_PARAMS_BLACKLEVELPATTERN_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::hardware::camera2::params {

class BlackLevelPattern : public object_base<SCAPIX_META_STRING("android/hardware/camera2/params/BlackLevelPattern"),
	java::lang::Object>
{
public:

	static jint COUNT_();

	jint getOffsetForIndex(jint column, jint row);
	void copyTo(ref<link::java::array<jint>> destination, jint offset);
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	BlackLevelPattern(handle_type h) : base_(h) {}

};

} // namespace android::hardware::camera2::params
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::hardware::camera2::params {

inline jint BlackLevelPattern::COUNT_() { return get_static_field<SCAPIX_META_STRING("COUNT"), jint>(); }
inline jint BlackLevelPattern::getOffsetForIndex(jint column, jint row) { return call_method<SCAPIX_META_STRING("getOffsetForIndex"), jint>(column, row); }
inline void BlackLevelPattern::copyTo(ref<link::java::array<jint>> destination, jint offset) { return call_method<SCAPIX_META_STRING("copyTo"), void>(destination, offset); }
inline jboolean BlackLevelPattern::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint BlackLevelPattern::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> BlackLevelPattern::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::hardware::camera2::params
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_HARDWARE_CAMERA2_PARAMS_BLACKLEVELPATTERN_H
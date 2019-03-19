// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_OS_PATTERNMATCHER_H
#define SCAPIX_ANDROID_OS_PATTERNMATCHER_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::os {

class PatternMatcher : public object_base<SCAPIX_META_STRING("android/os/PatternMatcher"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint PATTERN_ADVANCED_GLOB_();
	static jint PATTERN_LITERAL_();
	static jint PATTERN_PREFIX_();
	static jint PATTERN_SIMPLE_GLOB_();

	static ref<PatternMatcher> new_object(ref<java::lang::String> pattern, jint type);
	static ref<PatternMatcher> new_object(ref<android::os::Parcel> src);
	ref<java::lang::String> getPath();
	jint getType();
	jboolean match(ref<java::lang::String> str);
	ref<java::lang::String> toString();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);

protected:

	PatternMatcher(handle_type h) : base_(h) {}

};

} // namespace android::os
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::os {

inline ref<android::os::Parcelable_Creator> PatternMatcher::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint PatternMatcher::PATTERN_ADVANCED_GLOB_() { return get_static_field<SCAPIX_META_STRING("PATTERN_ADVANCED_GLOB"), jint>(); }
inline jint PatternMatcher::PATTERN_LITERAL_() { return get_static_field<SCAPIX_META_STRING("PATTERN_LITERAL"), jint>(); }
inline jint PatternMatcher::PATTERN_PREFIX_() { return get_static_field<SCAPIX_META_STRING("PATTERN_PREFIX"), jint>(); }
inline jint PatternMatcher::PATTERN_SIMPLE_GLOB_() { return get_static_field<SCAPIX_META_STRING("PATTERN_SIMPLE_GLOB"), jint>(); }
inline ref<PatternMatcher> PatternMatcher::new_object(ref<java::lang::String> pattern, jint type) { return base_::new_object(pattern, type); }
inline ref<PatternMatcher> PatternMatcher::new_object(ref<android::os::Parcel> src) { return base_::new_object(src); }
inline ref<java::lang::String> PatternMatcher::getPath() { return call_method<SCAPIX_META_STRING("getPath"), ref<java::lang::String>>(); }
inline jint PatternMatcher::getType() { return call_method<SCAPIX_META_STRING("getType"), jint>(); }
inline jboolean PatternMatcher::match(ref<java::lang::String> str) { return call_method<SCAPIX_META_STRING("match"), jboolean>(str); }
inline ref<java::lang::String> PatternMatcher::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint PatternMatcher::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void PatternMatcher::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }

} // namespace android::os
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_PATTERNMATCHER_H
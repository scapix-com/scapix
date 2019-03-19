// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_ICU_LANG_UPROPERTY_NAMECHOICE_H
#define SCAPIX_ANDROID_ICU_LANG_UPROPERTY_NAMECHOICE_H

namespace scapix::java_api {


namespace android::icu::lang {

class UProperty_NameChoice : public object_base<SCAPIX_META_STRING("android/icu/lang/UProperty$NameChoice"),
	java::lang::Object>
{
public:

	static jint LONG_();
	static jint SHORT_();


protected:

	UProperty_NameChoice(handle_type h) : base_(h) {}

};

} // namespace android::icu::lang
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::icu::lang {

inline jint UProperty_NameChoice::LONG_() { return get_static_field<SCAPIX_META_STRING("LONG"), jint>(); }
inline jint UProperty_NameChoice::SHORT_() { return get_static_field<SCAPIX_META_STRING("SHORT"), jint>(); }

} // namespace android::icu::lang
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_LANG_UPROPERTY_NAMECHOICE_H
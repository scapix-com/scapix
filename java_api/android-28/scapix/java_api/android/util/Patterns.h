// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_UTIL_PATTERNS_H
#define SCAPIX_ANDROID_UTIL_PATTERNS_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::util::regex { class Matcher; }
namespace java::util::regex { class Pattern; }

namespace android::util {

class Patterns : public object_base<SCAPIX_META_STRING("android/util/Patterns"),
	java::lang::Object>
{
public:

	static ref<java::util::regex::Pattern> DOMAIN_NAME_();
	static ref<java::util::regex::Pattern> EMAIL_ADDRESS_();
	static ref<java::lang::String> GOOD_IRI_CHAR_();
	static ref<java::util::regex::Pattern> IP_ADDRESS_();
	static ref<java::util::regex::Pattern> PHONE_();
	static ref<java::util::regex::Pattern> TOP_LEVEL_DOMAIN_();
	static ref<java::lang::String> TOP_LEVEL_DOMAIN_STR_();
	static ref<java::lang::String> TOP_LEVEL_DOMAIN_STR_FOR_WEB_URL_();
	static ref<java::util::regex::Pattern> WEB_URL_();

	static ref<java::lang::String> concatGroups(ref<java::util::regex::Matcher> matcher);
	static ref<java::lang::String> digitsAndPlusOnly(ref<java::util::regex::Matcher> matcher);

protected:

	Patterns(handle_type h) : base_(h) {}

};

} // namespace android::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/regex/Matcher.h>
#include <scapix/java_api/java/util/regex/Pattern.h>

namespace scapix::java_api {
namespace android::util {

inline ref<java::util::regex::Pattern> Patterns::DOMAIN_NAME_() { return get_static_field<SCAPIX_META_STRING("DOMAIN_NAME"), ref<java::util::regex::Pattern>>(); }
inline ref<java::util::regex::Pattern> Patterns::EMAIL_ADDRESS_() { return get_static_field<SCAPIX_META_STRING("EMAIL_ADDRESS"), ref<java::util::regex::Pattern>>(); }
inline ref<java::lang::String> Patterns::GOOD_IRI_CHAR_() { return get_static_field<SCAPIX_META_STRING("GOOD_IRI_CHAR"), ref<java::lang::String>>(); }
inline ref<java::util::regex::Pattern> Patterns::IP_ADDRESS_() { return get_static_field<SCAPIX_META_STRING("IP_ADDRESS"), ref<java::util::regex::Pattern>>(); }
inline ref<java::util::regex::Pattern> Patterns::PHONE_() { return get_static_field<SCAPIX_META_STRING("PHONE"), ref<java::util::regex::Pattern>>(); }
inline ref<java::util::regex::Pattern> Patterns::TOP_LEVEL_DOMAIN_() { return get_static_field<SCAPIX_META_STRING("TOP_LEVEL_DOMAIN"), ref<java::util::regex::Pattern>>(); }
inline ref<java::lang::String> Patterns::TOP_LEVEL_DOMAIN_STR_() { return get_static_field<SCAPIX_META_STRING("TOP_LEVEL_DOMAIN_STR"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Patterns::TOP_LEVEL_DOMAIN_STR_FOR_WEB_URL_() { return get_static_field<SCAPIX_META_STRING("TOP_LEVEL_DOMAIN_STR_FOR_WEB_URL"), ref<java::lang::String>>(); }
inline ref<java::util::regex::Pattern> Patterns::WEB_URL_() { return get_static_field<SCAPIX_META_STRING("WEB_URL"), ref<java::util::regex::Pattern>>(); }
inline ref<java::lang::String> Patterns::concatGroups(ref<java::util::regex::Matcher> matcher) { return call_static_method<SCAPIX_META_STRING("concatGroups"), ref<java::lang::String>>(matcher); }
inline ref<java::lang::String> Patterns::digitsAndPlusOnly(ref<java::util::regex::Matcher> matcher) { return call_static_method<SCAPIX_META_STRING("digitsAndPlusOnly"), ref<java::lang::String>>(matcher); }

} // namespace android::util
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_UTIL_PATTERNS_H
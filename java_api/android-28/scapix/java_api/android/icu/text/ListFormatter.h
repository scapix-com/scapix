// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_ICU_TEXT_LISTFORMATTER_H
#define SCAPIX_ANDROID_ICU_TEXT_LISTFORMATTER_H

namespace scapix::java_api {

namespace android::icu::util { class ULocale; }
namespace java::lang { class String; }
namespace java::util { class Collection; }
namespace java::util { class Locale; }

namespace android::icu::text {

class ListFormatter : public object_base<SCAPIX_META_STRING("android/icu/text/ListFormatter"),
	java::lang::Object>
{
public:

	static ref<android::icu::text::ListFormatter> getInstance(ref<android::icu::util::ULocale> locale);
	static ref<android::icu::text::ListFormatter> getInstance(ref<java::util::Locale> locale);
	static ref<android::icu::text::ListFormatter> getInstance();
	ref<java::lang::String> format(ref<link::java::array<java::lang::Object>> items);
	ref<java::lang::String> format(ref<java::util::Collection> items);
	ref<java::lang::String> getPatternForNumItems(jint count);

protected:

	ListFormatter(handle_type h) : base_(h) {}

};

} // namespace android::icu::text
} // namespace scapix::java_api

#include <scapix/java_api/android/icu/util/ULocale.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Collection.h>
#include <scapix/java_api/java/util/Locale.h>

namespace scapix::java_api {
namespace android::icu::text {

inline ref<android::icu::text::ListFormatter> ListFormatter::getInstance(ref<android::icu::util::ULocale> locale) { return call_static_method<SCAPIX_META_STRING("getInstance"), ref<android::icu::text::ListFormatter>>(locale); }
inline ref<android::icu::text::ListFormatter> ListFormatter::getInstance(ref<java::util::Locale> locale) { return call_static_method<SCAPIX_META_STRING("getInstance"), ref<android::icu::text::ListFormatter>>(locale); }
inline ref<android::icu::text::ListFormatter> ListFormatter::getInstance() { return call_static_method<SCAPIX_META_STRING("getInstance"), ref<android::icu::text::ListFormatter>>(); }
inline ref<java::lang::String> ListFormatter::format(ref<link::java::array<java::lang::Object>> items) { return call_method<SCAPIX_META_STRING("format"), ref<java::lang::String>>(items); }
inline ref<java::lang::String> ListFormatter::format(ref<java::util::Collection> items) { return call_method<SCAPIX_META_STRING("format"), ref<java::lang::String>>(items); }
inline ref<java::lang::String> ListFormatter::getPatternForNumItems(jint count) { return call_method<SCAPIX_META_STRING("getPatternForNumItems"), ref<java::lang::String>>(count); }

} // namespace android::icu::text
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_ICU_TEXT_LISTFORMATTER_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_UTIL_LOG_H
#define SCAPIX_ANDROID_UTIL_LOG_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace android::util {

class Log : public object_base<SCAPIX_META_STRING("android/util/Log"),
	java::lang::Object>
{
public:

	static jint ASSERT_();
	static jint DEBUG_();
	static jint ERROR_();
	static jint INFO_();
	static jint VERBOSE_();
	static jint WARN_();

	static jint v(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint v(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static jint d(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint d(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static jint i(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint i(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static jint w(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint w(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static jboolean isLoggable(ref<java::lang::String> p1, jint p2);
	static jint w(ref<java::lang::String> tag, ref<java::lang::Throwable> tr);
	static jint e(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint e(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static jint wtf(ref<java::lang::String> tag, ref<java::lang::String> msg);
	static jint wtf(ref<java::lang::String> tag, ref<java::lang::Throwable> tr);
	static jint wtf(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr);
	static ref<java::lang::String> getStackTraceString(ref<java::lang::Throwable> tr);
	static jint println(jint priority, ref<java::lang::String> tag, ref<java::lang::String> msg);

protected:

	Log(handle_type h) : base_(h) {}

};

} // namespace android::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace android::util {

inline jint Log::ASSERT_() { return get_static_field<SCAPIX_META_STRING("ASSERT"), jint>(); }
inline jint Log::DEBUG_() { return get_static_field<SCAPIX_META_STRING("DEBUG"), jint>(); }
inline jint Log::ERROR_() { return get_static_field<SCAPIX_META_STRING("ERROR"), jint>(); }
inline jint Log::INFO_() { return get_static_field<SCAPIX_META_STRING("INFO"), jint>(); }
inline jint Log::VERBOSE_() { return get_static_field<SCAPIX_META_STRING("VERBOSE"), jint>(); }
inline jint Log::WARN_() { return get_static_field<SCAPIX_META_STRING("WARN"), jint>(); }
inline jint Log::v(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("v"), jint>(tag, msg); }
inline jint Log::v(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("v"), jint>(tag, msg, tr); }
inline jint Log::d(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("d"), jint>(tag, msg); }
inline jint Log::d(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("d"), jint>(tag, msg, tr); }
inline jint Log::i(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("i"), jint>(tag, msg); }
inline jint Log::i(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("i"), jint>(tag, msg, tr); }
inline jint Log::w(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("w"), jint>(tag, msg); }
inline jint Log::w(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("w"), jint>(tag, msg, tr); }
inline jboolean Log::isLoggable(ref<java::lang::String> p1, jint p2) { return call_static_method<SCAPIX_META_STRING("isLoggable"), jboolean>(p1, p2); }
inline jint Log::w(ref<java::lang::String> tag, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("w"), jint>(tag, tr); }
inline jint Log::e(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("e"), jint>(tag, msg); }
inline jint Log::e(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("e"), jint>(tag, msg, tr); }
inline jint Log::wtf(ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("wtf"), jint>(tag, msg); }
inline jint Log::wtf(ref<java::lang::String> tag, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("wtf"), jint>(tag, tr); }
inline jint Log::wtf(ref<java::lang::String> tag, ref<java::lang::String> msg, ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("wtf"), jint>(tag, msg, tr); }
inline ref<java::lang::String> Log::getStackTraceString(ref<java::lang::Throwable> tr) { return call_static_method<SCAPIX_META_STRING("getStackTraceString"), ref<java::lang::String>>(tr); }
inline jint Log::println(jint priority, ref<java::lang::String> tag, ref<java::lang::String> msg) { return call_static_method<SCAPIX_META_STRING("println"), jint>(priority, tag, msg); }

} // namespace android::util
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_UTIL_LOG_H
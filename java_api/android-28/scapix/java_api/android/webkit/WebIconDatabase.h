// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_WEBKIT_WEBICONDATABASE_H
#define SCAPIX_ANDROID_WEBKIT_WEBICONDATABASE_H

namespace scapix::java_api {

namespace android::webkit { class WebIconDatabase_IconListener; }
namespace java::lang { class String; }

namespace android::webkit {

class WebIconDatabase : public object_base<SCAPIX_META_STRING("android/webkit/WebIconDatabase"),
	java::lang::Object>
{
public:

	using IconListener = WebIconDatabase_IconListener;

	static ref<WebIconDatabase> new_object();
	void open(ref<java::lang::String> p1);
	void close();
	void removeAllIcons();
	void requestIconForPageUrl(ref<java::lang::String> p1, ref<android::webkit::WebIconDatabase_IconListener> p2);
	void retainIconForPageUrl(ref<java::lang::String> p1);
	void releaseIconForPageUrl(ref<java::lang::String> p1);
	static ref<android::webkit::WebIconDatabase> getInstance();

protected:

	WebIconDatabase(handle_type h) : base_(h) {}

};

} // namespace android::webkit
} // namespace scapix::java_api

#include <scapix/java_api/android/webkit/WebIconDatabase_IconListener.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::webkit {

inline ref<WebIconDatabase> WebIconDatabase::new_object() { return base_::new_object(); }
inline void WebIconDatabase::open(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("open"), void>(p1); }
inline void WebIconDatabase::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }
inline void WebIconDatabase::removeAllIcons() { return call_method<SCAPIX_META_STRING("removeAllIcons"), void>(); }
inline void WebIconDatabase::requestIconForPageUrl(ref<java::lang::String> p1, ref<android::webkit::WebIconDatabase_IconListener> p2) { return call_method<SCAPIX_META_STRING("requestIconForPageUrl"), void>(p1, p2); }
inline void WebIconDatabase::retainIconForPageUrl(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("retainIconForPageUrl"), void>(p1); }
inline void WebIconDatabase::releaseIconForPageUrl(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("releaseIconForPageUrl"), void>(p1); }
inline ref<android::webkit::WebIconDatabase> WebIconDatabase::getInstance() { return call_static_method<SCAPIX_META_STRING("getInstance"), ref<android::webkit::WebIconDatabase>>(); }

} // namespace android::webkit
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_WEBKIT_WEBICONDATABASE_H

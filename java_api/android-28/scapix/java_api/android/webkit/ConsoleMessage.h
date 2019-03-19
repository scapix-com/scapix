// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_WEBKIT_CONSOLEMESSAGE_H
#define SCAPIX_ANDROID_WEBKIT_CONSOLEMESSAGE_H

namespace scapix::java_api {

namespace android::webkit { class ConsoleMessage_MessageLevel; }
namespace java::lang { class String; }

namespace android::webkit {

class ConsoleMessage : public object_base<SCAPIX_META_STRING("android/webkit/ConsoleMessage"),
	java::lang::Object>
{
public:

	using MessageLevel = ConsoleMessage_MessageLevel;

	static ref<ConsoleMessage> new_object(ref<java::lang::String> message, ref<java::lang::String> sourceId, jint lineNumber, ref<android::webkit::ConsoleMessage_MessageLevel> msgLevel);
	ref<android::webkit::ConsoleMessage_MessageLevel> messageLevel();
	ref<java::lang::String> message();
	ref<java::lang::String> sourceId();
	jint lineNumber();

protected:

	ConsoleMessage(handle_type h) : base_(h) {}

};

} // namespace android::webkit
} // namespace scapix::java_api

#include <scapix/java_api/android/webkit/ConsoleMessage_MessageLevel.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::webkit {

inline ref<ConsoleMessage> ConsoleMessage::new_object(ref<java::lang::String> message, ref<java::lang::String> sourceId, jint lineNumber, ref<android::webkit::ConsoleMessage_MessageLevel> msgLevel) { return base_::new_object(message, sourceId, lineNumber, msgLevel); }
inline ref<android::webkit::ConsoleMessage_MessageLevel> ConsoleMessage::messageLevel() { return call_method<SCAPIX_META_STRING("messageLevel"), ref<android::webkit::ConsoleMessage_MessageLevel>>(); }
inline ref<java::lang::String> ConsoleMessage::message() { return call_method<SCAPIX_META_STRING("message"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ConsoleMessage::sourceId() { return call_method<SCAPIX_META_STRING("sourceId"), ref<java::lang::String>>(); }
inline jint ConsoleMessage::lineNumber() { return call_method<SCAPIX_META_STRING("lineNumber"), jint>(); }

} // namespace android::webkit
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_WEBKIT_CONSOLEMESSAGE_H
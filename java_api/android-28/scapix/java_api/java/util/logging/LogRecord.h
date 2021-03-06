// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_UTIL_LOGGING_LOGRECORD_H
#define SCAPIX_JAVA_UTIL_LOGGING_LOGRECORD_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }
namespace java::util { class ResourceBundle; }
namespace java::util::logging { class Level; }

namespace java::util::logging {

class LogRecord : public object_base<SCAPIX_META_STRING("java/util/logging/LogRecord"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<LogRecord> new_object(ref<java::util::logging::Level> level, ref<java::lang::String> msg);
	ref<java::lang::String> getLoggerName();
	void setLoggerName(ref<java::lang::String> name);
	ref<java::util::ResourceBundle> getResourceBundle();
	void setResourceBundle(ref<java::util::ResourceBundle> bundle);
	ref<java::lang::String> getResourceBundleName();
	void setResourceBundleName(ref<java::lang::String> name);
	ref<java::util::logging::Level> getLevel();
	void setLevel(ref<java::util::logging::Level> level);
	jlong getSequenceNumber();
	void setSequenceNumber(jlong seq);
	ref<java::lang::String> getSourceClassName();
	void setSourceClassName(ref<java::lang::String> sourceClassName);
	ref<java::lang::String> getSourceMethodName();
	void setSourceMethodName(ref<java::lang::String> sourceMethodName);
	ref<java::lang::String> getMessage();
	void setMessage(ref<java::lang::String> message);
	ref<link::java::array<java::lang::Object>> getParameters();
	void setParameters(ref<link::java::array<java::lang::Object>> parameters);
	jint getThreadID();
	void setThreadID(jint threadID);
	jlong getMillis();
	void setMillis(jlong millis);
	ref<java::lang::Throwable> getThrown();
	void setThrown(ref<java::lang::Throwable> thrown);

protected:

	LogRecord(handle_type h) : base_(h) {}

};

} // namespace java::util::logging
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>
#include <scapix/java_api/java/util/ResourceBundle.h>
#include <scapix/java_api/java/util/logging/Level.h>

namespace scapix::java_api {
namespace java::util::logging {

inline ref<LogRecord> LogRecord::new_object(ref<java::util::logging::Level> level, ref<java::lang::String> msg) { return base_::new_object(level, msg); }
inline ref<java::lang::String> LogRecord::getLoggerName() { return call_method<SCAPIX_META_STRING("getLoggerName"), ref<java::lang::String>>(); }
inline void LogRecord::setLoggerName(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("setLoggerName"), void>(name); }
inline ref<java::util::ResourceBundle> LogRecord::getResourceBundle() { return call_method<SCAPIX_META_STRING("getResourceBundle"), ref<java::util::ResourceBundle>>(); }
inline void LogRecord::setResourceBundle(ref<java::util::ResourceBundle> bundle) { return call_method<SCAPIX_META_STRING("setResourceBundle"), void>(bundle); }
inline ref<java::lang::String> LogRecord::getResourceBundleName() { return call_method<SCAPIX_META_STRING("getResourceBundleName"), ref<java::lang::String>>(); }
inline void LogRecord::setResourceBundleName(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("setResourceBundleName"), void>(name); }
inline ref<java::util::logging::Level> LogRecord::getLevel() { return call_method<SCAPIX_META_STRING("getLevel"), ref<java::util::logging::Level>>(); }
inline void LogRecord::setLevel(ref<java::util::logging::Level> level) { return call_method<SCAPIX_META_STRING("setLevel"), void>(level); }
inline jlong LogRecord::getSequenceNumber() { return call_method<SCAPIX_META_STRING("getSequenceNumber"), jlong>(); }
inline void LogRecord::setSequenceNumber(jlong seq) { return call_method<SCAPIX_META_STRING("setSequenceNumber"), void>(seq); }
inline ref<java::lang::String> LogRecord::getSourceClassName() { return call_method<SCAPIX_META_STRING("getSourceClassName"), ref<java::lang::String>>(); }
inline void LogRecord::setSourceClassName(ref<java::lang::String> sourceClassName) { return call_method<SCAPIX_META_STRING("setSourceClassName"), void>(sourceClassName); }
inline ref<java::lang::String> LogRecord::getSourceMethodName() { return call_method<SCAPIX_META_STRING("getSourceMethodName"), ref<java::lang::String>>(); }
inline void LogRecord::setSourceMethodName(ref<java::lang::String> sourceMethodName) { return call_method<SCAPIX_META_STRING("setSourceMethodName"), void>(sourceMethodName); }
inline ref<java::lang::String> LogRecord::getMessage() { return call_method<SCAPIX_META_STRING("getMessage"), ref<java::lang::String>>(); }
inline void LogRecord::setMessage(ref<java::lang::String> message) { return call_method<SCAPIX_META_STRING("setMessage"), void>(message); }
inline ref<link::java::array<java::lang::Object>> LogRecord::getParameters() { return call_method<SCAPIX_META_STRING("getParameters"), ref<link::java::array<java::lang::Object>>>(); }
inline void LogRecord::setParameters(ref<link::java::array<java::lang::Object>> parameters) { return call_method<SCAPIX_META_STRING("setParameters"), void>(parameters); }
inline jint LogRecord::getThreadID() { return call_method<SCAPIX_META_STRING("getThreadID"), jint>(); }
inline void LogRecord::setThreadID(jint threadID) { return call_method<SCAPIX_META_STRING("setThreadID"), void>(threadID); }
inline jlong LogRecord::getMillis() { return call_method<SCAPIX_META_STRING("getMillis"), jlong>(); }
inline void LogRecord::setMillis(jlong millis) { return call_method<SCAPIX_META_STRING("setMillis"), void>(millis); }
inline ref<java::lang::Throwable> LogRecord::getThrown() { return call_method<SCAPIX_META_STRING("getThrown"), ref<java::lang::Throwable>>(); }
inline void LogRecord::setThrown(ref<java::lang::Throwable> thrown) { return call_method<SCAPIX_META_STRING("setThrown"), void>(thrown); }

} // namespace java::util::logging
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_LOGGING_LOGRECORD_H

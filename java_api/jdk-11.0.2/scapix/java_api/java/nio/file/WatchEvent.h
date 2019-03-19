// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_NIO_FILE_WATCHEVENT_H
#define SCAPIX_JAVA_NIO_FILE_WATCHEVENT_H

namespace scapix::java_api {

namespace java::nio::file { class WatchEvent_Kind; }
namespace java::nio::file { class WatchEvent_Modifier; }

namespace java::nio::file {

class WatchEvent : public object_base<SCAPIX_META_STRING("java/nio/file/WatchEvent"),
	java::lang::Object>
{
public:

	using Modifier = WatchEvent_Modifier;
	using Kind = WatchEvent_Kind;

	ref<java::nio::file::WatchEvent_Kind> kind();
	jint count();
	ref<java::lang::Object> context();

protected:

	WatchEvent(handle_type h) : base_(h) {}

};

} // namespace java::nio::file
} // namespace scapix::java_api

#include <scapix/java_api/java/nio/file/WatchEvent_Kind.h>

namespace scapix::java_api {
namespace java::nio::file {

inline ref<java::nio::file::WatchEvent_Kind> WatchEvent::kind() { return call_method<SCAPIX_META_STRING("kind"), ref<java::nio::file::WatchEvent_Kind>>(); }
inline jint WatchEvent::count() { return call_method<SCAPIX_META_STRING("count"), jint>(); }
inline ref<java::lang::Object> WatchEvent::context() { return call_method<SCAPIX_META_STRING("context"), ref<java::lang::Object>>(); }

} // namespace java::nio::file
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_FILE_WATCHEVENT_H
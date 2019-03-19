// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_TIME_FORMAT_DATETIMEPARSECONTEXT_H
#define SCAPIX_JAVA_TIME_FORMAT_DATETIMEPARSECONTEXT_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::time::format {

// private
class DateTimeParseContext : public object_base<SCAPIX_META_STRING("java/time/format/DateTimeParseContext"),
	java::lang::Object>
{
public:

	ref<java::lang::String> toString();

protected:

	DateTimeParseContext(handle_type h) : base_(h) {}

};

} // namespace java::time::format
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::time::format {

inline ref<java::lang::String> DateTimeParseContext::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::time::format
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TIME_FORMAT_DATETIMEPARSECONTEXT_H
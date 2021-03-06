// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Error.h>

#ifndef SCAPIX_JAVA_UTIL_SERVICECONFIGURATIONERROR_H
#define SCAPIX_JAVA_UTIL_SERVICECONFIGURATIONERROR_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace java::util {

class ServiceConfigurationError : public object_base<SCAPIX_META_STRING("java/util/ServiceConfigurationError"),
	java::lang::Error>
{
public:

	static ref<ServiceConfigurationError> new_object(ref<java::lang::String> msg);
	static ref<ServiceConfigurationError> new_object(ref<java::lang::String> msg, ref<java::lang::Throwable> cause);

protected:

	ServiceConfigurationError(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace java::util {

inline ref<ServiceConfigurationError> ServiceConfigurationError::new_object(ref<java::lang::String> msg) { return base_::new_object(msg); }
inline ref<ServiceConfigurationError> ServiceConfigurationError::new_object(ref<java::lang::String> msg, ref<java::lang::Throwable> cause) { return base_::new_object(msg, cause); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_SERVICECONFIGURATIONERROR_H

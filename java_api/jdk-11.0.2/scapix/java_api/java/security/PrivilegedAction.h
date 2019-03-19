// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SECURITY_PRIVILEGEDACTION_H
#define SCAPIX_JAVA_SECURITY_PRIVILEGEDACTION_H

namespace scapix::java_api {
namespace java::security {

class PrivilegedAction : public object_base<SCAPIX_META_STRING("java/security/PrivilegedAction"),
	java::lang::Object>
{
public:

	ref<java::lang::Object> run();

protected:

	PrivilegedAction(handle_type h) : base_(h) {}

};

} // namespace java::security
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::security {

inline ref<java::lang::Object> PrivilegedAction::run() { return call_method<SCAPIX_META_STRING("run"), ref<java::lang::Object>>(); }

} // namespace java::security
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_PRIVILEGEDACTION_H
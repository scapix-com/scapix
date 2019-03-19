// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Exception.h>

#ifndef SCAPIX_JAVA_SECURITY_ACL_LASTOWNEREXCEPTION_H
#define SCAPIX_JAVA_SECURITY_ACL_LASTOWNEREXCEPTION_H

namespace scapix::java_api {
namespace java::security::acl {

class LastOwnerException : public object_base<SCAPIX_META_STRING("java/security/acl/LastOwnerException"),
	java::lang::Exception>
{
public:

	static ref<LastOwnerException> new_object();

protected:

	LastOwnerException(handle_type h) : base_(h) {}

};

} // namespace java::security::acl
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::security::acl {

inline ref<LastOwnerException> LastOwnerException::new_object() { return base_::new_object(); }

} // namespace java::security::acl
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_ACL_LASTOWNEREXCEPTION_H
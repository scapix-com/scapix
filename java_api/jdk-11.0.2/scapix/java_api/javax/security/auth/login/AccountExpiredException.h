// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/javax/security/auth/login/AccountException.h>

#ifndef SCAPIX_JAVAX_SECURITY_AUTH_LOGIN_ACCOUNTEXPIREDEXCEPTION_H
#define SCAPIX_JAVAX_SECURITY_AUTH_LOGIN_ACCOUNTEXPIREDEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace javax::security::auth::login {

class AccountExpiredException : public object_base<SCAPIX_META_STRING("javax/security/auth/login/AccountExpiredException"),
	javax::security::auth::login::AccountException>
{
public:

	static ref<AccountExpiredException> new_object();
	static ref<AccountExpiredException> new_object(ref<java::lang::String> msg);

protected:

	AccountExpiredException(handle_type h) : base_(h) {}

};

} // namespace javax::security::auth::login
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace javax::security::auth::login {

inline ref<AccountExpiredException> AccountExpiredException::new_object() { return base_::new_object(); }
inline ref<AccountExpiredException> AccountExpiredException::new_object(ref<java::lang::String> msg) { return base_::new_object(msg); }

} // namespace javax::security::auth::login
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_SECURITY_AUTH_LOGIN_ACCOUNTEXPIREDEXCEPTION_H
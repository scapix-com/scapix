// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/LinkageError.h>

#ifndef SCAPIX_JAVA_LANG_BOOTSTRAPMETHODERROR_H
#define SCAPIX_JAVA_LANG_BOOTSTRAPMETHODERROR_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace java::lang {

class BootstrapMethodError : public object_base<SCAPIX_META_STRING("java/lang/BootstrapMethodError"),
	java::lang::LinkageError>
{
public:

	static ref<BootstrapMethodError> new_object();
	static ref<BootstrapMethodError> new_object(ref<java::lang::String> s);
	static ref<BootstrapMethodError> new_object(ref<java::lang::String> s, ref<java::lang::Throwable> cause);
	static ref<BootstrapMethodError> new_object(ref<java::lang::Throwable> cause);

protected:

	BootstrapMethodError(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace java::lang {

inline ref<BootstrapMethodError> BootstrapMethodError::new_object() { return base_::new_object(); }
inline ref<BootstrapMethodError> BootstrapMethodError::new_object(ref<java::lang::String> s) { return base_::new_object(s); }
inline ref<BootstrapMethodError> BootstrapMethodError::new_object(ref<java::lang::String> s, ref<java::lang::Throwable> cause) { return base_::new_object(s, cause); }
inline ref<BootstrapMethodError> BootstrapMethodError::new_object(ref<java::lang::Throwable> cause) { return base_::new_object(cause); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_BOOTSTRAPMETHODERROR_H

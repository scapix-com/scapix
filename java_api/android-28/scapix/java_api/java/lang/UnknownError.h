// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/VirtualMachineError.h>

#ifndef SCAPIX_JAVA_LANG_UNKNOWNERROR_H
#define SCAPIX_JAVA_LANG_UNKNOWNERROR_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::lang {

class UnknownError : public object_base<SCAPIX_META_STRING("java/lang/UnknownError"),
	java::lang::VirtualMachineError>
{
public:

	static ref<UnknownError> new_object();
	static ref<UnknownError> new_object(ref<java::lang::String> s);

protected:

	UnknownError(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::lang {

inline ref<UnknownError> UnknownError::new_object() { return base_::new_object(); }
inline ref<UnknownError> UnknownError::new_object(ref<java::lang::String> s) { return base_::new_object(s); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_UNKNOWNERROR_H
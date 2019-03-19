// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/RuntimeException.h>

#ifndef SCAPIX_JAVA_LANG_TYPENOTPRESENTEXCEPTION_H
#define SCAPIX_JAVA_LANG_TYPENOTPRESENTEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace java::lang {

class TypeNotPresentException : public object_base<SCAPIX_META_STRING("java/lang/TypeNotPresentException"),
	java::lang::RuntimeException>
{
public:

	static ref<TypeNotPresentException> new_object(ref<java::lang::String> typeName, ref<java::lang::Throwable> cause);
	ref<java::lang::String> typeName();

protected:

	TypeNotPresentException(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace java::lang {

inline ref<TypeNotPresentException> TypeNotPresentException::new_object(ref<java::lang::String> typeName, ref<java::lang::Throwable> cause) { return base_::new_object(typeName, cause); }
inline ref<java::lang::String> TypeNotPresentException::typeName() { return call_method<SCAPIX_META_STRING("typeName"), ref<java::lang::String>>(); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_TYPENOTPRESENTEXCEPTION_H
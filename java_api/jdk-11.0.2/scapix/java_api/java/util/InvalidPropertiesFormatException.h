// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/IOException.h>

#ifndef SCAPIX_JAVA_UTIL_INVALIDPROPERTIESFORMATEXCEPTION_H
#define SCAPIX_JAVA_UTIL_INVALIDPROPERTIESFORMATEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace java::util {

class InvalidPropertiesFormatException : public object_base<SCAPIX_META_STRING("java/util/InvalidPropertiesFormatException"),
	java::io::IOException>
{
public:

	static ref<InvalidPropertiesFormatException> new_object(ref<java::lang::Throwable> cause);
	static ref<InvalidPropertiesFormatException> new_object(ref<java::lang::String> message);

protected:

	InvalidPropertiesFormatException(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace java::util {

inline ref<InvalidPropertiesFormatException> InvalidPropertiesFormatException::new_object(ref<java::lang::Throwable> cause) { return base_::new_object(cause); }
inline ref<InvalidPropertiesFormatException> InvalidPropertiesFormatException::new_object(ref<java::lang::String> message) { return base_::new_object(message); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_INVALIDPROPERTIESFORMATEXCEPTION_H
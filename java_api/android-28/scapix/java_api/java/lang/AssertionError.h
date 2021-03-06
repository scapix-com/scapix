// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Error.h>

#ifndef SCAPIX_JAVA_LANG_ASSERTIONERROR_H
#define SCAPIX_JAVA_LANG_ASSERTIONERROR_H

namespace scapix::java_api {

namespace java::lang { class Object; }
namespace java::lang { class String; }
namespace java::lang { class Throwable; }

namespace java::lang {

class AssertionError : public object_base<SCAPIX_META_STRING("java/lang/AssertionError"),
	java::lang::Error>
{
public:

	static ref<AssertionError> new_object();
	static ref<AssertionError> new_object(ref<java::lang::Object> detailMessage);
	static ref<AssertionError> new_object(jboolean detailMessage);
	static ref<AssertionError> new_object(jchar detailMessage);
	static ref<AssertionError> new_object(jint detailMessage);
	static ref<AssertionError> new_object(jlong detailMessage);
	static ref<AssertionError> new_object(jfloat detailMessage);
	static ref<AssertionError> new_object(jdouble detailMessage);
	static ref<AssertionError> new_object(ref<java::lang::String> message, ref<java::lang::Throwable> cause);

protected:

	AssertionError(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/Throwable.h>

namespace scapix::java_api {
namespace java::lang {

inline ref<AssertionError> AssertionError::new_object() { return base_::new_object(); }
inline ref<AssertionError> AssertionError::new_object(ref<java::lang::Object> detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jboolean detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jchar detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jint detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jlong detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jfloat detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(jdouble detailMessage) { return base_::new_object(detailMessage); }
inline ref<AssertionError> AssertionError::new_object(ref<java::lang::String> message, ref<java::lang::Throwable> cause) { return base_::new_object(message, cause); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_ASSERTIONERROR_H

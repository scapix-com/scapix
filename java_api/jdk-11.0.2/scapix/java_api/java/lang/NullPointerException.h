// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/RuntimeException.h>

#ifndef SCAPIX_JAVA_LANG_NULLPOINTEREXCEPTION_H
#define SCAPIX_JAVA_LANG_NULLPOINTEREXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::lang {

class NullPointerException : public object_base<SCAPIX_META_STRING("java/lang/NullPointerException"),
	java::lang::RuntimeException>
{
public:

	static ref<NullPointerException> new_object();
	static ref<NullPointerException> new_object(ref<java::lang::String> s);

protected:

	NullPointerException(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::lang {

inline ref<NullPointerException> NullPointerException::new_object() { return base_::new_object(); }
inline ref<NullPointerException> NullPointerException::new_object(ref<java::lang::String> s) { return base_::new_object(s); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_NULLPOINTEREXCEPTION_H
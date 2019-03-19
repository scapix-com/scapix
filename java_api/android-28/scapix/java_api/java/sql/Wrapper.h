// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_SQL_WRAPPER_H
#define SCAPIX_JAVA_SQL_WRAPPER_H

namespace scapix::java_api {

namespace java::lang { class Class; }

namespace java::sql {

class Wrapper : public object_base<SCAPIX_META_STRING("java/sql/Wrapper"),
	java::lang::Object>
{
public:

	ref<java::lang::Object> unwrap(ref<java::lang::Class> p1);
	jboolean isWrapperFor(ref<java::lang::Class> p1);

protected:

	Wrapper(handle_type h) : base_(h) {}

};

} // namespace java::sql
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Class.h>

namespace scapix::java_api {
namespace java::sql {

inline ref<java::lang::Object> Wrapper::unwrap(ref<java::lang::Class> p1) { return call_method<SCAPIX_META_STRING("unwrap"), ref<java::lang::Object>>(p1); }
inline jboolean Wrapper::isWrapperFor(ref<java::lang::Class> p1) { return call_method<SCAPIX_META_STRING("isWrapperFor"), jboolean>(p1); }

} // namespace java::sql
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SQL_WRAPPER_H
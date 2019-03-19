// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_UTIL_FUNCTION_DOUBLESUPPLIER_H
#define SCAPIX_JAVA_UTIL_FUNCTION_DOUBLESUPPLIER_H

namespace scapix::java_api {
namespace java::util::function {

class DoubleSupplier : public object_base<SCAPIX_META_STRING("java/util/function/DoubleSupplier"),
	java::lang::Object>
{
public:

	jdouble getAsDouble();

protected:

	DoubleSupplier(handle_type h) : base_(h) {}

};

} // namespace java::util::function
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::util::function {

inline jdouble DoubleSupplier::getAsDouble() { return call_method<SCAPIX_META_STRING("getAsDouble"), jdouble>(); }

} // namespace java::util::function
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_FUNCTION_DOUBLESUPPLIER_H
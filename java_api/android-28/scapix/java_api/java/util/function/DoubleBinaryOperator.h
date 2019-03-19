// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_UTIL_FUNCTION_DOUBLEBINARYOPERATOR_H
#define SCAPIX_JAVA_UTIL_FUNCTION_DOUBLEBINARYOPERATOR_H

namespace scapix::java_api {
namespace java::util::function {

class DoubleBinaryOperator : public object_base<SCAPIX_META_STRING("java/util/function/DoubleBinaryOperator"),
	java::lang::Object>
{
public:

	jdouble applyAsDouble(jdouble p1, jdouble p2);

protected:

	DoubleBinaryOperator(handle_type h) : base_(h) {}

};

} // namespace java::util::function
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::util::function {

inline jdouble DoubleBinaryOperator::applyAsDouble(jdouble p1, jdouble p2) { return call_method<SCAPIX_META_STRING("applyAsDouble"), jdouble>(p1, p2); }

} // namespace java::util::function
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_FUNCTION_DOUBLEBINARYOPERATOR_H
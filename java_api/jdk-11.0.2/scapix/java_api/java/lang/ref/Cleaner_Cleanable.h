// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_LANG_REF_CLEANER_CLEANABLE_H
#define SCAPIX_JAVA_LANG_REF_CLEANER_CLEANABLE_H

namespace scapix::java_api {


namespace java::lang::ref {

class Cleaner_Cleanable : public object_base<SCAPIX_META_STRING("java/lang/ref/Cleaner$Cleanable"),
	java::lang::Object>
{
public:

	void clean();

protected:

	Cleaner_Cleanable(handle_type h) : base_(h) {}

};

} // namespace java::lang::ref
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::lang::ref {

inline void Cleaner_Cleanable::clean() { return call_method<SCAPIX_META_STRING("clean"), void>(); }

} // namespace java::lang::ref
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_REF_CLEANER_CLEANABLE_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Error.h>

#ifndef SCAPIX_JAVA_LANG_THREADDEATH_H
#define SCAPIX_JAVA_LANG_THREADDEATH_H

namespace scapix::java_api {
namespace java::lang {

class ThreadDeath : public object_base<SCAPIX_META_STRING("java/lang/ThreadDeath"),
	java::lang::Error>
{
public:

	static ref<ThreadDeath> new_object();

protected:

	ThreadDeath(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::lang {

inline ref<ThreadDeath> ThreadDeath::new_object() { return base_::new_object(); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_THREADDEATH_H

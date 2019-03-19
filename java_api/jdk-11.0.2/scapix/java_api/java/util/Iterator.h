// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_UTIL_ITERATOR_H
#define SCAPIX_JAVA_UTIL_ITERATOR_H

namespace scapix::java_api {

namespace java::util::function { class Consumer; }

namespace java::util {

class Iterator : public object_base<SCAPIX_META_STRING("java/util/Iterator"),
	java::lang::Object>
{
public:

	jboolean hasNext();
	ref<java::lang::Object> next();
	void remove();
	void forEachRemaining(ref<java::util::function::Consumer> action);

protected:

	Iterator(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/util/function/Consumer.h>

namespace scapix::java_api {
namespace java::util {

inline jboolean Iterator::hasNext() { return call_method<SCAPIX_META_STRING("hasNext"), jboolean>(); }
inline ref<java::lang::Object> Iterator::next() { return call_method<SCAPIX_META_STRING("next"), ref<java::lang::Object>>(); }
inline void Iterator::remove() { return call_method<SCAPIX_META_STRING("remove"), void>(); }
inline void Iterator::forEachRemaining(ref<java::util::function::Consumer> action) { return call_method<SCAPIX_META_STRING("forEachRemaining"), void>(action); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_ITERATOR_H
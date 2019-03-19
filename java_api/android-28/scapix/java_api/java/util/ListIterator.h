// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/Iterator.h>

#ifndef SCAPIX_JAVA_UTIL_LISTITERATOR_H
#define SCAPIX_JAVA_UTIL_LISTITERATOR_H

namespace scapix::java_api {
namespace java::util {

class ListIterator : public object_base<SCAPIX_META_STRING("java/util/ListIterator"),
	java::lang::Object,
	java::util::Iterator>
{
public:

	jboolean hasNext();
	ref<java::lang::Object> next();
	jboolean hasPrevious();
	ref<java::lang::Object> previous();
	jint nextIndex();
	jint previousIndex();
	void remove();
	void set(ref<java::lang::Object> p1);
	void add(ref<java::lang::Object> p1);

protected:

	ListIterator(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::util {

inline jboolean ListIterator::hasNext() { return call_method<SCAPIX_META_STRING("hasNext"), jboolean>(); }
inline ref<java::lang::Object> ListIterator::next() { return call_method<SCAPIX_META_STRING("next"), ref<java::lang::Object>>(); }
inline jboolean ListIterator::hasPrevious() { return call_method<SCAPIX_META_STRING("hasPrevious"), jboolean>(); }
inline ref<java::lang::Object> ListIterator::previous() { return call_method<SCAPIX_META_STRING("previous"), ref<java::lang::Object>>(); }
inline jint ListIterator::nextIndex() { return call_method<SCAPIX_META_STRING("nextIndex"), jint>(); }
inline jint ListIterator::previousIndex() { return call_method<SCAPIX_META_STRING("previousIndex"), jint>(); }
inline void ListIterator::remove() { return call_method<SCAPIX_META_STRING("remove"), void>(); }
inline void ListIterator::set(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("set"), void>(p1); }
inline void ListIterator::add(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("add"), void>(p1); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_LISTITERATOR_H
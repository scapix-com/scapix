// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/Set.h>

#ifndef SCAPIX_JAVA_UTIL_SORTEDSET_H
#define SCAPIX_JAVA_UTIL_SORTEDSET_H

namespace scapix::java_api {

namespace java::util { class Comparator; }
namespace java::util { class Spliterator; }

namespace java::util {

class SortedSet : public object_base<SCAPIX_META_STRING("java/util/SortedSet"),
	java::lang::Object,
	java::util::Set>
{
public:

	ref<java::util::Comparator> comparator();
	ref<java::util::SortedSet> subSet(ref<java::lang::Object> p1, ref<java::lang::Object> p2);
	ref<java::util::SortedSet> headSet(ref<java::lang::Object> p1);
	ref<java::util::SortedSet> tailSet(ref<java::lang::Object> p1);
	ref<java::lang::Object> first();
	ref<java::lang::Object> last();
	ref<java::util::Spliterator> spliterator();

protected:

	SortedSet(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/util/Comparator.h>
#include <scapix/java_api/java/util/Spliterator.h>

namespace scapix::java_api {
namespace java::util {

inline ref<java::util::Comparator> SortedSet::comparator() { return call_method<SCAPIX_META_STRING("comparator"), ref<java::util::Comparator>>(); }
inline ref<java::util::SortedSet> SortedSet::subSet(ref<java::lang::Object> p1, ref<java::lang::Object> p2) { return call_method<SCAPIX_META_STRING("subSet"), ref<java::util::SortedSet>>(p1, p2); }
inline ref<java::util::SortedSet> SortedSet::headSet(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("headSet"), ref<java::util::SortedSet>>(p1); }
inline ref<java::util::SortedSet> SortedSet::tailSet(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("tailSet"), ref<java::util::SortedSet>>(p1); }
inline ref<java::lang::Object> SortedSet::first() { return call_method<SCAPIX_META_STRING("first"), ref<java::lang::Object>>(); }
inline ref<java::lang::Object> SortedSet::last() { return call_method<SCAPIX_META_STRING("last"), ref<java::lang::Object>>(); }
inline ref<java::util::Spliterator> SortedSet::spliterator() { return call_method<SCAPIX_META_STRING("spliterator"), ref<java::util::Spliterator>>(); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_SORTEDSET_H

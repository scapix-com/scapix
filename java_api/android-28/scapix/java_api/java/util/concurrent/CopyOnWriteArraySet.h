// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/AbstractSet.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_UTIL_CONCURRENT_COPYONWRITEARRAYSET_H
#define SCAPIX_JAVA_UTIL_CONCURRENT_COPYONWRITEARRAYSET_H

namespace scapix::java_api {

namespace java::lang { class Object; }
namespace java::util { class Collection; }
namespace java::util { class Iterator; }
namespace java::util { class Spliterator; }
namespace java::util::function { class Consumer; }
namespace java::util::function { class Predicate; }

namespace java::util::concurrent {

class CopyOnWriteArraySet : public object_base<SCAPIX_META_STRING("java/util/concurrent/CopyOnWriteArraySet"),
	java::util::AbstractSet,
	java::io::Serializable>
{
public:

	static ref<CopyOnWriteArraySet> new_object();
	static ref<CopyOnWriteArraySet> new_object(ref<java::util::Collection> c);
	jint size();
	jboolean isEmpty();
	jboolean contains(ref<java::lang::Object> o);
	ref<link::java::array<java::lang::Object>> toArray();
	ref<link::java::array<java::lang::Object>> toArray(ref<link::java::array<java::lang::Object>> a);
	void clear();
	jboolean remove(ref<java::lang::Object> o);
	jboolean add(ref<java::lang::Object> e);
	jboolean containsAll(ref<java::util::Collection> c);
	jboolean addAll(ref<java::util::Collection> c);
	jboolean removeAll(ref<java::util::Collection> c);
	jboolean retainAll(ref<java::util::Collection> c);
	ref<java::util::Iterator> iterator();
	jboolean equals(ref<java::lang::Object> o);
	jboolean removeIf(ref<java::util::function::Predicate> filter);
	void forEach(ref<java::util::function::Consumer> action);
	ref<java::util::Spliterator> spliterator();

protected:

	CopyOnWriteArraySet(handle_type h) : base_(h) {}

};

} // namespace java::util::concurrent
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/Collection.h>
#include <scapix/java_api/java/util/Iterator.h>
#include <scapix/java_api/java/util/Spliterator.h>
#include <scapix/java_api/java/util/function/Consumer.h>
#include <scapix/java_api/java/util/function/Predicate.h>

namespace scapix::java_api {
namespace java::util::concurrent {

inline ref<CopyOnWriteArraySet> CopyOnWriteArraySet::new_object() { return base_::new_object(); }
inline ref<CopyOnWriteArraySet> CopyOnWriteArraySet::new_object(ref<java::util::Collection> c) { return base_::new_object(c); }
inline jint CopyOnWriteArraySet::size() { return call_method<SCAPIX_META_STRING("size"), jint>(); }
inline jboolean CopyOnWriteArraySet::isEmpty() { return call_method<SCAPIX_META_STRING("isEmpty"), jboolean>(); }
inline jboolean CopyOnWriteArraySet::contains(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("contains"), jboolean>(o); }
inline ref<link::java::array<java::lang::Object>> CopyOnWriteArraySet::toArray() { return call_method<SCAPIX_META_STRING("toArray"), ref<link::java::array<java::lang::Object>>>(); }
inline ref<link::java::array<java::lang::Object>> CopyOnWriteArraySet::toArray(ref<link::java::array<java::lang::Object>> a) { return call_method<SCAPIX_META_STRING("toArray"), ref<link::java::array<java::lang::Object>>>(a); }
inline void CopyOnWriteArraySet::clear() { return call_method<SCAPIX_META_STRING("clear"), void>(); }
inline jboolean CopyOnWriteArraySet::remove(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("remove"), jboolean>(o); }
inline jboolean CopyOnWriteArraySet::add(ref<java::lang::Object> e) { return call_method<SCAPIX_META_STRING("add"), jboolean>(e); }
inline jboolean CopyOnWriteArraySet::containsAll(ref<java::util::Collection> c) { return call_method<SCAPIX_META_STRING("containsAll"), jboolean>(c); }
inline jboolean CopyOnWriteArraySet::addAll(ref<java::util::Collection> c) { return call_method<SCAPIX_META_STRING("addAll"), jboolean>(c); }
inline jboolean CopyOnWriteArraySet::removeAll(ref<java::util::Collection> c) { return call_method<SCAPIX_META_STRING("removeAll"), jboolean>(c); }
inline jboolean CopyOnWriteArraySet::retainAll(ref<java::util::Collection> c) { return call_method<SCAPIX_META_STRING("retainAll"), jboolean>(c); }
inline ref<java::util::Iterator> CopyOnWriteArraySet::iterator() { return call_method<SCAPIX_META_STRING("iterator"), ref<java::util::Iterator>>(); }
inline jboolean CopyOnWriteArraySet::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jboolean CopyOnWriteArraySet::removeIf(ref<java::util::function::Predicate> filter) { return call_method<SCAPIX_META_STRING("removeIf"), jboolean>(filter); }
inline void CopyOnWriteArraySet::forEach(ref<java::util::function::Consumer> action) { return call_method<SCAPIX_META_STRING("forEach"), void>(action); }
inline ref<java::util::Spliterator> CopyOnWriteArraySet::spliterator() { return call_method<SCAPIX_META_STRING("spliterator"), ref<java::util::Spliterator>>(); }

} // namespace java::util::concurrent
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_CONCURRENT_COPYONWRITEARRAYSET_H

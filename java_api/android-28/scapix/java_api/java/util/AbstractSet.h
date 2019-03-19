// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/AbstractCollection.h>
#include <scapix/java_api/java/util/Set.h>

#ifndef SCAPIX_JAVA_UTIL_ABSTRACTSET_H
#define SCAPIX_JAVA_UTIL_ABSTRACTSET_H

namespace scapix::java_api {

namespace java::lang { class Object; }
namespace java::util { class Collection; }

namespace java::util {

class AbstractSet : public object_base<SCAPIX_META_STRING("java/util/AbstractSet"),
	java::util::AbstractCollection,
	java::util::Set>
{
public:

	jboolean equals(ref<java::lang::Object> o);
	jint hashCode();
	jboolean removeAll(ref<java::util::Collection> c);

protected:

	AbstractSet(handle_type h) : base_(h) {}

};

} // namespace java::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/util/Collection.h>

namespace scapix::java_api {
namespace java::util {

inline jboolean AbstractSet::equals(ref<java::lang::Object> o) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(o); }
inline jint AbstractSet::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean AbstractSet::removeAll(ref<java::util::Collection> c) { return call_method<SCAPIX_META_STRING("removeAll"), jboolean>(c); }

} // namespace java::util
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_ABSTRACTSET_H
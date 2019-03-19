// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/reflect/AnnotatedElement.h>

#ifndef SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDTYPE_H
#define SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDTYPE_H

namespace scapix::java_api {

namespace java::lang::reflect { class Type; }

namespace java::lang::reflect {

class AnnotatedType : public object_base<SCAPIX_META_STRING("java/lang/reflect/AnnotatedType"),
	java::lang::Object,
	java::lang::reflect::AnnotatedElement>
{
public:

	ref<java::lang::reflect::AnnotatedType> getAnnotatedOwnerType();
	ref<java::lang::reflect::Type> getType();

protected:

	AnnotatedType(handle_type h) : base_(h) {}

};

} // namespace java::lang::reflect
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/reflect/Type.h>

namespace scapix::java_api {
namespace java::lang::reflect {

inline ref<java::lang::reflect::AnnotatedType> AnnotatedType::getAnnotatedOwnerType() { return call_method<SCAPIX_META_STRING("getAnnotatedOwnerType"), ref<java::lang::reflect::AnnotatedType>>(); }
inline ref<java::lang::reflect::Type> AnnotatedType::getType() { return call_method<SCAPIX_META_STRING("getType"), ref<java::lang::reflect::Type>>(); }

} // namespace java::lang::reflect
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDTYPE_H
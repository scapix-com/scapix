// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/reflect/AnnotatedType.h>

#ifndef SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDPARAMETERIZEDTYPE_H
#define SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDPARAMETERIZEDTYPE_H

namespace scapix::java_api {
namespace java::lang::reflect {

class AnnotatedParameterizedType : public object_base<SCAPIX_META_STRING("java/lang/reflect/AnnotatedParameterizedType"),
	java::lang::Object,
	java::lang::reflect::AnnotatedType>
{
public:

	ref<link::java::array<java::lang::reflect::AnnotatedType>> getAnnotatedActualTypeArguments();
	ref<java::lang::reflect::AnnotatedType> getAnnotatedOwnerType();

protected:

	AnnotatedParameterizedType(handle_type h) : base_(h) {}

};

} // namespace java::lang::reflect
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::lang::reflect {

inline ref<link::java::array<java::lang::reflect::AnnotatedType>> AnnotatedParameterizedType::getAnnotatedActualTypeArguments() { return call_method<SCAPIX_META_STRING("getAnnotatedActualTypeArguments"), ref<link::java::array<java::lang::reflect::AnnotatedType>>>(); }
inline ref<java::lang::reflect::AnnotatedType> AnnotatedParameterizedType::getAnnotatedOwnerType() { return call_method<SCAPIX_META_STRING("getAnnotatedOwnerType"), ref<java::lang::reflect::AnnotatedType>>(); }

} // namespace java::lang::reflect
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_REFLECT_ANNOTATEDPARAMETERIZEDTYPE_H
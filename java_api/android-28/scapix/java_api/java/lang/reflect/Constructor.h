// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/reflect/Executable.h>

#ifndef SCAPIX_JAVA_LANG_REFLECT_CONSTRUCTOR_H
#define SCAPIX_JAVA_LANG_REFLECT_CONSTRUCTOR_H

namespace scapix::java_api {

namespace java::lang { class Class; }
namespace java::lang { class Object; }
namespace java::lang { class String; }
namespace java::lang::annotation { class Annotation; }
namespace java::lang::reflect { class Type; }
namespace java::lang::reflect { class TypeVariable; }

namespace java::lang::reflect {

class Constructor : public object_base<SCAPIX_META_STRING("java/lang/reflect/Constructor"),
	java::lang::reflect::Executable>
{
public:

	ref<java::lang::Class> getDeclaringClass();
	ref<java::lang::String> getName();
	jint getModifiers();
	ref<link::java::array<java::lang::reflect::TypeVariable>> getTypeParameters();
	ref<link::java::array<java::lang::Class>> getParameterTypes();
	jint getParameterCount();
	ref<link::java::array<java::lang::reflect::Type>> getGenericParameterTypes();
	ref<link::java::array<java::lang::Class>> getExceptionTypes();
	ref<link::java::array<java::lang::reflect::Type>> getGenericExceptionTypes();
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();
	ref<java::lang::String> toGenericString();
	ref<java::lang::Object> newInstance(ref<link::java::array<java::lang::Object>> initargs);
	jboolean isVarArgs();
	jboolean isSynthetic();
	ref<java::lang::annotation::Annotation> getAnnotation(ref<java::lang::Class> annotationClass);
	ref<link::java::array<java::lang::annotation::Annotation>> getDeclaredAnnotations();
	ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>> getParameterAnnotations();

protected:

	Constructor(handle_type h) : base_(h) {}

};

} // namespace java::lang::reflect
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/annotation/Annotation.h>
#include <scapix/java_api/java/lang/reflect/Type.h>
#include <scapix/java_api/java/lang/reflect/TypeVariable.h>

namespace scapix::java_api {
namespace java::lang::reflect {

inline ref<java::lang::Class> Constructor::getDeclaringClass() { return call_method<SCAPIX_META_STRING("getDeclaringClass"), ref<java::lang::Class>>(); }
inline ref<java::lang::String> Constructor::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline jint Constructor::getModifiers() { return call_method<SCAPIX_META_STRING("getModifiers"), jint>(); }
inline ref<link::java::array<java::lang::reflect::TypeVariable>> Constructor::getTypeParameters() { return call_method<SCAPIX_META_STRING("getTypeParameters"), ref<link::java::array<java::lang::reflect::TypeVariable>>>(); }
inline ref<link::java::array<java::lang::Class>> Constructor::getParameterTypes() { return call_method<SCAPIX_META_STRING("getParameterTypes"), ref<link::java::array<java::lang::Class>>>(); }
inline jint Constructor::getParameterCount() { return call_method<SCAPIX_META_STRING("getParameterCount"), jint>(); }
inline ref<link::java::array<java::lang::reflect::Type>> Constructor::getGenericParameterTypes() { return call_method<SCAPIX_META_STRING("getGenericParameterTypes"), ref<link::java::array<java::lang::reflect::Type>>>(); }
inline ref<link::java::array<java::lang::Class>> Constructor::getExceptionTypes() { return call_method<SCAPIX_META_STRING("getExceptionTypes"), ref<link::java::array<java::lang::Class>>>(); }
inline ref<link::java::array<java::lang::reflect::Type>> Constructor::getGenericExceptionTypes() { return call_method<SCAPIX_META_STRING("getGenericExceptionTypes"), ref<link::java::array<java::lang::reflect::Type>>>(); }
inline jboolean Constructor::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint Constructor::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> Constructor::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Constructor::toGenericString() { return call_method<SCAPIX_META_STRING("toGenericString"), ref<java::lang::String>>(); }
inline ref<java::lang::Object> Constructor::newInstance(ref<link::java::array<java::lang::Object>> initargs) { return call_method<SCAPIX_META_STRING("newInstance"), ref<java::lang::Object>>(initargs); }
inline jboolean Constructor::isVarArgs() { return call_method<SCAPIX_META_STRING("isVarArgs"), jboolean>(); }
inline jboolean Constructor::isSynthetic() { return call_method<SCAPIX_META_STRING("isSynthetic"), jboolean>(); }
inline ref<java::lang::annotation::Annotation> Constructor::getAnnotation(ref<java::lang::Class> annotationClass) { return call_method<SCAPIX_META_STRING("getAnnotation"), ref<java::lang::annotation::Annotation>>(annotationClass); }
inline ref<link::java::array<java::lang::annotation::Annotation>> Constructor::getDeclaredAnnotations() { return call_method<SCAPIX_META_STRING("getDeclaredAnnotations"), ref<link::java::array<java::lang::annotation::Annotation>>>(); }
inline ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>> Constructor::getParameterAnnotations() { return call_method<SCAPIX_META_STRING("getParameterAnnotations"), ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>>>(); }

} // namespace java::lang::reflect
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_REFLECT_CONSTRUCTOR_H
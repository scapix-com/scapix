// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/reflect/AccessibleObject.h>
#include <scapix/java_api/java/lang/reflect/Member.h>
#include <scapix/java_api/java/lang/reflect/GenericDeclaration.h>

#ifndef SCAPIX_JAVA_LANG_REFLECT_EXECUTABLE_H
#define SCAPIX_JAVA_LANG_REFLECT_EXECUTABLE_H

namespace scapix::java_api {

namespace java::lang { class Class; }
namespace java::lang { class String; }
namespace java::lang::annotation { class Annotation; }
namespace java::lang::reflect { class Parameter; }
namespace java::lang::reflect { class Type; }
namespace java::lang::reflect { class TypeVariable; }

namespace java::lang::reflect {

class Executable : public object_base<SCAPIX_META_STRING("java/lang/reflect/Executable"),
	java::lang::reflect::AccessibleObject,
	java::lang::reflect::Member,
	java::lang::reflect::GenericDeclaration>
{
public:

	ref<java::lang::Class> getDeclaringClass();
	ref<java::lang::String> getName();
	jint getModifiers();
	ref<link::java::array<java::lang::reflect::TypeVariable>> getTypeParameters();
	ref<link::java::array<java::lang::Class>> getParameterTypes();
	jint getParameterCount();
	ref<link::java::array<java::lang::reflect::Type>> getGenericParameterTypes();
	ref<link::java::array<java::lang::reflect::Parameter>> getParameters();
	ref<link::java::array<java::lang::Class>> getExceptionTypes();
	ref<link::java::array<java::lang::reflect::Type>> getGenericExceptionTypes();
	ref<java::lang::String> toGenericString();
	jboolean isVarArgs();
	jboolean isSynthetic();
	ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>> getParameterAnnotations();
	ref<java::lang::annotation::Annotation> getAnnotation(ref<java::lang::Class> annotationClass);
	ref<link::java::array<java::lang::annotation::Annotation>> getAnnotationsByType(ref<java::lang::Class> annotationClass);
	ref<link::java::array<java::lang::annotation::Annotation>> getDeclaredAnnotations();
	jboolean isAnnotationPresent(ref<java::lang::Class> annotationType);

protected:

	Executable(handle_type h) : base_(h) {}

};

} // namespace java::lang::reflect
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/annotation/Annotation.h>
#include <scapix/java_api/java/lang/reflect/Parameter.h>
#include <scapix/java_api/java/lang/reflect/Type.h>
#include <scapix/java_api/java/lang/reflect/TypeVariable.h>

namespace scapix::java_api {
namespace java::lang::reflect {

inline ref<java::lang::Class> Executable::getDeclaringClass() { return call_method<SCAPIX_META_STRING("getDeclaringClass"), ref<java::lang::Class>>(); }
inline ref<java::lang::String> Executable::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline jint Executable::getModifiers() { return call_method<SCAPIX_META_STRING("getModifiers"), jint>(); }
inline ref<link::java::array<java::lang::reflect::TypeVariable>> Executable::getTypeParameters() { return call_method<SCAPIX_META_STRING("getTypeParameters"), ref<link::java::array<java::lang::reflect::TypeVariable>>>(); }
inline ref<link::java::array<java::lang::Class>> Executable::getParameterTypes() { return call_method<SCAPIX_META_STRING("getParameterTypes"), ref<link::java::array<java::lang::Class>>>(); }
inline jint Executable::getParameterCount() { return call_method<SCAPIX_META_STRING("getParameterCount"), jint>(); }
inline ref<link::java::array<java::lang::reflect::Type>> Executable::getGenericParameterTypes() { return call_method<SCAPIX_META_STRING("getGenericParameterTypes"), ref<link::java::array<java::lang::reflect::Type>>>(); }
inline ref<link::java::array<java::lang::reflect::Parameter>> Executable::getParameters() { return call_method<SCAPIX_META_STRING("getParameters"), ref<link::java::array<java::lang::reflect::Parameter>>>(); }
inline ref<link::java::array<java::lang::Class>> Executable::getExceptionTypes() { return call_method<SCAPIX_META_STRING("getExceptionTypes"), ref<link::java::array<java::lang::Class>>>(); }
inline ref<link::java::array<java::lang::reflect::Type>> Executable::getGenericExceptionTypes() { return call_method<SCAPIX_META_STRING("getGenericExceptionTypes"), ref<link::java::array<java::lang::reflect::Type>>>(); }
inline ref<java::lang::String> Executable::toGenericString() { return call_method<SCAPIX_META_STRING("toGenericString"), ref<java::lang::String>>(); }
inline jboolean Executable::isVarArgs() { return call_method<SCAPIX_META_STRING("isVarArgs"), jboolean>(); }
inline jboolean Executable::isSynthetic() { return call_method<SCAPIX_META_STRING("isSynthetic"), jboolean>(); }
inline ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>> Executable::getParameterAnnotations() { return call_method<SCAPIX_META_STRING("getParameterAnnotations"), ref<link::java::array<link::java::array<java::lang::annotation::Annotation>>>>(); }
inline ref<java::lang::annotation::Annotation> Executable::getAnnotation(ref<java::lang::Class> annotationClass) { return call_method<SCAPIX_META_STRING("getAnnotation"), ref<java::lang::annotation::Annotation>>(annotationClass); }
inline ref<link::java::array<java::lang::annotation::Annotation>> Executable::getAnnotationsByType(ref<java::lang::Class> annotationClass) { return call_method<SCAPIX_META_STRING("getAnnotationsByType"), ref<link::java::array<java::lang::annotation::Annotation>>>(annotationClass); }
inline ref<link::java::array<java::lang::annotation::Annotation>> Executable::getDeclaredAnnotations() { return call_method<SCAPIX_META_STRING("getDeclaredAnnotations"), ref<link::java::array<java::lang::annotation::Annotation>>>(); }
inline jboolean Executable::isAnnotationPresent(ref<java::lang::Class> annotationType) { return call_method<SCAPIX_META_STRING("isAnnotationPresent"), jboolean>(annotationType); }

} // namespace java::lang::reflect
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_REFLECT_EXECUTABLE_H
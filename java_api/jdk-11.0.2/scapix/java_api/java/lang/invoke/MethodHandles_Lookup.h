// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_LANG_INVOKE_METHODHANDLES_LOOKUP_H
#define SCAPIX_JAVA_LANG_INVOKE_METHODHANDLES_LOOKUP_H

namespace scapix::java_api {

namespace java::lang { class Class; }
namespace java::lang { class String; }
namespace java::lang::invoke { class MethodHandle; }
namespace java::lang::invoke { class MethodHandleInfo; }
namespace java::lang::invoke { class MethodType; }
namespace java::lang::invoke { class VarHandle; }
namespace java::lang::reflect { class Constructor; }
namespace java::lang::reflect { class Field; }
namespace java::lang::reflect { class Method; }

namespace java::lang::invoke {

class MethodHandles_Lookup : public object_base<SCAPIX_META_STRING("java/lang/invoke/MethodHandles$Lookup"),
	java::lang::Object>
{
public:

	static jint PUBLIC_();
	static jint PRIVATE_();
	static jint PROTECTED_();
	static jint PACKAGE_();
	static jint MODULE_();
	static jint UNCONDITIONAL_();

	ref<java::lang::Class> lookupClass();
	jint lookupModes();
	ref<java::lang::invoke::MethodHandles_Lookup> in(ref<java::lang::Class> requestedLookupClass);
	ref<java::lang::invoke::MethodHandles_Lookup> dropLookupMode(jint modeToDrop);
	ref<java::lang::Class> defineClass(ref<link::java::array<jbyte>> bytes);
	ref<java::lang::String> toString();
	ref<java::lang::invoke::MethodHandle> findStatic(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type);
	ref<java::lang::invoke::MethodHandle> findVirtual(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type);
	ref<java::lang::invoke::MethodHandle> findConstructor(ref<java::lang::Class> refc, ref<java::lang::invoke::MethodType> type);
	ref<java::lang::Class> findClass(ref<java::lang::String> targetName);
	ref<java::lang::Class> accessClass(ref<java::lang::Class> targetClass);
	ref<java::lang::invoke::MethodHandle> findSpecial(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type, ref<java::lang::Class> specialCaller);
	ref<java::lang::invoke::MethodHandle> findGetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::MethodHandle> findSetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::VarHandle> findVarHandle(ref<java::lang::Class> recv, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::MethodHandle> findStaticGetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::MethodHandle> findStaticSetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::VarHandle> findStaticVarHandle(ref<java::lang::Class> decl, ref<java::lang::String> name, ref<java::lang::Class> type);
	ref<java::lang::invoke::MethodHandle> bind(ref<java::lang::Object> receiver, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type);
	ref<java::lang::invoke::MethodHandle> unreflect(ref<java::lang::reflect::Method> m);
	ref<java::lang::invoke::MethodHandle> unreflectSpecial(ref<java::lang::reflect::Method> m, ref<java::lang::Class> specialCaller);
	ref<java::lang::invoke::MethodHandle> unreflectConstructor(ref<java::lang::reflect::Constructor> c);
	ref<java::lang::invoke::MethodHandle> unreflectGetter(ref<java::lang::reflect::Field> f);
	ref<java::lang::invoke::MethodHandle> unreflectSetter(ref<java::lang::reflect::Field> f);
	ref<java::lang::invoke::VarHandle> unreflectVarHandle(ref<java::lang::reflect::Field> f);
	ref<java::lang::invoke::MethodHandleInfo> revealDirect(ref<java::lang::invoke::MethodHandle> target);
	jboolean hasPrivateAccess();

protected:

	MethodHandles_Lookup(handle_type h) : base_(h) {}

};

} // namespace java::lang::invoke
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/lang/invoke/MethodHandle.h>
#include <scapix/java_api/java/lang/invoke/MethodHandleInfo.h>
#include <scapix/java_api/java/lang/invoke/MethodType.h>
#include <scapix/java_api/java/lang/invoke/VarHandle.h>
#include <scapix/java_api/java/lang/reflect/Constructor.h>
#include <scapix/java_api/java/lang/reflect/Field.h>
#include <scapix/java_api/java/lang/reflect/Method.h>

namespace scapix::java_api {
namespace java::lang::invoke {

inline jint MethodHandles_Lookup::PUBLIC_() { return get_static_field<SCAPIX_META_STRING("PUBLIC"), jint>(); }
inline jint MethodHandles_Lookup::PRIVATE_() { return get_static_field<SCAPIX_META_STRING("PRIVATE"), jint>(); }
inline jint MethodHandles_Lookup::PROTECTED_() { return get_static_field<SCAPIX_META_STRING("PROTECTED"), jint>(); }
inline jint MethodHandles_Lookup::PACKAGE_() { return get_static_field<SCAPIX_META_STRING("PACKAGE"), jint>(); }
inline jint MethodHandles_Lookup::MODULE_() { return get_static_field<SCAPIX_META_STRING("MODULE"), jint>(); }
inline jint MethodHandles_Lookup::UNCONDITIONAL_() { return get_static_field<SCAPIX_META_STRING("UNCONDITIONAL"), jint>(); }
inline ref<java::lang::Class> MethodHandles_Lookup::lookupClass() { return call_method<SCAPIX_META_STRING("lookupClass"), ref<java::lang::Class>>(); }
inline jint MethodHandles_Lookup::lookupModes() { return call_method<SCAPIX_META_STRING("lookupModes"), jint>(); }
inline ref<java::lang::invoke::MethodHandles_Lookup> MethodHandles_Lookup::in(ref<java::lang::Class> requestedLookupClass) { return call_method<SCAPIX_META_STRING("in"), ref<java::lang::invoke::MethodHandles_Lookup>>(requestedLookupClass); }
inline ref<java::lang::invoke::MethodHandles_Lookup> MethodHandles_Lookup::dropLookupMode(jint modeToDrop) { return call_method<SCAPIX_META_STRING("dropLookupMode"), ref<java::lang::invoke::MethodHandles_Lookup>>(modeToDrop); }
inline ref<java::lang::Class> MethodHandles_Lookup::defineClass(ref<link::java::array<jbyte>> bytes) { return call_method<SCAPIX_META_STRING("defineClass"), ref<java::lang::Class>>(bytes); }
inline ref<java::lang::String> MethodHandles_Lookup::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findStatic(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type) { return call_method<SCAPIX_META_STRING("findStatic"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findVirtual(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type) { return call_method<SCAPIX_META_STRING("findVirtual"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findConstructor(ref<java::lang::Class> refc, ref<java::lang::invoke::MethodType> type) { return call_method<SCAPIX_META_STRING("findConstructor"), ref<java::lang::invoke::MethodHandle>>(refc, type); }
inline ref<java::lang::Class> MethodHandles_Lookup::findClass(ref<java::lang::String> targetName) { return call_method<SCAPIX_META_STRING("findClass"), ref<java::lang::Class>>(targetName); }
inline ref<java::lang::Class> MethodHandles_Lookup::accessClass(ref<java::lang::Class> targetClass) { return call_method<SCAPIX_META_STRING("accessClass"), ref<java::lang::Class>>(targetClass); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findSpecial(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type, ref<java::lang::Class> specialCaller) { return call_method<SCAPIX_META_STRING("findSpecial"), ref<java::lang::invoke::MethodHandle>>(refc, name, type, specialCaller); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findGetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findGetter"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findSetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findSetter"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::VarHandle> MethodHandles_Lookup::findVarHandle(ref<java::lang::Class> recv, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findVarHandle"), ref<java::lang::invoke::VarHandle>>(recv, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findStaticGetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findStaticGetter"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::findStaticSetter(ref<java::lang::Class> refc, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findStaticSetter"), ref<java::lang::invoke::MethodHandle>>(refc, name, type); }
inline ref<java::lang::invoke::VarHandle> MethodHandles_Lookup::findStaticVarHandle(ref<java::lang::Class> decl, ref<java::lang::String> name, ref<java::lang::Class> type) { return call_method<SCAPIX_META_STRING("findStaticVarHandle"), ref<java::lang::invoke::VarHandle>>(decl, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::bind(ref<java::lang::Object> receiver, ref<java::lang::String> name, ref<java::lang::invoke::MethodType> type) { return call_method<SCAPIX_META_STRING("bind"), ref<java::lang::invoke::MethodHandle>>(receiver, name, type); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::unreflect(ref<java::lang::reflect::Method> m) { return call_method<SCAPIX_META_STRING("unreflect"), ref<java::lang::invoke::MethodHandle>>(m); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::unreflectSpecial(ref<java::lang::reflect::Method> m, ref<java::lang::Class> specialCaller) { return call_method<SCAPIX_META_STRING("unreflectSpecial"), ref<java::lang::invoke::MethodHandle>>(m, specialCaller); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::unreflectConstructor(ref<java::lang::reflect::Constructor> c) { return call_method<SCAPIX_META_STRING("unreflectConstructor"), ref<java::lang::invoke::MethodHandle>>(c); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::unreflectGetter(ref<java::lang::reflect::Field> f) { return call_method<SCAPIX_META_STRING("unreflectGetter"), ref<java::lang::invoke::MethodHandle>>(f); }
inline ref<java::lang::invoke::MethodHandle> MethodHandles_Lookup::unreflectSetter(ref<java::lang::reflect::Field> f) { return call_method<SCAPIX_META_STRING("unreflectSetter"), ref<java::lang::invoke::MethodHandle>>(f); }
inline ref<java::lang::invoke::VarHandle> MethodHandles_Lookup::unreflectVarHandle(ref<java::lang::reflect::Field> f) { return call_method<SCAPIX_META_STRING("unreflectVarHandle"), ref<java::lang::invoke::VarHandle>>(f); }
inline ref<java::lang::invoke::MethodHandleInfo> MethodHandles_Lookup::revealDirect(ref<java::lang::invoke::MethodHandle> target) { return call_method<SCAPIX_META_STRING("revealDirect"), ref<java::lang::invoke::MethodHandleInfo>>(target); }
inline jboolean MethodHandles_Lookup::hasPrivateAccess() { return call_method<SCAPIX_META_STRING("hasPrivateAccess"), jboolean>(); }

} // namespace java::lang::invoke
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_INVOKE_METHODHANDLES_LOOKUP_H
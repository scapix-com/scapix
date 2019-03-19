// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/Comparable.h>

#ifndef SCAPIX_JAVA_LANG_MODULE_MODULEDESCRIPTOR_VERSION_H
#define SCAPIX_JAVA_LANG_MODULE_MODULEDESCRIPTOR_VERSION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::lang::module {

class ModuleDescriptor_Version : public object_base<SCAPIX_META_STRING("java/lang/module/ModuleDescriptor$Version"),
	java::lang::Object,
	java::lang::Comparable>
{
public:

	static ref<java::lang::module::ModuleDescriptor_Version> parse(ref<java::lang::String> v);
	jint compareTo(ref<java::lang::module::ModuleDescriptor_Version> that);
	jboolean equals(ref<java::lang::Object> ob);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	ModuleDescriptor_Version(handle_type h) : base_(h) {}

};

} // namespace java::lang::module
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::lang::module {

inline ref<java::lang::module::ModuleDescriptor_Version> ModuleDescriptor_Version::parse(ref<java::lang::String> v) { return call_static_method<SCAPIX_META_STRING("parse"), ref<java::lang::module::ModuleDescriptor_Version>>(v); }
inline jint ModuleDescriptor_Version::compareTo(ref<java::lang::module::ModuleDescriptor_Version> that) { return call_method<SCAPIX_META_STRING("compareTo"), jint>(that); }
inline jboolean ModuleDescriptor_Version::equals(ref<java::lang::Object> ob) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(ob); }
inline jint ModuleDescriptor_Version::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> ModuleDescriptor_Version::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::lang::module
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_MODULE_MODULEDESCRIPTOR_VERSION_H
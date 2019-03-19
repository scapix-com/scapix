// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/org/w3c/dom/Node.h>

#ifndef SCAPIX_ORG_W3C_DOM_ATTR_H
#define SCAPIX_ORG_W3C_DOM_ATTR_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace org::w3c::dom { class Element; }
namespace org::w3c::dom { class TypeInfo; }

namespace org::w3c::dom {

class Attr : public object_base<SCAPIX_META_STRING("org/w3c/dom/Attr"),
	java::lang::Object,
	org::w3c::dom::Node>
{
public:

	ref<java::lang::String> getName();
	jboolean getSpecified();
	ref<java::lang::String> getValue();
	void setValue(ref<java::lang::String> p1);
	ref<org::w3c::dom::Element> getOwnerElement();
	ref<org::w3c::dom::TypeInfo> getSchemaTypeInfo();
	jboolean isId();

protected:

	Attr(handle_type h) : base_(h) {}

};

} // namespace org::w3c::dom
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/org/w3c/dom/Element.h>
#include <scapix/java_api/org/w3c/dom/TypeInfo.h>

namespace scapix::java_api {
namespace org::w3c::dom {

inline ref<java::lang::String> Attr::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline jboolean Attr::getSpecified() { return call_method<SCAPIX_META_STRING("getSpecified"), jboolean>(); }
inline ref<java::lang::String> Attr::getValue() { return call_method<SCAPIX_META_STRING("getValue"), ref<java::lang::String>>(); }
inline void Attr::setValue(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("setValue"), void>(p1); }
inline ref<org::w3c::dom::Element> Attr::getOwnerElement() { return call_method<SCAPIX_META_STRING("getOwnerElement"), ref<org::w3c::dom::Element>>(); }
inline ref<org::w3c::dom::TypeInfo> Attr::getSchemaTypeInfo() { return call_method<SCAPIX_META_STRING("getSchemaTypeInfo"), ref<org::w3c::dom::TypeInfo>>(); }
inline jboolean Attr::isId() { return call_method<SCAPIX_META_STRING("isId"), jboolean>(); }

} // namespace org::w3c::dom
} // namespace scapix::java_api

#endif // SCAPIX_ORG_W3C_DOM_ATTR_H
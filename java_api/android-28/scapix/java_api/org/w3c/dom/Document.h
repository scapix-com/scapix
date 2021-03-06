// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/org/w3c/dom/Node.h>

#ifndef SCAPIX_ORG_W3C_DOM_DOCUMENT_H
#define SCAPIX_ORG_W3C_DOM_DOCUMENT_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace org::w3c::dom { class Attr; }
namespace org::w3c::dom { class CDATASection; }
namespace org::w3c::dom { class Comment; }
namespace org::w3c::dom { class DOMConfiguration; }
namespace org::w3c::dom { class DOMImplementation; }
namespace org::w3c::dom { class DocumentFragment; }
namespace org::w3c::dom { class DocumentType; }
namespace org::w3c::dom { class Element; }
namespace org::w3c::dom { class EntityReference; }
namespace org::w3c::dom { class NodeList; }
namespace org::w3c::dom { class ProcessingInstruction; }
namespace org::w3c::dom { class Text; }

namespace org::w3c::dom {

class Document : public object_base<SCAPIX_META_STRING("org/w3c/dom/Document"),
	java::lang::Object,
	org::w3c::dom::Node>
{
public:

	ref<org::w3c::dom::DocumentType> getDoctype();
	ref<org::w3c::dom::DOMImplementation> getImplementation();
	ref<org::w3c::dom::Element> getDocumentElement();
	ref<org::w3c::dom::Element> createElement(ref<java::lang::String> p1);
	ref<org::w3c::dom::DocumentFragment> createDocumentFragment();
	ref<org::w3c::dom::Text> createTextNode(ref<java::lang::String> p1);
	ref<org::w3c::dom::Comment> createComment(ref<java::lang::String> p1);
	ref<org::w3c::dom::CDATASection> createCDATASection(ref<java::lang::String> p1);
	ref<org::w3c::dom::ProcessingInstruction> createProcessingInstruction(ref<java::lang::String> p1, ref<java::lang::String> p2);
	ref<org::w3c::dom::Attr> createAttribute(ref<java::lang::String> p1);
	ref<org::w3c::dom::EntityReference> createEntityReference(ref<java::lang::String> p1);
	ref<org::w3c::dom::NodeList> getElementsByTagName(ref<java::lang::String> p1);
	ref<org::w3c::dom::Node> importNode(ref<org::w3c::dom::Node> p1, jboolean p2);
	ref<org::w3c::dom::Element> createElementNS(ref<java::lang::String> p1, ref<java::lang::String> p2);
	ref<org::w3c::dom::Attr> createAttributeNS(ref<java::lang::String> p1, ref<java::lang::String> p2);
	ref<org::w3c::dom::NodeList> getElementsByTagNameNS(ref<java::lang::String> p1, ref<java::lang::String> p2);
	ref<org::w3c::dom::Element> getElementById(ref<java::lang::String> p1);
	ref<java::lang::String> getInputEncoding();
	ref<java::lang::String> getXmlEncoding();
	jboolean getXmlStandalone();
	void setXmlStandalone(jboolean p1);
	ref<java::lang::String> getXmlVersion();
	void setXmlVersion(ref<java::lang::String> p1);
	jboolean getStrictErrorChecking();
	void setStrictErrorChecking(jboolean p1);
	ref<java::lang::String> getDocumentURI();
	void setDocumentURI(ref<java::lang::String> p1);
	ref<org::w3c::dom::Node> adoptNode(ref<org::w3c::dom::Node> p1);
	ref<org::w3c::dom::DOMConfiguration> getDomConfig();
	void normalizeDocument();
	ref<org::w3c::dom::Node> renameNode(ref<org::w3c::dom::Node> p1, ref<java::lang::String> p2, ref<java::lang::String> p3);

protected:

	Document(handle_type h) : base_(h) {}

};

} // namespace org::w3c::dom
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/org/w3c/dom/Attr.h>
#include <scapix/java_api/org/w3c/dom/CDATASection.h>
#include <scapix/java_api/org/w3c/dom/Comment.h>
#include <scapix/java_api/org/w3c/dom/DOMConfiguration.h>
#include <scapix/java_api/org/w3c/dom/DOMImplementation.h>
#include <scapix/java_api/org/w3c/dom/DocumentFragment.h>
#include <scapix/java_api/org/w3c/dom/DocumentType.h>
#include <scapix/java_api/org/w3c/dom/Element.h>
#include <scapix/java_api/org/w3c/dom/EntityReference.h>
#include <scapix/java_api/org/w3c/dom/NodeList.h>
#include <scapix/java_api/org/w3c/dom/ProcessingInstruction.h>
#include <scapix/java_api/org/w3c/dom/Text.h>

namespace scapix::java_api {
namespace org::w3c::dom {

inline ref<org::w3c::dom::DocumentType> Document::getDoctype() { return call_method<SCAPIX_META_STRING("getDoctype"), ref<org::w3c::dom::DocumentType>>(); }
inline ref<org::w3c::dom::DOMImplementation> Document::getImplementation() { return call_method<SCAPIX_META_STRING("getImplementation"), ref<org::w3c::dom::DOMImplementation>>(); }
inline ref<org::w3c::dom::Element> Document::getDocumentElement() { return call_method<SCAPIX_META_STRING("getDocumentElement"), ref<org::w3c::dom::Element>>(); }
inline ref<org::w3c::dom::Element> Document::createElement(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createElement"), ref<org::w3c::dom::Element>>(p1); }
inline ref<org::w3c::dom::DocumentFragment> Document::createDocumentFragment() { return call_method<SCAPIX_META_STRING("createDocumentFragment"), ref<org::w3c::dom::DocumentFragment>>(); }
inline ref<org::w3c::dom::Text> Document::createTextNode(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createTextNode"), ref<org::w3c::dom::Text>>(p1); }
inline ref<org::w3c::dom::Comment> Document::createComment(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createComment"), ref<org::w3c::dom::Comment>>(p1); }
inline ref<org::w3c::dom::CDATASection> Document::createCDATASection(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createCDATASection"), ref<org::w3c::dom::CDATASection>>(p1); }
inline ref<org::w3c::dom::ProcessingInstruction> Document::createProcessingInstruction(ref<java::lang::String> p1, ref<java::lang::String> p2) { return call_method<SCAPIX_META_STRING("createProcessingInstruction"), ref<org::w3c::dom::ProcessingInstruction>>(p1, p2); }
inline ref<org::w3c::dom::Attr> Document::createAttribute(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createAttribute"), ref<org::w3c::dom::Attr>>(p1); }
inline ref<org::w3c::dom::EntityReference> Document::createEntityReference(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("createEntityReference"), ref<org::w3c::dom::EntityReference>>(p1); }
inline ref<org::w3c::dom::NodeList> Document::getElementsByTagName(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("getElementsByTagName"), ref<org::w3c::dom::NodeList>>(p1); }
inline ref<org::w3c::dom::Node> Document::importNode(ref<org::w3c::dom::Node> p1, jboolean p2) { return call_method<SCAPIX_META_STRING("importNode"), ref<org::w3c::dom::Node>>(p1, p2); }
inline ref<org::w3c::dom::Element> Document::createElementNS(ref<java::lang::String> p1, ref<java::lang::String> p2) { return call_method<SCAPIX_META_STRING("createElementNS"), ref<org::w3c::dom::Element>>(p1, p2); }
inline ref<org::w3c::dom::Attr> Document::createAttributeNS(ref<java::lang::String> p1, ref<java::lang::String> p2) { return call_method<SCAPIX_META_STRING("createAttributeNS"), ref<org::w3c::dom::Attr>>(p1, p2); }
inline ref<org::w3c::dom::NodeList> Document::getElementsByTagNameNS(ref<java::lang::String> p1, ref<java::lang::String> p2) { return call_method<SCAPIX_META_STRING("getElementsByTagNameNS"), ref<org::w3c::dom::NodeList>>(p1, p2); }
inline ref<org::w3c::dom::Element> Document::getElementById(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("getElementById"), ref<org::w3c::dom::Element>>(p1); }
inline ref<java::lang::String> Document::getInputEncoding() { return call_method<SCAPIX_META_STRING("getInputEncoding"), ref<java::lang::String>>(); }
inline ref<java::lang::String> Document::getXmlEncoding() { return call_method<SCAPIX_META_STRING("getXmlEncoding"), ref<java::lang::String>>(); }
inline jboolean Document::getXmlStandalone() { return call_method<SCAPIX_META_STRING("getXmlStandalone"), jboolean>(); }
inline void Document::setXmlStandalone(jboolean p1) { return call_method<SCAPIX_META_STRING("setXmlStandalone"), void>(p1); }
inline ref<java::lang::String> Document::getXmlVersion() { return call_method<SCAPIX_META_STRING("getXmlVersion"), ref<java::lang::String>>(); }
inline void Document::setXmlVersion(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("setXmlVersion"), void>(p1); }
inline jboolean Document::getStrictErrorChecking() { return call_method<SCAPIX_META_STRING("getStrictErrorChecking"), jboolean>(); }
inline void Document::setStrictErrorChecking(jboolean p1) { return call_method<SCAPIX_META_STRING("setStrictErrorChecking"), void>(p1); }
inline ref<java::lang::String> Document::getDocumentURI() { return call_method<SCAPIX_META_STRING("getDocumentURI"), ref<java::lang::String>>(); }
inline void Document::setDocumentURI(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("setDocumentURI"), void>(p1); }
inline ref<org::w3c::dom::Node> Document::adoptNode(ref<org::w3c::dom::Node> p1) { return call_method<SCAPIX_META_STRING("adoptNode"), ref<org::w3c::dom::Node>>(p1); }
inline ref<org::w3c::dom::DOMConfiguration> Document::getDomConfig() { return call_method<SCAPIX_META_STRING("getDomConfig"), ref<org::w3c::dom::DOMConfiguration>>(); }
inline void Document::normalizeDocument() { return call_method<SCAPIX_META_STRING("normalizeDocument"), void>(); }
inline ref<org::w3c::dom::Node> Document::renameNode(ref<org::w3c::dom::Node> p1, ref<java::lang::String> p2, ref<java::lang::String> p3) { return call_method<SCAPIX_META_STRING("renameNode"), ref<org::w3c::dom::Node>>(p1, p2, p3); }

} // namespace org::w3c::dom
} // namespace scapix::java_api

#endif // SCAPIX_ORG_W3C_DOM_DOCUMENT_H

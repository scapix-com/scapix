// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVAX_XML_PARSERS_SAXPARSERFACTORY_H
#define SCAPIX_JAVAX_XML_PARSERS_SAXPARSERFACTORY_H

namespace scapix::java_api {

namespace java::lang { class ClassLoader; }
namespace java::lang { class String; }
namespace javax::xml::parsers { class SAXParser; }
namespace javax::xml::validation { class Schema; }

namespace javax::xml::parsers {

class SAXParserFactory : public object_base<SCAPIX_META_STRING("javax/xml/parsers/SAXParserFactory"),
	java::lang::Object>
{
public:

	static ref<javax::xml::parsers::SAXParserFactory> newInstance();
	static ref<javax::xml::parsers::SAXParserFactory> newInstance(ref<java::lang::String> factoryClassName, ref<java::lang::ClassLoader> classLoader);
	ref<javax::xml::parsers::SAXParser> newSAXParser();
	void setNamespaceAware(jboolean awareness);
	void setValidating(jboolean validating);
	jboolean isNamespaceAware();
	jboolean isValidating();
	void setFeature(ref<java::lang::String> p1, jboolean p2);
	jboolean getFeature(ref<java::lang::String> p1);
	ref<javax::xml::validation::Schema> getSchema();
	void setSchema(ref<javax::xml::validation::Schema> schema);
	void setXIncludeAware(jboolean state);
	jboolean isXIncludeAware();

protected:

	SAXParserFactory(handle_type h) : base_(h) {}

};

} // namespace javax::xml::parsers
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/ClassLoader.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/javax/xml/parsers/SAXParser.h>
#include <scapix/java_api/javax/xml/validation/Schema.h>

namespace scapix::java_api {
namespace javax::xml::parsers {

inline ref<javax::xml::parsers::SAXParserFactory> SAXParserFactory::newInstance() { return call_static_method<SCAPIX_META_STRING("newInstance"), ref<javax::xml::parsers::SAXParserFactory>>(); }
inline ref<javax::xml::parsers::SAXParserFactory> SAXParserFactory::newInstance(ref<java::lang::String> factoryClassName, ref<java::lang::ClassLoader> classLoader) { return call_static_method<SCAPIX_META_STRING("newInstance"), ref<javax::xml::parsers::SAXParserFactory>>(factoryClassName, classLoader); }
inline ref<javax::xml::parsers::SAXParser> SAXParserFactory::newSAXParser() { return call_method<SCAPIX_META_STRING("newSAXParser"), ref<javax::xml::parsers::SAXParser>>(); }
inline void SAXParserFactory::setNamespaceAware(jboolean awareness) { return call_method<SCAPIX_META_STRING("setNamespaceAware"), void>(awareness); }
inline void SAXParserFactory::setValidating(jboolean validating) { return call_method<SCAPIX_META_STRING("setValidating"), void>(validating); }
inline jboolean SAXParserFactory::isNamespaceAware() { return call_method<SCAPIX_META_STRING("isNamespaceAware"), jboolean>(); }
inline jboolean SAXParserFactory::isValidating() { return call_method<SCAPIX_META_STRING("isValidating"), jboolean>(); }
inline void SAXParserFactory::setFeature(ref<java::lang::String> p1, jboolean p2) { return call_method<SCAPIX_META_STRING("setFeature"), void>(p1, p2); }
inline jboolean SAXParserFactory::getFeature(ref<java::lang::String> p1) { return call_method<SCAPIX_META_STRING("getFeature"), jboolean>(p1); }
inline ref<javax::xml::validation::Schema> SAXParserFactory::getSchema() { return call_method<SCAPIX_META_STRING("getSchema"), ref<javax::xml::validation::Schema>>(); }
inline void SAXParserFactory::setSchema(ref<javax::xml::validation::Schema> schema) { return call_method<SCAPIX_META_STRING("setSchema"), void>(schema); }
inline void SAXParserFactory::setXIncludeAware(jboolean state) { return call_method<SCAPIX_META_STRING("setXIncludeAware"), void>(state); }
inline jboolean SAXParserFactory::isXIncludeAware() { return call_method<SCAPIX_META_STRING("isXIncludeAware"), jboolean>(); }

} // namespace javax::xml::parsers
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_XML_PARSERS_SAXPARSERFACTORY_H
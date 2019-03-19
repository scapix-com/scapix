// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_TEXT_ATTRIBUTEDCHARACTERITERATOR_ATTRIBUTE_H
#define SCAPIX_JAVA_TEXT_ATTRIBUTEDCHARACTERITERATOR_ATTRIBUTE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::text {

class AttributedCharacterIterator_Attribute : public object_base<SCAPIX_META_STRING("java/text/AttributedCharacterIterator$Attribute"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<java::text::AttributedCharacterIterator_Attribute> INPUT_METHOD_SEGMENT_();
	static ref<java::text::AttributedCharacterIterator_Attribute> LANGUAGE_();
	static ref<java::text::AttributedCharacterIterator_Attribute> READING_();

	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	AttributedCharacterIterator_Attribute(handle_type h) : base_(h) {}

};

} // namespace java::text
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::text {

inline ref<java::text::AttributedCharacterIterator_Attribute> AttributedCharacterIterator_Attribute::INPUT_METHOD_SEGMENT_() { return get_static_field<SCAPIX_META_STRING("INPUT_METHOD_SEGMENT"), ref<java::text::AttributedCharacterIterator_Attribute>>(); }
inline ref<java::text::AttributedCharacterIterator_Attribute> AttributedCharacterIterator_Attribute::LANGUAGE_() { return get_static_field<SCAPIX_META_STRING("LANGUAGE"), ref<java::text::AttributedCharacterIterator_Attribute>>(); }
inline ref<java::text::AttributedCharacterIterator_Attribute> AttributedCharacterIterator_Attribute::READING_() { return get_static_field<SCAPIX_META_STRING("READING"), ref<java::text::AttributedCharacterIterator_Attribute>>(); }
inline jboolean AttributedCharacterIterator_Attribute::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint AttributedCharacterIterator_Attribute::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> AttributedCharacterIterator_Attribute::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::text
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TEXT_ATTRIBUTEDCHARACTERITERATOR_ATTRIBUTE_H
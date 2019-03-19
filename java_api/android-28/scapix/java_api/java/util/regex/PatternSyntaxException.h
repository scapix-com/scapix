// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/IllegalArgumentException.h>

#ifndef SCAPIX_JAVA_UTIL_REGEX_PATTERNSYNTAXEXCEPTION_H
#define SCAPIX_JAVA_UTIL_REGEX_PATTERNSYNTAXEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::util::regex {

class PatternSyntaxException : public object_base<SCAPIX_META_STRING("java/util/regex/PatternSyntaxException"),
	java::lang::IllegalArgumentException>
{
public:

	static ref<PatternSyntaxException> new_object(ref<java::lang::String> desc, ref<java::lang::String> regex, jint index);
	jint getIndex();
	ref<java::lang::String> getDescription();
	ref<java::lang::String> getPattern();
	ref<java::lang::String> getMessage();

protected:

	PatternSyntaxException(handle_type h) : base_(h) {}

};

} // namespace java::util::regex
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::util::regex {

inline ref<PatternSyntaxException> PatternSyntaxException::new_object(ref<java::lang::String> desc, ref<java::lang::String> regex, jint index) { return base_::new_object(desc, regex, index); }
inline jint PatternSyntaxException::getIndex() { return call_method<SCAPIX_META_STRING("getIndex"), jint>(); }
inline ref<java::lang::String> PatternSyntaxException::getDescription() { return call_method<SCAPIX_META_STRING("getDescription"), ref<java::lang::String>>(); }
inline ref<java::lang::String> PatternSyntaxException::getPattern() { return call_method<SCAPIX_META_STRING("getPattern"), ref<java::lang::String>>(); }
inline ref<java::lang::String> PatternSyntaxException::getMessage() { return call_method<SCAPIX_META_STRING("getMessage"), ref<java::lang::String>>(); }

} // namespace java::util::regex
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_REGEX_PATTERNSYNTAXEXCEPTION_H
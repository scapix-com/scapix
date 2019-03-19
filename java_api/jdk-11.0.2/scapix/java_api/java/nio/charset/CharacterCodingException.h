// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/IOException.h>

#ifndef SCAPIX_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H
#define SCAPIX_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H

namespace scapix::java_api {
namespace java::nio::charset {

class CharacterCodingException : public object_base<SCAPIX_META_STRING("java/nio/charset/CharacterCodingException"),
	java::io::IOException>
{
public:

	static ref<CharacterCodingException> new_object();

protected:

	CharacterCodingException(handle_type h) : base_(h) {}

};

} // namespace java::nio::charset
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::nio::charset {

inline ref<CharacterCodingException> CharacterCodingException::new_object() { return base_::new_object(); }

} // namespace java::nio::charset
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_CHARSET_CHARACTERCODINGEXCEPTION_H
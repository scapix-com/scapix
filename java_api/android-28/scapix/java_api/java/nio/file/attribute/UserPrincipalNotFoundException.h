// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/io/IOException.h>

#ifndef SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_USERPRINCIPALNOTFOUNDEXCEPTION_H
#define SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_USERPRINCIPALNOTFOUNDEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::nio::file::attribute {

class UserPrincipalNotFoundException : public object_base<SCAPIX_META_STRING("java/nio/file/attribute/UserPrincipalNotFoundException"),
	java::io::IOException>
{
public:

	static ref<UserPrincipalNotFoundException> new_object(ref<java::lang::String> name);
	ref<java::lang::String> getName();

protected:

	UserPrincipalNotFoundException(handle_type h) : base_(h) {}

};

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::nio::file::attribute {

inline ref<UserPrincipalNotFoundException> UserPrincipalNotFoundException::new_object(ref<java::lang::String> name) { return base_::new_object(name); }
inline ref<java::lang::String> UserPrincipalNotFoundException::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_USERPRINCIPALNOTFOUNDEXCEPTION_H
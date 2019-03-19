// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_POSIXFILEPERMISSIONS_H
#define SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_POSIXFILEPERMISSIONS_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::nio::file::attribute { class FileAttribute; }
namespace java::util { class Set; }

namespace java::nio::file::attribute {

class PosixFilePermissions : public object_base<SCAPIX_META_STRING("java/nio/file/attribute/PosixFilePermissions"),
	java::lang::Object>
{
public:

	static ref<java::lang::String> toString(ref<java::util::Set> perms);
	static ref<java::util::Set> fromString(ref<java::lang::String> perms);
	static ref<java::nio::file::attribute::FileAttribute> asFileAttribute(ref<java::util::Set> perms);

protected:

	PosixFilePermissions(handle_type h) : base_(h) {}

};

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/nio/file/attribute/FileAttribute.h>
#include <scapix/java_api/java/util/Set.h>

namespace scapix::java_api {
namespace java::nio::file::attribute {

inline ref<java::lang::String> PosixFilePermissions::toString(ref<java::util::Set> perms) { return call_static_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(perms); }
inline ref<java::util::Set> PosixFilePermissions::fromString(ref<java::lang::String> perms) { return call_static_method<SCAPIX_META_STRING("fromString"), ref<java::util::Set>>(perms); }
inline ref<java::nio::file::attribute::FileAttribute> PosixFilePermissions::asFileAttribute(ref<java::util::Set> perms) { return call_static_method<SCAPIX_META_STRING("asFileAttribute"), ref<java::nio::file::attribute::FileAttribute>>(perms); }

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_POSIXFILEPERMISSIONS_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/nio/file/attribute/FileAttributeView.h>

#ifndef SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_FILEOWNERATTRIBUTEVIEW_H
#define SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_FILEOWNERATTRIBUTEVIEW_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::nio::file::attribute { class UserPrincipal; }

namespace java::nio::file::attribute {

class FileOwnerAttributeView : public object_base<SCAPIX_META_STRING("java/nio/file/attribute/FileOwnerAttributeView"),
	java::lang::Object,
	java::nio::file::attribute::FileAttributeView>
{
public:

	ref<java::lang::String> name();
	ref<java::nio::file::attribute::UserPrincipal> getOwner();
	void setOwner(ref<java::nio::file::attribute::UserPrincipal> p1);

protected:

	FileOwnerAttributeView(handle_type h) : base_(h) {}

};

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/nio/file/attribute/UserPrincipal.h>

namespace scapix::java_api {
namespace java::nio::file::attribute {

inline ref<java::lang::String> FileOwnerAttributeView::name() { return call_method<SCAPIX_META_STRING("name"), ref<java::lang::String>>(); }
inline ref<java::nio::file::attribute::UserPrincipal> FileOwnerAttributeView::getOwner() { return call_method<SCAPIX_META_STRING("getOwner"), ref<java::nio::file::attribute::UserPrincipal>>(); }
inline void FileOwnerAttributeView::setOwner(ref<java::nio::file::attribute::UserPrincipal> p1) { return call_method<SCAPIX_META_STRING("setOwner"), void>(p1); }

} // namespace java::nio::file::attribute
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NIO_FILE_ATTRIBUTE_FILEOWNERATTRIBUTEVIEW_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/RuntimeException.h>

#ifndef SCAPIX_ANDROID_OS_FILEURIEXPOSEDEXCEPTION_H
#define SCAPIX_ANDROID_OS_FILEURIEXPOSEDEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::os {

class FileUriExposedException : public object_base<SCAPIX_META_STRING("android/os/FileUriExposedException"),
	java::lang::RuntimeException>
{
public:

	static ref<FileUriExposedException> new_object(ref<java::lang::String> message);

protected:

	FileUriExposedException(handle_type h) : base_(h) {}

};

} // namespace android::os
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::os {

inline ref<FileUriExposedException> FileUriExposedException::new_object(ref<java::lang::String> message) { return base_::new_object(message); }

} // namespace android::os
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_OS_FILEURIEXPOSEDEXCEPTION_H

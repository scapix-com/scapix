/*
	scapix/jni/throwable.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_THROWABLE_H
#define SCAPIX_JNI_THROWABLE_H

#include <scapix/jni/object.h>

namespace scapix::jni {

class throwable : public object<"java/lang/Throwable">
{
public:

	jint throw_() const
	{
		return detail::env()->Throw(handle());
	}

protected:

	throwable(handle_type h) : object(h) {}

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_THROWABLE_H

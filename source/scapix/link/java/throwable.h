/*
	scapix/link/java/throwable.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_THROWABLE_H
#define SCAPIX_LINK_JAVA_THROWABLE_H

#include <scapix/link/java/object.h>

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

#endif // SCAPIX_LINK_JAVA_THROWABLE_H

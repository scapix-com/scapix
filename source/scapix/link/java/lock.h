/*
	scapix/link/java/lock.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_LOCK_H
#define SCAPIX_LINK_JAVA_LOCK_H

#include <scapix/link/java/env.h>

namespace scapix::link::java {

enum class lock
{
	noncritical,
	critical,
};

enum class release_mode
{
	copy = 0,
	abort = JNI_ABORT,
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_LOCK_H

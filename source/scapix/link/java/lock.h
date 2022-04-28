/*
	scapix/link/java/lock.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_LOCK_H
#define SCAPIX_LINK_JAVA_LOCK_H

namespace scapix::link::java {

enum class lock
{
	noncritical,
	critical,
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_LOCK_H

/*
	scapix/link/java/lock.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_LOCK_H
#define SCAPIX_LINK_JAVA_LOCK_H

namespace scapix {
namespace link {
namespace java {

enum class lock
{
	noncritical,
	critical,
};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_LOCK_H

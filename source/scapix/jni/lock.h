/*
	scapix/jni/lock.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_LOCK_H
#define SCAPIX_JNI_LOCK_H

#include <scapix/jni/env.h>

namespace scapix::jni {

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

} // namespace scapix::jni

#endif // SCAPIX_JNI_LOCK_H

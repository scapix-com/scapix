/*
	scapix/link/java/detail/env.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_ENV_H
#define SCAPIX_LINK_JAVA_DETAIL_ENV_H

#include <jni.h>
#include <scapix/link/java/detail/config.h>

namespace scapix {
namespace link {
namespace java {
namespace detail {

inline JavaVM*& jvm() noexcept
{
	static JavaVM* ptr;
	return ptr;
}

inline JNIEnv*& env() noexcept
{
#ifdef SCAPIX_LINK_JAVA_NO_THREAD_LOCAL

	static __thread JNIEnv* ptr;

#else

	thread_local JNIEnv* ptr;

#endif

	return ptr;
}

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_DETAIL_ENV_H

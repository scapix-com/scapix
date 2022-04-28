/*
	scapix/link/java/env.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_ENV_H
#define SCAPIX_LINK_JAVA_ENV_H

#include <scapix/link/java/detail/config.h>

namespace scapix::link::java {

inline jint get_env(jint version = JNI_VERSION_1_6) noexcept
{
	return detail::jvm()->GetEnv((void**)&detail::env(), version);
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_ENV_H

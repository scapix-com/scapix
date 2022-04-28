/*
	scapix/link/java/init.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_INIT_H
#define SCAPIX_LINK_JAVA_INIT_H

#include <scapix/link/java/env.h>

namespace scapix::link::java {

inline jint on_load(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm() = vm;
	get_env();

	return JNI_VERSION_1_6;
}

inline void on_unload(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm() = nullptr;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_INIT_H

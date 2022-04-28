/*
	scapix/link/java/vm.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_VM_H
#define SCAPIX_LINK_JAVA_VM_H

#include <scapix/link/java/detail/config.h>

namespace scapix::link::java {

inline bool init_created_vm() noexcept
{
	jint count;
	JNI_GetCreatedJavaVMs(&detail::jvm(), 1, &count);
	return count != 0;
}

inline void deinit_created_vm() noexcept
{
	detail::jvm() = nullptr;
}

inline jint create_vm(void* args) noexcept
{
	return JNI_CreateJavaVM(&detail::jvm(), reinterpret_cast<detail::jnienv_type>(&detail::env()), args);
}

inline jint destroy_vm() noexcept
{
	auto r = detail::jvm()->DestroyJavaVM();
	if (r == JNI_OK)
		detail::jvm() = nullptr;
	return r;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_VM_H

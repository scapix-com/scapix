/*
	scapix/link/java/vm.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_VM_H
#define SCAPIX_LINK_JAVA_VM_H

#include <scapix/link/java/env.h>

namespace scapix::link::java {

inline bool init_created_vm() noexcept
{
	jint count;
	JNI_GetCreatedJavaVMs(&detail::jvm_ptr, 1, &count);
	return count != 0;
}

inline void deinit_created_vm() noexcept
{
	detail::jvm_ptr = nullptr;
	detail::env_.ptr = nullptr;
}

inline jint create_vm(JavaVMInitArgs* args) noexcept
{
	return JNI_CreateJavaVM(&detail::jvm_ptr, detail::env_.addr(), args);
}

inline jint destroy_vm() noexcept
{
	auto r = detail::jvm()->DestroyJavaVM();

	detail::jvm_ptr = nullptr;
	detail::env_.ptr = nullptr;

	return r;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_VM_H

/*
	scapix/jni/vm.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_VM_H
#define SCAPIX_JNI_VM_H

#include <scapix/jni/env.h>

namespace scapix::jni {

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

} // namespace scapix::jni

#endif // SCAPIX_JNI_VM_H

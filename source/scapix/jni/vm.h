/*
	scapix/jni/vm.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_VM_H
#define SCAPIX_JNI_VM_H

#include <stdexcept>
#include <string>
#include <scapix/jni/env.h>
#include <scapix/jni/detail/init.h>

namespace scapix::jni {

inline void create_vm(JavaVMInitArgs* args)
{
	auto r = JNI_CreateJavaVM(&detail::jvm_ptr, detail::env_.addr(), args);

	if (r != JNI_OK)
		throw std::runtime_error("JNI_CreateJavaVM failed: " + std::to_string(r));

	detail::init();
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

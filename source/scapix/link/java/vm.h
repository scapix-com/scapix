/*
	scapix/link/java/vm.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_VM_H
#define SCAPIX_LINK_JAVA_VM_H

#include <scapix/link/java/detail/env.h>
#include <scapix/link/java/thread.h>

/*
struct JavaVM_
{
	jint DestroyJavaVM();
	jint AttachCurrentThread(void **penv, void *args);
	jint DetachCurrentThread();
	jint GetEnv(void **penv, jint version);
	jint AttachCurrentThreadAsDaemon(void **penv, void *args);
};

_JNI_IMPORT_OR_EXPORT_ jint JNICALL JNI_GetDefaultJavaVMInitArgs(void *args);
_JNI_IMPORT_OR_EXPORT_ jint JNICALL JNI_CreateJavaVM(JavaVM **pvm, void **penv, void *args);
_JNI_IMPORT_OR_EXPORT_ jint JNICALL JNI_GetCreatedJavaVMs(JavaVM **, jsize, jsize *);
*/

namespace scapix {
namespace link {
namespace java {

inline jint on_load(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm() = vm;
	get_env();

//	execute_init_handlers();

	return JNI_VERSION_1_6;
}

inline void on_unload(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm() = nullptr;
}

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

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_VM_H

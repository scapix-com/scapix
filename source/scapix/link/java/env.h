/*
	scapix/link/java/env.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_ENV_H
#define SCAPIX_LINK_JAVA_ENV_H

#include <jni.h>
#include <boost/config.hpp>
#include <scapix/core/function_traits.h>

namespace scapix::link::java {
namespace detail {

/*

jni.h (JDK) uses void** type:

	jint JNI_CreateJavaVM(JavaVM**, void**, void*);
	jint AttachCurrentThread(JavaVM*, void**, void*);
	jint AttachCurrentThreadAsDaemon(JavaVM*, void**, void*);

jni.h (Android NDK) uses JNIEnv** type:

	jint JNI_CreateJavaVM(JavaVM**, JNIEnv**, void*);
	jint AttachCurrentThread(JavaVM*, JNIEnv**, void*);
	jint AttachCurrentThreadAsDaemon(JavaVM*, JNIEnv**, void*);

*/

using jnienv_type = function_traits<std::remove_pointer_t<decltype(&JNI_CreateJavaVM)>>::argument_type<1>;

inline JavaVM* jvm_ptr;

inline JavaVM* jvm() noexcept
{
	return jvm_ptr;
}

struct thread_env
{
	~thread_env()
	{
		if (ptr && jvm())
			jvm()->DetachCurrentThread();
	}

	jnienv_type addr() { return reinterpret_cast<jnienv_type>(&ptr); }
	void** addr_void() { return reinterpret_cast<void**>(&ptr); }

	JNIEnv* ptr = nullptr;
};

inline thread_local thread_env env_;

} // namespace detail

inline jint get_env(jint version = JNI_VERSION_1_6) noexcept
{
	return detail::jvm()->GetEnv(detail::env_.addr_void(), version);
}

inline jint attach_current_thread(JavaVMAttachArgs* args = nullptr) noexcept
{
	return detail::jvm()->AttachCurrentThread(detail::env_.addr(), args);
}

inline jint attach_current_thread_as_daemon(JavaVMAttachArgs* args = nullptr) noexcept
{
	return detail::jvm()->AttachCurrentThreadAsDaemon(detail::env_.addr(), args);
}

inline jint detach_current_thread() noexcept
{
	detail::env_.ptr = nullptr;
	return detail::jvm()->DetachCurrentThread();
}

namespace detail {

inline JNIEnv* env() noexcept
{
#ifdef SCAPIX_JAVA_AUTO_ATTACH_THREAD

	if (BOOST_UNLIKELY(!env_.ptr))
		attach_current_thread();

#endif

	return env_.ptr;
}

} // namespace detail
} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_ENV_H

/*
	scapix/link/java/detail/config.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_CONFIG_H
#define SCAPIX_LINK_JAVA_DETAIL_CONFIG_H

#include <jni.h>
#include <scapix/core/function_traits.h>

// apple clang is missing thread_local

#if defined(__clang__)
#if !__has_feature(cxx_thread_local)
#define SCAPIX_LINK_JAVA_NO_THREAD_LOCAL
#endif
#endif

namespace scapix::link::java::detail {

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

} // namespace scapix::link::java::detail

#endif // SCAPIX_LINK_JAVA_DETAIL_CONFIG_H

/*
	scapix/link/java/thread.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_THREAD_H
#define SCAPIX_LINK_JAVA_THREAD_H

#include <boost/config.hpp>
#include <scapix/link/java/vm.h>
#include <scapix/link/java/detail/env.h>

#ifdef SCAPIX_LINK_JAVA_NO_THREAD_LOCAL
#include <pthread.h>
#endif

namespace scapix {
namespace link {
namespace java {

inline jint detach_current_thread() noexcept
{
	if (detail::env())
	{
		auto r = detail::jvm()->DetachCurrentThread();
		if (r == JNI_OK)
			detail::env() = nullptr;
		return r;
	}
	return JNI_EDETACHED;
}

namespace detail {

#ifdef SCAPIX_LINK_JAVA_NO_THREAD_LOCAL

inline void thread_detach_function(void*)
{
	detach_current_thread();
}

#endif

inline void register_thread_detach() noexcept
{
#ifdef SCAPIX_LINK_JAVA_NO_THREAD_LOCAL

	static __thread bool registered = false;

	if (!registered)
	{
		pthread_cleanup_push(thread_detach_function, nullptr);
		registered = true;
	}

#else

	struct thread_detach_context
	{
		~thread_detach_context() { detach_current_thread(); }
	};

	thread_local thread_detach_context context;

#endif
}

} // namespace detail

inline jint attach_current_thread(void *args = nullptr) noexcept
{
	if (!detail::env())
	{
		auto r = detail::jvm()->AttachCurrentThread((detail::jnienv_api_type**)&detail::env(), args);
		if (r == JNI_OK)
			detail::register_thread_detach();
		return r;
	}
	return JNI_OK;
}

inline jint attach_current_thread_as_daemon(void *args = nullptr) noexcept
{
	if (!detail::env())
	{
		auto r = detail::jvm()->AttachCurrentThreadAsDaemon((detail::jnienv_api_type**)&detail::env(), args);
		if (r == JNI_OK)
			detail::register_thread_detach();
		return r;
	}
	return JNI_OK;
}

inline jint get_env(jint version = JNI_VERSION_1_6) noexcept
{
	return detail::jvm()->GetEnv((void**)&detail::env(), version);
}

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_THREAD_H

/*
	scapix/link/java/detail/config.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_CONFIG_H
#define SCAPIX_LINK_JAVA_DETAIL_CONFIG_H

#include <vector>

// apple clang is missing thread_local

#if defined(__clang__)
#if !__has_feature(cxx_thread_local)
#define SCAPIX_LINK_JAVA_NO_THREAD_LOCAL
#endif
#endif

namespace scapix {
namespace link {
namespace java {
namespace detail {

// jni.h on android uses JNIEnv
#ifdef ANDROID
    using jnienv_api_type = JNIEnv;
#else
    using jnienv_api_type = void;
#endif

inline std::vector<void(*)()>& init_handlers()
{
	static std::vector<void(*)()> handlers;
	return handlers;
}

inline void register_init_handler(void(*init)())
{
	init_handlers().push_back(init);
}

inline void execute_init_handlers()
{
	for (auto& handler : init_handlers())
		handler();

	init_handlers().clear();
}

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_DETAIL_CONFIG_H

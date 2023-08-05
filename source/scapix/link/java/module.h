/*
	scapix/link/java/module.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_MODULE_H
#define SCAPIX_LINK_JAVA_MODULE_H

#include <scapix/link/java/env.h>
#include <scapix/link/java/detail/native_exception.h>
#include <scapix/link/java/native_method.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/link/java/class_loader.h>
#endif

namespace scapix::link::java {

inline jint on_load(JavaVM *vm, void *reserved)
{
	detail::jvm_ptr = vm;
	get_env();

#ifdef SCAPIX_CACHE_CLASS_LOADER
	class_loader::init();
#endif

	native_methods
	<
		detail::native_exception::class_name,
		native_method<SCAPIX_META_STRING("finalize"), void(), void(detail::native_exception_cpp::*)(), &detail::native_exception_cpp::finalize>,
		native_method<SCAPIX_META_STRING("getMessage"), ref<string>(), ref<string>(detail::native_exception_cpp::*)() const, &detail::native_exception_cpp::message>
	>
	::register_();

	return JNI_VERSION_1_6;
}

inline void on_unload(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm_ptr = nullptr;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_MODULE_H

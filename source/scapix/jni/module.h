/*
	scapix/jni/module.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_MODULE_H
#define SCAPIX_JNI_MODULE_H

#include <scapix/jni/env.h>
#include <scapix/jni/vm_exception.h>
#include <scapix/jni/native_method.h>
#include <scapix/jni/com/scapix/native_exception.h>
#include <scapix/jni/com/scapix/bridge.h>
#include <scapix/jni/com/scapix/function.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/jni/class_loader.h>
#endif

namespace scapix::jni {

inline jint on_load(JavaVM* vm, void* reserved, void(*init)() = []{})
{
	try
	{
		detail::jvm_ptr = vm;
		get_env();

		com::scapix::native_exception::native_methods::register_();
		com::scapix::bridge_::native_methods::register_();
		com::scapix::function::native_methods::register_();

		#ifdef SCAPIX_CACHE_CLASS_LOADER
		class_loader::init();
		#endif

		init();

		return JNI_VERSION_1_6;
	}
	catch (const vm_exception& e)
	{
		e.get()->throw_();

		// Android doesn't check exception after calling JNI_OnLoad()
		#ifdef ANDROID
		detail::env()->ExceptionDescribe();
		detail::env()->ExceptionClear();
		#endif
	}

	return JNI_ERR;
}

inline void on_unload(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm_ptr = nullptr;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_MODULE_H

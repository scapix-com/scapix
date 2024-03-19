/*
	scapix/jni/module.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_MODULE_H
#define SCAPIX_JNI_MODULE_H

#include <scapix/jni/env.h>
#include <scapix/jni/vm_exception.h>
#include <scapix/jni/detail/init.h>

namespace scapix::jni {

inline jint on_load(JavaVM* vm, void* reserved, void(*init)() = []{})
{
	try
	{
		detail::jvm_ptr = vm;
		get_env();

		detail::init();
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

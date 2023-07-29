/*
	scapix/bridge/java/module.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_MODULE_H
#define SCAPIX_BRIDGE_JAVA_MODULE_H

#include <scapix/bridge/java/on_load.h>
#include <scapix/bridge/java/object.h>
#include <scapix/bridge/java/function.h>
#include <scapix/link/java/module.h>
#include <scapix/link/java/native_method.h>
#include <scapix/link/java/vm_exception.h>

namespace scapix::bridge::java {

inline jint on_load(JavaVM *vm, void *reserved, void(*init)())
{
	try
	{
		auto result = link::java::on_load(vm, reserved);

		link::java::native_methods
		<
			detail::bridge::class_name,
			link::java::native_method<SCAPIX_META_STRING("finalize"), void(), void(object_base::*)(), &object_base::finalize>
		>
		::register_();

		link::java::native_methods
		<
			link::java::detail::function::class_name,
			link::java::native_method<SCAPIX_META_STRING("finalize"), void(), void(function_base::*)(), &function_base::finalize>
		>
		::register_();

		init();

		return result;
	}
	catch (const link::java::vm_exception& e)
	{
		e.get()->throw_();

		// Android doesn't check exception after calling JNI_OnLoad()
		#ifdef ANDROID
		link::java::detail::env()->ExceptionDescribe();
		link::java::detail::env()->ExceptionClear();
		#endif
	}

	return JNI_ERR;
}

} // namespace scapix::bridge::java

#endif // SCAPIX_BRIDGE_JAVA_MODULE_H

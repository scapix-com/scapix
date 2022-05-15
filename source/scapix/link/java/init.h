/*
	scapix/link/java/init.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_INIT_H
#define SCAPIX_LINK_JAVA_INIT_H

#include <scapix/link/java/env.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <algorithm>
#include <scapix/link/java/class.h>
#include <scapix/link/java/string.h>
#endif

namespace scapix::link::java {

#ifdef SCAPIX_CACHE_CLASS_LOADER

class class_loader
{
public:

	static void init()
	{
		auto app_cls = class_::find_class("com/scapix/NativeException");
		auto cls = app_cls->get_object_class();
		auto get_class_loader_method = cls->get_method_id<SCAPIX_META_STRING("getClassLoader"), ref<SCAPIX_META_STRING("java/lang/ClassLoader")>()>();
		loader.reset(global_ref<SCAPIX_META_STRING("java/lang/ClassLoader")>(app_cls->call_method<ref<SCAPIX_META_STRING("java/lang/ClassLoader")>()>(get_class_loader_method)).release());
		auto loader_cls = loader->get_object_class();
		load_class_method = loader_cls->get_method_id<SCAPIX_META_STRING("loadClass"), ref<SCAPIX_META_STRING("java/lang/Class")>(ref<SCAPIX_META_STRING("java/lang/String")>)>();
	}

	static local_ref<class_> find_class(const char* name)
	{
		return loader->call_method<ref<SCAPIX_META_STRING("java/lang/Class")>(ref<SCAPIX_META_STRING("java/lang/String")>)>(load_class_method, string::new_(name));
	}

private:

	inline static ref<SCAPIX_META_STRING("java/lang/ClassLoader")> loader;
	inline static jmethodID load_class_method;

};

#endif

inline jint on_load(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm_ptr = vm;
	get_env();

#ifdef SCAPIX_CACHE_CLASS_LOADER
	class_loader::init();
#endif

	return JNI_VERSION_1_6;
}

inline void on_unload(JavaVM *vm, void *reserved) noexcept
{
	detail::jvm_ptr = nullptr;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_INIT_H

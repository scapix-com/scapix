/*
	scapix/link/java/class_loader.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/link/java/object_impl.h>

#ifndef SCAPIX_LINK_JAVA_CLASS_LOADER_H
#define SCAPIX_LINK_JAVA_CLASS_LOADER_H

#include <scapix/link/java/class.h>
#include <scapix/link/java/string.h>

namespace scapix::link::java {

/*

In some JVM scenarios (notably on Android), JNI FindClass() fails to load application classes when called from C++ created threads.
More information here: [Why didn’t FindClass find my class?](https://developer.android.com/training/articles/perf-jni#faq:-why-didnt-findclass-find-my-class).
This implements the option "Cache a reference to the ClassLoader object somewhere handy, and issue loadClass calls directly."

*/

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

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_CLASS_LOADER_H

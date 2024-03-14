/*
	scapix/jni/class_loader.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/jni/object_impl.h>

#ifndef SCAPIX_JNI_CLASS_LOADER_H
#define SCAPIX_JNI_CLASS_LOADER_H

#include <scapix/jni/class.h>
#include <scapix/jni/string.h>

namespace scapix::jni {

/*

In some JVM scenarios (notably on Android), JNI FindClass() fails to load application classes when called from C++ created threads.
More information here: [Why didn’t FindClass find my class?](https://developer.android.com/training/articles/perf-jni#faq:-why-didnt-findclass-find-my-class).
This implements the option "Cache a reference to the ClassLoader object somewhere handy, and issue loadClass calls directly."

*/

class class_loader
{
	using java_lang_class_loader = object<"java/lang/ClassLoader">;

public:

	static void init()
	{
		auto app_cls = class_::find_class("com/scapix/NativeException");
		auto cls = app_cls->get_object_class();
		auto get_class_loader_method = cls->get_method_id("getClassLoader", signature_v<ref<java_lang_class_loader>()>);
		loader = app_cls->call_method<ref<java_lang_class_loader>()>(get_class_loader_method);
		auto loader_cls = loader->get_object_class();
		load_class_method = loader_cls->get_method_id("loadClass", signature_v<ref<class_>(ref<string>)>);
	}

	static local_ref<class_> find_class(const char* name)
	{
		return loader->call_method<ref<class_>(ref<string>)>(load_class_method, string::new_(name));
	}

private:

	inline static static_global_ref<java_lang_class_loader> loader;
	inline static jmethodID load_class_method;

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_CLASS_LOADER_H

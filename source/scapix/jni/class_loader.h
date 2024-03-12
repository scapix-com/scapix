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

template<>
inline ref<class_> object_impl<"java/lang/Thread">::class_object()
{
	static const static_global_ref<class_> cls(class_::find_class(class_name));
	return cls;
}

template<>
inline ref<class_> object_impl<"java/lang/ClassLoader">::class_object()
{
	static const static_global_ref<class_> cls(class_::find_class(class_name));
	return cls;
}

class class_loader
{
public:

	static void init()
	{
		loader = object<"java/lang/Thread">::call_static_method<"currentThread", ref<object<"java/lang/Thread">>()>()->call_method<"getContextClassLoader", ref<object<"java/lang/ClassLoader">>()>();
	}

	static local_ref<class_> find_class(const char* name)
	{
		return loader->call_method<"loadClass", ref<class_>(ref<string>)>(new_object<string>(name));
	}

private:

	inline static static_global_ref<object<"java/lang/ClassLoader">> loader;

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_CLASS_LOADER_H

/*
	scapix/jni/detail/init.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_INIT_H
#define SCAPIX_JNI_DETAIL_INIT_H

#include <scapix/jni/native_method.h>
#include <scapix/jni/com/scapix/native_exception.h>
#include <scapix/jni/com/scapix/bridge.h>
#include <scapix/jni/com/scapix/function.h>

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/jni/class_loader.h>
#endif

namespace scapix::jni::detail {

inline void init()
{
	#ifdef SCAPIX_CACHE_CLASS_LOADER
	class_loader::init();
	#endif

	com::scapix::native_exception::native_methods::register_();
	com::scapix::bridge_::native_methods::register_();
	com::scapix::function::native_methods::register_();
}

} // namespace scapix::jni::detail

#endif // SCAPIX_JNI_DETAIL_INIT_H

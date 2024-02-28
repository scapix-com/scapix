/*
	scapix/jni/fwd/native_method.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_NATIVE_METHOD_H
#define SCAPIX_JNI_FWD_NATIVE_METHOD_H

#include <type_traits>
#include <scapix/core/fixed_string.h>

namespace scapix::jni {

template <fixed_string ClassName, typename ...Methods>
class native_methods;

template <fixed_string Name, typename JniType, typename Type, std::decay_t<Type> Method>
struct native_method;

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_NATIVE_METHOD_H

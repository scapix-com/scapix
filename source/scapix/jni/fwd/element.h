/*
	scapix/jni/fwd/element.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_ELEMENT_H
#define SCAPIX_JNI_FWD_ELEMENT_H

namespace scapix::jni {

template <typename T>
struct element_type;

template <typename T>
using element_type_t = typename element_type<T>::type;

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_ELEMENT_H

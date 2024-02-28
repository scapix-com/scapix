/*
	scapix/jni/fwd/signature.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_SIGNATURE_H
#define SCAPIX_JNI_FWD_SIGNATURE_H

namespace scapix::jni {

template <typename T>
struct signature;

template <typename T>
constexpr auto signature_v = signature<T>::value;

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_SIGNATURE_H

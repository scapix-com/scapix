/*
	scapix/link/java/fwd/signature.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_SIGNATURE_H
#define SCAPIX_LINK_JAVA_FWD_SIGNATURE_H

namespace scapix::link::java {

template <typename T>
struct signature;

template <typename T>
constexpr auto signature_v = signature<T>::value;

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FWD_SIGNATURE_H

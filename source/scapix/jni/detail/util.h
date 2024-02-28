/*
	scapix/jni/detail/util.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_UTIL_H
#define SCAPIX_JNI_DETAIL_UTIL_H

namespace scapix::jni::detail {

template <typename T, typename Friend>
class befriend : public T
{
	using T::T;
	friend Friend;
};

} // namespace scapix::jni::detail

#endif // SCAPIX_JNI_DETAIL_UTIL_H

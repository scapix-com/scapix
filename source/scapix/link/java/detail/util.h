/*
	scapix/link/java/detail/util.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_UTIL_H
#define SCAPIX_LINK_JAVA_DETAIL_UTIL_H

namespace scapix {
namespace link {
namespace java {
namespace detail {

template <typename T, typename>
class tag : public T
{
	using T::T;
};

template <typename T, typename Friend>
class befriend : public T
{
	using T::T;
	friend Friend;
};

// befriend doesn't work on MSC (as of vs2019 16.4.4) in C++17 mode

#if defined(_MSC_VER) && !defined(__clang__)
#define protected public
#endif

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_DETAIL_UTIL_H

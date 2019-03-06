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

// befriend doesn't work on MSC (as of 2017 15.9) in C++17 mode

#ifdef _MSC_VER
#define protected public
#endif

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_DETAIL_UTIL_H

/*
	scapix/link/cs/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_TYPE_TRAITS_H
#define SCAPIX_LINK_CS_TYPE_TRAITS_H

#include <cstdint>
#include <type_traits>

namespace scapix::link::cs {

// is_simple

template<typename T, typename = void>
struct is_simple : std::false_type {};

template<typename T>
struct is_simple<T, std::enable_if_t<std::is_arithmetic_v<T> || std::is_enum_v<T>>> : std::true_type {};

template<typename T>
constexpr bool is_simple_v = is_simple<T>::value;

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_TYPE_TRAITS_H

/*
	scapix/link/cs/type_traits.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_TYPE_TRAITS_H
#define SCAPIX_LINK_CS_TYPE_TRAITS_H

#include <cstdint>
#include <type_traits>

namespace scapix {
namespace link {
namespace cs {

// is_simple

template<class T>
struct is_simple : std::false_type {};

template<> struct is_simple<bool> : std::true_type {};
template<> struct is_simple<std::int8_t> : std::true_type {};
template<> struct is_simple<std::int16_t> : std::true_type {};
template<> struct is_simple<std::int32_t> : std::true_type {};
template<> struct is_simple<std::int64_t> : std::true_type {};
template<> struct is_simple<std::uint8_t> : std::true_type {};
template<> struct is_simple<std::uint16_t> : std::true_type {};
template<> struct is_simple<std::uint32_t> : std::true_type {};
template<> struct is_simple<std::uint64_t> : std::true_type {};
template<> struct is_simple<float> : std::true_type {};
template<> struct is_simple<double> : std::true_type {};

template<typename T>
constexpr bool is_simple_v = is_simple<T>::value;

} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_CS_TYPE_TRAITS_H

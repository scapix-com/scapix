/*
	scapix/bridge/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_TYPE_TRAITS_H
#define SCAPIX_BRIDGE_TYPE_TRAITS_H

#include <type_traits>
#include <cstdint>

namespace scapix {
namespace bridge {

namespace SCAPIX_BRIDGE {

class object_base;

} // namespace SCAPIX_BRIDGE

template <typename T>
constexpr bool is_object = std::is_base_of_v<SCAPIX_BRIDGE::object_base, T>;

template <typename T>
struct is_arithmetic : std::false_type {};

template <> struct is_arithmetic<bool> : std::true_type {};
template <> struct is_arithmetic<std::int8_t> : std::true_type {};
template <> struct is_arithmetic<std::int16_t> : std::true_type {};
template <> struct is_arithmetic<std::int32_t> : std::true_type {};
template <> struct is_arithmetic<std::int64_t> : std::true_type {};
template <> struct is_arithmetic<float> : std::true_type {};
template <> struct is_arithmetic<double> : std::true_type {};

template <typename T>
constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

} // namespace bridge
} // namespace scapix

#endif // SCAPIX_BRIDGE_TYPE_TRAITS_H

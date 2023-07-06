/*
	scapix/link/js/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JS_TYPE_TRAITS_H
#define SCAPIX_LINK_JS_TYPE_TRAITS_H

#include <type_traits>

namespace scapix {
namespace link {
namespace js {

template<typename T>
struct is_native : std::false_type {};

template<> struct is_native<bool> : std::true_type {};
template<> struct is_native<char> : std::true_type {};
template<> struct is_native<signed char> : std::true_type {};
template<> struct is_native<unsigned char> : std::true_type {};
template<> struct is_native<signed short> : std::true_type {};
template<> struct is_native<unsigned short> : std::true_type {};
template<> struct is_native<signed int> : std::true_type {};
template<> struct is_native<unsigned int> : std::true_type {};
template<> struct is_native<signed long> : std::true_type {};
template<> struct is_native<unsigned long> : std::true_type {};
template<> struct is_native<signed long long> : std::true_type {}; // doesn't work: emscripten doesn't support 64-bit integers
template<> struct is_native<unsigned long long> : std::true_type {}; // doesn't work: emscripten doesn't support 64-bit integers
template<> struct is_native<float> : std::true_type {};
template<> struct is_native<double> : std::true_type {};

template<typename T>
constexpr bool is_native_v = is_native<T>::value;

} // namespace js
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JS_TYPE_TRAITS_H

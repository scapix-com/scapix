/*
	scapix/core/type_traits.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_TYPE_TRAITS_H
#define SCAPIX_CORE_TYPE_TRAITS_H

#include <type_traits>

namespace scapix {

// member_pointer_type

template <typename T>
struct member_pointer_type
{
	using type = T;
};

template <typename T, typename C>
struct member_pointer_type<T C::*>
{
	using type = T;
};

template <typename T>
using member_pointer_type_t = typename member_pointer_type<T>::type;

// member_pointer_class

template <typename T>
struct member_pointer_class
{
	using type = T;
};

template <typename T, typename C>
struct member_pointer_class<T C::*>
{
	using type = C;
};

template <typename T>
using member_pointer_class_t = typename member_pointer_class<T>::type;

// function_pointer

template <typename T>
concept function_pointer = std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>;

// member_pointer

template <typename T>
concept member_pointer = std::is_member_pointer_v<T>;

template <typename T>
concept member_object_pointer = std::is_member_object_pointer_v<T>;

template <typename T>
concept member_function_pointer = std::is_member_function_pointer_v<T>;

// class_template

template <typename T, template<typename...> class C>
constexpr bool is_class_template = false;

template <template<typename...> class C, typename ...Ts>
constexpr bool is_class_template<C<Ts...>, C> = true;

template <typename T, template<typename...> class C>
concept class_template = is_class_template<T, C>;

} // namespace scapix

#endif // SCAPIX_CORE_TYPE_TRAITS_H

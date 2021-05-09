/*
	scapix/core/type_traits.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_TYPE_TRAITS_H
#define SCAPIX_CORE_TYPE_TRAITS_H

#include <type_traits>

namespace scapix {

// C++20

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

// C++20

template <typename T>
struct type_identity
{
	using type = T;
};

template <typename T>
using type_identity_t = typename type_identity<T>::type;

// member_pointer_traits

template <typename T>
struct member_pointer_traits;

template <typename T, typename Class>
struct member_pointer_traits<T Class::*>
{
	using type = T;
	using class_type = Class;
};

template <typename T>
using member_pointer_type = typename member_pointer_traits<T>::type;

template <typename T>
using member_pointer_class_type = typename member_pointer_traits<T>::class_type;

template <auto Ptr>
using member_type = member_pointer_type<decltype(Ptr)>;

template <auto Ptr>
using member_class_type = member_pointer_class_type<decltype(Ptr)>;

} // namespace scapix

#endif // SCAPIX_CORE_TYPE_TRAITS_H

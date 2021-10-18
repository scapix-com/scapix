/*
	scapix/core/type_traits.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_TYPE_TRAITS_H
#define SCAPIX_CORE_TYPE_TRAITS_H

#include <type_traits>
#include <scapix/core/remove_function_qualifiers.h>

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

} // namespace scapix

#endif // SCAPIX_CORE_TYPE_TRAITS_H

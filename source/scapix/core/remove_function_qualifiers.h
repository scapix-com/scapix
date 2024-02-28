/*
	scapix/core/remove_function_qualifiers.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H
#define SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H

#include <scapix/core/type_traits.h>

namespace scapix {

template <typename T>
struct remove_function_qualifiers
{
	using type = T;
};

template <typename T>
using remove_function_qualifiers_t = typename remove_function_qualifiers<T>::type;

template <function_pointer T>
struct remove_function_qualifiers<T>
{
	using type = std::add_pointer_t<remove_function_qualifiers_t<std::remove_pointer_t<T>>>;
};

template <member_function_pointer T>
struct remove_function_qualifiers<T>
{
	using type = remove_function_qualifiers_t<member_pointer_type_t<T>> member_pointer_class_t<T>::*;
};

// qualifiers: const volatile & && noexcept, 24 total

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)&&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const&&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile&&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile&&>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)&& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const&& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)volatile&& noexcept>
{
	using type = R(Args...);
};

template <typename R, typename ...Args>
struct remove_function_qualifiers<R(Args...)const volatile&& noexcept>
{
	using type = R(Args...);
};

} // namespace scapix

#endif // SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H

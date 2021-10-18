/*
	scapix/core/remove_function_qualifiers.h

	Copyright (c) 2021 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H
#define SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H

namespace scapix {

template <typename T>
struct remove_function_qualifiers
{
	using type = T;
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

// remove_function_qualifiers_t

template <typename T>
using remove_function_qualifiers_t = typename remove_function_qualifiers<T>::type;

} // namespace scapix

#endif // SCAPIX_CORE_REMOVE_FUNCTION_QUALIFIERS_H

/*
	scapix/core/function_traits.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_FUNCTION_TRAITS_H
#define SCAPIX_CORE_FUNCTION_TRAITS_H

#include <cstddef>
#include <tuple>

namespace scapix {

template <typename F>
struct function_traits;

template<typename R, typename ...Args>
struct function_traits<R(Args...)>
{
	using return_type = R;

	constexpr inline static std::size_t arity = sizeof...(Args);

	template <std::size_t N>
	using argument_type = typename std::tuple_element_t<N, std::tuple<Args...>>;
};

} // namespace scapix

#endif // SCAPIX_CORE_FUNCTION_TRAITS_H

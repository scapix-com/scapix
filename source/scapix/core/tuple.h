/*
	scapix/core/tuple.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)

	Tuple with preserved order of elements.
*/

#ifndef SCAPIX_CORE_TUPLE_H
#define SCAPIX_CORE_TUPLE_H

#include <type_traits>
#include <utility>
#include <cstddef>

namespace scapix {
namespace detail {

template <std::size_t Index, typename Type>
struct tuple_value
{
	Type value;
};

template <typename IndexSequence, typename ...Types>
struct tuple_base;

template <std::size_t... Indexes, typename ...Types>
struct tuple_base<std::index_sequence<Indexes...>, Types...> : tuple_value<Indexes, Types>...
{
	constexpr tuple_base() = default;
	constexpr tuple_base(const tuple_base&) = default;
	constexpr tuple_base(tuple_base&&) = default;

	template <std::size_t Count = sizeof...(Types), typename = std::enable_if_t<Count >= 1>>
	constexpr tuple_base(Types... values) : tuple_value<Indexes, Types>{ values }... {}

	constexpr tuple_base& operator=(const tuple_base&) = default;
	constexpr tuple_base& operator=(tuple_base&&) = default;
};

} // namespace detail

// tuple

template <typename ...Types>
struct tuple : detail::tuple_base<std::index_sequence_for<Types...>, Types...>
{
	using detail::tuple_base<std::index_sequence_for<Types...>, Types...>::tuple_base;
};

template <typename... Ts>
tuple(Ts...) -> tuple<Ts...>;

// tuple_size

template <typename Tuple>
struct tuple_size;

template <typename... Types>
struct tuple_size<tuple<Types...>> : std::integral_constant<std::size_t, sizeof...(Types)> {};

template <typename Tuple>
struct tuple_size<const Tuple> : tuple_size<Tuple> {};

template <typename Tuple>
inline constexpr std::size_t tuple_size_v = tuple_size<Tuple>::value;

// tuple_element

template <std::size_t Index, typename Tuple>
struct tuple_element;

template <std::size_t Index, typename Tuple>
using tuple_element_t = typename tuple_element<Index, Tuple>::type;

template <std::size_t Index, typename Tuple>
struct tuple_element<Index, const Tuple>
{
	using type = std::add_const_t<tuple_element_t<Index, Tuple>>;
};

template <typename First, typename... Rest>
struct tuple_element<0, tuple<First, Rest...>>
{
	using type = First;
};

template <std::size_t Index, typename First, typename... Rest>
struct tuple_element<Index, tuple<First, Rest...>>
{
	using type = tuple_element_t<Index - 1, tuple<Rest...>>;
};

// get (by index)

template <std::size_t Index, typename ...Types>
constexpr tuple_element_t<Index, tuple<Types...>>& get(tuple<Types...>& t) noexcept
{
	detail::tuple_value<Index, tuple_element_t<Index, tuple<Types...>>>& v(t);
	return v.value;
}

template <std::size_t Index, typename ...Types>
constexpr const tuple_element_t<Index, tuple<Types...>>& get(const tuple<Types...>& t) noexcept
{
	const detail::tuple_value<Index, tuple_element_t<Index, tuple<Types...>>>& v(t);
	return v.value;
}

template <std::size_t Index, typename ...Types>
constexpr tuple_element_t<Index, tuple<Types...>>&& get(tuple<Types...>&& t) noexcept
{
	detail::tuple_value<Index, tuple_element_t<Index, tuple<Types...>>>&& v(std::move(t));
	return std::move(v).value;
}

template <std::size_t Index, typename ...Types>
constexpr const tuple_element_t<Index, tuple<Types...>>&& get(const tuple<Types...>&& t) noexcept
{
	const detail::tuple_value<Index, tuple_element_t<Index, tuple<Types...>>>&& v(std::move(t));
	return std::move(v).value;
}

} // namespace scapix

#endif // SCAPIX_CORE_TUPLE_H

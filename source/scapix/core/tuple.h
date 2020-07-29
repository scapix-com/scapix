/*
	scapix/core/tuple.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_TUPLE_H
#define SCAPIX_CORE_TUPLE_H

namespace scapix {

template <class... Ts>
struct tuple;

template <class T, class... Ts>
struct tuple<T, Ts...>
{
	constexpr tuple() = default;
	constexpr tuple(T f, Ts... r) : first(f), rest(r...) {}

	T first;
	tuple<Ts...> rest;
};

template <class T>
struct tuple<T>
{
	constexpr tuple() = default;
	constexpr tuple(T f) : first(f) {}

	T first;
};

template <>
struct tuple<>
{
};

} // namespace scapix

#endif // SCAPIX_CORE_TUPLE_H

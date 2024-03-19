/*
	scapix/core/meta/iota.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_META_IOTA_H
#define SCAPIX_CORE_META_IOTA_H

#include <scapix/core/tuple.h>

namespace scapix::meta {
namespace detail {

template<class S>
struct from_sequence_impl;

template<template<class T, T... I> class S, class U, U... J>
struct from_sequence_impl<S<U, J...>>
{
	using type = tuple<std::integral_constant<U, J>...>;
};

} // namespace detail

template<class S>
using from_sequence = typename detail::from_sequence_impl<S>::type;

template<std::size_t N>
using iota_c = from_sequence<std::make_index_sequence<N>>;

} // namespace scapix::meta

#endif // SCAPIX_CORE_META_IOTA_H

/*
	scapix/mpv/transform.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_MPV_TRANSFORM_H
#define SCAPIX_MPV_TRANSFORM_H

namespace scapix::mpv {
namespace detail {

template <typename List, auto Func>
struct transform_impl;

template <template<auto...> typename List, auto... Seq, auto Func>
struct transform_impl<List<Seq...>, Func>
{
	using type = List<Func(Seq)...>;
};

} // namespace detail

template <typename List, auto Func>
using transform = typename detail::transform_impl<List, Func>::type;

} // namespace scapix::mpv

#endif // SCAPIX_MPV_TRANSFORM_H

/*
	scapix/mpv/replace.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_MPV_REPLACE_H
#define SCAPIX_MPV_REPLACE_H

#include <scapix/mpv/transform.h>

namespace scapix::mpv {
namespace detail {

template <auto Old, auto New>
struct replace_impl
{
	constexpr static auto func(decltype(Old) C)
	{
		if (C == Old)
			return New;

		return C;
	}
};

} // namespace detail

template <typename List, auto Old, auto New>
using replace = transform<List, detail::replace_impl<Old, New>::func>;

} // namespace scapix::mpv

#endif // SCAPIX_MPV_REPLACE_H

/*
	scapix/mpv/replace.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_MPV_REPLACE_H
#define SCAPIX_MPV_REPLACE_H

#include <scapix/mpv/transform.h>

namespace scapix::mpv {
namespace detail {

template <auto Old, auto New>
constexpr auto replace(decltype(Old) v)
{
	return v == Old ? New : v;
}

} // namespace detail

template <typename List, auto Old, auto New>
using replace = transform<List, detail::replace<Old, New>>;

// C++20
//template <typename List, auto Old, auto New>
//using replace = transform<List, [](decltype(Old) v) { return v == Old ? New : v; }> ;

} // namespace scapix::mpv

#endif // SCAPIX_MPV_REPLACE_H

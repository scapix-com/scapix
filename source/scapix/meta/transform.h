/*
	scapix/meta/transform.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_META_TRANSFORM_H
#define SCAPIX_META_TRANSFORM_H

namespace scapix::meta {
namespace detail {

template <template <class> class F, class List>
struct transform_impl;

template <template <class> class F, template <class...> class List, class... T>
struct transform_impl<F, List<T...>>
{
    using type = List<F<T>...>;
};

} // namespace detail

template <template <class> class F, class List>
using transform = typename detail::transform_impl<F, List>::type;

} // namespace scapix::meta

#endif // SCAPIX_META_TRANSFORM_H

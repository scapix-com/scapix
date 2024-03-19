/*
	scapix/core/meta/for_each.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_META_FOR_EACH_H
#define SCAPIX_CORE_META_FOR_EACH_H

#include <utility>
#include <initializer_list>

namespace scapix::meta {
namespace detail {

template <class L>
struct for_each_impl;

template <template <class...> class L, class ...T>
struct for_each_impl<L<T...>>
{
	template <class F>
	static constexpr F call(F&& f)
	{
		return (void)std::initializer_list<int>{((void)f(T()), 0)...}, f;
	}
};

} // namespace detail

template <class L, class F>
constexpr F for_each(F&& f)
{
	return detail::for_each_impl<L>::call(std::forward<F>(f));
}

} // namespace scapix::meta

#endif // SCAPIX_CORE_META_FOR_EACH_H

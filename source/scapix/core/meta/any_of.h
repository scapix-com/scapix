/*
	scapix/core/meta/any_of.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_META_ANY_OF_H
#define SCAPIX_CORE_META_ANY_OF_H

#include <type_traits>

namespace scapix::meta {

template <typename L, template <typename> class P>
struct any_of;

template <typename L, template <typename> class P>
constexpr bool any_of_v = any_of<L, P>::value;

template <template <typename...> class L, typename E1, typename ...E, template <typename> class P>
struct any_of<L<E1, E...>, P>
{
	static constexpr bool value = P<E1>::value || any_of_v<L<E...>, P>;
};

template <template <typename...> class L, template <typename> class P>
struct any_of<L<>, P> : std::false_type {};

} // namespace scapix::meta

#endif // SCAPIX_CORE_META_ANY_OF_H

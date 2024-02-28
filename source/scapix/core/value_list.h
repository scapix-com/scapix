/*
	scapix/core/value_list.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_VALUE_LIST_H
#define SCAPIX_CORE_VALUE_LIST_H

#include <scapix/core/tuple.h>

namespace scapix {

template <auto ...Values>
struct value_list
{
	using type = tuple<decltype(Values)...>;
	constexpr inline static type values { Values... };
};

} // namespace scapix

#endif // SCAPIX_CORE_VALUE_LIST_H

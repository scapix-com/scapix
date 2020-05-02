/*
	scapix/core/type_traits.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_TYPE_TRAITS_H
#define SCAPIX_CORE_TYPE_TRAITS_H

#include <type_traits>

namespace scapix {

// C++20

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

} // namespace scapix

#endif // SCAPIX_CORE_TYPE_TRAITS_H

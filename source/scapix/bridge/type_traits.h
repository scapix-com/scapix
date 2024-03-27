/*
	scapix/bridge/type_traits.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_TYPE_TRAITS_H
#define SCAPIX_BRIDGE_TYPE_TRAITS_H

#include <type_traits>

namespace scapix::bridge {
namespace SCAPIX_BRIDGE {

class object_base;

} // namespace SCAPIX_BRIDGE

template <typename T>
constexpr bool is_object = std::is_base_of_v<SCAPIX_BRIDGE::object_base, T>;

} // namespace scapix::bridge

#endif // SCAPIX_BRIDGE_TYPE_TRAITS_H

/*
	scapix/bridge/object.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_OBJECT_H
#define SCAPIX_BRIDGE_OBJECT_H

#include <scapix/config.h>
#include SCAPIX_BRIDGE_INCLUDE(object.h)

namespace scapix {
namespace bridge {

template <typename T>
using object = SCAPIX_BRIDGE::object<T>;

} // namespace bridge
} // namespace scapix

#endif // SCAPIX_BRIDGE_OBJECT_H

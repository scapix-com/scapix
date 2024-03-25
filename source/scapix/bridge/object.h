/*
	scapix/bridge/object.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_OBJECT_H
#define SCAPIX_BRIDGE_OBJECT_H

#define SCAPIX_INCLUDE(a,b,c) <a/b/c>
#include SCAPIX_INCLUDE(scapix/bridge, SCAPIX_BRIDGE, object.h)

namespace scapix {
namespace bridge {

template <typename T>
using object = SCAPIX_BRIDGE::object<T>;

} // namespace bridge
} // namespace scapix

#endif // SCAPIX_BRIDGE_OBJECT_H

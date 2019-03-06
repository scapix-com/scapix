/*
	scapix/bridge/cpp/object.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_CPP_OBJECT_H
#define SCAPIX_BRIDGE_CPP_OBJECT_H

#include <memory>

namespace scapix {
namespace bridge {
namespace cpp {

template <typename T>
class object : public std::enable_shared_from_this<T>
{
};

} // namespace cpp
} // namespace bridge
} // namespace scapix

#endif // SCAPIX_BRIDGE_CPP_OBJECT_H

/*

scapix/bridge/python/object.h

*/

#ifndef SCAPIX_BRIDGE_PYTHON_OBJECT_H
#define SCAPIX_BRIDGE_PYTHON_OBJECT_H

#include <memory>

namespace scapix {
namespace bridge {
namespace python {

template <typename T>
class object : public std::enable_shared_from_this<T>
{
};

} // namespace python
} // namespace bridge
} // namespace scapix

#endif // SCAPIX_BRIDGE_PYTHON_OBJECT_H

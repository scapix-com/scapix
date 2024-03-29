/*
	scapix/bridge/java/object.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_OBJECT_H
#define SCAPIX_BRIDGE_JAVA_OBJECT_H

#include <scapix/jni/com/scapix/bridge.h>

namespace scapix::bridge::java {

template <typename T>
using object = jni::com::scapix::cpp::object<T>;

} // namespace scapix::bridge::java

#endif // SCAPIX_BRIDGE_JAVA_OBJECT_H

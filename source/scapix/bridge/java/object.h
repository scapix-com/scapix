/*
	scapix/bridge/java/object.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_OBJECT_H
#define SCAPIX_BRIDGE_JAVA_OBJECT_H

#include <scapix/link/java/com/scapix/bridge.h>
#include <scapix/link/java/com/scapix/function.h>

namespace scapix::bridge::java {

template <typename T>
using object = link::java::com::scapix::cpp::object<T>;

template <typename T>
using init = link::java::com::scapix::cpp::init<T>;

template <typename T>
using function = link::java::com::scapix::cpp::function_impl<T>;

} // namespace scapix::bridge::java

#endif // SCAPIX_BRIDGE_JAVA_OBJECT_H

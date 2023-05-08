/*
	scapix/link/java/class_name.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_CLASS_NAME_H
#define SCAPIX_LINK_JAVA_CLASS_NAME_H

#include <scapix/link/java/detail/util.h>

namespace scapix::link::java {

// Get class name for object<> type.
// For defined object<> type get type::class_name.
// For incomplete object<> type, specialized to provide class name.

template <typename T>
struct class_name
{
	using type = typename detail::befriend<T, class_name>::class_name;
};

template <typename T>
using class_name_t = typename class_name<T>::type;

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_CLASS_NAME_H

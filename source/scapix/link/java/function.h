/*
	scapix/link/java/function.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FUNCTION_H
#define SCAPIX_LINK_JAVA_FUNCTION_H

#include <scapix/meta/string.h>

namespace scapix {
namespace link {
namespace java {

// represents java @FunctionalInterface

template <typename ClassName, typename Type, typename Name = SCAPIX_META_STRING("call")>
class function
{
public:

    using class_name = ClassName;
    using type = Type;
    using name = Name;

};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_FUNCTION_H

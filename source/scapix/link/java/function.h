/*
	scapix/link/java/function.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FUNCTION_H
#define SCAPIX_LINK_JAVA_FUNCTION_H

#include <scapix/meta/string.h>

namespace scapix::link::java {

// represents java @FunctionalInterface

template <typename ClassName, typename Type, typename Name = SCAPIX_META_STRING("call")>
class function
{
public:

	using class_name = ClassName;
	using type = Type;
	using name = Name;

};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FUNCTION_H

/*
	scapix/link/java/fwd/string.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_STRING_H
#define SCAPIX_LINK_JAVA_FWD_STRING_H

#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/link/java/object_traits.h>
#include <scapix/link/java/fwd/object.h>

namespace scapix::jni {

class string;

template<>
struct object_traits<string>
{
	static constexpr fixed_string class_name = "java/lang/String";
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::jni

#endif // SCAPIX_LINK_JAVA_FWD_STRING_H

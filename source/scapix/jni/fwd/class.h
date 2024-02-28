/*
	scapix/jni/fwd/class.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FWD_CLASS_H
#define SCAPIX_LINK_JAVA_FWD_CLASS_H

#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/object.h>

namespace scapix::jni {

class class_;

template<>
struct object_traits<class_>
{
	static constexpr fixed_string class_name = "java/lang/Class";
	using base_classes = std::tuple<object<>>;
};

} // namespace scapix::jni

#endif // SCAPIX_LINK_JAVA_FWD_CLASS_H

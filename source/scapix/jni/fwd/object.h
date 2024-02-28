/*
	scapix/jni/fwd/object.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_FWD_OBJECT_H
#define SCAPIX_JNI_FWD_OBJECT_H

#include <tuple>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/object_traits.h>

namespace scapix::jni {

template <fixed_string ClassName = "java/lang/Object", typename ...Bases>
class object;

template <fixed_string ClassName, typename ...Bases>
struct object_traits<object<ClassName, Bases...>>
{
	static constexpr auto class_name = ClassName;
	using base_classes = std::tuple<Bases...>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_FWD_OBJECT_H

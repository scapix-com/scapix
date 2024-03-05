/*
	scapix/jni/element.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_ELEMENT_H
#define SCAPIX_JNI_ELEMENT_H

#include <scapix/jni/fwd/element.h>
#include <scapix/jni/fwd/object.h>
#include <scapix/jni/fwd/array.h>

namespace scapix::jni {

template <typename T, typename ...Params>
struct generic_type;

template <typename T, typename Extends = object<>>
struct generic;

//template <typename T>
//struct extends;

//template <typename T>
//struct super;

template <typename T>
struct element_type
{
	using type = T;
};

template <typename T>
struct element_type<T[]>
{
	using type = array<T>;
};

template <typename T, typename ...Params>
struct element_type<generic_type<T, Params...>>
{
	using type = element_type_t<T>;
};

template <typename T, typename Extends>
struct element_type<generic<T, Extends>>
{
	using type = element_type_t<T>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_ELEMENT_H

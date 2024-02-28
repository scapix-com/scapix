/*
	scapix/jni/struct.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_STRUCT_H
#define SCAPIX_JNI_STRUCT_H

#include <type_traits>
#include <scapix/core/fixed_string.h>

namespace scapix::jni {

template <typename Struct>
struct struct_;

template <typename T, typename = void>
struct is_struct : std::false_type {};

template <typename T>
struct is_struct<T, std::void_t<typename struct_<T>::fields>> : std::true_type {};

template <typename T>
constexpr bool is_struct_v = is_struct<T>::value;

template <typename Type, fixed_string Name, auto Ptr>
struct field
{
	using type = Type;
	static constexpr auto name = Name;
	static constexpr auto ptr = Ptr;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_STRUCT_H

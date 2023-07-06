/*
	scapix/link/java/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_TYPE_TRAITS_H
#define SCAPIX_LINK_JAVA_TYPE_TRAITS_H

#include <type_traits>
#include <scapix/meta/string.h>
#include <scapix/link/java/env.h>

namespace scapix::link::java {

// handle_type

/*

template<typename ClassName>
struct handle_type { using type = jobject; };

template<> struct handle_type<SCAPIX_META_STRING("java/lang/Object")> { using type = jobject; };
template<> struct handle_type<SCAPIX_META_STRING("java/lang/Class")> { using type = jclass; };
template<> struct handle_type<SCAPIX_META_STRING("java/lang/String")> { using type = jstring; };
template<> struct handle_type<SCAPIX_META_STRING("java/lang/Throwable")> { using type = jthrowable; };
template<> struct handle_type<SCAPIX_META_STRING("[Z")> { using type = jbooleanArray; };
template<> struct handle_type<SCAPIX_META_STRING("[B")> { using type = jbyteArray; };
template<> struct handle_type<SCAPIX_META_STRING("[C")> { using type = jcharArray; };
template<> struct handle_type<SCAPIX_META_STRING("[S")> { using type = jshortArray; };
template<> struct handle_type<SCAPIX_META_STRING("[I")> { using type = jintArray; };
template<> struct handle_type<SCAPIX_META_STRING("[J")> { using type = jlongArray; };
template<> struct handle_type<SCAPIX_META_STRING("[F")> { using type = jfloatArray; };
template<> struct handle_type<SCAPIX_META_STRING("[D")> { using type = jdoubleArray; };
template <char... Cs> struct handle_type<meta::string<'[', 'L', Cs...>> { using type = jobjectArray; };

template<typename ClassName>
using handle_type_t = typename handle_type<ClassName>::type;

*/

template<typename T>
struct handle_type;

template<typename T>
using handle_type_t = typename handle_type<T>::type;

template<typename T>
struct handle_type<T[]> { using type = jobjectArray; };

template<> struct handle_type<jboolean[]> { using type = jbooleanArray; };
template<> struct handle_type<jbyte[]> { using type = jbyteArray; };
template<> struct handle_type<jchar[]> { using type = jcharArray; };
template<> struct handle_type<jshort[]> { using type = jshortArray; };
template<> struct handle_type<jint[]> { using type = jintArray; };
template<> struct handle_type<jlong[]> { using type = jlongArray; };
template<> struct handle_type<jfloat[]> { using type = jfloatArray; };
template<> struct handle_type<jdouble[]> { using type = jdoubleArray; };

// is_object_handle

template<typename T>
struct is_object_handle : std::false_type {};

template<> struct is_object_handle<jobject> : std::true_type {};
template<> struct is_object_handle<jclass> : std::true_type {};
template<> struct is_object_handle<jthrowable> : std::true_type {};
template<> struct is_object_handle<jstring> : std::true_type {};
template<> struct is_object_handle<jarray> : std::true_type {};
template<> struct is_object_handle<jbooleanArray> : std::true_type {};
template<> struct is_object_handle<jbyteArray> : std::true_type {};
template<> struct is_object_handle<jcharArray> : std::true_type {};
template<> struct is_object_handle<jshortArray> : std::true_type {};
template<> struct is_object_handle<jintArray> : std::true_type {};
template<> struct is_object_handle<jlongArray> : std::true_type {};
template<> struct is_object_handle<jfloatArray> : std::true_type {};
template<> struct is_object_handle<jdoubleArray> : std::true_type {};
template<> struct is_object_handle<jobjectArray> : std::true_type {};

template<typename T>
constexpr bool is_object_handle_v = is_object_handle<T>::value;

// is_primitive

template<class T>
struct is_primitive : std::false_type {};

template<> struct is_primitive<jboolean> : std::true_type {};
template<> struct is_primitive<jbyte> : std::true_type {};
template<> struct is_primitive<jchar> : std::true_type {};
template<> struct is_primitive<jshort> : std::true_type {};
template<> struct is_primitive<jint> : std::true_type {};
template<> struct is_primitive<jlong> : std::true_type {};
template<> struct is_primitive<jfloat> : std::true_type {};
template<> struct is_primitive<jdouble> : std::true_type {};

template<typename T>
constexpr bool is_primitive_v = is_primitive<T>::value;

// is_value

template<typename T>
struct is_value : std::integral_constant<bool, is_object_handle_v<T> || is_primitive_v<T>> {};

template<typename T>
constexpr bool is_value_v = is_value<T>::value;

// is_array

template<typename T>
struct is_array : std::integral_constant<bool, meta::c_str_v<typename T::class_name>[0] == '['> {};

template<typename T>
constexpr bool is_array_v = is_array<T>::value;

template<typename T>
struct is_object_array : std::integral_constant<bool, meta::c_str_v<typename T::class_name>[0] == '[' && (meta::c_str_v<typename T::class_name>[1] == 'L' || meta::c_str_v<typename T::class_name>[1] == '[')> {};

template<typename T>
constexpr bool is_object_array_v = is_object_array<T>::value;

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_TYPE_TRAITS_H

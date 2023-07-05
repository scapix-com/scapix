/*
	scapix/link/java/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_TYPE_TRAITS_H
#define SCAPIX_LINK_JAVA_TYPE_TRAITS_H

#include <type_traits>
#include <scapix/meta/string.h>
#include <scapix/meta/any_of.h>
#include <scapix/link/java/env.h>
#include <scapix/link/java/object_traits.h>
#include <scapix/link/java/fwd/array.h>

namespace scapix::link::java {

// is_primitive

template <typename T>
struct is_primitive : std::false_type {};

template<> struct is_primitive<jboolean> : std::true_type {};
template<> struct is_primitive<jbyte> : std::true_type {};
template<> struct is_primitive<jchar> : std::true_type {};
template<> struct is_primitive<jshort> : std::true_type {};
template<> struct is_primitive<jint> : std::true_type {};
template<> struct is_primitive<jlong> : std::true_type {};
template<> struct is_primitive<jfloat> : std::true_type {};
template<> struct is_primitive<jdouble> : std::true_type {};

template <typename T>
constexpr bool is_primitive_v = is_primitive<T>::value;

// is_array

template <typename T>
struct is_array : std::integral_constant<bool, meta::c_str_v<class_name_t<T>>[0] == '['> {};

template <typename T>
constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct is_object_array : std::integral_constant<bool, meta::c_str_v<class_name_t<T>>[0] == '[' && (meta::c_str_v<class_name_t<T>>[1] == 'L' || meta::c_str_v<class_name_t<T>>[1] == '[')> {};

template <typename T>
constexpr bool is_object_array_v = is_object_array<T>::value;

namespace detail {

// detail::handle_type_from_class_name

template <typename ClassName>
struct handle_type_from_class_name { using type = jobject; };

template<> struct handle_type_from_class_name<SCAPIX_META_STRING("java/lang/Object")> { using type = jobject; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("java/lang/Class")> { using type = jclass; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("java/lang/String")> { using type = jstring; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("java/lang/Throwable")> { using type = jthrowable; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[Z")> { using type = jbooleanArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[B")> { using type = jbyteArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[C")> { using type = jcharArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[S")> { using type = jshortArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[I")> { using type = jintArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[J")> { using type = jlongArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[F")> { using type = jfloatArray; };
template<> struct handle_type_from_class_name<SCAPIX_META_STRING("[D")> { using type = jdoubleArray; };
template <char... Cs> struct handle_type_from_class_name<meta::string<'[', Cs...>> { using type = jobjectArray; };

template <typename ClassName>
using handle_type_from_class_name_t = typename handle_type_from_class_name<ClassName>::type;

// detail::select_handle_type

template <typename ClassName, typename Bases>
struct select_handle_type;

template <typename ClassName>
struct select_handle_type<ClassName, std::tuple<>>
{
	using type = handle_type_from_class_name_t<ClassName>;
};

template <typename ClassName, typename Base1, typename ...Bases>
struct select_handle_type<ClassName, std::tuple<Base1, Bases...>>
{
	using base1_handle_type = typename select_handle_type<class_name_t<Base1>, base_classes_t<Base1>>::type;
	using type = std::conditional_t<std::is_same_v<handle_type_from_class_name_t<ClassName>, jobject>, base1_handle_type, handle_type_from_class_name_t<ClassName>>;
};

} // namespace detail

// handle_type

template <typename T>
struct handle_type;

template <typename T>
using handle_type_t = typename handle_type<T>::type;

template <typename T>
struct handle_type
{
	using type = typename detail::select_handle_type<class_name_t<T>, base_classes_t<T>>::type;
};

// is_convertible_object

template <typename From, typename To>
struct is_convertible_object;

template <typename From, typename To>
constexpr bool is_convertible_object_v = is_convertible_object<From, To>::value;

template <typename From, typename To>
struct is_convertible_object
{
	template <typename T>
	struct is_convertible : is_convertible_object<T, To> {};

	static constexpr bool value =
		std::is_same_v<class_name_t<From>, class_name_t<To>> ||
		meta::any_of_v<base_classes_t<From>, is_convertible>
	;
};

template <typename From, typename To>
struct is_convertible_object<array<From, std::enable_if_t<!is_primitive_v<From>>>, array<To, std::enable_if_t<!is_primitive_v<To>>>>
{
	static constexpr bool value = is_convertible_object_v<typename array<From>::element_type, typename array<To>::element_type>;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_TYPE_TRAITS_H

/*
	scapix/link/java/type_traits.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_TYPE_TRAITS_H
#define SCAPIX_LINK_JAVA_TYPE_TRAITS_H

#include <type_traits>
#include <scapix/core/fixed_string.h>
#include <scapix/meta/any_of.h>
#include <scapix/meta/for_each.h>
#include <scapix/meta/iota.h>
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
struct is_array : std::integral_constant<bool, class_name_v<T>[0] == '['> {};

template <typename T>
constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct is_object_array : std::integral_constant<bool, class_name_v<T>[0] == '[' && (class_name_v<T>[1] == 'L' || class_name_v<T>[1] == '[')> {};

template <typename T>
constexpr bool is_object_array_v = is_object_array<T>::value;

// handle_type

namespace detail {

template <fixed_string ClassName, typename HandleType>
struct handle_type_info
{
	static constexpr auto class_name = ClassName;
	using handle_type = HandleType;
};

using handle_types = std::tuple
<
	handle_type_info<"java/lang/Object", jobject>, // must be first
	handle_type_info<"java/lang/Class", jclass>,
	handle_type_info<"java/lang/String", jstring>,
	handle_type_info<"java/lang/Throwable", jthrowable>,
	handle_type_info<"[Z", jbooleanArray>,
	handle_type_info<"[B", jbyteArray>,
	handle_type_info<"[C", jcharArray>,
	handle_type_info<"[S", jshortArray>,
	handle_type_info<"[I", jintArray>,
	handle_type_info<"[J", jlongArray>,
	handle_type_info<"[F", jfloatArray>,
	handle_type_info<"[D", jdoubleArray>,
	handle_type_info<"[", jobjectArray> // uses "begins_with" compare, must be last
>;

template <typename T>
constexpr std::size_t handle_type()
{
	auto class_name = class_name_v<T>;
	using bases = base_classes_t<T>;

	std::size_t result = 0;

	meta::for_each<meta::iota_c<std::tuple_size_v<handle_types>>>([&](auto index)
	{
		if (std::tuple_element_t<index, handle_types>::class_name == class_name)
			result = index;
	});

	if (!result)
	{
		if (class_name[0] == '[')
		{
			result = std::tuple_size_v<handle_types> - 1;
		}
		else if constexpr (std::tuple_size_v<bases> != 0)
		{
			result = handle_type<std::tuple_element_t<0, bases>>();
		}
	}

	return result;
}

} // namespace detail

template <typename T>
using handle_type_t = typename std::tuple_element_t<detail::handle_type<T>(), detail::handle_types>::handle_type;

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
		class_name_v<From> == class_name_v<To> ||
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

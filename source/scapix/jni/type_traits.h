/*
	scapix/jni/type_traits.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_TYPE_TRAITS_H
#define SCAPIX_JNI_TYPE_TRAITS_H

#include <type_traits>
#include <scapix/core/fixed_string.h>
#include <scapix/core/meta/any_of.h>
#include <scapix/core/meta/for_each.h>
#include <scapix/core/meta/iota.h>
#include <scapix/jni/env.h>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/element.h>
#include <scapix/jni/fwd/array.h>
#include <scapix/jni/fwd/object.h>
#include <scapix/jni/fwd/object_base.h>

namespace scapix::jni {

// reference

template <typename T>
concept reference = requires
{
	requires std::is_class_v<element_type_t<T>>;
	class_name_v<element_type_t<T>>;
	typename base_classes_t<element_type_t<T>>;
};

// primitive

template <typename T>
concept integral =
	std::same_as<T, jbyte> ||
	std::same_as<T, jshort> ||
	std::same_as<T, jint> ||
	std::same_as<T, jlong> ||
	std::same_as<T, jchar>;

template <typename T>
concept floating_point =
	std::same_as<T, jfloat> ||
	std::same_as<T, jdouble>;

template <typename T>
concept numeric = integral<T> || floating_point<T>;

template <typename T>
concept primitive = numeric<T> || std::same_as<T, jboolean>;

// array_element

template <typename T>
concept array_element = reference<T> || primitive<T>;

// is_array

template <typename T>
struct is_array : std::integral_constant<bool, class_name_v<T>[0] == '['> {};

template <typename T>
constexpr bool is_array_v = is_array<T>::value;

template <typename T>
struct is_object_array : std::integral_constant<bool, class_name_v<T>[0] == '[' && (class_name_v<T>[1] == 'L' || class_name_v<T>[1] == '[')> {};

template <typename T>
constexpr bool is_object_array_v = is_object_array<T>::value;

template <typename T>
concept object_array = is_object_array_v<T>;

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

template <reference T>
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

template <reference T>
using handle_type_t = typename std::tuple_element_t<detail::handle_type<element_type_t<T>>(), detail::handle_types>::handle_type;

// is_convertible_object

template <typename From, typename To>
struct is_convertible_object;

template <typename From, typename To>
constexpr bool is_convertible_object_v = is_convertible_object<element_type_t<From>, element_type_t<To>>::value;

template <typename From, typename To>
concept convertible_object = is_convertible_object_v<From, To>;

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

template <object_array From, object_array To>
struct is_convertible_object<From, To>
{
	static constexpr bool value = is_convertible_object_v<typename From::element_type, typename To::element_type>;
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_TYPE_TRAITS_H

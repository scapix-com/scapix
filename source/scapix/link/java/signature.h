/*
	scapix/link/java/signature.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_SIGNATURE_H
#define SCAPIX_LINK_JAVA_SIGNATURE_H

#include <scapix/core/fixed_string.h>
#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/fwd/ref.h>
#include <scapix/link/java/fwd/array.h>
#include <scapix/link/java/fwd/signature.h>

namespace scapix::link::java {

template <typename T>
struct signature
{
	static constexpr auto value = "L" + class_name_v<T> + ";";
};

template<> struct signature<void>     { static constexpr fixed_string value = "V"; };
template<> struct signature<jboolean> { static constexpr fixed_string value = "Z"; };
template<> struct signature<jbyte>    { static constexpr fixed_string value = "B"; };
template<> struct signature<jchar>    { static constexpr fixed_string value = "C"; };
template<> struct signature<jshort>   { static constexpr fixed_string value = "S"; };
template<> struct signature<jint>     { static constexpr fixed_string value = "I"; };
template<> struct signature<jlong>    { static constexpr fixed_string value = "J"; };
template<> struct signature<jfloat>   { static constexpr fixed_string value = "F"; };
template<> struct signature<jdouble>  { static constexpr fixed_string value = "D"; };

template <typename T>
struct signature<ref<T>>
{
	static constexpr auto value = signature_v<T>;
};

template <typename T>
struct signature<array<T>>
{
	static constexpr auto value = "[" + signature_v<T>;
};

template <typename T>
struct signature<T[]>
{
	static constexpr auto value = signature_v<array<T>>;
};

template <typename T, typename ...Params>
struct signature<generic_type<T, Params...>>
{
	static constexpr auto value = signature_v<T>;
};

template <typename T, typename Extends>
struct signature<generic<T, Extends>>
{
	static constexpr auto value = signature_v<Extends>;
};

template <typename R, typename ...Args>
struct signature<R(Args...)>
{
	static constexpr auto value = ("(" + ... + signature_v<Args>) + (")" + signature_v<R>);
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_SIGNATURE_H

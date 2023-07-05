/*
	scapix/link/java/signature.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_SIGNATURE_H
#define SCAPIX_LINK_JAVA_SIGNATURE_H

#include <scapix/meta/string.h>
#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/fwd/ref.h>
#include <scapix/link/java/fwd/array.h>
#include <scapix/link/java/fwd/signature.h>

namespace scapix::link::java {

template <typename T>
struct signature
{
	using type = meta::concat_t<meta::string<'L'>, class_name_t<T>, meta::string<';'>>;
};

template<> struct signature<void>     { using type = meta::string<'V'>; };
template<> struct signature<jboolean> { using type = meta::string<'Z'>; };
template<> struct signature<jbyte>    { using type = meta::string<'B'>; };
template<> struct signature<jchar>    { using type = meta::string<'C'>; };
template<> struct signature<jshort>   { using type = meta::string<'S'>; };
template<> struct signature<jint>     { using type = meta::string<'I'>; };
template<> struct signature<jlong>    { using type = meta::string<'J'>; };
template<> struct signature<jfloat>   { using type = meta::string<'F'>; };
template<> struct signature<jdouble>  { using type = meta::string<'D'>; };

template <typename T>
struct signature<ref<T>>
{
	using type = signature_t<T>;
};

template <typename T>
struct signature<array<T>>
{
	using type = meta::concat_t<meta::string<'['>, signature_t<T>>;
};

template <typename T>
struct signature<T[]>
{
	using type = signature_t<array<T>>;
};

template <typename T, typename ...Params>
struct signature<generic_type<T, Params...>>
{
	using type = signature_t<T>;
};

template <typename T, typename Extends>
struct signature<generic<T, Extends>>
{
	using type = signature_t<Extends>;
};

template <typename R, typename ...Args>
struct signature<R(Args...)>
{
	using type = meta::concat_t<meta::string<'('>, signature_t<Args>..., meta::string<')'>, signature_t<R>>;
};

template <char... Chars>
struct signature<meta::string<Chars...>>
{
	using type = meta::concat_t<meta::string<'L'>, meta::string<Chars...>, meta::string<';'>>;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_SIGNATURE_H

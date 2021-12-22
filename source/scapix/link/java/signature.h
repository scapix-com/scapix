/*
	scapix/link/java/signature.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_SIGNATURE_H
#define SCAPIX_LINK_JAVA_SIGNATURE_H

#include <scapix/meta/string.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/detail/util.h>

namespace scapix {
namespace link {
namespace java {

template <typename T>
struct class_name;

template <typename T>
using class_name_t = typename class_name<T>::type;

template <typename T>
struct class_name
{
	using type = typename detail::befriend<T, class_name>::class_name;
};

template <typename T, typename Extends>
struct class_name<ref<generic<T, Extends>>>
{
	using type = class_name_t<Extends>;
};

template <char... Chars>
struct class_name<meta::string<Chars...>>
{
	using type = meta::string<Chars...>;
};

template <typename T>
struct signature;

template <typename T>
using signature_t = typename signature<T>::type;

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
struct signature<T[]>
{
	using type = meta::concat_t<meta::string<'['>, signature_t<T>>;
};

template <typename T>
struct signature<ref<T[]>>
{
	using type = meta::concat_t<meta::string<'['>, signature_t<T>>;
};

template <typename T>
struct signature<array<T>>
{
	using type = meta::concat_t<meta::string<'['>, signature_t<T>>;
};

template <typename T>
struct signature<ref<array<T>>>
{
	using type = meta::concat_t<meta::string<'['>, signature_t<T>>;
};

template <typename R, typename ...Args>
struct signature<R(Args...)>
{
	using type = meta::concat_t<meta::string<'('>, signature_t<Args>..., meta::string<')'>, signature_t<R>>;
};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_SIGNATURE_H

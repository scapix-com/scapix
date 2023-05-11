/*
	scapix/link/java/detail/api/ref.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_API_REF_H
#define SCAPIX_LINK_JAVA_DETAIL_API_REF_H

#include <scapix/link/java/env.h>

namespace scapix::link::java::detail::api {

enum class scope
{
	generic,
	local,
	global,
	weak
};

template <scope Scope>
struct ref;

template <>
struct ref<scope::local>
{
	static jobject new_ref(jobject h) noexcept { return detail::env()->NewLocalRef(h); }
	static void delete_ref(jobject h) noexcept { detail::env()->DeleteLocalRef(h); }
};

template <>
struct ref<scope::global>
{
	static jobject new_ref(jobject h) noexcept { return detail::env()->NewGlobalRef(h); }
	static void delete_ref(jobject h) noexcept { detail::env()->DeleteGlobalRef(h); }
};

template <>
struct ref<scope::weak>
{
	static jobject new_ref(jobject h) noexcept { return detail::env()->NewWeakGlobalRef(h); }
	static void delete_ref(jobject h) noexcept { detail::env()->DeleteWeakGlobalRef(h); }
};

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_REF_H

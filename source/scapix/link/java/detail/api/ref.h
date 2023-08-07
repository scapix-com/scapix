/*
	scapix/link/java/detail/api/ref.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
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

// Bug in JDK 17+: according to JNI specification,
// `NewWeakGlobalRef` should return null when passed null argument.
// But some JVM implementations throw `java.lang.OutOfMemoryError: C heap space`.
// https://bugs.openjdk.org/browse/JDK-8313874

template <>
struct ref<scope::weak>
{
	static jobject new_ref(jobject h) noexcept { if (!h) return nullptr; return detail::env()->NewWeakGlobalRef(h); }
	static void delete_ref(jobject h) noexcept { detail::env()->DeleteWeakGlobalRef(h); }
};

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_REF_H

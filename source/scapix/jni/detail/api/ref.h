/*
	scapix/jni/detail/api/ref.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_API_REF_H
#define SCAPIX_JNI_DETAIL_API_REF_H

#include <scapix/jni/env.h>

namespace scapix::jni::detail::api {

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

// Bug in JDK 16-21: according to JNI specification,
// NewWeakGlobalRef should return null when passed null argument.
// JDK 16-21 throws `java.lang.OutOfMemoryError: C heap space`.
// https://bugs.openjdk.org/browse/JDK-8313874
// Fixed in JDK 22, JDK 21.0.1, JDK 17.0.9

template <>
struct ref<scope::weak>
{
	static jobject new_ref(jobject h) noexcept { if (!h) return nullptr; return detail::env()->NewWeakGlobalRef(h); }
	static void delete_ref(jobject h) noexcept { detail::env()->DeleteWeakGlobalRef(h); }
};

} // namespace scapix::jni::detail::api

#endif // SCAPIX_JNI_DETAIL_API_REF_H

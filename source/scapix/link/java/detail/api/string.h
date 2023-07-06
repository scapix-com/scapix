/*
	scapix/link/java/detail/api/string.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_API_STRING_H
#define SCAPIX_LINK_JAVA_DETAIL_API_STRING_H

#include <scapix/link/java/env.h>
#include <scapix/link/java/lock.h>

namespace scapix::link::java::detail::api {

template <typename Char, lock Lock = lock::noncritical>
struct string;

template <>
struct string<jchar, lock::noncritical>
{
	static jsize length(jstring str) noexcept { return env()->GetStringLength(str); }
	static const jchar* get_chars(jstring str, jboolean* is_copy) noexcept { return env()->GetStringChars(str, is_copy); }
	static void release_chars(jstring str, const jchar* chars) noexcept { env()->ReleaseStringChars(str, chars); }
	static void get_region(jstring str, jsize start, jsize len, jchar* buf) noexcept { env()->GetStringRegion(str, start, len, buf); }
};

template <>
struct string<jchar, lock::critical> : string<jchar, lock::noncritical>
{
	static const jchar* get_chars(jstring str, jboolean* is_copy) noexcept { return env()->GetStringCritical(str, is_copy); }
	static void release_chars(jstring str, const jchar* chars) noexcept { env()->ReleaseStringCritical(str, chars); }
};

template <>
struct string<char, lock::noncritical>
{
	static jsize length(jstring str) noexcept { return env()->GetStringUTFLength(str); }
	static const char* get_chars(jstring str, jboolean* is_copy) noexcept { return env()->GetStringUTFChars(str, is_copy); }
	static void release_chars(jstring str, const char* chars) noexcept { env()->ReleaseStringUTFChars(str, chars); }
	static void get_region(jstring str, jsize start, jsize len, char* buf) noexcept { env()->GetStringUTFRegion(str, start, len, buf); }
};

} // namespace scapix::link::java::detail::api

#endif // SCAPIX_LINK_JAVA_DETAIL_API_STRING_H

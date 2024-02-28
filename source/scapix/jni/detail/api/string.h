/*
	scapix/jni/detail/api/string.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_DETAIL_API_STRING_H
#define SCAPIX_JNI_DETAIL_API_STRING_H

#include <scapix/jni/env.h>
#include <scapix/jni/lock.h>

namespace scapix::jni::detail::api {

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

} // namespace scapix::jni::detail::api

#endif // SCAPIX_JNI_DETAIL_API_STRING_H

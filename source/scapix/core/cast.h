/*
	scapix/code/cast.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CORE_CAST_H
#define SCAPIX_CORE_CAST_H

namespace scapix {

// constexpr cast from pointer to function to void* (not allowed by standard).
// Another workaround would be to use native_method in place of JNINativeMethod to avoid cast completely,
// and store std::tuple<Methods...> in native_methods instead of array (UB but would work).

#ifdef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wmicrosoft-cast"
#endif

template <typename Source>
constexpr inline void* void_cast(const Source& source)
{
#ifdef _MSC_VER
	// static_cast here is Microsoft extension, standard requires reinterpret_cast which ruins constexpr.
	return source;
#else
	// gcc/clang extension
	return __builtin_constant_p(reinterpret_cast<void*>(source)) ? (reinterpret_cast<void*>(source)) : (reinterpret_cast<void*>(source));
#endif
}

#ifdef __clang__
#pragma GCC diagnostic pop
#endif

} // namespace scapix

#endif // SCAPIX_CORE_CAST_H

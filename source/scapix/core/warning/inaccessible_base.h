/*
	scapix/core/warning/inaccessible_base.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4584) // 'class1' : base-class 'class2' is already a base-class of 'class3'
#endif

// "-Winaccessible-base" can be disabled starting with GCC 10 and clang 3.7

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Winaccessible-base"
#endif

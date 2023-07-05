/*
	scapix/detail/warning/pop.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4584) // 'class1' : base-class 'class2' is already a base-class of 'class3'
#endif

#if defined(__GNUG__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winaccessible-base"
#endif

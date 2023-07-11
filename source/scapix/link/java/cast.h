/*
	scapix/link/java/cast.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_CAST_H
#define SCAPIX_LINK_JAVA_CAST_H

#include <utility>
#include <scapix/link/java/detail/util.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/object.h>

namespace scapix::link::java {

// static_pointer_cast

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> static_pointer_cast(const ref<Y, Scope>& r)
{
	return ref<T, Scope>(ref<detail::cast<Y>, Scope>(r));
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> static_pointer_cast(ref<Y, Scope>&& r)
{
	return ref<T, Scope>(ref<detail::cast<Y>, Scope>(std::move(r)));
}

// dynamic_pointer_cast

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> dynamic_pointer_cast(const ref<Y, Scope>& r)
{
	if (ref<object<>>(r)->template is_instance_of<T>())
		return static_pointer_cast<T>(r);

	return nullptr;
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> dynamic_pointer_cast(ref<Y, Scope>&& r)
{
	if (ref<object<>>(r)->template is_instance_of<T>())
		return static_pointer_cast<T>(std::move(r));

	return nullptr;
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_CAST_H

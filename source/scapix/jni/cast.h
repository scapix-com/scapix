/*
	scapix/jni/cast.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_CAST_H
#define SCAPIX_JNI_CAST_H

#include <utility>
#include <scapix/jni/ref.h>

namespace scapix::jni {

template <typename T, typename Y, scope Scope>
inline ref<T> static_pointer_cast(const ref<Y, Scope>& r)
{
	return ref<T>(r.handle());
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> static_pointer_cast(ref<Y, Scope>&& r)
{
	if constexpr (Scope == scope::generic)
		return ref<T, Scope>(r.release(), r.get_scope());
	else
		return ref<T, Scope>(r.release());
}

template <typename T, typename Y, scope Scope>
inline ref<T> dynamic_pointer_cast(const ref<Y, Scope>& r)
{
	if (ref<>(r)->template is_instance_of<T>())
		return static_pointer_cast<T>(r);

	return nullptr;
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> dynamic_pointer_cast(ref<Y, Scope>&& r)
{
	if (ref<>(r)->template is_instance_of<T>())
		return static_pointer_cast<T>(std::move(r));

	return nullptr;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_CAST_H

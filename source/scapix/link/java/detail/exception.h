/*
	scapix/link/java/detail/exception.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H
#define SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H

#include <boost/config.hpp>
#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/ref.h>

namespace scapix::link::java::detail {

[[noreturn]] void throw_exception(jthrowable e = env()->ExceptionOccurred());
[[noreturn]] void throw_exception_nested(jthrowable e = env()->ExceptionOccurred());

inline void check_exception()
{
	jthrowable e = env()->ExceptionOccurred();
	if (BOOST_UNLIKELY(e != 0))
		throw_exception(e);
}

inline void check_exception_nested()
{
	jthrowable e = env()->ExceptionOccurred();
	if (BOOST_UNLIKELY(e != 0))
		throw_exception_nested(e);
}

inline jfieldID check_exception(jfieldID id)
{
	if (BOOST_UNLIKELY(!id))
		throw_exception();

	return id;
}

inline jmethodID check_exception(jmethodID id)
{
	if (BOOST_UNLIKELY(!id))
		throw_exception();

	return id;
}

// RegisterNatives()

inline jint check_exception(jint i)
{
	if (BOOST_UNLIKELY(i))
		throw_exception();

	return i;
}

// Get<PrimitiveType>ArrayElements(), GetPrimitiveArrayCritical()

template <typename T, typename = std::enable_if_t<is_primitive_v<T>>>
inline T* check_exception(T* p)
{
	if (BOOST_UNLIKELY(!p))
		throw_exception();

	return p;
}

// to do: remove when all api calls return ref<>

template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, jobject>>>
inline T check_exception(T obj)
{
	if (BOOST_UNLIKELY(!obj))
		throw_exception();

	return obj;
}

template <typename T, scope Scope>
inline ref<T, Scope> check_exception(ref<T, Scope> obj)
{
	if (BOOST_UNLIKELY(!obj.handle()))
		throw_exception();

	return obj;
}

template <typename T, scope Scope>
inline ref<T, Scope> check_exception_nested(ref<T, Scope> obj)
{
	if (BOOST_UNLIKELY(!obj.handle()))
		throw_exception_nested();

	return obj;
}

struct check_exception_on_destroy
{
	check_exception_on_destroy() = default;
	~check_exception_on_destroy() noexcept(false) { check_exception(); }

	check_exception_on_destroy(const check_exception_on_destroy&) = delete;
	check_exception_on_destroy(check_exception_on_destroy&&) = delete;
	check_exception_on_destroy& operator = (const check_exception_on_destroy&) = delete;
	check_exception_on_destroy& operator = (check_exception_on_destroy&&) = delete;
};

struct check_exception_nested_on_destroy
{
	check_exception_nested_on_destroy() = default;
	~check_exception_nested_on_destroy() noexcept(false) { check_exception_nested(); }

	check_exception_nested_on_destroy(const check_exception_nested_on_destroy&) = delete;
	check_exception_nested_on_destroy(check_exception_nested_on_destroy&&) = delete;
	check_exception_nested_on_destroy& operator = (const check_exception_nested_on_destroy&) = delete;
	check_exception_nested_on_destroy& operator = (check_exception_nested_on_destroy&&) = delete;
};

} // namespace scapix::link::java::detail

#endif // SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H

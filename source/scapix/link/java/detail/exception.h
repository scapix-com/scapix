/*
	scapix/link/java/detail/exception.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/ref.h>

#ifndef SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H
#define SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H

#include <boost/config.hpp>

namespace scapix::link::java::detail {

void throw_exception(jthrowable e);
void throw_exception();

// to do:
// auto check_exception(T v) {check(); return v; }
// auto check_exception_value(T v) { check(v); return v; }

inline void check_exception()
{
	jthrowable e = env()->ExceptionOccurred();
	if (BOOST_UNLIKELY(e != 0))
		throw_exception(e);
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

inline jint check_exception(jint i)
{
	if (BOOST_UNLIKELY(i))
		throw_exception();

	return i;
}

// to do: remove after api refactoring finished

template <typename T, typename = std::enable_if_t<is_object_handle_v<T>>>
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

struct check_exception_on_destroy
{
	check_exception_on_destroy() = default;
	~check_exception_on_destroy() noexcept(false) { check_exception(); }

	check_exception_on_destroy(const check_exception_on_destroy&) = delete;
	check_exception_on_destroy(check_exception_on_destroy&&) = delete;
	check_exception_on_destroy& operator = (const check_exception_on_destroy&) = delete;
	check_exception_on_destroy& operator = (check_exception_on_destroy&&) = delete;
};

} // namespace scapix::link::java::detail

#include <scapix/link/java/throwable.h>
#include <scapix/link/java/detail/native_exception.h>
#include <scapix/link/java/vm_exception.h>

namespace scapix::link::java::detail {

inline void throw_exception(jthrowable e)
{
	local_ref<throwable<>> exception(e);

//	env()->ExceptionDescribe();
	env()->ExceptionClear();

//	std::string msg = exception->call_method<SCAPIX_META_STRING("getMessage"), ref<string>()>()->chars<char>().data();

	// if com.scapix.NativeException is not found, native_exception::class_object() causes infinite recursion:
	// libc++abi.dylib: __cxa_guard_acquire detected deadlock

	if (auto native = dynamic_pointer_cast<native_exception>(std::move(exception)))
	{
		native->rethrow();
	}
	else
	{
		throw vm_exception(std::move(exception));
	}
}

inline void throw_exception()
{
	throw_exception(env()->ExceptionOccurred());
}

} // namespace scapix::link::java::detail

#endif // SCAPIX_LINK_JAVA_DETAIL_EXCEPTION_H

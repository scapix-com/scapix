/*
	scapix/link/java/detail/exception.cpp

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/detail/exception.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/throwable.h>
#include <scapix/link/java/detail/native_exception.h>
#include <scapix/link/java/vm_exception.h>

namespace scapix {
namespace link {
namespace java {
namespace detail {

void throw_exception(jthrowable e)
{
	local_ref<throwable<>> exception(e);

	env()->ExceptionClear();

//	auto msg = convert<std::string>::cpp(exception->call_method<SCAPIX_META_STRING("getMessage"), ref<string>()>());

	// if com.scapix.NativeException is not found, native_exception::class_object() causes infitine recursion:
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

void throw_exception()
{
	throw_exception(env()->ExceptionOccurred());
}

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

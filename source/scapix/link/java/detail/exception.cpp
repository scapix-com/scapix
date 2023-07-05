/*
	scapix/link/java/detail/exception.cpp

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/detail/exception.h>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/throwable.h>
#include <scapix/link/java/detail/native_exception.h>
#include <scapix/link/java/vm_exception.h>

namespace scapix::link::java::detail {

[[noreturn]] void throw_exception(jthrowable e)
{
//	env()->ExceptionDescribe();
	env()->ExceptionClear();
	throw vm_exception(local_ref<throwable>(e));
}

/*

Only check for possible (nested) C++ exception (native_exception)
after calling these four JNI function families,
which can throw any exception thrown by executed Java code:

1. call_method
2. call_nonvirtual_method
3. call_static_method
4. new_object

*/

[[noreturn]] void throw_exception_nested(jthrowable e)
{
//	env()->ExceptionDescribe();
	env()->ExceptionClear();

	local_ref<throwable> exception(e);

	if (auto native = dynamic_pointer_cast<native_exception>(std::move(exception)))
		native->rethrow();

	throw vm_exception(std::move(exception));
}

} // namespace scapix::link::java::detail

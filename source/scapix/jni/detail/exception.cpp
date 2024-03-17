/*
	scapix/jni/detail/exception.cpp

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#include <scapix/jni/detail/exception.h>
#include <scapix/jni/ref.h>
#include <scapix/jni/throwable.h>
#include <scapix/jni/com/scapix/native_exception.h>
#include <scapix/jni/vm_exception.h>

namespace scapix::jni::detail {

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

	if (auto native = exception->instance_of<com::scapix::native_exception>())
		native->rethrow();

	throw vm_exception(std::move(exception));
}

} // namespace scapix::jni::detail

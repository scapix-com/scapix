/*
	scapix/jni/vm_exception.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_VM_EXCEPTION_H
#define SCAPIX_JNI_VM_EXCEPTION_H

#include <string>
#include <exception>
#include <scapix/jni/ref.h>
#include <scapix/jni/throwable.h>
#include <scapix/jni/string.h>
#include <scapix/jni/convert.h>

namespace scapix::jni {

class vm_exception : public std::exception
{
public:

	const char* what() const noexcept override
	{
		if (description.empty())
		{
			try
			{
				description = prefix + class_name() + ": " + message();
			}
			catch (...)
			{
				return prefix;
			}
		}

		return description.c_str();
	}

	template <convertible_object<throwable> T>
	ref<T> instance_of() const noexcept
	{
		return exception->instance_of<T>();
	}

	ref<throwable> get() const noexcept
	{
		return exception;
	}

private:

	friend void detail::throw_exception(jthrowable e);
	friend void detail::throw_exception_nested(jthrowable e);

	explicit vm_exception(local_ref<throwable>&& e) : exception(std::move(e)) {}

private:

	inline constexpr static char prefix[] = "jni::vm_exception: ";

	std::string class_name() const
	{
		return exception->get_object_class()->call_method<"getName", ref<string>()>();
	}

	std::string message() const
	{
		return exception->call_method<"getMessage", ref<string>()>();
	}

	local_ref<throwable> exception;
	mutable std::string description;

};

} // namespace scapix::jni

#endif // SCAPIX_JNI_VM_EXCEPTION_H

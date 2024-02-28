/*
	scapix/jni/vm_exception.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_VM_EXCEPTION_H
#define SCAPIX_LINK_JAVA_VM_EXCEPTION_H

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

	virtual const char* what() const noexcept override { return message().c_str(); }

	ref<throwable> get() const { return exception; }

	const std::string& class_name() const
	{
		if (cls_name.empty())
			get_class_name();

		return cls_name;
	}

	const std::string& message() const
	{
		if (msg.empty())
			get_message();

		return msg;
	}

private:

	friend void detail::throw_exception(jthrowable e);
	friend void detail::throw_exception_nested(jthrowable e);

	vm_exception(local_ref<throwable>&& e) : exception(std::move(e)) {}

private:

	void get_class_name() const
	{
		cls_name = exception->get_object_class()->call_method<"getName", ref<string>()>();
	}

	void get_message() const
	{
		msg = exception->call_method<"getMessage", ref<string>()>();
	}

	local_ref<throwable> exception;
	mutable std::string cls_name;
	mutable std::string msg;

};

inline bool operator == (const vm_exception& e, const std::string& cls_name) { return e.class_name() == cls_name; }
inline bool operator == (const std::string& cls_name, const vm_exception& e) { return e.class_name() == cls_name; }

inline bool operator == (const vm_exception& e, const char* cls_name) { return e.class_name() == cls_name; }
inline bool operator == (const char* cls_name, const vm_exception& e) { return e.class_name() == cls_name; }

} // namespace scapix::jni

#endif // SCAPIX_LINK_JAVA_VM_EXCEPTION_H

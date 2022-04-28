/*
	scapix/link/java/vm_exception.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_VM_EXCEPTION_H
#define SCAPIX_LINK_JAVA_VM_EXCEPTION_H

#include <string>
#include <exception>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/throwable.h>

namespace scapix::link::java {

class vm_exception : public std::exception
{
public:

	virtual const char* what() const noexcept override { return class_name().c_str(); }

	ref<throwable<>> get() const { return exception; }

	const std::string& class_name() const
	{
		if (cls_name.empty())
			get_class_name();

		return cls_name;
	}

private:

	friend void detail::throw_exception(jthrowable e);

	vm_exception(local_ref<throwable<>>&& e) : exception(std::move(e)) {}

private:

	void get_class_name() const
	{
		cls_name = exception->get_object_class()->call_method<SCAPIX_META_STRING("getName"), ref<string>()>()->chars<char>().data();
	}

	local_ref<throwable<>> exception;
	mutable std::string cls_name;

};

inline bool operator == (const vm_exception& e, const std::string& cls_name) { return e.class_name() == cls_name; }
inline bool operator == (const std::string& cls_name, const vm_exception& e) { return e.class_name() == cls_name; }

inline bool operator == (const vm_exception& e, const char* cls_name) { return e.class_name() == cls_name; }
inline bool operator == (const char* cls_name, const vm_exception& e) { return e.class_name() == cls_name; }

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_VM_EXCEPTION_H

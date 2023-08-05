/*
	scapix/link/java/detail/native_exception.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H
#define SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H

#include <memory>
#include <exception>
#include <scapix/link/java/throwable.h>
#include <scapix/link/java/string.h>
#include <scapix/link/java/convert.h>

#if __has_include(<cxxabi.h>)
#include <cxxabi.h>
#endif

namespace scapix::link::java {
namespace detail {

class native_exception_cpp final
{
public:

	[[noreturn]] void rethrow()
	{
		std::rethrow_exception(ptr);
	}

	void finalize()
	{
		delete this;
	}

	ref<string> message() const
	{
		try
		{
			std::rethrow_exception(ptr);
		}
		catch (const std::exception& e)
		{
			return string::new_(e.what());
		}
		catch (...)
		{
		#if __has_include(<cxxabi.h>)
			int status;
			auto name = abi::__cxa_current_exception_type()->name();
			auto demangled_name = abi::__cxa_demangle(name, nullptr, nullptr, &status);
			auto ret = string::new_(demangled_name);
			free(demangled_name);
			return ret;
		#else
			return string::new_("unknown");
		#endif
		}
	}

private:

	std::exception_ptr ptr = std::current_exception();

};

class native_exception : public object<SCAPIX_META_STRING("com/scapix/NativeException"), throwable>
{
public:

	native_exception_cpp* cpp()
	{
		return reinterpret_cast<native_exception_cpp*>(get_field<SCAPIX_META_STRING("ptr"), jlong>());
	}

	static local_ref<native_exception> new_object()
	{
		return object::new_object<void(jlong)>(reinterpret_cast<jlong>(new native_exception_cpp));
	}

	[[noreturn]] void rethrow()
	{
		cpp()->rethrow();
	}

protected:

	native_exception(handle_type h) : object(h) {}

};

} // namespace detail

template <>
struct class_name<detail::native_exception_cpp>
{
	using type = detail::native_exception::class_name;
};

template <>
struct convert_this<detail::native_exception_cpp>
{
	static detail::native_exception_cpp& cpp(ref<detail::native_exception> v)
	{
		return *v->cpp();
	}
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H

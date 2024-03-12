/*
	scapix/jni/com/scapix/native_exception.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_COM_SCAPIX_NATIVE_EXCEPTION_H
#define SCAPIX_JNI_COM_SCAPIX_NATIVE_EXCEPTION_H

#include <memory>
#include <exception>
#include <scapix/jni/throwable.h>
#include <scapix/jni/string.h>
#include <scapix/jni/convert.h>
#include <scapix/jni/fwd/native_method.h>

#if __has_include(<cxxabi.h>)
#include <cxxabi.h>
#endif

namespace scapix::jni {
namespace com::scapix {
namespace cpp {

class native_exception final
{
public:

	[[noreturn]] void rethrow() const
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
			return new_object<string>(e.what());
		}
		catch (...)
		{
		#if __has_include(<cxxabi.h>)
			int status;
			auto name = abi::__cxa_current_exception_type()->name();
			auto demangled_name = abi::__cxa_demangle(name, nullptr, nullptr, &status);
			auto ret = new_object<string>(demangled_name);
			free(demangled_name);
			return ret;
		#else
			return new_object<string>("unknown");
		#endif
		}
	}

private:

	std::exception_ptr ptr = std::current_exception();

};

} // namespace cpp

class native_exception : public object<"com/scapix/NativeException", throwable>
{
public:

	using native_methods = jni::native_methods
	<
		class_name,
		native_method<"finalize", void(), void(cpp::native_exception::*)(), &cpp::native_exception::finalize>,
		native_method<"getMessage", ref<string>(), ref<string>(cpp::native_exception::*)() const, &cpp::native_exception::message>
	>;

	cpp::native_exception* cpp() const
	{
		return reinterpret_cast<cpp::native_exception*>(get_field<"ptr", jlong>());
	}

	static local_ref<native_exception> new_object()
	{
		return jni::new_object<native_exception, void(jlong)>(reinterpret_cast<jlong>(new cpp::native_exception));
	}

	[[noreturn]] void rethrow() const
	{
		cpp()->rethrow();
	}

protected:

	native_exception(handle_type h) : object(h) {}

};

} // namespace com::scapix

template <std::same_as<com::scapix::cpp::native_exception> T>
com::scapix::cpp::native_exception& convert_this(ref<com::scapix::native_exception> v)
{
	return *v->cpp();
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_COM_SCAPIX_NATIVE_EXCEPTION_H

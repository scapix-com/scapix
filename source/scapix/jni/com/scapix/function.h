/*
	scapix/jni/com/scapix/function.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_COM_SCAPIX_FUNCTION_H
#define SCAPIX_JNI_COM_SCAPIX_FUNCTION_H

#include <functional>
#include <utility>
#include <scapix/jni/object.h>
#include <scapix/jni/function.h>
#include <scapix/jni/fwd/native_method.h>

namespace scapix::jni {
namespace com::scapix {
namespace cpp {

class function
{
public:

	virtual ~function() = default;

	void finalize()
	{
		delete this;
	}

};

template <typename T>
class function_impl;

template <typename R, typename ...Args>
class function_impl<R(Args...)> : public function
{
public:

	function_impl(std::function<R(Args...)>&& f) : func(std::move(f)) {}

	R call(Args... args)
	{
		return func(std::forward<Args>(args)...);
	}

private:

	std::function<R(Args...)> func;

};

} // namespace cpp

class function : public object<"com/scapix/Function">
{
public:

	using native_methods = jni::native_methods
	<
		class_name,
		native_method<"finalize", void(), void(cpp::function::*)(), &cpp::function::finalize>
	>;

	cpp::function* get_ptr() const { return reinterpret_cast<cpp::function*>(get_field<"ptr", jlong>()); }

protected:

	function(handle_type h) : object(h) {}

};

template <fixed_string InterfaceClassName, typename Type, fixed_string Name>
class function_impl;

template <fixed_string InterfaceClassName, typename JniR, typename ...JniArgs, fixed_string Name>
class function_impl<InterfaceClassName, JniR(JniArgs...), Name> : public object<InterfaceClassName + "Impl",
	function,
	jni::function<InterfaceClassName, JniR(JniArgs...), Name>>
{
	using base = object<InterfaceClassName + "Impl",
		function,
		jni::function<InterfaceClassName, JniR(JniArgs...), Name>>;

public:

	template <typename R, typename ...Args>
	static local_ref<function_impl> new_object(std::function<R(Args...)>&& func)
	{
		cpp::function* ptr = new cpp::function_impl<R(Args...)>(std::move(func));
		return jni::new_object<function_impl, void(jlong)>(reinterpret_cast<jlong>(ptr));
	}

protected:

	function_impl(typename base::handle_type h) : base(h) {}

};

} // namespace com::scapix

template <std::derived_from<com::scapix::cpp::function> T, typename J>
T& convert_this(ref<J> x)
{
	return *static_cast<T*>(static_pointer_cast<com::scapix::function>(x)->get_ptr());
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_COM_SCAPIX_FUNCTION_H

/*
	scapix/bridge/java/function.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_FUNCTION_H
#define SCAPIX_BRIDGE_JAVA_FUNCTION_H

#include <functional>
#include <utility>
#include <scapix/link/java/object.h>
#include <scapix/link/java/convert.h>

namespace scapix::bridge::java {

class function_base
{
public:

	virtual ~function_base() = default;

	void finalize()
	{
		delete this;
	}

};

template <typename T>
class function;

template <typename R, typename ...Args>
class function<R(Args...)> : public function_base
{
public:

	function(std::function<R(Args...)>&& f) : func(std::move(f)) {}

	R call(Args... args)
	{
		return func(std::forward<Args>(args)...);
	}

private:

	std::function<R(Args...)> func;

};

} // namespace scapix::bridge::java

namespace scapix::link::java {
namespace detail {

class function : public object<SCAPIX_META_STRING("com/scapix/Function")>
{
	using ptr = SCAPIX_META_STRING("ptr");

public:

	bridge::java::function_base* get_ptr() { return reinterpret_cast<bridge::java::function_base*>(get_field<ptr, jlong>()); }

protected:

	function(handle_type h) : object(h) {}

};

template <typename InterfaceClassName, typename Type, typename Name>
class function_impl;

template <typename InterfaceClassName, typename JniR, typename ...JniArgs, typename Name>
class function_impl<InterfaceClassName, JniR(JniArgs...), Name> : public object<meta::concat_t<InterfaceClassName, SCAPIX_META_STRING("Impl")>,
	function,
	java::function<InterfaceClassName, JniR(JniArgs...), Name>>
{
	using base = object<meta::concat_t<InterfaceClassName, SCAPIX_META_STRING("Impl")>,
		function,
		java::function<InterfaceClassName, JniR(JniArgs...), Name>>;

public:

	template <typename R, typename ...Args>
	static link::java::local_ref<function_impl> create(std::function<R(Args...)>&& func)
	{
		bridge::java::function_base* ptr = new bridge::java::function<R(Args...)>(std::move(func));
		return base::template new_object<void(jlong)>(reinterpret_cast<jlong>(ptr));
	}

protected:

	function_impl(typename base::handle_type h) : base(h) {}

};

} // namespace detail

template <>
struct class_name<bridge::java::function_base>
{
	using type = detail::function::class_name;
};

template <typename T>
struct class_name<bridge::java::function<T>>
{
	using type = detail::function::class_name;
};

template <typename T>
struct convert_this<bridge::java::function<T>>
{
	static bridge::java::function<T>& cpp(ref<detail::function> v)
	{
		return *static_cast<bridge::java::function<T>*>(v->get_ptr());
	}
};

template <>
struct convert_this<bridge::java::function_base>
{
	static bridge::java::function_base& cpp(ref<detail::function> v)
	{
		return *v->get_ptr();
	}
};

} // namespace scapix::link::java

#endif // SCAPIX_BRIDGE_JAVA_FUNCTION_H

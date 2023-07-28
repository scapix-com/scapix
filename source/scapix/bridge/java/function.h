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

class function_base;

namespace detail {

class function : public link::java::object<SCAPIX_META_STRING("com/scapix/Function")>
{
public:

	using ptr = SCAPIX_META_STRING("ptr");

	template <typename ClassName>
	static link::java::local_ref<ClassName> create(function_base* p)
	{
		return link::java::static_pointer_cast<ClassName>(link::java::object<meta::concat_t<ClassName, SCAPIX_META_STRING("Impl")>>::template new_object<void(jlong)>(reinterpret_cast<jlong>(p)));
	}

	void set_ptr(function_base* p) { set_field<ptr>(reinterpret_cast<jlong>(p)); }
	function_base* get_ptr() { return reinterpret_cast<function_base*>(get_field<ptr, jlong>()); }

protected:

	function(handle_type h) : object(h) {}

};

} // namespace detail

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

	template <typename ClassName>
	static link::java::ref<ClassName> create(std::function<R(Args...)>&& func)
	{
		return detail::function::create<ClassName>(new function<R(Args...)>(std::move(func)));
	}

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

template <>
struct class_name<bridge::java::function_base>
{
	using type = bridge::java::detail::function::class_name;
};

template <typename T>
struct class_name<bridge::java::function<T>>
{
	using type = bridge::java::detail::function::class_name;
};

// used to convert 'this'

template <typename Jni, typename T>
struct convert<Jni, bridge::java::function<T>>
{
	static bridge::java::function<T>& cpp(ref<bridge::java::detail::function> v)
	{
		return *static_cast<bridge::java::function<T>*>(v->get_ptr());
	}
};

// used to convert 'this'

template <typename Jni>
struct convert<Jni, bridge::java::function_base>
{
	static bridge::java::function_base& cpp(ref<bridge::java::detail::function> v)
	{
		return *v->get_ptr();
	}
};

template <typename T>
struct function_impl;

template <typename ClassName, typename JniR, typename ...JniArgs>
struct function_impl<function<ClassName, JniR(JniArgs...)>>
{
	template <typename R, typename ...Args>
	static link::java::ref<ClassName> create(std::function<R(Args...)>&& func)
	{
		return bridge::java::function<R(Args...)>::template create<ClassName>(std::move(func));
	}
};

} // namespace scapix::link::java

#endif // SCAPIX_BRIDGE_JAVA_FUNCTION_H

/*
	scapix/bridge/java/object.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_OBJECT_H
#define SCAPIX_BRIDGE_JAVA_OBJECT_H

#include <memory>
#include <type_traits>
#include <scapix/bridge/type_traits.h>
#include <scapix/bridge/java/on_load.h>
#include <scapix/link/java/object.h>
#include <scapix/link/java/init.h>
#include <scapix/link/java/convert.h>
#include <scapix/link/java/native_method.h>
#include <scapix/link/java/array.h>

namespace scapix::bridge::java {

class object_base;
class function_base;

namespace detail {

class bridge : public link::java::object<SCAPIX_META_STRING("com/scapix/Bridge")>
{
public:

	using nop = link::java::object<SCAPIX_META_STRING("com/scapix/Bridge$Nop")>;
	using ptr = SCAPIX_META_STRING("ptr");

	template <typename Wrapper>
	static link::java::local_ref<bridge> create() { return link::java::static_pointer_cast<bridge>(link::java::object<Wrapper>::template new_object<void(link::java::ref<nop>)>(nullptr)); }

	void set_ptr(object_base* p) { set_field<ptr>(reinterpret_cast<jlong>(p)); }
	object_base* get_ptr() { return reinterpret_cast<object_base*>(get_field<ptr, jlong>()); }

protected:

	bridge(handle_type h) : object_type(h) {}

};

class function : public link::java::object<SCAPIX_META_STRING("com/scapix/Function")>
{
public:

	using ptr = SCAPIX_META_STRING("ptr");

	template <typename ClassName>
	static link::java::local_ref<ClassName> create(function_base* p) { return link::java::static_pointer_cast<ClassName>(link::java::object<meta::concat_t<ClassName, SCAPIX_META_STRING("Impl")>>::template new_object<void(jlong)>(reinterpret_cast<jlong>(p))); }

	void set_ptr(function_base* p) { set_field<ptr>(reinterpret_cast<jlong>(p)); }
	function_base* get_ptr() { return reinterpret_cast<function_base*>(get_field<ptr, jlong>()); }

protected:

	function(handle_type h) : object_type(h) {}

};

} // namespace detail

class object_base
{
protected:

	object_base() = default;
	object_base(const object_base&) {}
	object_base(object_base&&) = default;
	object_base& operator =(const object_base&) { return *this; }
	object_base& operator =(object_base&&) = default;

private:

	template <typename>
	friend class init;

	template <typename Jni, typename Cpp, typename>
	friend struct link::java::convert_shared;

	friend jint on_load(JavaVM *vm, void *reserved, void(*init)());

	void attach(link::java::ref<detail::bridge> obj, std::shared_ptr<object_base> shared_this)
	{
		assert(!wrapper);
		assert(!self);

		wrapper = std::move(obj);
		self = std::move(shared_this);

		wrapper->set_ptr(this);
	}

	// to do: with indirect inheritance support,
	// wrappers should depend on actual object type.

	template <typename T>
	link::java::local_ref<detail::bridge> get_ref(std::shared_ptr<T> shared_this)
	{
		link::java::local_ref<detail::bridge> local(wrapper);

		if (!local)
		{
			local = detail::bridge::create<link::java::class_name_t<T>>();
			attach(local, std::move(shared_this));
		}

		return local;
	}

	const std::shared_ptr<object_base>& scapix_shared()
	{
		assert(self);
		return self;
	}

	void finalize()
	{
		wrapper.reset();
		self.reset(); // might destroy this object
	}

	link::java::weak_ref<detail::bridge> wrapper;
	std::shared_ptr<object_base> self;

};

// to do: inheritance should be private

template <typename>
class object : public object_base
{
protected:

	object() = default;
	object(const object&) = default;
	object(object&&) = default;
	object& operator =(const object&) = default;
	object& operator =(object&&) = default;

};

template <typename T>
class init
{
public:

	init(link::java::ref<link::java::class_name_t<T>>&& wrapper) : wrapper(std::move(wrapper)) {}

	template <typename ...Args>
	void create(Args... args)
	{
		std::shared_ptr<object_base> obj = std::make_shared<T>(std::forward<Args>(args)...);
		object_base* ptr = obj.get();
		ptr->attach(link::java::static_pointer_cast<detail::bridge>(std::move(wrapper)), std::move(obj));
	}

private:

	link::java::ref<link::java::class_name_t<T>> wrapper;

};

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

inline jint on_load(JavaVM *vm, void *reserved, void(*init)())
{
	try
	{
		auto result = link::java::on_load(vm, reserved);

		link::java::native_methods
		<
			detail::bridge::class_name,
			link::java::native_method<SCAPIX_META_STRING("finalize"), void(), void(object_base::*)(), &object_base::finalize>
		>
		::register_();

		link::java::native_methods
		<
			detail::function::class_name,
			link::java::native_method<SCAPIX_META_STRING("finalize"), void(), void(function_base::*)(), &function_base::finalize>
		>
		::register_();

		init();

		return result;
	}
	catch (const link::java::vm_exception& e)
	{
		e.get()->throw_();
	}

	return 0;
}

} // namespace scapix::bridge::java

namespace scapix::link::java {

template <>
struct class_name<bridge::java::object_base>
{
	using type = bridge::java::detail::bridge::class_name;
};

template <typename T>
struct class_name<bridge::java::init<T>>
{
	using type = class_name_t<T>;
};

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
struct convert<Jni, bridge::java::init<T>>
{
	static bridge::java::init<T> cpp(ref<class_name_t<T>> v)
	{
		return bridge::java::init<T>(std::move(v));
	}
};

// used to convert 'this'

template <typename Jni, typename T>
struct convert<Jni, T, std::enable_if_t<bridge::is_object<T>>>
{
	static T& cpp(ref<class_name_t<T>> v)
	{
		return *static_cast<T*>(static_pointer_cast<bridge::java::detail::bridge>(std::move(v))->get_ptr());
	}
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

template <typename Jni, typename T>
struct convert_shared<Jni, T, std::enable_if_t<bridge::is_object<T>>>
{
	static std::shared_ptr<T> cpp(ref<class_name_t<T>> v)
	{
		if (!v)
			return nullptr;

		return static_pointer_cast<T>(static_pointer_cast<bridge::java::detail::bridge>(std::move(v))->get_ptr()->scapix_shared());
	}

	static ref<class_name_t<T>> jni(std::shared_ptr<T> v)
	{
		if (!v)
			return nullptr;

		auto p = v.get();
		return static_pointer_cast<class_name_t<T>>(p->get_ref(std::move(v)));
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

#endif // SCAPIX_BRIDGE_JAVA_OBJECT_H

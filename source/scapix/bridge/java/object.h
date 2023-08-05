/*
	scapix/bridge/java/object.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_OBJECT_H
#define SCAPIX_BRIDGE_JAVA_OBJECT_H

#include <memory>
#include <utility>
#include <type_traits>
#include <scapix/bridge/type_traits.h>
#include <scapix/link/java/object.h>
#include <scapix/link/java/convert.h>

namespace scapix::bridge::java {

class object_base;

namespace detail {

class bridge : public link::java::object<SCAPIX_META_STRING("com/scapix/Bridge")>
{
public:

	using nop = link::java::object<SCAPIX_META_STRING("com/scapix/Bridge$Nop")>;
	using ptr = SCAPIX_META_STRING("ptr");

	void set_ptr(object_base* p) { set_field<ptr>(reinterpret_cast<jlong>(p)); }
	object_base* get_ptr() { return reinterpret_cast<object_base*>(get_field<ptr, jlong>()); }

protected:

	bridge(handle_type h) : object(h) {}

};

template <typename T>
class bridge_object : public link::java::object<link::java::class_name_t<T>, bridge>
{
	using base = link::java::object<link::java::class_name_t<T>, bridge>;

public:

	static link::java::local_ref<bridge_object> create()
	{
		return base::template new_object<void(link::java::ref<typename base::nop>)>(nullptr);
	}

	void set_ptr(T* p) { base::set_ptr(p); }
	T* get_ptr() { return static_cast<T*>(base::get_ptr()); }

protected:

	bridge_object(typename base::handle_type h) : base(h) {}

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
	link::java::local_ref<detail::bridge_object<T>> get_ref(std::shared_ptr<T> shared_this)
	{
		link::java::local_ref<detail::bridge_object<T>> local(link::java::static_pointer_cast<detail::bridge_object<T>>(wrapper));

		if (!local)
		{
			local = detail::bridge_object<T>::create();
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

	init(link::java::ref<detail::bridge_object<T>>&& wrapper) : wrapper(std::move(wrapper)) {}

	template <typename ...Args>
	void create(Args... args)
	{
		std::shared_ptr<object_base> obj = std::make_shared<T>(std::forward<Args>(args)...);
		object_base* ptr = obj.get();
		ptr->attach(std::move(wrapper), std::move(obj));
	}

private:

	link::java::ref<detail::bridge_object<T>> wrapper;

};

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

template <typename T>
struct convert_this<bridge::java::init<T>>
{
	static bridge::java::init<T> cpp(ref<bridge::java::detail::bridge_object<T>> v)
	{
		return bridge::java::init<T>(std::move(v));
	}
};

template <typename T>
struct convert_this<T, std::enable_if_t<bridge::is_object<T>>>
{
	static T& cpp(ref<bridge::java::detail::bridge_object<T>> v)
	{
		return *v->get_ptr();
	}
};

template <typename Jni, typename T>
struct convert_shared<Jni, T, std::enable_if_t<bridge::is_object<T>>>
{
	static std::shared_ptr<T> cpp(ref<bridge::java::detail::bridge_object<T>> v)
	{
		if (!v)
			return nullptr;

		return static_pointer_cast<T>(v->get_ptr()->scapix_shared());
	}

	static ref<bridge::java::detail::bridge_object<T>> jni(std::shared_ptr<T> v)
	{
		if (!v)
			return nullptr;

		auto p = v.get();
		return p->get_ref(std::move(v));
	}
};

} // namespace scapix::link::java

#endif // SCAPIX_BRIDGE_JAVA_OBJECT_H

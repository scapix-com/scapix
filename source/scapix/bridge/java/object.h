/*
	scapix/bridge/java/object.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_OBJECT_H
#define SCAPIX_BRIDGE_JAVA_OBJECT_H

#include <memory>
#include <type_traits>
#include <scapix/bridge/type_traits.h>
#include <scapix/link/java/object.h>
#include <scapix/link/java/vm.h> // on_load
#include <scapix/link/java/convert.h>
#include <scapix/link/java/native_method.h>
#include <scapix/link/java/array.h>

namespace scapix {
namespace bridge {
namespace java {

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

	friend jint on_load(JavaVM *vm, void *reserved);

	void attach(link::java::ref<SCAPIX_META_STRING("com/scapix/Bridge")> obj, std::shared_ptr<object_base> shared_this)
	{
		assert(!wrapper);
		assert(!self);

		wrapper = std::move(obj);
		self = std::move(shared_this);

		wrapper->set_field<SCAPIX_META_STRING("ptr")>(reinterpret_cast<jlong>(this));
	}

	// to do: with indirect inheritance support,
	// wrappers should depend on actual object type.

	template <typename T>
	link::java::local_ref<SCAPIX_META_STRING("com/scapix/Bridge")> get_ref(std::shared_ptr<T> shared_this)
	{
		link::java::local_ref<SCAPIX_META_STRING("com/scapix/Bridge")> local(wrapper);

		if (!local)
		{
			local = link::java::static_pointer_cast<SCAPIX_META_STRING("com/scapix/Bridge")>(link::java::object<link::java::class_name_t<T>>::template new_object<void(link::java::ref<SCAPIX_META_STRING("com/scapix/Bridge$Tag")>)>(nullptr));
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

	link::java::weak_ref<SCAPIX_META_STRING("com/scapix/Bridge")> wrapper;
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
		ptr->attach(link::java::static_pointer_cast<SCAPIX_META_STRING("com/scapix/Bridge")>(std::move(wrapper)), std::move(obj));
	}

private:

	link::java::ref<link::java::class_name_t<T>> wrapper;

};

inline jint on_load(JavaVM *vm, void *reserved)
{
	auto result = link::java::on_load(vm, reserved);

	link::java::native_methods
	<
		SCAPIX_META_STRING("com/scapix/Bridge"),
		link::java::native_method<SCAPIX_META_STRING("_finalize"), void(), void(object_base::*)(), &object_base::finalize>
	>
	::register_();

	return result;
}

} // namespace java
} // namespace bridge

namespace link {
namespace java {

template <>
struct class_name<bridge::java::object_base>
{
    using type = SCAPIX_META_STRING("com/scapix/Bridge");
};

template <typename T>
struct class_name<bridge::java::init<T>>
{
    using type = class_name_t<T>;
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
        return *reinterpret_cast<T*>(static_pointer_cast<SCAPIX_META_STRING("com/scapix/Bridge")>(std::move(v))->template get_field<SCAPIX_META_STRING("ptr"), jlong>());
    }
};

template <typename Jni, typename T>
struct convert_shared<Jni, T, std::enable_if_t<bridge::is_object<T>>>
{
	static std::shared_ptr<T> cpp(ref<class_name_t<T>> v)
    {
		return static_pointer_cast<T>(reinterpret_cast<bridge::java::object_base*>(static_pointer_cast<SCAPIX_META_STRING("com/scapix/Bridge")>(std::move(v))->template get_field<SCAPIX_META_STRING("ptr"), jlong>())->scapix_shared());
    }

	static ref<class_name_t<T>> jni(std::shared_ptr<T> v)
    {
		auto p = v.get();
		return static_pointer_cast<class_name_t<T>>(p->get_ref(std::move(v)));
    }
};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_BRIDGE_JAVA_OBJECT_H

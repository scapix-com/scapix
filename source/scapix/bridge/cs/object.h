/*
	scapix/bridge/cs/object.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_CS_OBJECT_H
#define SCAPIX_BRIDGE_CS_OBJECT_H

#include <memory>
#include <cassert>
#include <scapix/link/cs/ref.h>
#include <scapix/link/cs/convert.h>
#include <scapix/bridge/type_traits.h>

namespace scapix {
namespace bridge {
namespace cs {

using link::cs::ref;
using link::cs::ref_type;

class object_base
{
protected:

	object_base() = default;
	object_base(const object_base&) {}
	object_base(object_base&&) = default;
	object_base& operator =(const object_base&) { return *this; }
	object_base& operator =(object_base&&) = default;

private:

	friend struct link::cs::api::cpp_api;

	template <typename T, typename ...Args>
	friend object_base* init(link::cs::api::handle_type weak_wrapper, Args&&... args);
		
	template <typename Cs, typename Cpp, typename>
	friend struct link::cs::convert_shared;

	void attach(ref<> weak, std::shared_ptr<object_base> shared)
	{
		//assert(!wrapper && !self);

		wrapper = std::move(weak);
		self = std::move(shared);
	}

	// to do: with indirect inheritance support,
	// wrappers should depend on actual object type.

	template <typename T>
	ref<> get_ref(std::shared_ptr<object_base> shared)
	{
		ref<> strong(wrapper);

		if (!strong)
		{
			strong = ref<>(link::cs::api::class_info<T>::cs_api.create(this));
			attach(ref<>(strong, ref_type::weak_track_resurrection), shared);
		}

		return strong;
	}

	const std::shared_ptr<object_base>& scapix_shared() const
	{
		assert(self);
		return self;
	}

	// Fix: finalize is called on arbitrary thread. Also in Java?

	bool finalize()
	{
		std::weak_ptr<object_base> weak_self(self);
		self.reset(); // might destroy this object

		if (auto shared_self = weak_self.lock())
		{
			self = std::move(shared_self);
			return false;
		}

		return true;
	}

	ref<> wrapper; // weak_track_resurrection
	std::shared_ptr<object_base> self;

};

// to do: inheritance should be private, not to expose protected members

template <typename T>
class object : public object_base
{
protected:

	object() = default;
	object(const object&) = default;
	object(object&&) = default;
	object& operator =(const object&) = default;
	object& operator =(object&&) = default;

};

template <typename T, typename ...Args>
object_base* init(link::cs::api::handle_type weak_wrapper, Args&&... args)
{
	auto obj = std::make_shared<T>(std::forward<Args>(args)...);
	auto ptr = obj.get();
	ptr->attach(ref<>(weak_wrapper), std::move(obj));
	return ptr;
}

} // namespace cs
} // namespace bridge

namespace link {
namespace cs {

template <typename T>
struct convert_shared<api::handle_type, T, std::enable_if_t<bridge::is_object<T>>>
{
	static std::shared_ptr<T> cpp(api::handle_type v)
	{
		ref<> r(v);
		return std::static_pointer_cast<T>(static_cast<const bridge::cs::object_base*>(link::cs::api::funcs.get_cpp(v))->scapix_shared());
	}

	static api::handle_type cs(std::shared_ptr<T> v)
	{
		auto p = v.get();
		return p->template get_ref<T>(std::move(v)).release();
	}
};

} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_BRIDGE_CS_OBJECT_H

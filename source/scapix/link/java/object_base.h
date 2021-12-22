/*
	scapix/link/java/object_base.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_OBJECT_BASE_H
#define SCAPIX_LINK_JAVA_OBJECT_BASE_H

#include <scapix/link/java/object.h>
#include <scapix/link/java/detail/util.h>
#include <boost/mp11.hpp>

namespace scapix {
namespace link {
namespace java {

// given list of (linearly) derived types, select the most derived

template <typename ...Ts>
struct derived;

template <typename T>
struct derived<T>
{
	using type = T;
};

template <typename T1, typename T2>
struct derived<T1, T2>
{
	using type = std::conditional_t<std::is_base_of_v<T1, T2>, T2, T1>;
};

template <typename T1, typename T2, typename ...Ts>
struct derived<T1, T2, Ts...>
{
	using type = typename derived<typename derived<T1, T2>::type, Ts...>::type;
};

// object_base

template <typename ClassName, typename ...Bases>
class object_base : protected object<ClassName>, public detail::tag<Bases, ClassName>...
{
protected:

	using base_classes = boost::mp11::mp_append<boost::mp11::mp_list<detail::tag<Bases, ClassName>...>, typename detail::tag<Bases, ClassName>::base_classes...>;

	template <typename T>
	struct is_same_key
	{
		template <typename L>
		struct result;

		template <template <typename...> class List, typename E1, typename ...Es>
		struct result<List<E1, Es...>> : std::is_same<E1, T> {};
	};

public:

	// Access base classes derived from more than once:
	// r->base_class<java::lang::Object>::getClass();
	// This includes java::lang::Object (all java classes AND interfaces extend it),
	// and the same java interface implemented by more than one base class.

	template <typename T>
	using base_class = boost::mp11::mp_at<base_classes, boost::mp11::mp_find_if<base_classes, is_same_key<T>::template result>>;

protected:

	using base_ = object_base;
	using object_type = object<ClassName>;

// to do: use befriend and make these protected.
public:

//  using typename object_type::handle_type;
	using handle_type = std::add_pointer_t<typename derived<std::remove_pointer_t<typename object_type::handle_type>, std::remove_pointer_t<typename Bases::handle_type>...>::type>;
	using typename object_type::class_name;
	using object_type::class_object;
	using object_type::native;

protected:

	object_base(handle_type h) : object_type(h), detail::tag<Bases, ClassName>(h)... {}

	handle_type handle() const { return static_cast<handle_type>(object_type::handle()); }

	template <typename ...Args>
	static local_ref<ClassName> new_object(Args&&... args)
	{
		return object_type::template new_object<void(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	template <typename Name, typename R, typename ...Args>
	auto call_method(Args&&... args) const
	{
		return object_type::template call_method<Name, R(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	template <typename Name, typename R, typename ...Args>
	static auto call_static_method(Args&&... args)
	{
		return object_type::template call_static_method<Name, R(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	using object_type::get_field;
	using object_type::set_field;
	using object_type::get_static_field;
	using object_type::set_static_field;

};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_OBJECT_BASE_H

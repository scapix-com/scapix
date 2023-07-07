/*
	scapix/link/java/object_base.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_OBJECT_BASE_H
#define SCAPIX_LINK_JAVA_OBJECT_BASE_H

#include <scapix/link/java/object.h>
#include <scapix/link/java/detail/util.h>

namespace scapix::link::java {
namespace detail {

	template <typename Object, typename ...Bases>
	struct select_handle_type;

	template <typename Object>
	struct select_handle_type<Object>
	{
		using type = typename Object::handle_type;
	};

	template <typename Object, typename Base1, typename ...Bases>
	struct select_handle_type<Object, Base1, Bases...>
	{
		using base1_handle_type = typename detail::befriend<Base1, select_handle_type>::handle_type;
		using type = std::conditional_t<std::is_same_v<base1_handle_type, jobject>, typename Object::handle_type, base1_handle_type>;
	};

} // namespace detail

template <typename ClassName, typename ...Bases>
class object_base : protected object<ClassName>, public detail::tag<Bases, ClassName>...
{
public:

	using object<ClassName>::native;

protected:

	using base_ = object_base;
	using object_type = object<ClassName>;
	using typename object_type::class_name;
	using handle_type = typename detail::select_handle_type<object_type, Bases...>::type;

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

	using object_type::class_object;

};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_OBJECT_BASE_H

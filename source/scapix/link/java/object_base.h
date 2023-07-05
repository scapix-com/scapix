/*
	scapix/link/java/object_base.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/link/java/object_impl.h>

#ifndef SCAPIX_LINK_JAVA_OBJECT_BASE_H
#define SCAPIX_LINK_JAVA_OBJECT_BASE_H

#include <scapix/link/java/fwd/object_base.h>
#include <scapix/link/java/object_impl.h>

namespace scapix::link::java {

#include <scapix/detail/warning/inaccessible_base.h>

template <typename ClassName, typename ...Bases>
class object_base : private object_impl<ClassName>, public Bases...
{
protected:

	using class_name = ClassName;
	using base_classes = std::tuple<Bases...>;
	using handle_type = handle_type_t<object_base>;

	using base_ = object_base;
	using object_type = object_impl<ClassName>;

	object_base(handle_type h) : object_type(h), Bases(h)... {}

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

#include <scapix/detail/warning/pop.h>

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_OBJECT_BASE_H

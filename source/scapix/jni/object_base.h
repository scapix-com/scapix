/*
	scapix/jni/object_base.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/jni/object_impl.h>

#ifndef SCAPIX_JNI_OBJECT_BASE_H
#define SCAPIX_JNI_OBJECT_BASE_H

#include <scapix/jni/fwd/object_base.h>
#include <scapix/jni/object_impl.h>

namespace scapix::jni {

#include <scapix/core/warning/inaccessible_base.h>

template <fixed_string ClassName, typename ...Bases>
class object_base : private object_impl<ClassName>, public Bases...
{
	using impl = object_impl<ClassName>;

protected:

	static constexpr auto class_name = ClassName;
	using base_classes = std::tuple<Bases...>;
	using handle_type = handle_type_t<object_base>;

	using base_ = object_base;

	object_base(handle_type h) : impl(h), Bases(h)... {}

	template <typename ...Args>
	static local_ref<object_base> new_object(Args&&... args)
	{
		return jni::new_object<object<ClassName>, void(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	template <fixed_string Name, typename R, typename ...Args>
	auto call_method(Args&&... args) const
	{
		return impl::template call_method<Name, R(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	template <fixed_string Name, typename R, typename ...Args>
	static auto call_static_method(Args&&... args)
	{
		return impl::template call_static_method<Name, R(std::remove_reference_t<Args>...)>(std::forward<Args>(args)...);
	}

	using impl::get_field;
	using impl::set_field;
	using impl::get_static_field;
	using impl::set_static_field;
	using impl::class_object;

};

#include <scapix/core/warning/pop.h>

} // namespace scapix::jni

#endif // SCAPIX_JNI_OBJECT_BASE_H

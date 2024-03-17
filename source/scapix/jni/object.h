/*
	scapix/jni/object.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

// outside of include guard
#include <scapix/jni/object_impl.h>

#ifndef SCAPIX_JNI_OBJECT_H
#define SCAPIX_JNI_OBJECT_H

#include <scapix/jni/fwd/object.h>
#include <scapix/jni/object_impl.h>

namespace scapix::jni {

#include <scapix/detail/warning/inaccessible_base.h>

template <fixed_string ClassName, typename ...Bases>
class object : private object_impl<ClassName>, public Bases...
{
	using impl = object_impl<ClassName>;

public:

	static constexpr auto class_name = ClassName;
	using base_classes = std::tuple<Bases...>;
	using handle_type = handle_type_t<object>;

	using impl::call_method;
	using impl::call_nonvirtual_method;
	using impl::call_static_method;
	using impl::new_object;
	using impl::get_field;
	using impl::set_field;
	using impl::get_static_field;
	using impl::set_static_field;
	using impl::class_object;

protected:

	object(handle_type h) : impl(h), Bases(h)... {}
	handle_type handle() const { return static_cast<handle_type>(impl::handle()); }

};

template <fixed_string ClassName>
class object<ClassName> : public object<ClassName, object<>>
{
public:

	using object<ClassName, object<>>::object;

};

template <typename T>
struct always_false : std::false_type {}; 

template <typename Base1, typename ...Bases>
class object<"java/lang/Object", Base1, Bases...>
{
	static_assert(always_false<Base1>::value, "java/lang/Object should not specify base classes");
};

template <>
class object<"java/lang/Object"> : private object_impl<"java/lang/Object">
{
public:

	static constexpr fixed_string class_name = "java/lang/Object";
	using base_classes = std::tuple<>;
	using handle_type = handle_type_t<object>;

	using object_impl::call_method;
	using object_impl::call_nonvirtual_method;
	using object_impl::call_static_method;
	using object_impl::new_object;
	using object_impl::get_field;
	using object_impl::set_field;
	using object_impl::get_static_field;
	using object_impl::set_static_field;
	using object_impl::class_object;

	template <reference T>
	bool is_instance_of() const noexcept
	{
		return is_instance_of(object_impl_t<T>::class_object());
	}

	bool is_instance_of(ref<class_> cls) const noexcept
	{
		return detail::env()->IsInstanceOf(handle(), cls.handle());
	}

	template <reference T>
	ref<T> instance_of() const noexcept
	{
		if (is_instance_of<T>())
			return ref<T>(handle());

		return nullptr;
	}

	local_ref<class_> get_object_class() const noexcept
	{
		return local_ref<class_>(detail::env()->GetObjectClass(handle()));
	}

protected:

	object(handle_type h) : object_impl(h) {}

};

#include <scapix/detail/warning/pop.h>

} // namespace scapix::jni

#endif // SCAPIX_JNI_OBJECT_H

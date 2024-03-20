/*
	scapix/jni/object_impl.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_OBJECT_IMPL_H
#define SCAPIX_JNI_OBJECT_IMPL_H

#include <utility>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/detail/api.h>
#include <scapix/jni/type_traits.h>
#include <scapix/jni/object_traits.h>
#include <scapix/jni/fwd/ref.h>
#include <scapix/jni/fwd/class.h>
#include <scapix/jni/fwd/element.h>

namespace scapix::jni {

template <fixed_string ClassName>
class object_impl
{
	static constexpr auto class_name = ClassName;
	using handle_type = jobject;

public:

	// call_method

	template <fixed_string Name, typename Type, typename ...Args>
	auto call_method(Args&&... args) const
	{
		return call_method<Type>(method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	auto call_method(jmethodID id, Args&&... args) const
	{
		return detail::api::call<Type>::method(handle(), id, std::forward<Args>(args)...);
	}

	// call_nonvirtual_method

	template <fixed_string Name, typename Type, typename ...Args>
	auto call_nonvirtual_method(Args&&... args) const
	{
		return call_nonvirtual_method<Type>(method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	auto call_nonvirtual_method(jmethodID id, Args&&... args) const
	{
		return detail::api::call<Type>::nonvirtual_method(handle(), class_object().handle(), id, std::forward<Args>(args)...);
	}

	// call_static_method

	template <fixed_string Name, typename Type, typename ...Args>
	static auto call_static_method(Args&&... args)
	{
		return call_static_method<Type>(static_method_id<Name, Type>(), std::forward<Args>(args)...);
	}

	template <typename Type, typename ...Args>
	static auto call_static_method(jmethodID id, Args&&... args)
	{
		return detail::api::call<Type>::static_method(class_object().handle(), id, std::forward<Args>(args)...);
	}

	// get_field

	template <fixed_string Name, typename Type>
	Type get_field() const
	{
		return get_field<Type>(field_id<Name, Type>());
	}

	template <typename Type>
	Type get_field(jfieldID id) const
	{
		return detail::api::type<Type>::get_field(handle(), id);
	}

	// set_field

	template <fixed_string Name, typename Type>
	void set_field(std::type_identity_t<Type> value) const
	{
		set_field<Type>(field_id<Name, Type>(), value);
	}

	template <typename Type>
	void set_field(jfieldID id, std::type_identity_t<Type> value) const
	{
		detail::api::type<Type>::set_field(handle(), id, value);
	}

	// get_static_field

	template <fixed_string Name, typename Type>
	static Type get_static_field()
	{
		return get_static_field<Type>(static_field_id<Name, Type>());
	}

	template <typename Type>
	static Type get_static_field(jfieldID id)
	{
		return detail::api::type<Type>::get_static_field(class_object().handle(), id);
	}

	// set_static_field

	template <fixed_string Name, typename Type>
	static void set_static_field(std::type_identity_t<Type> value)
	{
		set_static_field<Type>(static_field_id<Name, Type>(), value);
	}

	template <typename Type>
	static void set_static_field(jfieldID id, std::type_identity_t<Type> value)
	{
		detail::api::type<Type>::set_static_field(class_object().handle(), id, value);
	}

	// reflect

	template <fixed_string Name, typename Type>
	static ref<object<"java/lang/reflect/Executable">> to_reflected_method();

	template <fixed_string Name, typename Type>
	static ref<object<"java/lang/reflect/Executable">> to_reflected_static_method();

	template <fixed_string Name, typename Type>
	static ref<object<"java/lang/reflect/Field">> to_reflected_field();

	template <fixed_string Name, typename Type>
	static ref<object<"java/lang/reflect/Field">> to_reflected_static_field();

	// class_object

	static ref<class_> class_object();

protected:

	object_impl(handle_type h) : handle_(h) {}
	handle_type handle() const { return handle_; }

private:

	template <typename /*reference*/ Object, typename Type, typename ...Args>
	friend ref<Object> new_object(Args&&... args); // requires requires { element_type_t<Object>::class_name; };

	template <fixed_string Name, typename Type>
	static jmethodID method_id();

	template <fixed_string Name, typename Type>
	static jmethodID static_method_id();

	template <fixed_string Name, typename Type>
	static jfieldID field_id();

	template <fixed_string Name, typename Type>
	static jfieldID static_field_id();

	handle_type handle_;

};

template <reference T>
using object_impl_t = object_impl<class_name_v<element_type_t<T>>>;

template <reference Object, typename Type, typename ...Args>
ref<Object> new_object(jmethodID id, Args&&... args) requires requires { element_type_t<Object>::class_name; }
{
	return detail::api::call<Type>::template new_object<element_type_t<Object>>(object_impl_t<Object>::class_object().handle(), id, std::forward<Args>(args)...);
}

// https://github.com/llvm/llvm-project/issues/63536
template <typename /*reference*/ Object, typename Type, typename ...Args>
ref<Object> new_object(Args&&... args) // requires requires { element_type_t<Object>::class_name; }
{
	return new_object<Object, Type>(object_impl_t<Object>::template method_id<"<init>", Type>(), std::forward<Args>(args)...);
}

template <reference Object, typename ...Args>
ref<Object> new_object(Args&&... args) requires requires { element_type_t<Object>::new_object(std::forward<Args>(args)...); }
{
	return element_type_t<Object>::new_object(std::forward<Args>(args)...);
}

} // namespace scapix::jni

#ifdef SCAPIX_CACHE_CLASS_LOADER
#include <scapix/jni/class_loader.h>
#else
#include <scapix/jni/class.h>
#endif

namespace scapix::jni {

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline ref<object<"java/lang/reflect/Executable">> object_impl<ClassName>::to_reflected_method()
{
	return class_object()->to_reflected_method(method_id<Name, Type>(), false);
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline ref<object<"java/lang/reflect/Executable">> object_impl<ClassName>::to_reflected_static_method()
{
	return class_object()->to_reflected_method(static_method_id<Name, Type>(), true);
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline ref<object<"java/lang/reflect/Field">> object_impl<ClassName>::to_reflected_field()
{
	return class_object()->to_reflected_field(field_id<Name, Type>(), false);
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline ref<object<"java/lang/reflect/Field">> object_impl<ClassName>::to_reflected_static_field()
{
	return class_object()->to_reflected_field(static_field_id<Name, Type>(), true);
}

template <fixed_string ClassName>
inline ref<class_> object_impl<ClassName>::class_object()
{

#ifdef SCAPIX_CACHE_CLASS_LOADER
	static const static_global_ref<class_> cls(class_loader::find_class(ClassName.replace('/', '.')));
#else
	static const static_global_ref<class_> cls(class_::find_class(ClassName));
#endif

	return cls;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jmethodID object_impl<ClassName>::method_id()
{
	static const jmethodID id(class_object()->get_method_id(Name, signature_v<Type>));
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jmethodID object_impl<ClassName>::static_method_id()
{
	static const jmethodID id(class_object()->get_static_method_id(Name, signature_v<Type>));
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jfieldID object_impl<ClassName>::field_id()
{
	static const jfieldID id(class_object()->get_field_id(Name, signature_v<Type>));
	return id;
}

template <fixed_string ClassName>
template <fixed_string Name, typename Type>
inline jfieldID object_impl<ClassName>::static_field_id()
{
	static const jfieldID id(class_object()->get_static_field_id(Name, signature_v<Type>));
	return id;
}

} // namespace scapix::jni

#endif // SCAPIX_JNI_OBJECT_IMPL_H

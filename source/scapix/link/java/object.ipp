/*
	scapix/link/java/object.ipp

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/class.h>
#include <scapix/link/java/string.h>
#include <scapix/link/java/throwable.h>
#include <scapix/link/java/byte_buffer.h>
#include <scapix/link/java/array.h>

namespace scapix {
namespace link {
namespace java {

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline auto object<ClassName, HandleType>::call_nonvirtual_method(jmethodID id, Args&&... args) const
{
	return detail::api::call<Type>::nonvirtual_method(handle(), class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline auto object<ClassName, HandleType>::call_static_method(jmethodID id, Args&&... args)
{
	return detail::api::call<Type>::static_method(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Type, typename ...Args>
inline local_ref<object<ClassName, HandleType>> object<ClassName, HandleType>::new_object(jmethodID id, Args&&... args)
{
    return detail::api::call<Type>::template new_object<object>(class_object().handle(), id, std::forward<Args>(args)...);
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline Type object<ClassName, HandleType>::get_static_field()
{
	return detail::api::get_static_field<Type>(class_object().handle(), static_field_id<Name, Type>());
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline void object<ClassName, HandleType>::set_static_field(Type value)
{
	detail::api::set_static_field<Type>(class_object().handle(), static_field_id<Name, Type>(), value);
}

template <typename ClassName, typename HandleType>
inline jboolean object<ClassName, HandleType>::is_instance_of(ref<class_> cls) const
{
	return detail::env()->IsInstanceOf(handle(), cls.handle());
}

template <typename ClassName, typename HandleType>
inline local_ref<class_> object<ClassName, HandleType>::get_object_class() const noexcept
{
	return local_ref<class_>(detail::env()->GetObjectClass(handle()));
}

template <typename ClassName, typename HandleType>
inline ref<class_> object<ClassName, HandleType>::class_object()
{
//  static const global_ref<class_> cls(class_::find_class(meta::c_str_v<ClassName>));
	static const ref<class_> cls(global_ref<class_>(class_::find_class(meta::c_str_v<ClassName>)).release());
	return cls;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jmethodID object<ClassName, HandleType>::method_id()
{
	static const jmethodID id(class_object()->get_method_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jmethodID object<ClassName, HandleType>::static_method_id()
{
	static const jmethodID id(class_object()->get_static_method_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jfieldID object<ClassName, HandleType>::field_id()
{
	static const jfieldID id(class_object()->get_field_id<Name, Type>());
	return id;
}

template <typename ClassName, typename HandleType>
template <typename Name, typename Type>
inline jfieldID object<ClassName, HandleType>::static_field_id()
{
	static const jfieldID id(class_object()->get_static_field_id<Name, Type>());
	return id;
}

} // namespace java
} // namespace link
} // namespace scapix

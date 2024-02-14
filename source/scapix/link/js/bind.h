/*
	scapix/link/js/bind.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JS_BIND_H
#define SCAPIX_LINK_JS_BIND_H

#include <emscripten/bind.h>
#include <scapix/core/remove_function_qualifiers.h>
#include <scapix/link/js/convert.h>

namespace scapix {
namespace link {
namespace js {

// Clang bug:
// https://bugs.llvm.org/show_bug.cgi?id=42805

//template <typename Class, typename... Args>
//std::shared_ptr<Class> constructor(param_t<Args>... args)
//{
//	return std::make_shared<Class>(convert_cpp<Args>(std::forward<param_t<Args>>(args))...);
//}

template <typename Class, typename... Args>
struct constructor_impl
{
	static std::shared_ptr<Class> func(param_t<Args>... args)
	{
		return std::make_shared<Class>(convert_cpp<Args>(std::forward<param_t<Args>>(args))...);
	}
};

template <typename Class, typename... Args>
constexpr auto constructor = &constructor_impl<Class, Args...>::func;

template <typename Signature, Signature Function>
struct function_impl
{
	template <typename Type = remove_function_qualifiers_t<Signature>>
	struct select;

	template <typename R, typename... Args, typename Class>
	struct select<R(Class::*)(Args...)>
	{
		static param_t<R> func(Class& obj, param_t<Args>... args)
		{
			if constexpr (std::is_void_v<R>)
				return (obj.*Function)(convert_cpp<Args>(std::forward<param_t<Args>>(args))...);
			else
				return convert_js<param_t<R>>((obj.*Function)(convert_cpp<Args>(std::forward<param_t<Args>>(args))...));
		}
	};

	template <typename R, typename... Args>
	struct select<R(Args...)>
	{
		static param_t<R> func(param_t<Args>... args)
		{
			if constexpr (std::is_void_v<R>)
				return Function(convert_cpp<Args>(std::forward<param_t<Args>>(args))...);
			else
				return convert_js<param_t<R>>(Function(convert_cpp<Args>(std::forward<param_t<Args>>(args))...));
		}
	};
};

template <typename Signature, Signature Function>
constexpr auto function = &function_impl<Signature, Function>::template select<>::func;

template <typename T>
class wrapper : public emscripten::wrapper<T>
{
public:

	using emscripten::wrapper<T>::wrapper;

protected:

	template<typename R, typename... Args>
	R call(const char* name, Args&&... args) const
	{
		if constexpr (std::is_void_v<R>)
			return emscripten::wrapper<T>::template call<param_t<R>>(name, convert_js<param_t<Args>>(std::forward<Args>(args))...);
		else
			return convert_cpp<R>(emscripten::wrapper<T>::template call<param_t<R>>(name, convert_js<param_t<Args>>(std::forward<Args>(args))...));
	}

};

} // namespace js
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JS_BIND_H

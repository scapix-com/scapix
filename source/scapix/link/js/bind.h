/*
	scapix/link/js/bind.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JS_BIND_H
#define SCAPIX_LINK_JS_BIND_H

#include <emscripten/val.h>
#include <scapix/link/js/convert.h>

namespace scapix {
namespace link {
namespace js {

//template <typename T>
//using param = std::conditional_t<std::experimental::is_detected_v<has_convert_cpp_t<emscripten::val, T>>, emscripten::val, T>;

template <typename T>
using param = emscripten::val;

// Clang bug

// template <typename Class, typename... Args>
// std::shared_ptr<Class> constructor(param<Args>... args)
// {
// 	return std::make_shared<Class>(convert_cpp<Args>(args)...);
// }

template <typename Class, typename... Args>
struct constructor
{
	static std::shared_ptr<Class> func(param<Args>... args)
	{
		return std::make_shared<Class>(convert_cpp<Args>(args)...);
	}
};

template <typename Signature, Signature Function>
struct function
{
	template <typename = Signature>
	struct select;

	template <typename R, typename... Args>
	struct select<R(Args...)>
	{
		static param<R> func(param<Args>... args)
		{
			return convert_js<param<R>>(Function(convert_cpp<Args>(args)...));
		}
	};

	template <typename... Args>
	struct select<void(Args...)>
	{
		static void func(param<Args>... args)
		{
			Function(convert_cpp<Args>(args)...);
		}
	};

	template <typename R, typename Class, typename... Args>
	struct select<R(Class::*)(Args...)>
	{
		static param<R> func(Class& thiz, param<Args>... args)
		{
			return convert_js<param<R>>((thiz.*Function)(convert_cpp<Args>(args)...));
		}
	};

	template <typename Class, typename... Args>
	struct select<void(Class::*)(Args...)>
	{
		static void func(Class& thiz, param<Args>... args)
		{
			(thiz.*Function)(convert_cpp<Args>(args)...);
		}
	};

	template <typename R, typename Class, typename... Args>
	struct select<R(Class::*)(Args...)const>
	{
		static param<R> func(const Class& thiz, param<Args>... args)
		{
			return convert_js<param<R>>((thiz.*Function)(convert_cpp<Args>(args)...));
		}
	};

	template <typename Class, typename... Args>
	struct select<void(Class::*)(Args...)const>
	{
		static void func(const Class& thiz, param<Args>... args)
		{
			(thiz.*Function)(convert_cpp<Args>(args)...);
		}
	};
};

} // namespace js
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JS_BIND_H

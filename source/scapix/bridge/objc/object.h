//
//  scapix/bridge/objc/object.h
//  Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
//

#ifndef SCAPIX_BRIDGE_OBJC_OBJECT_H
#define SCAPIX_BRIDGE_OBJC_OBJECT_H

#include <memory>
#include <utility>
#include <cassert>
#include <concepts>
#include <scapix/core/type_traits.h>
#include <scapix/core/remove_function_qualifiers.h>
#include <CoreFoundation/CFBase.h>

namespace scapix {
namespace link::objc {

template <typename ObjC, typename Cpp, typename>
struct convert_shared;

} // namespace link::objc

namespace bridge::objc {

class object_base
{
protected:

	object_base() = default;
	object_base(const object_base&) {}
	object_base(object_base&& other) : wrapper(other.wrapper) { other.wrapper = nullptr; }
	object_base& operator =(const object_base&) { return *this; }
	object_base& operator =(object_base&& other) { object_base(std::move(other)).swap(*this); return *this; }

	~object_base()
	{
		if (wrapper)
			CFRelease(wrapper);
	}

private:

	void swap(object_base& other)
	{
		using std::swap;
		swap(wrapper, other.wrapper);
	}

	template <typename T>
	friend void attach(const std::shared_ptr<T>& cpp, CFTypeRef objc)
	{
		cpp->attach(objc, cpp);
	}

	void attach(CFTypeRef obj, std::shared_ptr<object_base> shared_this);

	template <typename ObjC, typename Cpp, typename>
	friend struct link::objc::convert_shared;

	template <typename Wrapper>
	Wrapper get_wrapper(std::shared_ptr<object_base> shared_this);

	// @class BridgeObject
	CFTypeRef wrapper = nullptr;

};

// to do: inheritance should be private

template <typename>
class object : public object_base
{
protected:

	object() = default;
	object(const object&) = default;
	object(object&&) = default;
	object& operator =(const object&) = default;
	object& operator =(object&&) = default;

};

} // namespace bridge::objc
} // namespace scapix

#if defined(__OBJC__) && __has_feature(objc_arc)

#include <scapix/link/objc/convert.h>
#import "BridgeObjectPrivate.h"

namespace scapix {
namespace bridge::objc {

inline void object_base::attach(CFTypeRef obj, std::shared_ptr<object_base> shared_this)
{
	assert(obj);
	assert(!wrapper);
	wrapper = obj;

	[(__bridge BridgeObject*)obj attachObject:shared_this];
}

// to do: with indirect inheritance support,
// wrappers should depend on actual object type.

template <typename Wrapper>
inline Wrapper object_base::get_wrapper(std::shared_ptr<object_base> shared_this)
{
	if (!wrapper)
	{
		Wrapper w = [std::remove_pointer_t<Wrapper> alloc];
		attach(CFBridgingRetain(w), shared_this);
		return w;
	}

	return (__bridge Wrapper)wrapper;
}

template <typename F>
struct init_impl;

template <typename ...Args>
struct init_impl<void(Args...)>
{
	template <typename T, typename Wrapper, typename ...ObjcArgs>
	static void init(Wrapper* wrapper, ObjcArgs... args)
	{
		attach(std::make_shared<T>(link::objc::convert_cpp<Args>(std::forward<ObjcArgs>(args))...), CFBridgingRetain(wrapper));
	}
};

template <typename T, typename F, typename Wrapper, typename ...ObjcArgs>
inline Wrapper* init(Wrapper* wrapper, ObjcArgs... args)
{
	init_impl<F>::template init<T>(wrapper, args...);
	return wrapper;
}

template <auto Func>
struct call_impl
{
	template <typename Type = remove_function_qualifiers_t<decltype(Func)>>
	struct select;

	template <typename R, typename ...Args, typename Class>
	struct select<R(Class::*)(Args...)>
	{
		template <typename ObjcRet, typename Wrapper, typename ...ObjcArgs>
		static ObjcRet call(Wrapper* wrapper, ObjcArgs... args)
		{
			decltype(auto) obj = link::objc::convert_cpp<Class>(wrapper);

			if constexpr (std::is_void_v<R>)
			{
				return (obj.*Func)(link::objc::convert_cpp<Args>(std::forward<ObjcArgs>(args))...);
			}
			else
			{
				return link::objc::convert_objc<ObjcRet>((obj.*Func)(link::objc::convert_cpp<Args>(std::forward<ObjcArgs>(args))...));
			}
		}
	};

	template <typename R, typename ...Args>
	struct select<R(*)(Args...)>
	{
		template <typename ObjcRet, typename ...ObjcArgs>
		static ObjcRet call(ObjcArgs... args)
		{
			if constexpr (std::is_void_v<R>)
			{
				return (*Func)(link::objc::convert_cpp<Args>(std::forward<ObjcArgs>(args))...);
			}
			else
			{
				return link::objc::convert_objc<ObjcRet>((*Func)(link::objc::convert_cpp<Args>(std::forward<ObjcArgs>(args))...));
			}
		}
	};
};

template <typename F, F Func, typename ObjcRet, typename ...ObjcArgs>
inline auto call(ObjcArgs... args)
{
	return call_impl<Func>::template select<>::template call<ObjcRet>(std::forward<ObjcArgs>(args)...);
}

} // namespace bridge::objc

namespace link::objc {

// only used to convert 'this'

template <std::convertible_to<BridgeObject*> Wrapper, std::derived_from<bridge::objc::object_base> Bridge>
struct convert<Wrapper, Bridge>
{
	static Bridge& cpp(Wrapper value)
	{
		return *static_cast<Bridge*>(value->shared.get());
	}
};

template <std::convertible_to<BridgeObject*> Wrapper, std::derived_from<bridge::objc::object_base> Bridge>
struct convert_shared<Wrapper, Bridge>
{
	static std::shared_ptr<Bridge> cpp(Wrapper value)
	{
		if (!value)
			return nullptr;

		return std::static_pointer_cast<Bridge>(value->shared);
	}

	static Wrapper objc(std::shared_ptr<Bridge> value)
	{
		if (!value)
			return nil;

		return value->template get_wrapper<Wrapper>(value);
	}
};

} // namespace link::objc
} // namespace scapix

#endif // __OBJC__
#endif // SCAPIX_BRIDGE_OBJC_OBJECT_H

/*
	scapix/link/cs/function.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_FUNCTION_H
#define SCAPIX_LINK_CS_FUNCTION_H

#include <scapix/core/tuple.h>
#include <scapix/core/remove_function_qualifiers.h>
#include <scapix/link/cs/convert.h>
#include <scapix/link/cs/exception.h>
#include <scapix/link/cs/ref.h>
#include <scapix/bridge/cs/object.h>

namespace scapix::link::cs {

template <typename ...Functions>
struct function_table
{
	const tuple<decltype(Functions::value)...> functions = { Functions::value... };
};

template <typename T, typename ...Args>
class constructor
{
private:

	static api::handle_type func(api::handle_type weak_wrapper, param_t<Args>... args)
	{
		return bridge::cs::init<T>(weak_wrapper, param_cpp<Args>(args)...);
	}

public:

	inline static constexpr auto value = &func;

};

// std::decay is a workaround for GCC bug (fixed in GCC 12):
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61355

template <typename Type, std::decay_t<Type> Func>
class function
{
private:

	template <typename Type_>
	struct impl;

	template <typename R, typename ...Args, typename Class>
	struct impl<R(Class::*)(Args...)>
	{
		static param_t<R> func(bridge::cs::object_base* thiz, param_t<Args>... args)
		{
			try
			{
				auto obj = static_cast<Class*>(thiz);

				if constexpr (std::is_void_v<R>)
				{
					return (obj->*Func)(param_cpp<Args>(args)...);
				}
				else
				{
					return param_cs<R>((obj->*Func)(param_cpp<Args>(args)...));
				}
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}

			if constexpr (!std::is_void_v<R>)
				return {};
		}
	};

	template <typename R, typename ...Args>
	struct impl<R(Args...)>
	{
		static param_t<R> func(param_t<Args>... args)
		{
			try
			{
				if constexpr (std::is_void_v<R>)
				{
					return Func(param_cpp<Args>(args)...);
				}
				else
				{
					return param_cs<R>(Func(param_cpp<Args>(args)...));
				}
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}

			if constexpr (!std::is_void_v<R>)
				return {};
		}
	};

	static void set_exception()
	{
		api::funcs.set_exception(new std::exception_ptr(std::current_exception()), true);
	}

	static void set_exception(api::handle_type e)
	{
		api::funcs.set_exception(e, false);
	}

public:

	static constexpr auto value = impl<remove_function_qualifiers_t<Type>>::func;

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_FUNCTION_H

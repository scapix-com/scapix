/*
	scapix/link/cs/function.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_FUNCTION_H
#define SCAPIX_LINK_CS_FUNCTION_H

#include <scapix/core/tuple.h>
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

	template <bool IsMember, typename Type_>
	struct select;

	template <typename R, typename ...Args>
	struct select<true, R(Args...)>
	{
		static param_t<R> func(bridge::cs::object_base* thiz, param_t<Args>... args)
		{
			try
			{
				using class_type = member_pointer_class_t<Type>;

				if constexpr (std::is_void_v<R>)
				{
					return (static_cast<class_type*>(thiz)->*Func)(param_cpp<Args>(args)...);
				}
				else
				{
					return param_cs<R>((static_cast<class_type*>(thiz)->*Func)(param_cpp<Args>(args)...));
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
	struct select<false, R(Args...)>
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

	inline static constexpr auto value = select<std::is_member_pointer_v<Type>, remove_function_qualifiers_t<member_pointer_type_t<std::remove_pointer_t<Type>>>>::func;

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_FUNCTION_H

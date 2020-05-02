/*
	scapix/link/cs/function.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_FUNCTION_H
#define SCAPIX_LINK_CS_FUNCTION_H

#include <scapix/core/cast.h>
#include <scapix/link/cs/convert.h>
#include <scapix/link/cs/exception.h>
#include <scapix/bridge/cs/object.h>

namespace scapix::link::cs {

template <typename ...Functions>
struct function_table
{
	const void* functions[sizeof...(Functions)] = { Functions()... };
};

template <typename T, typename ...Args>
class constructor
{
public:

	constexpr operator void* ()
	{
		return void_cast(func);
	}

private:

	static api::handle_type func(api::handle_type weak_wrapper, param_t<Args>... args)
	{
		return bridge::cs::init<T>(weak_wrapper, convert_cpp<Args>(args)...);
	}

};

// std::decay is a workaround for GCC:
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=82773

template <typename Type, std::decay_t<Type> Func>
class function
{
public:

	constexpr operator void* ()
	{
		return void_cast(select<Type>::func);
	}

private:

	static void set_exception()
	{
		api::funcs.set_exception(new std::exception_ptr(std::current_exception()), true);
	}

	static void set_exception(api::handle_type e)
	{
		api::funcs.set_exception(e, false);
	}

	template <typename Type_>
	struct select;

	template <typename Class, typename R, typename ...Args>
	struct select<R(Class::*)(Args...)>
	{
		static param_t<R> func(Class* thiz, param_t<Args>... args)
		{
			try
			{
				return convert_cs<param_t<R>>((thiz->*Func)(convert_cpp<Args>(args)...));
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}

			return {};
		}
	};

	template <typename Class, typename ...Args>
	struct select<void(Class::*)(Args...)>
	{
		static void func(Class* thiz, param_t<Args>... args)
		{
			try
			{
				(thiz->*Func)(convert_cpp<Args>(args)...);
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}
		}
	};

	template <typename Class, typename R, typename ...Args>
	struct select<R(Class::*)(Args...)const>
	{
		static param_t<R> func(Class* thiz, param_t<Args>... args)
		{
			try
			{
				return convert_cs<param_t<R>>((thiz->*Func)(convert_cpp<Args>(args)...));
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}

			return {};
		}
	};

	template <typename Class, typename ...Args>
	struct select<void(Class::*)(Args...)const>
	{
		static void func(Class* thiz, param_t<Args>... args)
		{
			try
			{
				(thiz->*Func)(convert_cpp<Args>(args)...);
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}
		}
	};

	template <typename R, typename ...Args>
	struct select<R(Args...)>
	{
		static param_t<R> func(param_t<Args>... args)
		{
			try
			{
				return convert_cs<param_t<R>>(Func(convert_cpp<Args>(args)...));
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}

			return {};
		}
	};

	template <typename ...Args>
	struct select<void(Args...)>
	{
		static void func(param_t<Args>... args)
		{
			try
			{
				Func(convert_cpp<Args>(args)...);
			}
			catch (cs::exception& e)
			{
				set_exception(e.release());
			}
			catch (...)
			{
				set_exception();
			}
		}
	};

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_FUNCTION_H

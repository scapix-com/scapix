/*
	scapix/jni/native_method.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_NATIVE_METHOD_H
#define SCAPIX_JNI_NATIVE_METHOD_H

#include <scapix/jni/fwd/native_method.h>
#include <scapix/core/tuple.h>
#include <scapix/core/remove_function_qualifiers.h>
#include <scapix/core/fixed_string.h>
#include <scapix/jni/convert.h>
#include <scapix/jni/signature.h>
#include <scapix/jni/vm_exception.h>
#include <scapix/jni/com/scapix/native_exception.h>
#include <scapix/jni/class.h>

namespace scapix::jni {

template <typename Jni, typename Cpp>
struct param;

template <primitive Jni, typename Cpp>
struct param<Jni, Cpp>
{
	using Cpv = std::remove_reference_t<Cpp>;

	static Jni jni(Cpp v) { return convert_jni<Jni>(v); }
	static Cpv cpp(Jni v) { return convert_cpp<Cpp>(v); }
};

template <typename T, typename Cpp>
struct param<ref<T>, Cpp>
{
	static jobject jni(Cpp&& v)
	{
		ref<T> res(std::move(v));

		assert(res.get_scope() == scope::local || res.get_scope() == scope::generic);

//      if (res.get_scope() == scope::global || res.get_scope() == scope::weak)
//          return local_ref<>(res).release();

		return res.release();
	}

	static decltype(auto) cpp(jobject v)
	{
		return ref<T>(v);
	}
};

template <typename Jni>
struct param_t;

template <typename Jni>
	requires (primitive<Jni> || std::is_void_v<Jni>)
struct param_t<Jni>
{
	using type = Jni;
};

template <typename T>
struct param_t<ref<T>>
{
	using type = jobject;
};

template <typename T>
using param_type = typename param_t<T>::type;

template <typename Func>
struct jni_native_method
{
	const char* name;
	const char* signature;
	Func fnPtr;

private:

	static void compile_check()
	{
		static_assert(sizeof(JNINativeMethod) == sizeof(jni_native_method), "jni_native_method should be ABI compatible with JNINativeMethod");
	}

};

// for apple clang 15.0.0.15000100
template <typename Func>
jni_native_method(const char*, const char*, Func) -> jni_native_method<Func>;

template <fixed_string ClassName, typename ...Methods>
class native_methods
{
public:

	static void register_()
	{
		class_::find_class(ClassName)->register_natives(reinterpret_cast<const JNINativeMethod*>(&methods), sizeof...(Methods));
	}

private:

	native_methods() = delete;

	static constexpr tuple methods = { Methods::template get<ClassName>()... };

};

// std::decay is a workaround for GCC bug (fixed in GCC 12):
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61355

template <fixed_string Name, typename JniType, typename Type, std::decay_t<Type> Method>
struct native_method
{
	template <fixed_string ClassName, typename JniType_, typename Type_>
	struct impl;

	template <fixed_string ClassName, typename JniR, typename ...JniArgs, typename R, typename ...Args, typename Class>
	struct impl<ClassName, JniR(JniArgs...), R(Class::*)(Args...)>
	{
		static param_type<JniR> func(JNIEnv* env, jobject thiz, param_type<JniArgs>... args)
		{
			detail::env_.ptr = env;

			try
			{
				decltype(auto) obj = convert_this<Class>(ref<object<ClassName>>(thiz));

				if constexpr (std::is_void_v<R>)
				{
					return (obj.*Method)(param<JniArgs, Args>::cpp(args)...);
				}
				else
				{
					return param<JniR, R>::jni((obj.*Method)(param<JniArgs, Args>::cpp(args)...));
				}
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				new_object<com::scapix::native_exception>()->throw_();
			}

			if constexpr (!std::is_void_v<R>)
				return {};
		}
	};

	template <fixed_string ClassName, typename JniR, typename ...JniArgs, typename R, typename ...Args>
	struct impl<ClassName, JniR(JniArgs...), R(Args...)>
	{
		static param_type<JniR> func(JNIEnv* env, jclass clazz, param_type<JniArgs>... args)
		{
			detail::env_.ptr = env;

			try
			{
				if constexpr (std::is_void_v<R>)
				{
					return Method(param<JniArgs, Args>::cpp(args)...);
				}
				else
				{
					return param<JniR, R>::jni(Method(param<JniArgs, Args>::cpp(args)...));
				}
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				new_object<com::scapix::native_exception>()->throw_();
			}

			if constexpr (!std::is_void_v<R>)
				return {};
		}
	};

	template <fixed_string ClassName>
	static constexpr auto get()
	{
		return jni_native_method
		{
			Name,
			signature_v<JniType>,
			impl<ClassName, JniType, remove_function_qualifiers_t<Type>>::func
		};
	}
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_NATIVE_METHOD_H

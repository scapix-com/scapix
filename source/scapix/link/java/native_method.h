/*
	scapix/link/java/native_method.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_NATIVE_METHOD_H
#define SCAPIX_LINK_JAVA_NATIVE_METHOD_H

#include <scapix/core/tuple.h>
#include <scapix/meta/string.h>
#include <scapix/link/java/convert.h>
#include <scapix/link/java/signature.h>
#include <scapix/link/java/vm_exception.h>
#include <scapix/link/java/detail/env.h>
#include <scapix/link/java/detail/native_exception.h>
#include <scapix/link/java/class.h>

namespace scapix {
namespace link {
namespace java {

template <typename Jni, typename Cpp>
struct param
{
	static_assert(is_primitive_v<Jni>);

	using Cpv = std::remove_reference_t<Cpp>;

	static Jni jni(Cpp v) { return convert_jni<Jni>(v); }
	static Cpv cpp(Jni v) { return convert_cpp<Cpp>(v); }
};

template <typename T, typename Cpp>
struct param<ref<T>, Cpp>
{
	static jobject jni(Cpp v)
	{
		auto res = convert_jni<ref<T>>(v);

		assert(res.get_scope() == scope::local || res.get_scope() == scope::generic);

//      if (res.get_scope() == scope::global || res.get_scope() == scope::weak)
//          return local_ref<>(res).release();

		return res.release();
	}

	static decltype(auto) cpp(jobject v)
	{
		return convert_cpp<Cpp>(ref<T>(static_cast<typename ref<T>::handle_type>(v)));
	}
};

template <typename Jni>
struct param_t
{
	static_assert(is_primitive_v<Jni> || std::is_void_v<Jni>);

	using type = Jni;
};

template <typename T>
struct param_t<ref<T>>
{
	using type = jobject;
};

template <typename T>
using param_type = typename param_t<T>::type;

template <typename Class>
inline decltype(auto) get_object(jobject thiz)
{
	return param<ref<class_name_t<Class>>, Class&>::cpp(thiz);
}

//template <typename T>
//inline std::remove_reference_t<T> initialized()
//{
//	return {};
//}
//
//template<>
//inline void initialized<void>()
//{
//}

template <typename Func>
struct jni_native_method
{
	char* name;
	char* signature;
	Func* fnPtr;

private:

	static void compile_check()
	{
		static_assert(sizeof(JNINativeMethod) == sizeof(jni_native_method), "jni_native_method should be ABI compatable with JNINativeMethod");
	}

};

template <typename ClassName, typename ...Methods>
class native_methods
{
public:

	static void register_()
	{
#ifdef SCAPIX_DEBUG
		for (auto& m : methods)
			std::cout << "native_method: " << m.name << " - " << m.signature << "\n";
#endif

		class_::find_class(meta::c_str_v<ClassName>)->register_natives(reinterpret_cast<const JNINativeMethod*>(&methods), sizeof...(Methods));
	}

private:

	native_methods() = delete;

	inline constexpr static tuple<jni_native_method<typename Methods::func_type>...> methods = { Methods::get()... };

};

// std::decay is a workaround for GCC:
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=82773

template <typename Name, typename JniType, typename Type, std::decay_t<Type> Method>
class native_method
{
private:

	template <typename JniType_, typename Type_>
	struct type;

	template <typename JniR, typename ...JniArgs, typename Class, typename R, typename ...Args>
	struct type<JniR(JniArgs...), R(Class::*)(Args...)>
	{
		static param_type<JniR> thunk(JNIEnv* env, jobject thiz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				return param<JniR, R>::jni((get_object<Class>(thiz).*Method)(param<JniArgs, Args>::cpp(args)...));
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}

			return {};
		}
	};

	template <typename ...JniArgs, typename Class, typename ...Args>
	struct type<void(JniArgs...), void(Class::*)(Args...)>
	{
		static void thunk(JNIEnv* env, jobject thiz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				(get_object<Class>(thiz).*Method)(param<JniArgs, Args>::cpp(args)...);
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}
		}
	};

	template <typename JniR, typename ...JniArgs, typename Class, typename R, typename ...Args>
	struct type<JniR(JniArgs...), R(Class::*)(Args...)const>
	{
		static param_type<JniR> thunk(JNIEnv* env, jobject thiz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				return param<JniR, R>::jni((get_object<Class>(thiz).*Method)(param<JniArgs, Args>::cpp(args)...));
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}

			return {};
		}
	};

	template <typename ...JniArgs, typename Class, typename ...Args>
	struct type<void(JniArgs...), void(Class::*)(Args...)const>
	{
		static void thunk(JNIEnv* env, jobject thiz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				(get_object<Class>(thiz).*Method)(param<JniArgs, Args>::cpp(args)...);
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}
		}
	};

	template <typename JniR, typename ...JniArgs, typename R, typename ...Args>
	struct type<JniR(JniArgs...), R(Args...)>
	{
		static param_type<JniR> thunk(JNIEnv* env, jclass clazz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				return param<JniR, R>::jni(Method(param<JniArgs, Args>::cpp(args)...));
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}

			return {};
		}
	};

	template <typename ...JniArgs, typename ...Args>
	struct type<void(JniArgs...), void(Args...)>
	{
		static void thunk(JNIEnv* env, jclass clazz, param_type<JniArgs>... args)
		{
			detail::env() = env;

			try
			{
				Method(param<JniArgs, Args>::cpp(args)...);
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}
		}
	};

public:

	using func_type = decltype(type<JniType, Type>::thunk);

	static constexpr jni_native_method<func_type> get()
	{
		return
		{
			const_cast<char*>(meta::c_str_v<Name>),
			const_cast<char*>(meta::c_str_v<signature_t<JniType>>),
			&type<JniType, Type>::thunk
		};
	}

};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_NATIVE_METHOD_H

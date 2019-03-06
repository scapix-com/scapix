/*
	scapix/link/java/native_method.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_NATIVE_METHOD_H
#define SCAPIX_LINK_JAVA_NATIVE_METHOD_H

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

    static Jni jni(Cpp v) { return convert<Jni>(v); }
    static Cpv cpp(Jni v) { return convert<Cpp>(v); }
};

template <typename T, typename Cpp>
struct param<ref<T>, Cpp>
{
    static jobject jni(Cpp v)
    {
        auto res = convert<ref<T>>(v);

        assert(res.get_scope() == scope::local || res.get_scope() == scope::generic);

//      if (res.get_scope() == scope::global || res.get_scope() == scope::weak)
//          return local_ref<>(res).release();

        return res.release();
    }

    static decltype(auto) cpp(jobject v)
    {
        return convert<Cpp>(ref<T>(static_cast<typename ref<T>::handle_type>(v)));
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

// constexpr cast from pointer to function to void* (not allowed by standard).
// Another workaround would be to use native_method in place of JNINativeMethod to avoid cast completely,
// and store std::tuple<Methods...> in native_methods instead of array (UB but would work).

template <typename Source>
constexpr inline void* void_cast(const Source& source)
{
#ifdef _MSC_VER
	// static_cast here is Microsoft extension, standard requires reinterpret_cast which ruins constexpr.
	return source;
#else
	// gcc/clang extension
	return __builtin_constant_p(reinterpret_cast<void*>(source)) ? (reinterpret_cast<void*>(source)) : (reinterpret_cast<void*>(source));
#endif
}

template <typename T>
inline std::remove_reference_t<T> initialized()
{
    return {};
}

template<>
inline void initialized<void>()
{
}

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

        class_::find_class(meta::c_str_v<ClassName>)->register_natives(methods);
	}

private:

	native_methods() = delete;

	constexpr static JNINativeMethod methods[sizeof...(Methods)] = { Methods()... };

};

template <typename ClassName, typename ...Methods>
constexpr JNINativeMethod native_methods<ClassName, Methods...>::methods[];

template <typename Name, typename JniType, typename Type, Type Method>
class native_method
{
public:

	constexpr operator JNINativeMethod()
	{
		return
		{
			const_cast<char*>(meta::c_str_v<Name>),
			const_cast<char*>(meta::c_str_v<signature_t<JniType>>),
			void_cast(type<JniType, Type>::thunk)
		};
	}

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
                if constexpr (std::is_void_v<R>)
                    return (param<ref<class_name_t<Class>>, Class>::cpp(thiz).*Method)(param<JniArgs, Args>::cpp(args)...);
                else
                    return param<JniR, R>::jni((param<ref<class_name_t<Class>>, Class>::cpp(thiz).*Method)(param<JniArgs, Args>::cpp(args)...));
			}
			catch (const vm_exception& e)
			{
				e.get()->throw_();
			}
			catch (...)
			{
				detail::native_exception::new_object()->throw_();
			}

			return initialized<param_type<JniR>>();
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
                if constexpr (std::is_void_v<R>)
                    return (param<ref<class_name_t<Class>>, Class>::cpp(thiz).*Method)(param<JniArgs, Args>::cpp(args)...);
                else
                    return param<JniR, R>::jni((param<ref<class_name_t<Class>>, Class>::cpp(thiz).*Method)(param<JniArgs, Args>::cpp(args)...));
            }
            catch (const vm_exception& e)
            {
                e.get()->throw_();
            }
            catch (...)
            {
                detail::native_exception::new_object()->throw_();
            }
            
            return initialized<param_type<JniR>>();
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
                if constexpr (std::is_void_v<R>)
                    return Method(param<JniArgs, Args>::cpp(args)...);
                else
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

            return initialized<param_type<JniR>>();
		}
	};

};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_NATIVE_METHOD_H

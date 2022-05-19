/*
	scapix/link/java/ref.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/type_traits.h>
#include <scapix/link/java/function.h>
#include <scapix/link/java/detail/api/ref.h>
#include <scapix/link/java/detail/util.h>

#ifndef SCAPIX_LINK_JAVA_REF_H
#define SCAPIX_LINK_JAVA_REF_H

#include <utility>
#include <experimental/type_traits>
#include <scapix/core/type_traits.h>
#include <scapix/meta/string.h>

namespace scapix::link::java {

#if 0 // __cpp_concepts >= 201907L

template <typename T>
concept Object =
	CopyConstructible<T> &&
	CopyAssignable<T> &&
	Destructible<T> &&
	requires
{
	typename T::class_name;
	typename T::handle_type;
	{ Object{T::handle_type()} };
};

//static_assert(Object<T>);

template <typename T>
concept Ref =
	CopyConstructible<T> &&
	CopyAssignable<T> &&
	Destructible<T> &&
	requires
{
	typename T::class_name;
	typename T::handle_type;
	{ Object{T::handle_type()} };
};

#endif // __cpp_concepts

template <typename T>
class redirector
{
public:

	redirector(const redirector&) = delete;
	redirector& operator = (const redirector&) = delete;

	redirector(redirector&&) = delete;
	redirector& operator = (redirector&&) = delete;

	template <typename Y>
	explicit redirector(Y&& v) : value(std::forward<Y>(v)) {}

	T* operator -> () && { return &value; }
	const T* operator -> () const && { return &value; }

	T& operator * () && { return value; }
	const T& operator * () const && { return value; }

//	operator T* () && { return &value; }
//	operator const T* () const && { return &value; }

private:

	detail::befriend<T, redirector> value;

};

namespace detail {

template <typename T>
struct cast;

template <typename T>
struct is_cast : std::false_type {};

template <typename T>
struct is_cast<cast<T>> : std::true_type {};

} // namespace detail

template <typename ClassName = SCAPIX_META_STRING("java/lang/Object"), typename HandleType = jobject>
class object;

template <typename T, typename = void>
class array;

template <typename T, typename ...Params>
struct generic_type {};

template <typename T, typename Extends = object<>>
struct generic;

template <typename T>
struct extends;

template <typename T>
struct super;

template <typename T>
struct element_type
{
	using type = T;
};

template <char... Chars>
struct element_type<meta::string<Chars...>>
{
	using type = object<meta::string<Chars...>>;
};

template <typename T>
struct element_type<T[]>
{
	using type = array<T>;
};

template <typename T, typename ...Params>
struct element_type<generic_type<T, Params...>>
{
	using type = typename element_type<T>::type;
};

template <typename T>
struct element_type<generic<T>>
{
	using type = typename element_type<T>::type;
};

template <typename ClassName, typename Signature, typename Name>
struct element_type<function<ClassName, Signature, Name>>
{
	using type = typename element_type<ClassName>::type;
};

template <typename T>
struct element_type<detail::cast<T>>
{
	using type = typename element_type<T>::type;
};

using scope = detail::api::scope;

// convert

template <typename Jni, typename Cpp, typename = void>
struct convert;

template <typename Jni, typename Cpp>
decltype(auto) convert_jni(Cpp&& cpp)
{
	return convert<remove_cvref_t<Jni>, remove_cvref_t<Cpp>>::jni(std::forward<Cpp>(cpp));
}

template <typename Cpp, typename Jni>
decltype(auto) convert_cpp(Jni&& jni)
{
	return convert<remove_cvref_t<Jni>, remove_cvref_t<Cpp>>::cpp(std::forward<Jni>(jni));
}

template<typename Jni, typename Cpp>
using has_convert_jni_t = decltype(std::declval<Jni>() = convert<remove_cvref_t<Jni>, remove_cvref_t<Cpp>>::jni(std::declval<Cpp>()));

template<typename Jni, typename Cpp>
using has_convert_cpp_t = decltype(std::declval<Cpp>() = convert<remove_cvref_t<Jni>, remove_cvref_t<Cpp>>::cpp(std::declval<Jni>()));

// is_ref

template <typename T = object<>, scope Scope = scope::generic>
class ref;

template<typename T>
struct is_ref : std::false_type {};

template<typename T, scope Scope>
struct is_ref<ref<T, Scope>> : std::true_type {};

template<typename T>
constexpr bool is_ref_v = is_ref<T>::value;

/*

Implementation for owning reference types: local_ref, global_ref, weak_ref.

*/

template <typename T, scope Scope>
class ref
{
public:

	using element_type = typename element_type<T>::type;
	using element_type_friend = detail::befriend<element_type, ref>;
	using handle_type = typename element_type_friend::handle_type;
	using class_name = typename element_type_friend::class_name;

	static_assert(!is_ref_v<T> && !is_ref_v<element_type>);

	template <typename Y>
	static constexpr bool convertible_from =
		std::is_same_v<class_name, SCAPIX_META_STRING("java/lang/Object")> ||
		std::is_base_of_v<element_type, typename ref<Y>::element_type> ||
		std::is_same_v<class_name, typename ref<Y>::class_name> ||
		detail::is_cast<Y>::value
	;

	constexpr scope get_scope() { return Scope; }

	ref(std::nullptr_t = nullptr) : object(nullptr) {}

	explicit ref(handle_type h) : object(h) {}

	ref(const ref& r) : object(new_ref(r)) {}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref(const ref<Y, S>& r) : object(new_ref(r)) {}

	ref(ref&& r) noexcept : object(r.release()) {}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref(ref<Y, S>&& r) : object(nullptr)
	{
		if (get_scope() == r.get_scope())
		{
			object = r.release();
		}
		else
		{
			object = new_ref(r);
		}
	}

	~ref()
	{
		if (handle())
			detail::api::ref<Scope>::delete_ref(handle());
	}

	ref& operator = (const ref& r)
	{
		ref(r).swap(*this);
		return *this;
	}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref& operator = (const ref<Y, S>& r)
	{
		ref(r).swap(*this);
		return *this;
	}

	ref& operator = (ref&& r)
	{
		ref(std::move(r)).swap(*this);
		return *this;
	}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref& operator = (ref<Y, S>&& r)
	{
		ref(std::move(r)).swap(*this);
		return *this;
	}

	redirector<element_type> operator -> () { return redirector<element_type>(handle()); }
	const redirector<element_type> operator -> () const { return redirector<element_type>(handle()); }
	element_type_friend operator * () { return handle(); }
	const element_type_friend operator * () const { return handle(); }

	template <typename Y = element_type, typename = std::enable_if_t<is_array_v<Y>>>
	auto operator [] (jsize i) { return get()[i]; }

	explicit operator bool() const { return handle() != nullptr; }
	element_type_friend get() const { return handle(); }
	handle_type handle() const { return static_cast<handle_type>(object); }

	void reset(handle_type h = nullptr)
	{
		ref(h).swap(*this);
	}

	handle_type release()
	{
		auto temp(handle());
		object = nullptr;
		return temp;
	}

	void swap (ref& r)
	{
		using std::swap;
		swap (object, r.object);
	}

private:

	template <typename Ref>
	static jobject new_ref(const Ref& r)
	{
		return detail::api::ref<Scope>::new_ref(r.handle());
	}

	jobject object;

};

/*

Implementation for (conceptually) non-owning reference type: ref.

In reality takes ownership when moved to, and does not take ownership when copied to.
This allows both zero overhead parameters and safe return of temporaries.

When owning semantics is required, use local_ref, global_ref or weak_ref explicitly.

*/

template <typename T>
class ref<T, scope::generic>
{
public:

	using element_type = typename element_type<T>::type;
	using element_type_friend = detail::befriend<element_type, ref>;
	using handle_type = typename element_type_friend::handle_type;
	using class_name = typename element_type_friend::class_name;

	static_assert(!is_ref_v<T> && !is_ref_v<element_type>);

	template <typename Y>
	static constexpr bool convertible_from =
		std::is_same_v<class_name, SCAPIX_META_STRING("java/lang/Object")> ||
		std::is_base_of_v<element_type, typename ref<Y>::element_type> ||
		std::is_same_v<class_name, typename ref<Y>::class_name> ||
		detail::is_cast<Y>::value
	;

	scope get_scope() { return scp; }

	ref(std::nullptr_t = nullptr) : object(nullptr), scp(scope::generic) {}

	// ref<> (aka ref<object<>, generic>) can be constructed from handle implicitly.
	// all other refs can only be constructed from handle explicitly.

	template <typename Ref = ref<T>, std::enable_if_t<std::is_same_v<Ref, ref<>>, bool> = false>
	ref(handle_type h) : object(h), scp(scope::generic) {}

	template <typename Ref = ref<T>, std::enable_if_t<!std::is_same_v<Ref, ref<>>, bool> = false>
	explicit ref(handle_type h) : object(h), scp(scope::generic) {}

	ref(const ref& r) : object(r.handle()), scp(scope::generic) {}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref(const ref<Y, S>& r) : object(r.handle()), scp(scope::generic) {}

	ref(ref&& r) noexcept : object(r.release()), scp(r.get_scope()) {}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref(ref<Y, S>&& r) : object(r.release()), scp(r.get_scope()) {}

	template <typename X, typename = std::enable_if_t<std::experimental::is_detected_v<has_convert_jni_t, ref, X>>>
	ref(X&& x)
		: ref(convert_jni<ref>(std::forward<X>(x)))
	{
	}

	template <typename X, typename = std::enable_if_t<std::experimental::is_detected_v<has_convert_cpp_t, ref, X> && !std::is_same_v<X, bool>>>
	operator X() const
	{
		return convert_cpp<X>(*this);
	}

	~ref()
	{
		if (handle())
		{
			if (scp == scope::local)
			{
				detail::api::ref<scope::local>::delete_ref(handle());
			}
			else if (scp == scope::global)
			{
				detail::api::ref<scope::global>::delete_ref(handle());
			}
			else if (scp == scope::weak)
			{
				detail::api::ref<scope::weak>::delete_ref(handle());
			}
		}
	}

	ref& operator = (const ref& r)
	{
		ref(r).swap(*this);
		return *this;
	}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref& operator = (const ref<Y, S>& r)
	{
		ref(r).swap(*this);
		return *this;
	}

	ref& operator = (ref&& r)
	{
		ref(std::move(r)).swap(*this);
		return *this;
	}

	template <typename Y, scope S, typename = std::enable_if_t<convertible_from<Y>>>
	ref& operator = (ref<Y, S>&& r)
	{
		ref(std::move(r)).swap(*this);
		return *this;
	}

	redirector<element_type> operator -> () { return redirector<element_type>(handle()); }
	const redirector<element_type> operator -> () const { return redirector<element_type>(handle()); }
	element_type_friend operator * () { return handle(); }
	const element_type_friend operator * () const { return handle(); }

	template <typename Y = element_type, typename = std::enable_if_t<is_object_array_v<Y>>>
	auto operator [] (jsize i) { return get()[i]; }

	explicit operator bool() const { return handle() != nullptr; }
	element_type_friend get() const { return handle(); }
	handle_type handle() const { return static_cast<handle_type>(object); }

	void reset(handle_type h = nullptr)
	{
		ref(h).swap(*this);
	}

	handle_type release()
	{
		auto temp(handle());
		object = nullptr;
		return temp;
	}

	void swap (ref& r)
	{
		using std::swap;
		swap (object, r.object);
		swap (scp, r.scp);
	}

private:

	jobject object;
	scope scp;

};

template <typename T = object<>>
using local_ref = ref<T, scope::local>;

template <typename T = object<>>
using global_ref = ref<T, scope::global>;

template <typename T = object<>>
using weak_ref = ref<T, scope::weak>;

template <typename T, scope Scope>
inline void swap(ref<T, Scope>& a, ref<T, Scope>& b)
{
	a.swap(b);
}

template <typename T1, scope S1, typename T2, scope S2>
inline bool operator ==(const ref<T1, S1>& a, const ref<T2, S2>& b)
{
	return is_same_object(a->native(), b->native());
}

template <typename T1, scope S1, typename T2, scope S2>
inline bool operator !=(const ref<T1, S1>& a, const ref<T2, S2>& b)
{
	return !(a == b);
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> static_pointer_cast(const ref<Y, Scope>& r)
{
	return ref<T, Scope>(ref<detail::cast<Y>, Scope>(r));
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> dynamic_pointer_cast(const ref<Y, Scope>& r)
{
	if (r->native().template is_instance_of<T>())
		return static_pointer_cast<T>(r);

	return ref<T, Scope>();
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> static_pointer_cast(ref<Y, Scope>&& r)
{
	return ref<T, Scope>(ref<detail::cast<Y>, Scope>(std::move(r)));
}

template <typename T, typename Y, scope Scope>
inline ref<T, Scope> dynamic_pointer_cast(ref<Y, Scope>&& r)
{
	if (r->native().template is_instance_of<T>())
		return static_pointer_cast<T>(std::move(r));

	return ref<T, Scope>();
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_REF_H

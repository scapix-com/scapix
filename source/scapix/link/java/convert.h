/*
	scapix/link/java/convert.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_CONVERT_H
#define SCAPIX_LINK_JAVA_CONVERT_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <experimental/type_traits>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/string.h>
#include <scapix/link/java/array.h>

namespace scapix {
namespace link {
namespace java {

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T1, typename T2, typename = void>
struct convert_impl;

template<typename To, typename From>
using has_convert_t = decltype(convert_impl<To, From>::convert(std::declval<From>()));

template <typename T1, typename T2, typename = void>
struct convert_shared_impl;

template<typename To, typename From>
using has_convert_shared_t = decltype(convert_shared_impl<To, From>::convert(std::declval<std::shared_ptr<From>>()));

template <typename T>
struct canonical
{
	using type = T;
};

template <typename T>
struct canonical<ref<generic<T>>>
{
	using type = ref<T>;
};

template <typename T>
using canonical_t = typename canonical<T>::type;

template <typename To, typename From>
decltype(auto) convert(From value)
{
	using to = canonical_t<remove_cvref_t<To>>;
	using from = canonical_t<remove_cvref_t<From>>;

	if constexpr (std::experimental::is_detected_v<has_convert_t, to, from>)
		return convert_impl<to, from>::convert(from(value));
	else
		return convert_impl<from, to>::convert(from(value));
}

template <typename Jni, typename Cpp>
struct convert_impl<Jni, Cpp, std::enable_if_t<is_primitive_v<Jni> && std::is_arithmetic_v<Cpp>>>
{
	static Jni convert(Cpp v)
	{
		return v;
	}

	template <typename J = Jni, typename = std::enable_if_t<!std::is_same_v<J, Cpp>>>
	static Cpp convert(Jni v)
	{
		return v;
	}
};

template <typename Jni, typename T>
struct convert_impl<Jni, std::shared_ptr<T>>
{
	static std::shared_ptr<T> convert(Jni value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Jni, T>)
			return convert_shared_impl<Jni, T>::convert(value);
		else
			return std::make_shared<T>(link::java::convert<T>(value));
	}

	static Jni convert(std::shared_ptr<T> value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Jni, T>)
			return convert_shared_impl<Jni, T>::convert(value);
		else
			return link::java::convert<Jni>(*value);
	}
};

template <>
struct convert_impl<ref<string::class_name>, std::string>
{
	using charset = SCAPIX_META_STRING("java/nio/charset/Charset");
	using standard_charsets = SCAPIX_META_STRING("java/nio/charset/StandardCharsets");
    
	static ref<charset> utf8_charset()
	{
//		static const global_ref<charset> ch = object<standard_charsets>::get_static_field<SCAPIX_META_STRING("UTF_8"), ref<charset>>();
		static const ref<charset> ch (global_ref<charset>(object<standard_charsets>::get_static_field<SCAPIX_META_STRING("UTF_8"), ref<charset>>()).release());
		return ch;
	}

	// C->Java conversion is fixed on Android 6 (https://android-review.googlesource.com/#/c/130121/)

	static std::string convert(ref<string> obj)
	{
//		return obj->chars<char>().data();
        
		auto bytes = obj->call_method<SCAPIX_META_STRING("getBytes"), ref<jbyte[]>(ref<charset>)>(utf8_charset());
		std::string str(bytes->size(), char());
		bytes->get_region(0, (jsize)str.size(), (jbyte*)str.data());
        
		return str;
	}

	static ref<string> convert(const std::string& str)
	{
//		return string::new_(str.data());

		auto bytes = array<jbyte>::new_((jsize)str.size());
		bytes->set_region(0, (jsize)str.size(), (const jbyte*)str.data());

		return string::new_object<void(ref<jbyte[]>, ref<charset>)>(bytes, utf8_charset());
	}
};

template <typename ClassName, typename CppPrimitive, typename JniPrimitive, typename MethodName>
struct convert_primitive_object
{
	static CppPrimitive convert(ref<ClassName> obj)
	{
		return obj->template call_method<MethodName, JniPrimitive()>();
	}

	static ref<ClassName> convert(CppPrimitive value)
	{
		return object<ClassName>::template call_static_method<SCAPIX_META_STRING("valueOf"), ref<ClassName>(JniPrimitive)>(value);
	}
};

using boolean_class_name = SCAPIX_META_STRING("java/lang/Boolean");
template <> struct convert_impl<ref<boolean_class_name>, bool> :
convert_primitive_object<boolean_class_name, bool, jboolean, SCAPIX_META_STRING("booleanValue")> {};

using byte_class_name = SCAPIX_META_STRING("java/lang/Byte");
template <> struct convert_impl<ref<byte_class_name>, std::int8_t> :
convert_primitive_object<byte_class_name, std::int8_t, jbyte, SCAPIX_META_STRING("byteValue")> {};

using short_class_name = SCAPIX_META_STRING("java/lang/Short");
template <> struct convert_impl<ref<short_class_name>, std::int16_t> :
convert_primitive_object<short_class_name, std::int16_t, jshort, SCAPIX_META_STRING("shortValue")> {};

using integer_class_name = SCAPIX_META_STRING("java/lang/Integer");
template <> struct convert_impl<ref<integer_class_name>, std::int32_t> :
convert_primitive_object<integer_class_name, std::int32_t, jint, SCAPIX_META_STRING("intValue")> {};

using long_class_name = SCAPIX_META_STRING("java/lang/Long");
template <> struct convert_impl<ref<long_class_name>, std::int64_t> :
convert_primitive_object<long_class_name, std::int64_t, jlong, SCAPIX_META_STRING("longValue")> {};

using float_class_name = SCAPIX_META_STRING("java/lang/Float");
template <> struct convert_impl<ref<float_class_name>, float> :
convert_primitive_object<float_class_name, float, jfloat, SCAPIX_META_STRING("floatValue")> {};

using double_class_name = SCAPIX_META_STRING("java/lang/Double");
template <> struct convert_impl<ref<double_class_name>, double> :
convert_primitive_object<double_class_name, double, jdouble, SCAPIX_META_STRING("doubleValue")> {};

template <typename J, typename T, typename A>
struct convert_impl<ref<array<J>>, std::vector<T, A>, std::enable_if_t<is_primitive_v<J>>>
{
	static_assert(sizeof(J) == sizeof(T));

	static std::vector<T, A> convert(ref<array<J>> a)
	{
		std::vector<T, A> v(a->size());
		a->get_region(0, v.size(), v.data());
		return v;
	}

	static ref<array<J>> convert(const std::vector<T, A>& v)
	{
		auto a = array<J>::new_(v.size());
		a->set_region(0, v.size(), v.data());
		return a;
	}
};

template <typename J, typename T, typename A>
struct convert_impl<ref<array<J>>, std::vector<T, A>, std::enable_if_t<!is_primitive_v<J>>>
{
	static std::vector<T, A> convert(ref<array<J>> a)
	{
		std::vector<T, A> v(a->size());

		for (jsize i = 0; i < (jsize)v.size(); ++i)
			v[i] = link::java::convert<T>(a[i].get());

		return v;
	}

	static ref<array<J>> convert(const std::vector<T, A>& v)
	{
		auto a = array<J>::new_((jsize)v.size());

		for (jsize i = 0; i < (jsize)v.size(); ++i)
			a[i] = link::java::convert<ref<J>>(v[i]);

		return a;
	}
};

using treemap_class_name = SCAPIX_META_STRING("java/util/TreeMap");

template <typename JK, typename JV, typename K, typename V, typename C, typename A>
struct convert_impl<ref<generic_type<treemap_class_name, JK, JV>>, std::map<K, V, C, A>>
{
	static std::map<K, V, C, A> convert(ref<treemap_class_name> tm)
	{
		std::map<K, V, C, A> m;

		auto set = tm->call_method<SCAPIX_META_STRING("entrySet"), ref<SCAPIX_META_STRING("java/util/Set")>()>();
		auto i = set->call_method<SCAPIX_META_STRING("iterator"), ref<SCAPIX_META_STRING("java/util/Iterator")>()>();

		while (i->call_method<SCAPIX_META_STRING("hasNext"), jboolean()>())
		{
			auto entry = i->call_method<SCAPIX_META_STRING("next"), ref<generic<SCAPIX_META_STRING("java/util/Map$Entry")>>()>();

			m.emplace_hint
			(
				m.end(),
				link::java::convert<K>(entry->call_method<SCAPIX_META_STRING("getKey"), ref<generic<JK>>()>()),
				link::java::convert<V>(entry->call_method<SCAPIX_META_STRING("getValue"), ref<generic<JV>>()>())
			);
		}

		return m;
	}

	static ref<treemap_class_name> convert(const std::map<K, V, C, A>& m)
	{
		auto tm = object<treemap_class_name>::new_object<void()>();

		for (auto& i : m)
			tm->call_method<SCAPIX_META_STRING("put"), ref<generic<JV>>(ref<generic<JK>>, ref<generic<JV>>)>(link::java::convert<ref<JK>>(i.first), link::java::convert<ref<JV>>(i.second));

		return tm;
	}
};

using treeset_class_name = SCAPIX_META_STRING("java/util/TreeSet");
    
template <typename JE, typename K, typename C, typename A>
struct convert_impl<ref<generic_type<treeset_class_name, JE>>, std::set<K, C, A>>
{
	static std::set<K, C, A> convert(ref<treeset_class_name> set)
	{
		std::set<K, C, A> m;

		auto i = set->call_method<SCAPIX_META_STRING("iterator"), ref<SCAPIX_META_STRING("java/util/Iterator")>()>();

		while (i->call_method<SCAPIX_META_STRING("hasNext"), jboolean()>())
		{
			m.emplace_hint
			(
				m.end(),
				link::java::convert<K>(i->call_method<SCAPIX_META_STRING("next"), ref<generic<JE>>()>())
			);
		}
        
		return m;
	}

	static ref<treeset_class_name> convert(const std::set<K, C, A>& s)
	{
		auto set = object<treeset_class_name>::new_object<void()>();

		for (auto& i : s)
			set->call_method<SCAPIX_META_STRING("add"), jboolean(ref<generic<JE>>)>(link::java::convert<ref<JE>>(i));
        
		return set;
	}
};

using hashmap_class_name = SCAPIX_META_STRING("java/util/HashMap");
    
template <typename JK, typename JV, typename K, typename T, typename H, typename KE, typename A>
struct convert_impl<ref<generic_type<hashmap_class_name, JK, JV>>, std::unordered_map<K, T, H, KE, A>>
{
	static std::unordered_map<K, T, H, KE, A> convert(ref<hashmap_class_name> tm)
	{
		std::unordered_map<K, T, H, KE, A> m;

		auto set = tm->call_method<SCAPIX_META_STRING("entrySet"), ref<SCAPIX_META_STRING("java/util/Set")>()>();
		auto i = set->call_method<SCAPIX_META_STRING("iterator"), ref<SCAPIX_META_STRING("java/util/Iterator")>()>();

		while (i->call_method<SCAPIX_META_STRING("hasNext"), jboolean()>())
		{
			auto entry = i->call_method<SCAPIX_META_STRING("next"), ref<generic<SCAPIX_META_STRING("java/util/Map$Entry")>>()>();

			m.emplace_hint
			(
				m.end(),
				link::java::convert<K>(entry->call_method<SCAPIX_META_STRING("getKey"), ref<generic<JK>>()>()),
				link::java::convert<T>(entry->call_method<SCAPIX_META_STRING("getValue"), ref<generic<JV>>()>())
			);
		}

		return m;
	}
    
	static ref<hashmap_class_name> convert(const std::unordered_map<K, T, H, KE, A>& m)
	{
		auto tm = object<hashmap_class_name>::new_object<void()>();

		for (auto& i : m)
			tm->call_method<SCAPIX_META_STRING("put"), ref<generic<JV>>(ref<generic<JK>>, ref<generic<JV>>)>(link::java::convert<ref<JK>>(i.first), link::java::convert<ref<JV>>(i.second));

		return tm;
	}
};

using hashset_class_name = SCAPIX_META_STRING("java/util/HashSet");
    
template <typename JE, typename K, typename H, typename KE, typename A>
struct convert_impl<ref<generic_type<hashset_class_name, JE>>, std::unordered_set<K, H, KE, A>>
{
	static std::unordered_set<K, H, KE, A> convert(ref<hashset_class_name> set)
	{
		std::unordered_set<K, H, KE, A> m;
        
		auto i = set->call_method<SCAPIX_META_STRING("iterator"), ref<SCAPIX_META_STRING("java/util/Iterator")>()>();
        
		while (i->call_method<SCAPIX_META_STRING("hasNext"), jboolean()>())
		{
			m.emplace_hint
			(
				m.end(),
				link::java::convert<K>(i->call_method<SCAPIX_META_STRING("next"), ref<generic<JE>>()>())
			);
		}
        
		return m;
	}
    
	static ref<hashset_class_name> convert(const std::unordered_set<K, H, KE, A>& s)
	{
		auto set = object<hashset_class_name>::new_object<void()>();
        
		for (auto& i : s)
			set->call_method<SCAPIX_META_STRING("add"), jboolean(ref<generic<JE>>)>(link::java::convert<ref<JE>>(i));
        
		return set;
	}
};

template <typename ClassName, typename JniR, typename ...JniArgs, typename Name, typename R, typename ...Args>
struct convert_impl<ref<function<ClassName, JniR(JniArgs...), Name>>, std::function<R(Args...)>>
{
	static std::function<R(Args...)> convert(ref<function<ClassName, JniR(JniArgs...), Name>> i)
	{
		return std::function<R(Args...)>([i = global_ref<function<ClassName, JniR(JniArgs...), Name>>(i)](Args... args)
		{
			if constexpr (std::is_void_v<R>)
				return i->template call_method<Name, JniR(JniArgs...)>(link::java::convert<JniArgs>(args)...);
			else
				return link::java::convert<R>(i->template call_method<Name, JniR(JniArgs...)>(link::java::convert<JniArgs>(args)...));
		});
	}

//    static ref<function<ClassName, JniR(JniArgs...), Name>> convert(const std::function<R(Args...)>& f)
//    {
//        auto c = std::make_shared<callback<J, R, Args...>>(f);
//        return c.get_ref();
//    }
};

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_CONVERT_H

/*
	scapix/jni/convert.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JNI_CONVERT_H
#define SCAPIX_JNI_CONVERT_H

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <experimental/type_traits>
#include <scapix/core/meta/for_each.h>
#include <scapix/jni/ref.h>
#include <scapix/jni/string.h>
#include <scapix/jni/array.h>
#include <scapix/jni/function.h>
#include <scapix/jni/struct.h>
#include <scapix/jni/cast.h>
#include <scapix/jni/com/scapix/function.h>

namespace scapix::jni {

template <typename Jni, typename Cpp, typename = void>
struct convert_shared;

template<typename Jni, typename Cpp>
using has_convert_shared_t = decltype(convert_shared<Jni, Cpp>::jni(std::declval<std::shared_ptr<Cpp>>()));

template <primitive Jni, typename Cpp>
struct convert<Jni, Cpp, std::enable_if_t<std::is_arithmetic_v<Cpp>>>
{
	static_assert((std::is_integral_v<Jni> && std::is_integral_v<Cpp> && sizeof(Jni) == sizeof(Cpp)) || std::is_same_v<Jni, Cpp>);

	static Cpp cpp(Jni v)
	{
		return v;
	}

	static Jni jni(Cpp v)
	{
		return v;
	}
};

template <typename Jni, typename Cpp>
struct convert<Jni, Cpp, std::enable_if_t<std::is_enum_v<Cpp>>>
{
	static_assert(std::is_integral_v<Jni> && sizeof(Jni) == sizeof(Cpp));

	static Cpp cpp(Jni value)
	{
		return static_cast<Cpp>(value);
	}

	static Jni jni(Cpp value)
	{
		return static_cast<Jni>(value);
	}
};

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<std::is_enum_v<Cpp>>>
{
	using underlying = std::underlying_type_t<Cpp>;

	static Cpp cpp(ref<J> value)
	{
		return static_cast<Cpp>(convert_cpp<underlying>(value));
	}

	static ref<J> jni(Cpp value)
	{
		return convert_jni<ref<J>>(static_cast<underlying>(value));
	}
};

template <typename Jni, typename T>
struct convert<Jni, std::shared_ptr<T>>
{
	static std::shared_ptr<T> cpp(Jni value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Jni, T>)
			return convert_shared<Jni, T>::cpp(value);
		else
			return std::make_shared<T>(convert_cpp<T>(value));
	}

	static Jni jni(std::shared_ptr<T> value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Jni, T>)
			return convert_shared<Jni, T>::jni(value);
		else
			return convert_jni<Jni>(*value);
	}
};

struct convert_string
{
	using charset = object<"java/nio/charset/Charset">;
	using standard_charsets = object<"java/nio/charset/StandardCharsets">;

	static ref<charset> utf8_charset()
	{
		static const static_global_ref<charset> ch = standard_charsets::get_static_field<"UTF_8", ref<charset>>();
		return ch;
	}

	// C->Java conversion is fixed on Android 6 (https://android-review.googlesource.com/#/c/130121/)

	static std::string cpp(ref<string> obj)
	{
//		std::string str(obj->length<char>(), char());
//		obj->get_region(0, static_cast<jsize>(str.size()), str.data());
//		return str;

		auto bytes = obj->call_method<"getBytes", ref<jbyte[]>(ref<charset>)>(utf8_charset());
		std::string str(bytes->size(), char());
		bytes->get_region(0, static_cast<jsize>(str.size()), (jbyte*)str.data());

		return str;
	}

	static ref<string> jni(std::string_view str)
	{
//		return new_object<string>(str.data());

		auto bytes = new_object<array<jbyte>>(static_cast<jsize>(str.size()));
		bytes->set_region(0, static_cast<jsize>(str.size()), (const jbyte*)str.data());

		return new_object<string, void(ref<jbyte[]>, ref<charset>)>(bytes, utf8_charset());
	}
};

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<is_convertible_object_v<J, string> && std::is_convertible_v<Cpp, std::string> && !is_ref_v<Cpp>>> : convert_string
{
};

template <typename Object, typename CppPrimitive, typename JniPrimitive, fixed_string MethodName>
struct convert_primitive_object
{
	static CppPrimitive cpp(ref<Object> obj)
	{
		return obj->template call_method<MethodName, JniPrimitive()>();
	}

	static ref<Object> jni(CppPrimitive value)
	{
		return Object::template call_static_method<"valueOf", ref<Object>(JniPrimitive)>(value);
	}
};

using java_lang_boolean = object<"java/lang/Boolean">;
template <typename J> struct convert<ref<J>, bool, std::enable_if_t<is_convertible_object_v<J, java_lang_boolean>>> :
convert_primitive_object<java_lang_boolean, bool, jboolean, "booleanValue"> {};

using java_lang_byte = object<"java/lang/Byte">;

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<is_convertible_object_v<J, java_lang_byte> && std::is_integral_v<Cpp> && sizeof(Cpp) == sizeof(std::int8_t)>> :
convert_primitive_object<java_lang_byte, Cpp, jbyte, "byteValue"> {};

using java_lang_short = object<"java/lang/Short">;

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<is_convertible_object_v<J, java_lang_short> && std::is_integral_v<Cpp> && sizeof(Cpp) == sizeof(std::int16_t)>> :
convert_primitive_object<java_lang_short, Cpp, jshort, "shortValue"> {};

using java_lang_integer = object<"java/lang/Integer">;

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<is_convertible_object_v<J, java_lang_integer> && std::is_integral_v<Cpp> && sizeof(Cpp) == sizeof(std::int32_t)>> :
convert_primitive_object<java_lang_integer, Cpp, jint, "intValue"> {};

using java_lang_long = object<"java/lang/Long">;

template <typename J, typename Cpp>
struct convert<ref<J>, Cpp, std::enable_if_t<is_convertible_object_v<J, java_lang_long> && std::is_integral_v<Cpp> && sizeof(Cpp) == sizeof(std::int64_t)>> :
convert_primitive_object<java_lang_long, Cpp, jlong, "longValue"> {};

using java_lang_float = object<"java/lang/Float">;
template <typename J> struct convert<ref<J>, float, std::enable_if_t<is_convertible_object_v<J, java_lang_float>>> :
convert_primitive_object<java_lang_float, float, jfloat, "floatValue"> {};

using java_lang_double = object<"java/lang/Double">;
template <typename J> struct convert<ref<J>, double, std::enable_if_t<is_convertible_object_v<J, java_lang_double>>> :
convert_primitive_object<java_lang_double, double, jdouble, "doubleValue"> {};

template <primitive J, typename T, typename A>
struct convert<ref<array<J>>, std::vector<T, A>>
{
	static_assert(sizeof(J) == sizeof(T));

	static std::vector<T, A> cpp(ref<array<J>> a)
	{
		const auto size = a->size();
		std::vector<T, A> v(size);
		a->get_region(0, size, reinterpret_cast<J*>(v.data()));
		return v;
	}

	static ref<array<J>> jni(const std::vector<T, A>& v)
	{
		const auto size = static_cast<jsize>(v.size());
		auto a = new_object<array<J>>(size);
		a->set_region(0, size, reinterpret_cast<const J*>(v.data()));
		return a;
	}
};

template <typename A>
struct convert<ref<array<jboolean>>, std::vector<bool, A>>
{
	static std::vector<bool, A> cpp(ref<array<jboolean>> a)
	{
		auto e = a->const_elements<lock::critical>();
		return std::vector<bool, A>(e.begin(), e.end());
	}

	static ref<array<jboolean>> jni(const std::vector<bool, A>& v)
	{
		const auto size = static_cast<jsize>(v.size());
		auto a = new_object<array<jboolean>>(size);
		auto e = a->elements<lock::critical>(size);
		std::copy(v.begin(), v.end(), e.begin());
		return a;
	}
};

template <reference J, typename T, typename A>
struct convert<ref<array<J>>, std::vector<T, A>>
{
	static std::vector<T, A> cpp(ref<array<J>> a)
	{
		const auto size = a->size();
		std::vector<T, A> v(size);

		for (jsize i = 0; i < size; ++i)
			v[i] = convert_cpp<T>(a[i].get());

		return v;
	}

	static ref<array<J>> jni(const std::vector<T, A>& v)
	{
		const auto size = static_cast<jsize>(v.size());
		auto a = new_object<array<J>>(size);

		for (jsize i = 0; i < size; ++i)
			a[i] = convert_jni<ref<J>>(v[i]);

		return a;
	}
};

using java_util_treemap = object<"java/util/TreeMap">;

template <typename JK, typename JV, typename K, typename V, typename C, typename A>
struct convert<ref<generic_type<java_util_treemap, JK, JV>>, std::map<K, V, C, A>>
{
	static std::map<K, V, C, A> cpp(ref<java_util_treemap> tm)
	{
		std::map<K, V, C, A> m;

		auto set = tm->call_method<"entrySet", ref<object<"java/util/Set">>()>();
		auto i = set->call_method<"iterator", ref<object<"java/util/Iterator">>()>();

		while (i->call_method<"hasNext", jboolean()>())
		{
			auto entry = i->call_method<"next", ref<generic<object<"java/util/Map$Entry">>>()>();

			m.emplace_hint
			(
				m.end(),
				convert_cpp<K>(entry->call_method<"getKey", ref<generic<JK>>()>()),
				convert_cpp<V>(entry->call_method<"getValue", ref<generic<JV>>()>())
			);
		}

		return m;
	}

	static ref<java_util_treemap> jni(const std::map<K, V, C, A>& m)
	{
		auto tm = new_object<java_util_treemap, void()>();

		for (auto& i : m)
			tm->call_method<"put", ref<generic<JV>>(ref<generic<JK>>, ref<generic<JV>>)>(convert_jni<ref<JK>>(i.first), convert_jni<ref<JV>>(i.second));

		return tm;
	}
};

// currently used only manually, not in generated bindings

using java_util_map = object<"java/util/Map">;

template <typename JK, typename JV, typename K, typename V, typename C, typename A>
struct convert<ref<generic_type<java_util_map, JK, JV>>, std::map<K, V, C, A>>
{
	static std::map<K, V, C, A> cpp(ref<java_util_map> tm)
	{
		std::map<K, V, C, A> m;

		auto set = tm->call_method<"entrySet", ref<object<"java/util/Set">>()>();
		auto i = set->call_method<"iterator", ref<object<"java/util/Iterator">>()>();

		while (i->call_method<"hasNext", jboolean()>())
		{
			auto entry = i->call_method<"next", ref<generic<object<"java/util/Map$Entry">>>()>();

			m.emplace_hint
			(
				m.end(),
				convert_cpp<K>(entry->call_method<"getKey", ref<generic<JK>>()>()),
				convert_cpp<V>(entry->call_method<"getValue", ref<generic<JV>>()>())
			);
		}

		return m;
	}

	static ref<java_util_map> jni(const std::map<K, V, C, A>& m)
	{
		auto tm = new_object<java_util_treemap, void()>();

		for (auto& i : m)
			tm->call_method<"put", ref<generic<JV>>(ref<generic<JK>>, ref<generic<JV>>)>(convert_jni<ref<JK>>(i.first), convert_jni<ref<JV>>(i.second));

		return static_pointer_cast<java_util_map>(std::move(tm));
	}
};

using java_util_treeset = object<"java/util/TreeSet">;

template <typename JE, typename K, typename C, typename A>
struct convert<ref<generic_type<java_util_treeset, JE>>, std::set<K, C, A>>
{
	static std::set<K, C, A> cpp(ref<java_util_treeset> set)
	{
		std::set<K, C, A> m;

		auto i = set->call_method<"iterator", ref<object<"java/util/Iterator">>()>();

		while (i->call_method<"hasNext", jboolean()>())
		{
			m.emplace_hint
			(
				m.end(),
				convert_cpp<K>(i->call_method<"next", ref<generic<JE>>()>())
			);
		}

		return m;
	}

	static ref<java_util_treeset> jni(const std::set<K, C, A>& s)
	{
		auto set = new_object<java_util_treeset, void()>();

		for (auto& i : s)
			set->call_method<"add", jboolean(ref<generic<JE>>)>(convert_jni<ref<JE>>(i));

		return set;
	}
};

using java_util_hashmap = object<"java/util/HashMap">;

template <typename JK, typename JV, typename K, typename T, typename H, typename KE, typename A>
struct convert<ref<generic_type<java_util_hashmap, JK, JV>>, std::unordered_map<K, T, H, KE, A>>
{
	static std::unordered_map<K, T, H, KE, A> cpp(ref<java_util_hashmap> tm)
	{
		std::unordered_map<K, T, H, KE, A> m;

		auto set = tm->call_method<"entrySet", ref<object<"java/util/Set">>()>();
		auto i = set->call_method<"iterator", ref<object<"java/util/Iterator">>()>();

		while (i->call_method<"hasNext", jboolean()>())
		{
			auto entry = i->call_method<"next", ref<generic<object<"java/util/Map$Entry">>>()>();

			m.emplace_hint
			(
				m.end(),
				convert_cpp<K>(entry->call_method<"getKey", ref<generic<JK>>()>()),
				convert_cpp<T>(entry->call_method<"getValue", ref<generic<JV>>()>())
			);
		}

		return m;
	}

	static ref<java_util_hashmap> jni(const std::unordered_map<K, T, H, KE, A>& m)
	{
		auto tm = new_object<java_util_hashmap, void()>();

		for (auto& i : m)
			tm->call_method<"put", ref<generic<JV>>(ref<generic<JK>>, ref<generic<JV>>)>(convert_jni<ref<JK>>(i.first), convert_jni<ref<JV>>(i.second));

		return tm;
	}
};

using java_util_hashset = object<"java/util/HashSet">;

template <typename JE, typename K, typename H, typename KE, typename A>
struct convert<ref<generic_type<java_util_hashset, JE>>, std::unordered_set<K, H, KE, A>>
{
	static std::unordered_set<K, H, KE, A> cpp(ref<java_util_hashset> set)
	{
		std::unordered_set<K, H, KE, A> m;

		auto i = set->call_method<"iterator", ref<object<"java/util/Iterator">>()>();

		while (i->call_method<"hasNext", jboolean()>())
		{
			m.emplace_hint
			(
				m.end(),
				convert_cpp<K>(i->call_method<"next", ref<generic<JE>>()>())
			);
		}

		return m;
	}

	static ref<java_util_hashset> jni(const std::unordered_set<K, H, KE, A>& s)
	{
		auto set = new_object<java_util_hashset, void()>();

		for (auto& i : s)
			set->call_method<"add", jboolean(ref<generic<JE>>)>(convert_jni<ref<JE>>(i));

		return set;
	}
};

template <fixed_string ClassName, typename JniR, typename ...JniArgs, fixed_string Name, typename R, typename ...Args>
struct convert<ref<function<ClassName, JniR(JniArgs...), Name>>, std::function<R(Args...)>>
{
	static std::function<R(Args...)> cpp(ref<function<ClassName, JniR(JniArgs...), Name>> i)
	{
		if (!i)
			return nullptr;

		return std::function<R(Args...)>([i = global_ref<function<ClassName, JniR(JniArgs...), Name>>(i)](Args&&... args)
		{
			if constexpr (std::is_void_v<R>)
				return i->call(convert_jni<JniArgs>(std::forward<Args>(args))...);
			else
				return convert_cpp<R>(i->call(convert_jni<JniArgs>(std::forward<Args>(args))...));
		});
	}

	static ref<function<ClassName, JniR(JniArgs...), Name>> jni(std::function<R(Args...)> f)
	{
		if (!f)
			return nullptr;

		return new_object<com::scapix::function_impl<ClassName, JniR(JniArgs...), Name>>(std::move(f));
	}
};

template <typename Jni, typename Struct>
struct convert<Jni, Struct, std::enable_if_t<is_struct_v<Struct>>>
{
	using struct_object = object<struct_<Struct>::class_name>;
	using fields = typename struct_<Struct>::fields;

	static ref<struct_object> jni(const Struct& value)
	{
		auto obj = new_object<struct_object, void()>();

		meta::for_each<fields>([&](auto f)
		{
			using field = decltype(f);
			obj->template set_field<field::name, typename field::type>(convert_jni<typename field::type>(value.*field::ptr));
		});

		return obj;
	}

	static Struct cpp(ref<struct_object> value)
	{
		Struct obj;

		meta::for_each<fields>([&](auto f)
		{
			using field = decltype(f);
			obj.*field::ptr = convert_cpp<decltype(obj.*field::ptr)>(value->template get_field<field::name, typename field::type>());
		});

		return obj;
	}
};

} // namespace scapix::jni

#endif // SCAPIX_JNI_CONVERT_H

/*
	scapix/link/cs/convert.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_CONVERT_H
#define SCAPIX_LINK_CS_CONVERT_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <experimental/type_traits>
#include <scapix/core/tuple.h>
#include <scapix/meta/for_each.h>
#include <scapix/meta/transform.h>
#include <scapix/link/cs/type_traits.h>
#include <scapix/link/cs/api.h>
#include <scapix/link/cs/ref.h>

namespace scapix::link::cs {

using api::param;
using api::param_t;
using api::cs_type_t;

template <typename Cs, typename Cpp, typename = void>
struct convert;

template <typename Cs, typename Cpp>
decltype(auto) convert_cs(Cpp&& cpp)
{
	return convert<remove_cvref_t<Cs>, remove_cvref_t<Cpp>>::cs(std::forward<Cpp>(cpp));
}

template <typename Cpp, typename Cs>
decltype(auto) convert_cpp(Cs&& cs)
{
	return convert<remove_cvref_t<Cs>, remove_cvref_t<Cpp>>::cpp(std::forward<Cs>(cs));
}

template <typename Cpp>
decltype(auto) param_cs(Cpp&& cpp)
{
	return param<remove_cvref_t<Cpp>>::cs(convert_cs<cs_type_t<Cpp>>(std::forward<Cpp>(cpp)));
}

template <typename Cpp>
decltype(auto) param_cpp(param_t<Cpp> cs)
{
	return convert_cpp<Cpp>(param<remove_cvref_t<Cpp>>::cpp(cs));
}

template <typename T>
struct convert<T, T>
{
	static T cpp(T value)
	{
		return value;
	}

	static T cs(T value)
	{
		return value;
	}
};

template <typename Cs, typename Cpp, typename = void>
struct convert_shared;

template <typename Cpp>
using has_convert_shared_t = decltype(convert_shared<ref<>, Cpp>::cs(std::declval<std::shared_ptr<Cpp>>()));

template <typename T>
struct convert<ref<>, std::shared_ptr<T>>
{
	static std::shared_ptr<T> cpp(ref<>&& value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, T>)
			return convert_shared<ref<>, T>::cpp(value);
		else
			return std::make_shared<T>(convert_cpp<T>(value));
	}

	static ref<> cs(std::shared_ptr<T> value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, T>)
			return convert_shared<ref<>, T>::cs(value);
		else
			return convert_cs<ref<>>(*value);
	}
};

template <>
struct convert<ref<>, std::string>
{
	static std::string cpp(ref<>&& value)
	{
		std::string str;
		api::set_string(value, &str);
		return str;
	}

	static ref<> cs(std::string_view value)
	{
		return api::create_string(value.data(), static_cast<api::size_type>(value.size()));
	}
};

template <typename T, typename A>
struct convert<ref<>, std::vector<T, A>, std::enable_if_t<is_simple_v<T>>>
{
	using cs_type = std::conditional_t<std::is_same_v<T, bool>, char, T>;

	static std::vector<T, A> cpp(ref<>&& value)
	{
		auto data = static_cast<const cs_type*>(api::funcs.addr_of_pinned_object(value.get()));
		return std::vector<T, A>(data, data + api::funcs.get_array_size(value.get()));
	}

	static ref<> cs(const std::vector<T, A>& value)
	{
		auto a = api::create_struct_array<param_t<T>>(static_cast<api::size_type>(value.size()));
		auto data = static_cast<cs_type*>(api::funcs.addr_of_pinned_object(a.get()));
		std::copy(value.begin(), value.end(), data);
		return a;
	}
};

template <typename T, typename A>
struct convert<ref<>, std::vector<T, A>, std::enable_if_t<!is_simple_v<T>>>
{
	using cs_value = param_t<T>;

	static std::vector<T, A> cpp(ref<>&& value)
	{
		auto size = api::funcs.get_array_size(value.get());

		std::vector<T, A> vec;
		vec.reserve(size);

		for (auto i = 0; i < size; ++i)
		{
			vec.push_back(param_cpp<T>(api::funcs.get_object_array_element(value.get(), i)));
		}

		return vec;
	}

	static ref<> cs(const std::vector<T, A>& value)
	{
		auto size = value.size();
		auto arr = ref<>(api::array<T>::global.create(static_cast<api::size_type>(size)));

		for (auto i = 0; i < size; ++i)
		{
			api::funcs.set_object_array_element(arr.get(), i, param_cs(value[i]));
		}

		return arr;
	}
};

template <typename K, typename T, typename C, typename A>
struct convert<ref<>, std::map<K, T, C, A>>
{
	using cs_key = param_t<K>;
	using cs_value = param_t<T>;

	static std::map<K, T, C, A> cpp(ref<>&& value)
	{
		std::map<K, T, C, A> map;

		api::sorted_dictionary<K, T>::global.iterate(value.get(), &map, [](cs_key key, cs_value value, api::handle_type data)
		{
			auto& map = *(std::map<K, T, C, A>*)data;
			map.emplace(param_cpp<K>(key), param_cpp<T>(value));
		});

		return map;
	}

	static ref<> cs(const std::map<K, T, C, A>& value)
	{
		auto dict = ref<>(api::sorted_dictionary<K, T>::global.create());

		for (const auto& element : value)
			api::sorted_dictionary<K, T>::global.add(dict.get(), param_cs(element.first), param_cs(element.second));

		return dict;
	}
};

template <typename K, typename C, typename A>
struct convert<ref<>, std::set<K, C, A>>
{
	using cs_key = param_t<K>;

	static std::set<K, C, A> cpp(ref<>&& value)
	{
		std::set<K, C, A> set;

		api::sorted_set<K>::global.iterate(value.get(), &set, [](cs_key key, api::handle_type data)
		{
			auto& set = *(std::set<K, C, A>*)data;
			set.emplace(param_cpp<K>(key));
		});

		return set;
	}

	static ref<> cs(const std::set<K, C, A>& value)
	{
		auto set = ref<>(api::sorted_set<K>::global.create());

		for (const auto& element : value)
			api::sorted_set<K>::global.add(set.get(), param_cs(element));

		return set;
	}
};

template <typename K, typename V, typename H, typename P, typename A>
struct convert<ref<>, std::unordered_map<K, V, H, P, A>>
{
	using cs_key = param_t<K>;
	using cs_value = param_t<V>;

	static std::unordered_map<K, V, H, P, A> cpp(ref<>&& value)
	{
		std::unordered_map<K, V, H, P, A> map;

		api::dictionary<K, V>::global.iterate(value.get(), &map, [](cs_key key, cs_value value, api::handle_type data)
		{
			auto& map = *(std::unordered_map<K, V, H, P, A>*)data;
			map.emplace(param_cpp<K>(key), param_cpp<V>(value));
		});

		return map;
	}

	static ref<> cs(const std::unordered_map<K, V, H, P, A>& value)
	{
		auto dict = ref<>(api::dictionary<K, V>::global.create());

		for (const auto& element : value)
			api::dictionary<K, V>::global.add(dict.get(), param_cs(element.first), param_cs(element.second));

		return dict;
	}
};

template <typename V, typename H, typename P, typename A>
struct convert<ref<>, std::unordered_set<V, H, P, A>>
{
	using cs_value = param_t<V>;

	static std::unordered_set<V, H, P, A> cpp(ref<>&& value)
	{
		std::unordered_set<V, H, P, A> set;

		api::hash_set<V>::global.iterate(value.get(), &set, [](cs_value key, api::handle_type data)
		{
			auto& set = *(std::unordered_set<V, H, P, A>*)data;
			set.emplace(param_cpp<V>(key));
		});

		return set;
	}

	static ref<> cs(const std::unordered_set<V, H, P, A>& value)
	{
		auto set = ref<>(api::hash_set<V>::global.create());

		for (const auto& element : value)
			api::hash_set<V>::global.add(set.get(), param_cs(element));

		return set;
	}
};

template <typename R, typename ...Args>
struct convert<ref<>, std::function<R(Args...)>>
{
	static std::function<R(Args...)> cpp(ref<>&& delegate)
	{
		auto func = reinterpret_cast<param_t<R>(*)(param_t<Args>...)>(api::funcs.get_func(delegate.get()));

		return [delegate = std::move(delegate), func = std::move(func)](Args... args)
		{
			if constexpr (std::is_void_v<R>)
			{
				func(param_cs(std::forward<Args>(args))...);
				api::check_exception();
			}
			else
			{
				auto ret = func(param_cs(std::forward<Args>(args))...);
				api::check_exception();
				return param_cpp<R>(std::move(ret));
			}
		};
	}

	//static ref<> cs(std::function<R(Args...)>&& value)
	//{
	//}
};

template <typename Cs, typename Struct>
struct convert<Cs, Struct, std::enable_if_t<is_struct_v<Struct>>>
{
	using fields = typename struct_<Struct>::fields;

	static Cs cs(const Struct& value)
	{
		Cs obj;

		meta::for_each<meta::iota_c<tuple_size_v<Cs>>>([&](auto index)
		{
			using cs_type = decltype(get<index>(obj));
			get<index>(obj) = convert_cs<cs_type>(value.*get<index>(fields::values));
		});

		return obj;
	}

	static Struct cpp(Cs&& value)
	{
		Struct obj;

		meta::for_each<meta::iota_c<tuple_size_v<Cs>>>([&](auto index)
		{
			using cpp_type = decltype(obj.*get<index>(fields::values));
			obj.*get<index>(fields::values) = convert_cpp<cpp_type>(get<index>(std::move(value)));
		});

		return obj;
	}
};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_CONVERT_H

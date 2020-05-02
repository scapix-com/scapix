/*
	scapix/link/cs/convert.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
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
#include <scapix/link/cs/type_traits.h>
#include <scapix/link/cs/ref.h>

namespace scapix {
namespace link {
namespace cs {

using api::param_t;
	
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

template<typename Cs, typename Cpp>
using has_convert_cs_t = decltype(std::declval<Cs>() = convert<remove_cvref_t<Cs>, remove_cvref_t<Cpp>>::cs(std::declval<Cpp>()));

template<typename Cs, typename Cpp>
using has_convert_cpp_t = decltype(std::declval<Cpp>() = convert<remove_cvref_t<Cs>, remove_cvref_t<Cpp>>::cpp(std::declval<Cs>()));

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

template <typename Cs, typename Cpp>
struct convert<Cs, Cpp, std::enable_if_t<std::is_enum_v<Cpp>>>
{
	static_assert(std::is_integral_v<Cs> && sizeof(Cs) == sizeof(Cpp));

	static Cpp cpp(Cs value)
	{
		return static_cast<Cpp>(value);
	}

	static Cs cs(Cpp value)
	{
		return static_cast<Cs>(value);
	}
};

template <typename Cs, typename Cpp, typename = void>
struct convert_shared;

template<typename Cs, typename Cpp>
using has_convert_shared_t = decltype(convert_shared<Cs, Cpp>::cs(std::declval<std::shared_ptr<Cpp>>()));

template <typename Cs, typename T>
struct convert<Cs, std::shared_ptr<T>>
{
	static std::shared_ptr<T> cpp(Cs value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Cs, T>)
			return convert_shared<Cs, T>::cpp(value);
		else
			return std::make_shared<T>(convert_cpp<T>(value));
	}

	static Cs cs(std::shared_ptr<T> value)
	{
		if constexpr (std::experimental::is_detected_v<has_convert_shared_t, Cs, T>)
			return convert_shared<Cs, T>::cs(value);
		else
			return convert_cs<Cs>(*value);
	}
};

template <>
struct convert<api::handle_type, std::string>
{
	static std::string cpp(api::handle_type value)
	{
		std::string str;
		api::funcs.set_string(value, &str);
		return str;
	}

	static api::handle_type cs(std::string_view value)
	{
		return api::funcs.create_string(value.data(), static_cast<api::size_type>(value.size()));
	}
};

template <typename T, typename A>
struct convert<api::handle_type, std::vector<T, A>, std::enable_if_t<is_simple_v<T>>>
{
	static std::vector<T, A> cpp(api::handle_type value)
	{
		auto data = static_cast<const T*>(api::funcs.addr_of_pinned_object(value));
		return std::vector<T, A>(data, data + api::funcs.get_array_size(value));
	}

	static api::handle_type cs(const std::vector<T, A>& value)
	{
		auto a = api::create_struct_array<T>(static_cast<api::size_type>(value.size()));
		auto data = static_cast<T*>(api::funcs.addr_of_pinned_object(a));
		std::copy(value.data(), value.data() + value.size(), data);
		return a;
	}
};

template <typename T, typename A>
struct convert<api::handle_type, std::vector<T, A>, std::enable_if_t<!is_simple_v<T>>>
{
	using cs_value = param_t<T>;

	static std::vector<T, A> cpp(api::handle_type value)
	{
		auto size = api::funcs.get_array_size(value);

		std::vector<T, A> vec;
		vec.reserve(size);

		for (auto i = 0; i < size; ++i)
		{
			vec.push_back(convert_cpp<T>(api::funcs.get_object_array_element(value, i)));
		}

		return vec;
	}

	static api::handle_type cs(const std::vector<T, A>& value)
	{
		auto size = value.size();
		auto arr = api::array<T>::global.create(static_cast<api::size_type>(size));

		for (auto i = 0; i < size; ++i)
		{
			api::funcs.set_object_array_element(arr, i, convert_cs<cs_value>(value[i]));
		}

		return arr;
	}
};

template <typename K, typename T, typename C, typename A>
struct convert<api::handle_type, std::map<K, T, C, A>>
{
	using cs_key = param_t<K>;
	using cs_value = param_t<T>;

	static std::map<K, T, C, A> cpp(api::handle_type value)
	{
		std::map<K, T, C, A> map;

		api::sorted_dictionary<K, T>::global.iterate(value, &map, [](cs_key key, cs_value value, api::handle_type data)
		{
			auto& map = *(std::map<K, T, C, A>*)data;
			map.emplace(convert_cpp<K>(key), convert_cpp<T>(value));
		});

		return map;
	}

	static api::handle_type cs(const std::map<K, T, C, A>& value)
	{
		auto dict = api::sorted_dictionary<K, T>::global.create();

		for (const auto& element : value)
			api::sorted_dictionary<K, T>::global.add(dict, convert_cs<cs_key>(element.first), convert_cs<cs_value>(element.second));

		return dict;
	}
};

template <typename K, typename C, typename A>
struct convert<api::handle_type, std::set<K, C, A>>
{
	using cs_key = param_t<K>;

	static std::set<K, C, A> cpp(api::handle_type value)
	{
		std::set<K, C, A> set;

		api::sorted_set<K>::global.iterate(value, &set, [](cs_key key, api::handle_type data)
		{
			auto& set = *(std::set<K, C, A>*)data;
			set.emplace(convert_cpp<K>(key));
		});

		return set;
	}

	static api::handle_type cs(const std::set<K, C, A>& value)
	{
		auto set = api::sorted_set<K>::global.create();

		for (const auto& element : value)
			api::sorted_set<K>::global.add(set, convert_cs<cs_key>(element));

		return set;
	}
};

template <typename K, typename V, typename H, typename P, typename A>
struct convert<api::handle_type, std::unordered_map<K, V, H, P, A>>
{
	using cs_key = param_t<K>;
	using cs_value = param_t<V>;

	static std::unordered_map<K, V, H, P, A> cpp(api::handle_type value)
	{
		std::unordered_map<K, V, H, P, A> map;

		api::dictionary<K, V>::global.iterate(value, &map, [](cs_key key, cs_value value, api::handle_type data)
		{
			auto& map = *(std::unordered_map<K, V, H, P, A>*)data;
			map.emplace(convert_cpp<K>(key), convert_cpp<V>(value));
		});

		return map;
	}

	static api::handle_type cs(const std::unordered_map<K, V, H, P, A>& value)
	{
		auto dict = api::dictionary<K, V>::global.create();

		for (const auto& element : value)
			api::dictionary<K, V>::global.add(dict, convert_cs<cs_key>(element.first), convert_cs<cs_value>(element.second));

		return dict;
	}
};

template <typename V, typename H, typename P, typename A>
struct convert<api::handle_type, std::unordered_set<V, H, P, A>>
{
	using cs_value = param_t<V>;

	static std::unordered_set<V, H, P, A> cpp(api::handle_type value)
	{
		std::unordered_set<V, H, P, A> set;

		api::hash_set<V>::global.iterate(value, &set, [](cs_value key, api::handle_type data)
		{
			auto& set = *(std::unordered_set<V, H, P, A>*)data;
			set.emplace(convert_cpp<V>(key));
		});

		return set;
	}

	static api::handle_type cs(const std::unordered_set<V, H, P, A>& value)
	{
		auto set = api::hash_set<V>::global.create();

		for (const auto& element : value)
			api::hash_set<V>::global.add(set, convert_cs<cs_value>(element));

		return set;
	}
};

template <typename R, typename ...Args>
struct convert<api::handle_type, std::function<R(Args...)>>
{
	static std::function<R(Args...)> cpp(api::handle_type delegate)
	{
		return [delegate = ref(delegate), func = reinterpret_cast<R(*)(param_t<Args>...)>(api::funcs.get_func(delegate))](Args... args)
		{
			if constexpr (std::is_void_v<R>)
			{
				func(convert_cs<param_t<Args>>(args)...);
				api::check_exception();
			}
			else
			{
				auto ret = func(convert_cs<param_t<Args>>(args)...);
				api::check_exception();
				return convert_cpp<R>(ret);
			}
		};
	}

	//static api::handle_type cs(std::function<R(Args...)>&& value)
	//{
	//}
};

} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_CS_CONVERT_H

/*
	scapix/link/cs/api.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_API_H
#define SCAPIX_LINK_CS_API_H

#include <cstring>
#include <string>
#include <memory>
#include <scapix/meta/for_each.h>
#include <scapix/meta/transform.h>
#include <scapix/meta/iota.h>
#include <scapix/core/type_traits.h>
#include <scapix/link/cs/type_traits.h>
#include <scapix/link/cs/api_base.h>
#include <scapix/link/cs/ref.h>
#include <scapix/link/cs/struct.h>

#ifdef __GNUC__
#include <cxxabi.h>
#endif

#if defined _WIN32 || defined __CYGWIN__
	#define SCAPIX_EXPORT __declspec(dllexport)
#elif defined __GNUC__
	#define SCAPIX_EXPORT __attribute__ ((visibility ("default")))
#else
	#define SCAPIX_EXPORT
#endif

namespace scapix::bridge::cs { class object_base; }

namespace scapix {
namespace link {
namespace cs {
namespace api {

template <typename Cpp, typename = void>
struct cs_type
{
	using type = ref<>;
};

template <typename Cpp>
using cs_type_t = typename cs_type<remove_cvref_t<Cpp>>::type;

template <typename Cpp>
using cpp_struct_t = meta::transform<member_pointer_type_t, typename struct_<Cpp>::fields::type>;

template <typename Cpp>
using cs_struct_t = meta::transform<cs_type_t, cpp_struct_t<Cpp>>;

template <typename Cpp>
struct cs_type<Cpp, std::enable_if_t<is_simple_v<Cpp> || std::is_void_v<Cpp>>>
{
	using type = Cpp;
};

template <typename Cpp>
struct cs_type<Cpp, std::enable_if_t<is_struct_v<Cpp>>>
{
	using type = cs_struct_t<Cpp>;
};

template <typename T, typename = void>
struct param
{
	using type = api::handle_type;

	static type cs(ref<> v)
	{
		return v.release();
	}

	static ref<> cpp(type v)
	{
		return ref<>(v);
	}
};

template <typename T>
using param_t = typename param<remove_cvref_t<T>>::type;

template <typename Cpp>
using wire_struct_t = meta::transform<param_t, cpp_struct_t<Cpp>>;

template <>
struct param<void>
{
	using type = void;
};

template <typename T>
struct param<T, std::enable_if_t<std::is_arithmetic_v<T>>>
{
	using type = T;

	static type cs(T v)
	{
		return v;
	}

	static T cpp(type v)
	{
		return v;
	}
};

template <typename T>
struct param<T, std::enable_if_t<std::is_enum_v<T>>>
{
	using type = std::underlying_type_t<T>;

	static type cs(T v)
	{
		return static_cast<type>(v);
	}

	static T cpp(type v)
	{
		return static_cast<T>(v);
	}
};

template <typename T>
struct param<T, std::enable_if_t<is_struct_v<T>>>
{
	using type = wire_struct_t<T>;
	using cs_type = cs_struct_t<T>;

	static type cs(const cs_type& value)
	{
		type obj;

		meta::for_each<meta::iota_c<tuple_size_v<type>>>([&](auto index)
		{
			using cpp_type = tuple_element_t<index, cpp_struct_t<T>>;
			get<index>(obj) = param<cpp_type>::cs(get<index>(value));
		});

		return obj;
	}

	static cs_type cpp(const type& value)
	{
		cs_type obj;

		meta::for_each<meta::iota_c<tuple_size_v<type>>>([&](auto index)
		{
			using cpp_type = tuple_element_t<index, cpp_struct_t<T>>;
			get<index>(obj) = param<cpp_type>::cpp(get<index>(value));
		});

		return obj;
	}
};

inline const bridge::cs::object_base* get_cpp(ref<> r)
{
	return static_cast<const bridge::cs::object_base*>(funcs.get_cpp(r.get()));
}

inline ref<> create_string(const char* data, size_type size)
{
	return ref<>(funcs.create_string(data, size));
}

inline void set_string(ref<> r, std::string* str)
{
	funcs.set_string(r.get(), str);
}

struct cpp_api
{
	void(SCAPIX_CALL* SetString)(const char* s, std::string* str) = set_string;
	bool(SCAPIX_CALL* Finalize)(bridge::cs::object_base* obj) = finalize;
	handle_type(SCAPIX_CALL* GetExceptionMessage)(handle_type exception) = get_exception_message;
	void(SCAPIX_CALL* DeleteException)(handle_type exception) = delete_exception;
	void(SCAPIX_CALL* SetException)(handle_type exception, bool cpp) = set_exception;

	static void set_string(const char* s, std::string* str)
	{
		*str = s;
	}

	static bool finalize(bridge::cs::object_base* obj);

	static handle_type get_exception_message(handle_type exception)
	{
		try
		{
			std::rethrow_exception(*static_cast<const std::exception_ptr*>(exception));
		}
		catch (const std::exception& e)
		{
			auto str = e.what();
			return funcs.create_string(str, static_cast<api::size_type>(std::strlen(str)));
		}
		catch (...)
		{
			#ifdef __GNUC__
			auto str = abi::__cxa_current_exception_type()->name();
			#else
			auto str = "unknown";
			#endif

			return funcs.create_string(str, static_cast<api::size_type>(std::strlen(str)));
		}
	}

	static void delete_exception(handle_type exception)
	{
		delete static_cast<const std::exception_ptr*>(exception);
	}

	static void set_exception(handle_type exception, bool cpp)
	{
		current_exception = exception;
		exception_is_cpp = cpp;
	}

	thread_local inline static handle_type current_exception;
	thread_local inline static bool exception_is_cpp;
};

void throw_exception();

inline void check_exception()
{
	if (cpp_api::current_exception) /*[[unlikely]]*/
		throw_exception();
}

inline constexpr cpp_api cpp_funcs;

inline const cpp_api* init(const cs_api* funcs)
{
	api::funcs = *funcs;
	return &cpp_funcs;
}

template <typename T>
struct class_info
{
	inline static class_cs_api cs_api;
};

template <typename T, typename tag = void>
struct global
{
	inline static constexpr T instance{};
};

template <typename T, typename Api>
void register_class(const char* class_name)
{
	class_info<T>::cs_api = *funcs.register_class(class_name, &global<Api>::instance);
}

template <typename T>
ref<> create_struct_array(size_type size);

template <> inline ref<> create_struct_array<bool>         (size_type size) { return ref<>(api::funcs.create_bool_array(size)); }
template <> inline ref<> create_struct_array<std::int8_t>  (size_type size) { return ref<>(api::funcs.create_sbyte_array(size)); }
template <> inline ref<> create_struct_array<std::int16_t> (size_type size) { return ref<>(api::funcs.create_short_array(size)); }
template <> inline ref<> create_struct_array<std::int32_t> (size_type size) { return ref<>(api::funcs.create_int_array(size)); }
template <> inline ref<> create_struct_array<std::int64_t> (size_type size) { return ref<>(api::funcs.create_long_array(size)); }
template <> inline ref<> create_struct_array<std::uint8_t> (size_type size) { return ref<>(api::funcs.create_byte_array(size)); }
template <> inline ref<> create_struct_array<std::uint16_t>(size_type size) { return ref<>(api::funcs.create_ushort_array(size)); }
template <> inline ref<> create_struct_array<std::uint32_t>(size_type size) { return ref<>(api::funcs.create_uint_array(size)); }
template <> inline ref<> create_struct_array<std::uint64_t>(size_type size) { return ref<>(api::funcs.create_ulong_array(size)); }
template <> inline ref<> create_struct_array<float>        (size_type size) { return ref<>(api::funcs.create_float_array(size)); }
template <> inline ref<> create_struct_array<double>       (size_type size) { return ref<>(api::funcs.create_double_array(size)); }

// https://developercommunity.visualstudio.com/content/problem/973593/c-class-with-inline-static-member-of-the-same-type.html

template <typename T>
struct array
{
	handle_type(SCAPIX_CALL* create)(size_type size);

	static array global;
};

template <typename T>
array<T> array<T>::global;

template <typename K, typename V>
struct sorted_dictionary
{
	handle_type(SCAPIX_CALL* create)();
	void(SCAPIX_CALL* add)(handle_type dict, param_t<K> key, param_t<V> value);
	void(SCAPIX_CALL* iterate)(handle_type dict, handle_type data, void(*callback)(param_t<K> key, param_t<V> value, handle_type data));

	static sorted_dictionary global;
};

template <typename K, typename V>
sorted_dictionary<K, V> sorted_dictionary<K, V>::global;

template <typename K>
struct sorted_set
{
	handle_type(SCAPIX_CALL* create)();
	void(SCAPIX_CALL* add)(handle_type dict, param_t<K> key);
	void(SCAPIX_CALL* iterate)(handle_type dict, handle_type data, void(*callback)(param_t<K> key, handle_type data));

	static sorted_set global;
};

template <typename K>
sorted_set<K> sorted_set<K>::global;

template <typename K, typename V>
struct dictionary
{
	handle_type(SCAPIX_CALL* create)();
	void(SCAPIX_CALL* add)(handle_type dict, param_t<K> key, param_t<V> value);
	void(SCAPIX_CALL* iterate)(handle_type dict, handle_type data, void(*callback)(param_t<K> key, param_t<V> value, handle_type data));

	static dictionary global;
};

template <typename K, typename V>
dictionary<K, V> dictionary<K, V>::global;

template <typename K>
struct hash_set
{
	handle_type(SCAPIX_CALL* create)();
	void(SCAPIX_CALL* add)(handle_type dict, param_t<K> key);
	void(SCAPIX_CALL* iterate)(handle_type dict, handle_type data, void(*callback)(param_t<K> key, handle_type data));

	static hash_set global;
};

template <typename K>
hash_set<K> hash_set<K>::global;

} // namespace api
} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_CS_API_H

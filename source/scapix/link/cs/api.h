/*
	scapix/link/cs/api.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_API_H
#define SCAPIX_LINK_CS_API_H

#include <string>
#include <memory>
#include <scapix/core/type_traits.h>
#include <scapix/link/cs/ref_type.h>
#include <scapix/link/cs/type_traits.h>

#define SCAPIX_EXPORT __declspec(dllexport)
#define SCAPIX_CALL __stdcall

namespace scapix::bridge::cs { class object_base; }

// generated function
void scapix_cs_export();

namespace scapix {
namespace link {
namespace cs {
namespace api {

using handle_type = const void*;
using size_type = std::int32_t;
using func_ptr_type = void(*)();

template <typename T, typename = void>
struct param
{
	using type = api::handle_type;
};

template <typename T>
struct param<T, std::enable_if_t<std::is_void_v<T> || is_simple_v<T>>>
{
	using type = T;
};

template <typename T>
struct param<T, std::enable_if_t<std::is_enum_v<T>>>
{
	using type = typename param<std::underlying_type_t<T>>::type;
};

template <typename T, typename = void>
using param_t = typename param<remove_cvref_t<T>>::type;

struct class_cs_api
{
	handle_type(SCAPIX_CALL* create)(handle_type);
};

struct cs_api
{
	handle_type  (SCAPIX_CALL* copy_ref)(handle_type r, ref_type type);
	void         (SCAPIX_CALL* release_ref)(handle_type r);
	handle_type  (SCAPIX_CALL* create_string)(const char* data, size_type size);
	void         (SCAPIX_CALL* set_string)(handle_type r, std::string * str);
	func_ptr_type(SCAPIX_CALL* get_func)(handle_type d);
	size_type    (SCAPIX_CALL* get_array_size)(handle_type a);
	handle_type  (SCAPIX_CALL* get_object_array_element)(handle_type arr, size_type index);
	void         (SCAPIX_CALL* set_object_array_element)(handle_type arr, size_type index, handle_type value);
	class_cs_api*(SCAPIX_CALL* register_class)(const char* class_name, const void* class_cpp_api);
	handle_type  (SCAPIX_CALL* get_cpp)(handle_type obj);
	void*        (SCAPIX_CALL* addr_of_pinned_object)(handle_type obj);

	handle_type(SCAPIX_CALL* create_bool_array)(size_type size);
	handle_type(SCAPIX_CALL* create_sbyte_array)(size_type size);
	handle_type(SCAPIX_CALL* create_short_array)(size_type size);
	handle_type(SCAPIX_CALL* create_int_array)(size_type size);
	handle_type(SCAPIX_CALL* create_long_array)(size_type size);
	handle_type(SCAPIX_CALL* create_float_array)(size_type size);
	handle_type(SCAPIX_CALL* create_double_array)(size_type size);

	void(SCAPIX_CALL* set_exception)(handle_type exception, bool cpp);
	void(SCAPIX_CALL* get_exception_message)(handle_type exception, std::string* str);
};

inline cs_api funcs;

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
			auto str = __cxa_current_exception_type().name();
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

extern "C" SCAPIX_EXPORT
inline const cpp_api* SCAPIX_CALL ScapixInit(const cs_api* funcs)
{
	api::funcs = *funcs;
	scapix_cs_export();
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
handle_type create_struct_array(size_type size);

template <> inline handle_type create_struct_array<bool>        (size_type size) { return api::funcs.create_bool_array(size); }
template <> inline handle_type create_struct_array<std::int8_t> (size_type size) { return api::funcs.create_sbyte_array(size); }
template <> inline handle_type create_struct_array<std::int16_t>(size_type size) { return api::funcs.create_short_array(size); }
template <> inline handle_type create_struct_array<std::int32_t>(size_type size) { return api::funcs.create_int_array(size); }
template <> inline handle_type create_struct_array<std::int64_t>(size_type size) { return api::funcs.create_long_array(size); }
template <> inline handle_type create_struct_array<float>       (size_type size) { return api::funcs.create_float_array(size); }
template <> inline handle_type create_struct_array<double>      (size_type size) { return api::funcs.create_double_array(size); }

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

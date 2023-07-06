/*
	scapix/link/cs/api.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_API_BASE_H
#define SCAPIX_LINK_CS_API_BASE_H

#include <string>
#include <scapix/link/cs/ref_type.h>

#define SCAPIX_CALL //__stdcall

namespace scapix::link::cs::api {

using handle_type = const void*;
using size_type = std::int32_t;
using func_ptr_type = void(*)();

struct class_cs_api
{
	handle_type(SCAPIX_CALL* create)(handle_type);
};

struct cs_api
{
	handle_type  (SCAPIX_CALL* copy_ref)(handle_type r, ref_type type);
	void         (SCAPIX_CALL* release_ref)(handle_type r);
	handle_type  (SCAPIX_CALL* create_string)(const char* data, size_type size);
	void         (SCAPIX_CALL* set_string)(handle_type r, std::string* str);
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
	handle_type(SCAPIX_CALL* create_byte_array)(size_type size);
	handle_type(SCAPIX_CALL* create_ushort_array)(size_type size);
	handle_type(SCAPIX_CALL* create_uint_array)(size_type size);
	handle_type(SCAPIX_CALL* create_ulong_array)(size_type size);
	handle_type(SCAPIX_CALL* create_float_array)(size_type size);
	handle_type(SCAPIX_CALL* create_double_array)(size_type size);

	void(SCAPIX_CALL* set_exception)(handle_type exception, bool cpp);
	void(SCAPIX_CALL* get_exception_message)(handle_type exception, std::string* str);
};

inline cs_api funcs;

} // namespace scapix::link::cs::api

#endif // SCAPIX_LINK_CS_API_BASE_H

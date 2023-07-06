/*
	scapix/link/cs/api.cpp

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/cs/api.h>
#include <scapix/link/cs/exception.h>
#include <scapix/bridge/cs/object.h>

namespace scapix::link::cs::api {

bool cpp_api::finalize(bridge::cs::object_base* obj)
{
	return obj->finalize();
}

void throw_exception()
{
	if (cpp_api::exception_is_cpp)
	{
		std::unique_ptr<const std::exception_ptr> e(static_cast<const std::exception_ptr*>(cpp_api::current_exception));
		cpp_api::current_exception = nullptr;
		std::rethrow_exception(*e);
	}
	else
	{
		handle_type e(cpp_api::current_exception);
		cpp_api::current_exception = nullptr;
		throw cs::exception(std::move(e));
	}
}

} // namespace scapix::link::cs::api

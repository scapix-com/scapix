/*
	scapix/link/java/detail/native_exception.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H
#define SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H

#include <memory>
#include <scapix/link/java/object.h>

namespace scapix {
namespace link {
namespace java {
namespace detail {

class native_exception : public throwable<SCAPIX_META_STRING("com/scapix/NativeException")>
{
public:

	static local_ref<native_exception> new_object()
	{
		return object_type::new_object<void(jlong)>(reinterpret_cast<jlong>(new std::exception_ptr(std::current_exception())));
	}

	void rethrow()
	{
		std::unique_ptr<std::exception_ptr> ptr(reinterpret_cast<std::exception_ptr*>(get_field<SCAPIX_META_STRING("ptr"), jlong>()));
		std::rethrow_exception(*ptr);
	}

protected:

	native_exception(handle_type h) : throwable(h) {}

};

} // namespace detail
} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_DETAIL_NATIVE_EXCEPTION_H

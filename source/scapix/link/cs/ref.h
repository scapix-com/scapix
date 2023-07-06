/*
	scapix/link/cs/ref.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_REF_H
#define SCAPIX_LINK_CS_REF_H

#include <scapix/link/cs/ref_type.h>
#include <scapix/link/cs/api_base.h>

namespace scapix::link::cs {

class object;

template <typename Class = object>
class ref
{
public:

	using handle_type = api::handle_type;

	ref(std::nullptr_t = nullptr) noexcept : handle(nullptr) {}
	explicit ref(handle_type h) noexcept : handle(h) {}
	ref(const ref& r, ref_type t = ref_type::normal) noexcept : handle(r ? api::funcs.copy_ref(r.get(), t) : nullptr) {}
	ref(ref&& r) noexcept : handle(r.release()) {}

	~ref() { if (handle) api::funcs.release_ref(handle); }

	ref& operator = (const ref& r) noexcept { ref(r).swap(*this); return *this; }
	ref& operator = (ref&& r) noexcept { ref(std::move(r)).swap(*this); return *this; }

	handle_type get() const noexcept { return handle; }
	explicit operator bool() const noexcept { return handle != nullptr; }

	void reset(handle_type h = nullptr) noexcept { ref(h).swap(*this); }
	handle_type release() noexcept { auto h(handle); handle = nullptr; return h; }

	void swap(ref& r) noexcept
	{
		auto temp(handle);
		handle = r.handle;
		r.handle = temp;
	}

private:

	handle_type handle;

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_REF_H

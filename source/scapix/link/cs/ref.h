/*
	scapix/link/cs/ref.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_REF_H
#define SCAPIX_LINK_CS_REF_H

#include <scapix/link/cs/ref_type.h>
#include <scapix/link/cs/api.h>

namespace scapix {
namespace link {
namespace cs {

class object;

template <typename Class = object>
class ref
{
public:

	using handle_type = api::handle_type;

	ref() : handle(nullptr) {}
	explicit ref(handle_type h) : handle(h) {}
	ref(const ref& r, ref_type t = ref_type::normal) : handle(r ? api::funcs.copy_ref(r.get(), t) : nullptr) {}
	ref(ref&& r) noexcept : handle(r.release()) {}

	~ref() { if (handle) api::funcs.release_ref(handle); }

	ref& operator = (const ref& r) { ref(r).swap(*this); return *this; }
	ref& operator = (ref&& r) noexcept { ref(std::move(r)).swap(*this); return *this; }

	handle_type get() const { return handle; }
	explicit operator bool() const { return handle != nullptr; }

	void reset(handle_type h = nullptr) { ref(h).swap(*this); }
	handle_type release() { auto h(handle); handle = nullptr; return h; }

	void swap(ref& r)
	{
		auto temp(handle);
		handle = r.handle;
		r.handle = temp;
	}

private:

	handle_type handle;

};

} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_CS_REF_H

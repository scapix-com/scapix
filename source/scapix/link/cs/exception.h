/*
	scapix/link/cs/exception.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_EXCEPTION_H
#define SCAPIX_LINK_CS_EXCEPTION_H

#include <string>
#include <exception>
#include <scapix/link/cs/api.h>

namespace scapix::link::cs {

class exception : public std::exception
{
public:

	exception(const exception&) = delete;
	exception& operator = (const exception&) = delete;

	~exception()
	{
		api::funcs.release_ref(cs_exception);
	}

	virtual const char* what() const noexcept override { return message().c_str(); }

	api::handle_type release()
	{
		auto temp = cs_exception;
		cs_exception = nullptr;
		return temp;
	}

	const std::string& message() const
	{
		if (msg.empty())
			get_message();

		return msg;
	}

private:

	friend void api::throw_exception();

	exception(api::handle_type e) : cs_exception(std::move(e)) {}

private:

	void get_message() const
	{
		api::funcs.get_exception_message(cs_exception, &msg);
	}

	// to do: use ref<>
	api::handle_type cs_exception;
	mutable std::string msg;

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_EXCEPTION_H

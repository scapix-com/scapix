/*
	scapix/link/cs/exception.h

	Copyright (c) 2019-2024 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_EXCEPTION_H
#define SCAPIX_LINK_CS_EXCEPTION_H

#include <string>
#include <exception>
#include <scapix/link/cs/api.h>
#include <scapix/link/cs/ref.h>

namespace scapix::link::cs {

class exception : public std::exception
{
public:

	virtual const char* what() const noexcept override { return message().c_str(); }

	api::handle_type release()
	{
		return cs_exception.release();
	}

	const std::string& message() const
	{
		if (msg.empty())
			get_message();

		return msg;
	}

private:

	friend void api::throw_exception();

	exception(api::handle_type e) : cs_exception(e) {}

private:

	void get_message() const
	{
		api::funcs.get_exception_message(cs_exception.get(), &msg);
	}

	ref<> cs_exception;
	mutable std::string msg;

};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_EXCEPTION_H

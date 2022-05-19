/*
	scapix/link/java/throwable.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#include <scapix/link/java/object.h>

#ifndef SCAPIX_LINK_JAVA_THROWABLE_H
#define SCAPIX_LINK_JAVA_THROWABLE_H

namespace scapix::link::java {

template <typename ClassName = SCAPIX_META_STRING("java/lang/Throwable")>
class throwable : public object<ClassName, jthrowable>
{
public:

	jint throw_() const
	{
		return detail::env()->Throw(this->handle());
	}

protected:

	typedef object<ClassName, jthrowable> base;
	typedef typename base::handle_type handle_type;

	throwable(handle_type h) : base(h) {}

};

template <>
class object<SCAPIX_META_STRING("java/lang/Throwable")> : public throwable<>
{
	using throwable::throwable;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_THROWABLE_H

/*
	scapix/link/java/throwable.h

	Copyright (c) 2019-2022 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_THROWABLE_H
#define SCAPIX_LINK_JAVA_THROWABLE_H

#include <scapix/link/java/ref.h>
#include <scapix/link/java/object.h>

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

	using base = object<ClassName, jthrowable>;
	throwable(typename base::handle_type h) : base(h) {}

};

template <>
class object<SCAPIX_META_STRING("java/lang/Throwable")> : public throwable<>
{
	using throwable::throwable;
};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_THROWABLE_H

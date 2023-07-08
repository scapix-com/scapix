/*
	scapix/link/java/function.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FUNCTION_H
#define SCAPIX_LINK_JAVA_FUNCTION_H

#include <scapix/link/java/object.h>

namespace scapix::link::java {

// represents java @FunctionalInterface

template <typename ClassName, typename Type, typename Name = SCAPIX_META_STRING("call")>
class function;

template <typename ClassName, typename R, typename ...Args, typename Name>
class function<ClassName, R(Args...), Name> : public object<ClassName>
{
	using base = object<ClassName>;

public:

	R call(Args... args) const
	{
		return base::template call_method<Name, R(Args...)>(args...);
	}

protected:

	function(typename base::handle_type h) : base(h) {}

};

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_FUNCTION_H

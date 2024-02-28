/*
	scapix/jni/function.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_FUNCTION_H
#define SCAPIX_LINK_JAVA_FUNCTION_H

#include <scapix/jni/object.h>

namespace scapix::jni {

// represents java @FunctionalInterface

template <fixed_string ClassName, typename Type, fixed_string Name = "call">
class function;

template <fixed_string ClassName, typename R, typename ...Args, fixed_string Name>
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

} // namespace scapix::jni

#endif // SCAPIX_LINK_JAVA_FUNCTION_H
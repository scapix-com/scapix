/*
	scapix/java_api.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_JAVA_API_H
#define SCAPIX_JAVA_API_H

#include <scapix/jni/object_base.h>
#include <scapix/jni/ref.h>
#include <scapix/jni/array.h>
#include <scapix/jni/convert.h>

namespace scapix::java_api {

// compatibility with scapix_java 1.0 generated headers

#define SCAPIX_META_STRING(x) x
using jni::object_base;
using jni::ref;
namespace link::java { using jni::array; }

// workaround for conflict between namespaces "sun" and "com::sun"

namespace sun {}
namespace com::sun { namespace sun = ::scapix::java_api::sun; }

} // namespace scapix::java_api

#endif // SCAPIX_JAVA_API_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_LANG_VERSIONPROPS_H
#define SCAPIX_JAVA_LANG_VERSIONPROPS_H

namespace scapix::java_api {
namespace java::lang {

// private
class VersionProps : public object_base<SCAPIX_META_STRING("java/lang/VersionProps"),
	java::lang::Object>
{
public:

	static void init();
	static void print(jboolean err);
	static void println(jboolean err);

protected:

	VersionProps(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api


namespace scapix::java_api {
namespace java::lang {

inline void VersionProps::init() { return call_static_method<SCAPIX_META_STRING("init"), void>(); }
inline void VersionProps::print(jboolean err) { return call_static_method<SCAPIX_META_STRING("print"), void>(err); }
inline void VersionProps::println(jboolean err) { return call_static_method<SCAPIX_META_STRING("println"), void>(err); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_VERSIONPROPS_H

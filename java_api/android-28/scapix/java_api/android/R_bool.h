// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_R_BOOL_H
#define SCAPIX_ANDROID_R_BOOL_H

namespace scapix::java_api {


namespace android {

class R_bool : public object_base<SCAPIX_META_STRING("android/R$bool"),
	java::lang::Object>
{
public:

	static ref<R_bool> new_object();

protected:

	R_bool(handle_type h) : base_(h) {}

};

} // namespace android
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android {

inline ref<R_bool> R_bool::new_object() { return base_::new_object(); }

} // namespace android
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_R_BOOL_H
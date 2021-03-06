// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_PROVIDER_BASECOLUMNS_H
#define SCAPIX_ANDROID_PROVIDER_BASECOLUMNS_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::provider {

class BaseColumns : public object_base<SCAPIX_META_STRING("android/provider/BaseColumns"),
	java::lang::Object>
{
public:

	static ref<java::lang::String> _COUNT_();
	static ref<java::lang::String> _ID_();


protected:

	BaseColumns(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<java::lang::String> BaseColumns::_COUNT_() { return get_static_field<SCAPIX_META_STRING("_COUNT"), ref<java::lang::String>>(); }
inline ref<java::lang::String> BaseColumns::_ID_() { return get_static_field<SCAPIX_META_STRING("_ID"), ref<java::lang::String>>(); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_BASECOLUMNS_H

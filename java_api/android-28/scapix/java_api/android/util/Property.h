// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_UTIL_PROPERTY_H
#define SCAPIX_ANDROID_UTIL_PROPERTY_H

namespace scapix::java_api {

namespace java::lang { class Class; }
namespace java::lang { class String; }

namespace android::util {

class Property : public object_base<SCAPIX_META_STRING("android/util/Property"),
	java::lang::Object>
{
public:

	static ref<Property> new_object(ref<java::lang::Class> type, ref<java::lang::String> name);
	static ref<android::util::Property> of(ref<java::lang::Class> hostType, ref<java::lang::Class> valueType, ref<java::lang::String> name);
	jboolean isReadOnly();
	void set(ref<java::lang::Object> object, ref<java::lang::Object> value);
	ref<java::lang::Object> get(ref<java::lang::Object> p1);
	ref<java::lang::String> getName();
	ref<java::lang::Class> getType();

protected:

	Property(handle_type h) : base_(h) {}

};

} // namespace android::util
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::util {

inline ref<Property> Property::new_object(ref<java::lang::Class> type, ref<java::lang::String> name) { return base_::new_object(type, name); }
inline ref<android::util::Property> Property::of(ref<java::lang::Class> hostType, ref<java::lang::Class> valueType, ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("of"), ref<android::util::Property>>(hostType, valueType, name); }
inline jboolean Property::isReadOnly() { return call_method<SCAPIX_META_STRING("isReadOnly"), jboolean>(); }
inline void Property::set(ref<java::lang::Object> object, ref<java::lang::Object> value) { return call_method<SCAPIX_META_STRING("set"), void>(object, value); }
inline ref<java::lang::Object> Property::get(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("get"), ref<java::lang::Object>>(p1); }
inline ref<java::lang::String> Property::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline ref<java::lang::Class> Property::getType() { return call_method<SCAPIX_META_STRING("getType"), ref<java::lang::Class>>(); }

} // namespace android::util
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_UTIL_PROPERTY_H
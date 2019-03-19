// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/admin/NetworkEvent.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_APP_ADMIN_DNSEVENT_H
#define SCAPIX_ANDROID_APP_ADMIN_DNSEVENT_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }
namespace java::util { class List; }

namespace android::app::admin {

class DnsEvent : public object_base<SCAPIX_META_STRING("android/app/admin/DnsEvent"),
	android::app::admin::NetworkEvent,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	ref<java::lang::String> getHostname();
	ref<java::util::List> getInetAddresses();
	jint getTotalResolvedAddressCount();
	ref<java::lang::String> toString();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> out, jint flags);

protected:

	DnsEvent(handle_type h) : base_(h) {}

};

} // namespace android::app::admin
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::app::admin {

inline ref<android::os::Parcelable_Creator> DnsEvent::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<java::lang::String> DnsEvent::getHostname() { return call_method<SCAPIX_META_STRING("getHostname"), ref<java::lang::String>>(); }
inline ref<java::util::List> DnsEvent::getInetAddresses() { return call_method<SCAPIX_META_STRING("getInetAddresses"), ref<java::util::List>>(); }
inline jint DnsEvent::getTotalResolvedAddressCount() { return call_method<SCAPIX_META_STRING("getTotalResolvedAddressCount"), jint>(); }
inline ref<java::lang::String> DnsEvent::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint DnsEvent::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void DnsEvent::writeToParcel(ref<android::os::Parcel> out, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(out, flags); }

} // namespace android::app::admin
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_ADMIN_DNSEVENT_H
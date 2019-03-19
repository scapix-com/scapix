// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_NET_LOCALSOCKETADDRESS_H
#define SCAPIX_ANDROID_NET_LOCALSOCKETADDRESS_H

namespace scapix::java_api {

namespace android::net { class LocalSocketAddress_Namespace; }
namespace java::lang { class String; }

namespace android::net {

class LocalSocketAddress : public object_base<SCAPIX_META_STRING("android/net/LocalSocketAddress"),
	java::lang::Object>
{
public:

	using Namespace = LocalSocketAddress_Namespace;

	static ref<LocalSocketAddress> new_object(ref<java::lang::String> name, ref<android::net::LocalSocketAddress_Namespace> namespace_);
	static ref<LocalSocketAddress> new_object(ref<java::lang::String> name);
	ref<java::lang::String> getName();
	ref<android::net::LocalSocketAddress_Namespace> getNamespace();

protected:

	LocalSocketAddress(handle_type h) : base_(h) {}

};

} // namespace android::net
} // namespace scapix::java_api

#include <scapix/java_api/android/net/LocalSocketAddress_Namespace.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::net {

inline ref<LocalSocketAddress> LocalSocketAddress::new_object(ref<java::lang::String> name, ref<android::net::LocalSocketAddress_Namespace> namespace_) { return base_::new_object(name, namespace_); }
inline ref<LocalSocketAddress> LocalSocketAddress::new_object(ref<java::lang::String> name) { return base_::new_object(name); }
inline ref<java::lang::String> LocalSocketAddress::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline ref<android::net::LocalSocketAddress_Namespace> LocalSocketAddress::getNamespace() { return call_method<SCAPIX_META_STRING("getNamespace"), ref<android::net::LocalSocketAddress_Namespace>>(); }

} // namespace android::net
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NET_LOCALSOCKETADDRESS_H
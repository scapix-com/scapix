// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_NET_NETWORK_H
#define SCAPIX_ANDROID_NET_NETWORK_H

namespace scapix::java_api {

namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::io { class FileDescriptor; }
namespace java::lang { class String; }
namespace java::net { class DatagramSocket; }
namespace java::net { class InetAddress; }
namespace java::net { class Proxy; }
namespace java::net { class Socket; }
namespace java::net { class URL; }
namespace java::net { class URLConnection; }
namespace javax::net { class SocketFactory; }

namespace android::net {

class Network : public object_base<SCAPIX_META_STRING("android/net/Network"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	ref<link::java::array<java::net::InetAddress>> getAllByName(ref<java::lang::String> host);
	ref<java::net::InetAddress> getByName(ref<java::lang::String> host);
	ref<javax::net::SocketFactory> getSocketFactory();
	ref<java::net::URLConnection> openConnection(ref<java::net::URL> url);
	ref<java::net::URLConnection> openConnection(ref<java::net::URL> url, ref<java::net::Proxy> proxy);
	void bindSocket(ref<java::net::DatagramSocket> socket);
	void bindSocket(ref<java::net::Socket> socket);
	void bindSocket(ref<java::io::FileDescriptor> fd);
	static ref<android::net::Network> fromNetworkHandle(jlong networkHandle);
	jlong getNetworkHandle();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	Network(handle_type h) : base_(h) {}

};

} // namespace android::net
} // namespace scapix::java_api

#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/io/FileDescriptor.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/net/DatagramSocket.h>
#include <scapix/java_api/java/net/InetAddress.h>
#include <scapix/java_api/java/net/Proxy.h>
#include <scapix/java_api/java/net/Socket.h>
#include <scapix/java_api/java/net/URL.h>
#include <scapix/java_api/java/net/URLConnection.h>
#include <scapix/java_api/javax/net/SocketFactory.h>

namespace scapix::java_api {
namespace android::net {

inline ref<android::os::Parcelable_Creator> Network::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<link::java::array<java::net::InetAddress>> Network::getAllByName(ref<java::lang::String> host) { return call_method<SCAPIX_META_STRING("getAllByName"), ref<link::java::array<java::net::InetAddress>>>(host); }
inline ref<java::net::InetAddress> Network::getByName(ref<java::lang::String> host) { return call_method<SCAPIX_META_STRING("getByName"), ref<java::net::InetAddress>>(host); }
inline ref<javax::net::SocketFactory> Network::getSocketFactory() { return call_method<SCAPIX_META_STRING("getSocketFactory"), ref<javax::net::SocketFactory>>(); }
inline ref<java::net::URLConnection> Network::openConnection(ref<java::net::URL> url) { return call_method<SCAPIX_META_STRING("openConnection"), ref<java::net::URLConnection>>(url); }
inline ref<java::net::URLConnection> Network::openConnection(ref<java::net::URL> url, ref<java::net::Proxy> proxy) { return call_method<SCAPIX_META_STRING("openConnection"), ref<java::net::URLConnection>>(url, proxy); }
inline void Network::bindSocket(ref<java::net::DatagramSocket> socket) { return call_method<SCAPIX_META_STRING("bindSocket"), void>(socket); }
inline void Network::bindSocket(ref<java::net::Socket> socket) { return call_method<SCAPIX_META_STRING("bindSocket"), void>(socket); }
inline void Network::bindSocket(ref<java::io::FileDescriptor> fd) { return call_method<SCAPIX_META_STRING("bindSocket"), void>(fd); }
inline ref<android::net::Network> Network::fromNetworkHandle(jlong networkHandle) { return call_static_method<SCAPIX_META_STRING("fromNetworkHandle"), ref<android::net::Network>>(networkHandle); }
inline jlong Network::getNetworkHandle() { return call_method<SCAPIX_META_STRING("getNetworkHandle"), jlong>(); }
inline jint Network::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void Network::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jboolean Network::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint Network::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> Network::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::net
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NET_NETWORK_H
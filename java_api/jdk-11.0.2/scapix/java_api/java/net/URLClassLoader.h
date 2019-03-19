// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/security/SecureClassLoader.h>
#include <scapix/java_api/java/io/Closeable.h>

#ifndef SCAPIX_JAVA_NET_URLCLASSLOADER_H
#define SCAPIX_JAVA_NET_URLCLASSLOADER_H

namespace scapix::java_api {

namespace java::io { class InputStream; }
namespace java::lang { class ClassLoader; }
namespace java::lang { class String; }
namespace java::net { class URL; }
namespace java::net { class URLStreamHandlerFactory; }
namespace java::util { class Enumeration; }

namespace java::net {

class URLClassLoader : public object_base<SCAPIX_META_STRING("java/net/URLClassLoader"),
	java::security::SecureClassLoader,
	java::io::Closeable>
{
public:

	static ref<URLClassLoader> new_object(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent);
	static ref<URLClassLoader> new_object(ref<link::java::array<java::net::URL>> urls);
	static ref<URLClassLoader> new_object(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent, ref<java::net::URLStreamHandlerFactory> factory);
	static ref<URLClassLoader> new_object(ref<java::lang::String> name, ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent);
	static ref<URLClassLoader> new_object(ref<java::lang::String> name, ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent, ref<java::net::URLStreamHandlerFactory> factory);
	ref<java::io::InputStream> getResourceAsStream(ref<java::lang::String> name);
	void close();
	ref<link::java::array<java::net::URL>> getURLs();
	ref<java::net::URL> findResource(ref<java::lang::String> name);
	ref<java::util::Enumeration> findResources(ref<java::lang::String> name);
	static ref<java::net::URLClassLoader> newInstance(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent);
	static ref<java::net::URLClassLoader> newInstance(ref<link::java::array<java::net::URL>> urls);

protected:

	URLClassLoader(handle_type h) : base_(h) {}

};

} // namespace java::net
} // namespace scapix::java_api

#include <scapix/java_api/java/io/InputStream.h>
#include <scapix/java_api/java/lang/ClassLoader.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/net/URL.h>
#include <scapix/java_api/java/net/URLStreamHandlerFactory.h>
#include <scapix/java_api/java/util/Enumeration.h>

namespace scapix::java_api {
namespace java::net {

inline ref<URLClassLoader> URLClassLoader::new_object(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent) { return base_::new_object(urls, parent); }
inline ref<URLClassLoader> URLClassLoader::new_object(ref<link::java::array<java::net::URL>> urls) { return base_::new_object(urls); }
inline ref<URLClassLoader> URLClassLoader::new_object(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent, ref<java::net::URLStreamHandlerFactory> factory) { return base_::new_object(urls, parent, factory); }
inline ref<URLClassLoader> URLClassLoader::new_object(ref<java::lang::String> name, ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent) { return base_::new_object(name, urls, parent); }
inline ref<URLClassLoader> URLClassLoader::new_object(ref<java::lang::String> name, ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent, ref<java::net::URLStreamHandlerFactory> factory) { return base_::new_object(name, urls, parent, factory); }
inline ref<java::io::InputStream> URLClassLoader::getResourceAsStream(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("getResourceAsStream"), ref<java::io::InputStream>>(name); }
inline void URLClassLoader::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }
inline ref<link::java::array<java::net::URL>> URLClassLoader::getURLs() { return call_method<SCAPIX_META_STRING("getURLs"), ref<link::java::array<java::net::URL>>>(); }
inline ref<java::net::URL> URLClassLoader::findResource(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("findResource"), ref<java::net::URL>>(name); }
inline ref<java::util::Enumeration> URLClassLoader::findResources(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("findResources"), ref<java::util::Enumeration>>(name); }
inline ref<java::net::URLClassLoader> URLClassLoader::newInstance(ref<link::java::array<java::net::URL>> urls, ref<java::lang::ClassLoader> parent) { return call_static_method<SCAPIX_META_STRING("newInstance"), ref<java::net::URLClassLoader>>(urls, parent); }
inline ref<java::net::URLClassLoader> URLClassLoader::newInstance(ref<link::java::array<java::net::URL>> urls) { return call_static_method<SCAPIX_META_STRING("newInstance"), ref<java::net::URLClassLoader>>(urls); }

} // namespace java::net
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NET_URLCLASSLOADER_H
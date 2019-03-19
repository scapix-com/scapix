// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/Cloneable.h>

#ifndef SCAPIX_JAVA_NET_HTTPCOOKIE_H
#define SCAPIX_JAVA_NET_HTTPCOOKIE_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::util { class List; }

namespace java::net {

class HttpCookie : public object_base<SCAPIX_META_STRING("java/net/HttpCookie"),
	java::lang::Object,
	java::lang::Cloneable>
{
public:

	static ref<HttpCookie> new_object(ref<java::lang::String> name, ref<java::lang::String> value);
	static ref<java::util::List> parse(ref<java::lang::String> header);
	jboolean hasExpired();
	void setComment(ref<java::lang::String> purpose);
	ref<java::lang::String> getComment();
	void setCommentURL(ref<java::lang::String> purpose);
	ref<java::lang::String> getCommentURL();
	void setDiscard(jboolean discard);
	jboolean getDiscard();
	void setPortlist(ref<java::lang::String> ports);
	ref<java::lang::String> getPortlist();
	void setDomain(ref<java::lang::String> pattern);
	ref<java::lang::String> getDomain();
	void setMaxAge(jlong expiry);
	jlong getMaxAge();
	void setPath(ref<java::lang::String> uri);
	ref<java::lang::String> getPath();
	void setSecure(jboolean flag);
	jboolean getSecure();
	ref<java::lang::String> getName();
	void setValue(ref<java::lang::String> newValue);
	ref<java::lang::String> getValue();
	jint getVersion();
	void setVersion(jint v);
	jboolean isHttpOnly();
	void setHttpOnly(jboolean httpOnly);
	static jboolean domainMatches(ref<java::lang::String> domain, ref<java::lang::String> host);
	ref<java::lang::String> toString();
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::Object> clone();

protected:

	HttpCookie(handle_type h) : base_(h) {}

};

} // namespace java::net
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace java::net {

inline ref<HttpCookie> HttpCookie::new_object(ref<java::lang::String> name, ref<java::lang::String> value) { return base_::new_object(name, value); }
inline ref<java::util::List> HttpCookie::parse(ref<java::lang::String> header) { return call_static_method<SCAPIX_META_STRING("parse"), ref<java::util::List>>(header); }
inline jboolean HttpCookie::hasExpired() { return call_method<SCAPIX_META_STRING("hasExpired"), jboolean>(); }
inline void HttpCookie::setComment(ref<java::lang::String> purpose) { return call_method<SCAPIX_META_STRING("setComment"), void>(purpose); }
inline ref<java::lang::String> HttpCookie::getComment() { return call_method<SCAPIX_META_STRING("getComment"), ref<java::lang::String>>(); }
inline void HttpCookie::setCommentURL(ref<java::lang::String> purpose) { return call_method<SCAPIX_META_STRING("setCommentURL"), void>(purpose); }
inline ref<java::lang::String> HttpCookie::getCommentURL() { return call_method<SCAPIX_META_STRING("getCommentURL"), ref<java::lang::String>>(); }
inline void HttpCookie::setDiscard(jboolean discard) { return call_method<SCAPIX_META_STRING("setDiscard"), void>(discard); }
inline jboolean HttpCookie::getDiscard() { return call_method<SCAPIX_META_STRING("getDiscard"), jboolean>(); }
inline void HttpCookie::setPortlist(ref<java::lang::String> ports) { return call_method<SCAPIX_META_STRING("setPortlist"), void>(ports); }
inline ref<java::lang::String> HttpCookie::getPortlist() { return call_method<SCAPIX_META_STRING("getPortlist"), ref<java::lang::String>>(); }
inline void HttpCookie::setDomain(ref<java::lang::String> pattern) { return call_method<SCAPIX_META_STRING("setDomain"), void>(pattern); }
inline ref<java::lang::String> HttpCookie::getDomain() { return call_method<SCAPIX_META_STRING("getDomain"), ref<java::lang::String>>(); }
inline void HttpCookie::setMaxAge(jlong expiry) { return call_method<SCAPIX_META_STRING("setMaxAge"), void>(expiry); }
inline jlong HttpCookie::getMaxAge() { return call_method<SCAPIX_META_STRING("getMaxAge"), jlong>(); }
inline void HttpCookie::setPath(ref<java::lang::String> uri) { return call_method<SCAPIX_META_STRING("setPath"), void>(uri); }
inline ref<java::lang::String> HttpCookie::getPath() { return call_method<SCAPIX_META_STRING("getPath"), ref<java::lang::String>>(); }
inline void HttpCookie::setSecure(jboolean flag) { return call_method<SCAPIX_META_STRING("setSecure"), void>(flag); }
inline jboolean HttpCookie::getSecure() { return call_method<SCAPIX_META_STRING("getSecure"), jboolean>(); }
inline ref<java::lang::String> HttpCookie::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline void HttpCookie::setValue(ref<java::lang::String> newValue) { return call_method<SCAPIX_META_STRING("setValue"), void>(newValue); }
inline ref<java::lang::String> HttpCookie::getValue() { return call_method<SCAPIX_META_STRING("getValue"), ref<java::lang::String>>(); }
inline jint HttpCookie::getVersion() { return call_method<SCAPIX_META_STRING("getVersion"), jint>(); }
inline void HttpCookie::setVersion(jint v) { return call_method<SCAPIX_META_STRING("setVersion"), void>(v); }
inline jboolean HttpCookie::isHttpOnly() { return call_method<SCAPIX_META_STRING("isHttpOnly"), jboolean>(); }
inline void HttpCookie::setHttpOnly(jboolean httpOnly) { return call_method<SCAPIX_META_STRING("setHttpOnly"), void>(httpOnly); }
inline jboolean HttpCookie::domainMatches(ref<java::lang::String> domain, ref<java::lang::String> host) { return call_static_method<SCAPIX_META_STRING("domainMatches"), jboolean>(domain, host); }
inline ref<java::lang::String> HttpCookie::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jboolean HttpCookie::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint HttpCookie::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::Object> HttpCookie::clone() { return call_method<SCAPIX_META_STRING("clone"), ref<java::lang::Object>>(); }

} // namespace java::net
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_NET_HTTPCOOKIE_H
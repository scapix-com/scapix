// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ORG_W3C_DOM_LS_LSRESOURCERESOLVER_H
#define SCAPIX_ORG_W3C_DOM_LS_LSRESOURCERESOLVER_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace org::w3c::dom::ls { class LSInput; }

namespace org::w3c::dom::ls {

class LSResourceResolver : public object_base<SCAPIX_META_STRING("org/w3c/dom/ls/LSResourceResolver"),
	java::lang::Object>
{
public:

	ref<org::w3c::dom::ls::LSInput> resolveResource(ref<java::lang::String> p1, ref<java::lang::String> p2, ref<java::lang::String> p3, ref<java::lang::String> p4, ref<java::lang::String> p5);

protected:

	LSResourceResolver(handle_type h) : base_(h) {}

};

} // namespace org::w3c::dom::ls
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/org/w3c/dom/ls/LSInput.h>

namespace scapix::java_api {
namespace org::w3c::dom::ls {

inline ref<org::w3c::dom::ls::LSInput> LSResourceResolver::resolveResource(ref<java::lang::String> p1, ref<java::lang::String> p2, ref<java::lang::String> p3, ref<java::lang::String> p4, ref<java::lang::String> p5) { return call_method<SCAPIX_META_STRING("resolveResource"), ref<org::w3c::dom::ls::LSInput>>(p1, p2, p3, p4, p5); }

} // namespace org::w3c::dom::ls
} // namespace scapix::java_api

#endif // SCAPIX_ORG_W3C_DOM_LS_LSRESOURCERESOLVER_H
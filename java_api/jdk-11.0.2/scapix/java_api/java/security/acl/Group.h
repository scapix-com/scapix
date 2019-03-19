// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/Principal.h>

#ifndef SCAPIX_JAVA_SECURITY_ACL_GROUP_H
#define SCAPIX_JAVA_SECURITY_ACL_GROUP_H

namespace scapix::java_api {

namespace java::util { class Enumeration; }

namespace java::security::acl {

class Group : public object_base<SCAPIX_META_STRING("java/security/acl/Group"),
	java::lang::Object,
	java::security::Principal>
{
public:

	jboolean addMember(ref<java::security::Principal> p1);
	jboolean removeMember(ref<java::security::Principal> p1);
	jboolean isMember(ref<java::security::Principal> p1);
	ref<java::util::Enumeration> members();

protected:

	Group(handle_type h) : base_(h) {}

};

} // namespace java::security::acl
} // namespace scapix::java_api

#include <scapix/java_api/java/util/Enumeration.h>

namespace scapix::java_api {
namespace java::security::acl {

inline jboolean Group::addMember(ref<java::security::Principal> p1) { return call_method<SCAPIX_META_STRING("addMember"), jboolean>(p1); }
inline jboolean Group::removeMember(ref<java::security::Principal> p1) { return call_method<SCAPIX_META_STRING("removeMember"), jboolean>(p1); }
inline jboolean Group::isMember(ref<java::security::Principal> p1) { return call_method<SCAPIX_META_STRING("isMember"), jboolean>(p1); }
inline ref<java::util::Enumeration> Group::members() { return call_method<SCAPIX_META_STRING("members"), ref<java::util::Enumeration>>(); }

} // namespace java::security::acl
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_ACL_GROUP_H
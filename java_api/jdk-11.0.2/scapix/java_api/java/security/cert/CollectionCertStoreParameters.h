// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/security/cert/CertStoreParameters.h>

#ifndef SCAPIX_JAVA_SECURITY_CERT_COLLECTIONCERTSTOREPARAMETERS_H
#define SCAPIX_JAVA_SECURITY_CERT_COLLECTIONCERTSTOREPARAMETERS_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::util { class Collection; }

namespace java::security::cert {

class CollectionCertStoreParameters : public object_base<SCAPIX_META_STRING("java/security/cert/CollectionCertStoreParameters"),
	java::lang::Object,
	java::security::cert::CertStoreParameters>
{
public:

	static ref<CollectionCertStoreParameters> new_object(ref<java::util::Collection> collection);
	static ref<CollectionCertStoreParameters> new_object();
	ref<java::util::Collection> getCollection();
	ref<java::lang::Object> clone();
	ref<java::lang::String> toString();

protected:

	CollectionCertStoreParameters(handle_type h) : base_(h) {}

};

} // namespace java::security::cert
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Collection.h>

namespace scapix::java_api {
namespace java::security::cert {

inline ref<CollectionCertStoreParameters> CollectionCertStoreParameters::new_object(ref<java::util::Collection> collection) { return base_::new_object(collection); }
inline ref<CollectionCertStoreParameters> CollectionCertStoreParameters::new_object() { return base_::new_object(); }
inline ref<java::util::Collection> CollectionCertStoreParameters::getCollection() { return call_method<SCAPIX_META_STRING("getCollection"), ref<java::util::Collection>>(); }
inline ref<java::lang::Object> CollectionCertStoreParameters::clone() { return call_method<SCAPIX_META_STRING("clone"), ref<java::lang::Object>>(); }
inline ref<java::lang::String> CollectionCertStoreParameters::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::security::cert
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SECURITY_CERT_COLLECTIONCERTSTOREPARAMETERS_H
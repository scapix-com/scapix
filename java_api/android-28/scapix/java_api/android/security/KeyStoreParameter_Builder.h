// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_SECURITY_KEYSTOREPARAMETER_BUILDER_H
#define SCAPIX_ANDROID_SECURITY_KEYSTOREPARAMETER_BUILDER_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::security { class KeyStoreParameter; }

namespace android::security {

class KeyStoreParameter_Builder : public object_base<SCAPIX_META_STRING("android/security/KeyStoreParameter$Builder"),
	java::lang::Object>
{
public:

	static ref<KeyStoreParameter_Builder> new_object(ref<android::content::Context> context);
	ref<android::security::KeyStoreParameter_Builder> setEncryptionRequired(jboolean required);
	ref<android::security::KeyStoreParameter> build();

protected:

	KeyStoreParameter_Builder(handle_type h) : base_(h) {}

};

} // namespace android::security
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/security/KeyStoreParameter.h>

namespace scapix::java_api {
namespace android::security {

inline ref<KeyStoreParameter_Builder> KeyStoreParameter_Builder::new_object(ref<android::content::Context> context) { return base_::new_object(context); }
inline ref<android::security::KeyStoreParameter_Builder> KeyStoreParameter_Builder::setEncryptionRequired(jboolean required) { return call_method<SCAPIX_META_STRING("setEncryptionRequired"), ref<android::security::KeyStoreParameter_Builder>>(required); }
inline ref<android::security::KeyStoreParameter> KeyStoreParameter_Builder::build() { return call_method<SCAPIX_META_STRING("build"), ref<android::security::KeyStoreParameter>>(); }

} // namespace android::security
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_SECURITY_KEYSTOREPARAMETER_BUILDER_H
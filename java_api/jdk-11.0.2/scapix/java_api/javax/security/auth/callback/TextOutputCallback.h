// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/javax/security/auth/callback/Callback.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVAX_SECURITY_AUTH_CALLBACK_TEXTOUTPUTCALLBACK_H
#define SCAPIX_JAVAX_SECURITY_AUTH_CALLBACK_TEXTOUTPUTCALLBACK_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace javax::security::auth::callback {

class TextOutputCallback : public object_base<SCAPIX_META_STRING("javax/security/auth/callback/TextOutputCallback"),
	java::lang::Object,
	javax::security::auth::callback::Callback,
	java::io::Serializable>
{
public:

	static jint INFORMATION_();
	static jint WARNING_();
	static jint ERROR_();

	static ref<TextOutputCallback> new_object(jint messageType, ref<java::lang::String> message);
	jint getMessageType();
	ref<java::lang::String> getMessage();

protected:

	TextOutputCallback(handle_type h) : base_(h) {}

};

} // namespace javax::security::auth::callback
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace javax::security::auth::callback {

inline jint TextOutputCallback::INFORMATION_() { return get_static_field<SCAPIX_META_STRING("INFORMATION"), jint>(); }
inline jint TextOutputCallback::WARNING_() { return get_static_field<SCAPIX_META_STRING("WARNING"), jint>(); }
inline jint TextOutputCallback::ERROR_() { return get_static_field<SCAPIX_META_STRING("ERROR"), jint>(); }
inline ref<TextOutputCallback> TextOutputCallback::new_object(jint messageType, ref<java::lang::String> message) { return base_::new_object(messageType, message); }
inline jint TextOutputCallback::getMessageType() { return call_method<SCAPIX_META_STRING("getMessageType"), jint>(); }
inline ref<java::lang::String> TextOutputCallback::getMessage() { return call_method<SCAPIX_META_STRING("getMessage"), ref<java::lang::String>>(); }

} // namespace javax::security::auth::callback
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_SECURITY_AUTH_CALLBACK_TEXTOUTPUTCALLBACK_H

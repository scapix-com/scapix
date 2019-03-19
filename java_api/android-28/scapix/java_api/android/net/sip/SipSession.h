// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_NET_SIP_SIPSESSION_H
#define SCAPIX_ANDROID_NET_SIP_SIPSESSION_H

namespace scapix::java_api {

namespace android::net::sip { class SipProfile; }
namespace android::net::sip { class SipSession_Listener; }
namespace java::lang { class String; }
namespace android::net::sip { class SipSession_State; }

namespace android::net::sip {

class SipSession : public object_base<SCAPIX_META_STRING("android/net/sip/SipSession"),
	java::lang::Object>
{
public:

	using State = SipSession_State;
	using Listener = SipSession_Listener;

	ref<java::lang::String> getLocalIp();
	ref<android::net::sip::SipProfile> getLocalProfile();
	ref<android::net::sip::SipProfile> getPeerProfile();
	jint getState();
	jboolean isInCall();
	ref<java::lang::String> getCallId();
	void setListener(ref<android::net::sip::SipSession_Listener> listener);
	void register_(jint duration);
	void unregister();
	void makeCall(ref<android::net::sip::SipProfile> callee, ref<java::lang::String> sessionDescription, jint timeout);
	void answerCall(ref<java::lang::String> sessionDescription, jint timeout);
	void endCall();
	void changeCall(ref<java::lang::String> sessionDescription, jint timeout);

protected:

	SipSession(handle_type h) : base_(h) {}

};

} // namespace android::net::sip
} // namespace scapix::java_api

#include <scapix/java_api/android/net/sip/SipProfile.h>
#include <scapix/java_api/android/net/sip/SipSession_Listener.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::net::sip {

inline ref<java::lang::String> SipSession::getLocalIp() { return call_method<SCAPIX_META_STRING("getLocalIp"), ref<java::lang::String>>(); }
inline ref<android::net::sip::SipProfile> SipSession::getLocalProfile() { return call_method<SCAPIX_META_STRING("getLocalProfile"), ref<android::net::sip::SipProfile>>(); }
inline ref<android::net::sip::SipProfile> SipSession::getPeerProfile() { return call_method<SCAPIX_META_STRING("getPeerProfile"), ref<android::net::sip::SipProfile>>(); }
inline jint SipSession::getState() { return call_method<SCAPIX_META_STRING("getState"), jint>(); }
inline jboolean SipSession::isInCall() { return call_method<SCAPIX_META_STRING("isInCall"), jboolean>(); }
inline ref<java::lang::String> SipSession::getCallId() { return call_method<SCAPIX_META_STRING("getCallId"), ref<java::lang::String>>(); }
inline void SipSession::setListener(ref<android::net::sip::SipSession_Listener> listener) { return call_method<SCAPIX_META_STRING("setListener"), void>(listener); }
inline void SipSession::register_(jint duration) { return call_method<SCAPIX_META_STRING("register"), void>(duration); }
inline void SipSession::unregister() { return call_method<SCAPIX_META_STRING("unregister"), void>(); }
inline void SipSession::makeCall(ref<android::net::sip::SipProfile> callee, ref<java::lang::String> sessionDescription, jint timeout) { return call_method<SCAPIX_META_STRING("makeCall"), void>(callee, sessionDescription, timeout); }
inline void SipSession::answerCall(ref<java::lang::String> sessionDescription, jint timeout) { return call_method<SCAPIX_META_STRING("answerCall"), void>(sessionDescription, timeout); }
inline void SipSession::endCall() { return call_method<SCAPIX_META_STRING("endCall"), void>(); }
inline void SipSession::changeCall(ref<java::lang::String> sessionDescription, jint timeout) { return call_method<SCAPIX_META_STRING("changeCall"), void>(sessionDescription, timeout); }

} // namespace android::net::sip
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NET_SIP_SIPSESSION_H
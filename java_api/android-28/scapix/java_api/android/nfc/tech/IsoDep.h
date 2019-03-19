// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/nfc/tech/TagTechnology.h>

#ifndef SCAPIX_ANDROID_NFC_TECH_ISODEP_H
#define SCAPIX_ANDROID_NFC_TECH_ISODEP_H

namespace scapix::java_api {

namespace android::nfc { class Tag; }

namespace android::nfc::tech {

class IsoDep : public object_base<SCAPIX_META_STRING("android/nfc/tech/IsoDep"),
	java::lang::Object,
	android::nfc::tech::TagTechnology>
{
public:

	static ref<android::nfc::tech::IsoDep> get(ref<android::nfc::Tag> tag);
	void setTimeout(jint timeout);
	jint getTimeout();
	ref<link::java::array<jbyte>> getHistoricalBytes();
	ref<link::java::array<jbyte>> getHiLayerResponse();
	ref<link::java::array<jbyte>> transceive(ref<link::java::array<jbyte>> data);
	jint getMaxTransceiveLength();
	jboolean isExtendedLengthApduSupported();
	jboolean isConnected();
	ref<android::nfc::Tag> getTag();
	void close();
	void connect();

protected:

	IsoDep(handle_type h) : base_(h) {}

};

} // namespace android::nfc::tech
} // namespace scapix::java_api

#include <scapix/java_api/android/nfc/Tag.h>

namespace scapix::java_api {
namespace android::nfc::tech {

inline ref<android::nfc::tech::IsoDep> IsoDep::get(ref<android::nfc::Tag> tag) { return call_static_method<SCAPIX_META_STRING("get"), ref<android::nfc::tech::IsoDep>>(tag); }
inline void IsoDep::setTimeout(jint timeout) { return call_method<SCAPIX_META_STRING("setTimeout"), void>(timeout); }
inline jint IsoDep::getTimeout() { return call_method<SCAPIX_META_STRING("getTimeout"), jint>(); }
inline ref<link::java::array<jbyte>> IsoDep::getHistoricalBytes() { return call_method<SCAPIX_META_STRING("getHistoricalBytes"), ref<link::java::array<jbyte>>>(); }
inline ref<link::java::array<jbyte>> IsoDep::getHiLayerResponse() { return call_method<SCAPIX_META_STRING("getHiLayerResponse"), ref<link::java::array<jbyte>>>(); }
inline ref<link::java::array<jbyte>> IsoDep::transceive(ref<link::java::array<jbyte>> data) { return call_method<SCAPIX_META_STRING("transceive"), ref<link::java::array<jbyte>>>(data); }
inline jint IsoDep::getMaxTransceiveLength() { return call_method<SCAPIX_META_STRING("getMaxTransceiveLength"), jint>(); }
inline jboolean IsoDep::isExtendedLengthApduSupported() { return call_method<SCAPIX_META_STRING("isExtendedLengthApduSupported"), jboolean>(); }
inline jboolean IsoDep::isConnected() { return call_method<SCAPIX_META_STRING("isConnected"), jboolean>(); }
inline ref<android::nfc::Tag> IsoDep::getTag() { return call_method<SCAPIX_META_STRING("getTag"), ref<android::nfc::Tag>>(); }
inline void IsoDep::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }
inline void IsoDep::connect() { return call_method<SCAPIX_META_STRING("connect"), void>(); }

} // namespace android::nfc::tech
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_NFC_TECH_ISODEP_H
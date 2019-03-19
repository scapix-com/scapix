// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_APP_ASSIST_ASSISTCONTENT_H
#define SCAPIX_ANDROID_APP_ASSIST_ASSISTCONTENT_H

namespace scapix::java_api {

namespace android::content { class ClipData; }
namespace android::content { class Intent; }
namespace android::net { class Uri; }
namespace android::os { class Bundle; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class String; }

namespace android::app::assist {

class AssistContent : public object_base<SCAPIX_META_STRING("android/app/assist/AssistContent"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();

	static ref<AssistContent> new_object();
	void setIntent(ref<android::content::Intent> intent);
	ref<android::content::Intent> getIntent();
	jboolean isAppProvidedIntent();
	void setClipData(ref<android::content::ClipData> clip);
	ref<android::content::ClipData> getClipData();
	void setStructuredData(ref<java::lang::String> structuredData);
	ref<java::lang::String> getStructuredData();
	void setWebUri(ref<android::net::Uri> uri);
	ref<android::net::Uri> getWebUri();
	jboolean isAppProvidedWebUri();
	ref<android::os::Bundle> getExtras();
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);

protected:

	AssistContent(handle_type h) : base_(h) {}

};

} // namespace android::app::assist
} // namespace scapix::java_api

#include <scapix/java_api/android/content/ClipData.h>
#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::app::assist {

inline ref<android::os::Parcelable_Creator> AssistContent::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<AssistContent> AssistContent::new_object() { return base_::new_object(); }
inline void AssistContent::setIntent(ref<android::content::Intent> intent) { return call_method<SCAPIX_META_STRING("setIntent"), void>(intent); }
inline ref<android::content::Intent> AssistContent::getIntent() { return call_method<SCAPIX_META_STRING("getIntent"), ref<android::content::Intent>>(); }
inline jboolean AssistContent::isAppProvidedIntent() { return call_method<SCAPIX_META_STRING("isAppProvidedIntent"), jboolean>(); }
inline void AssistContent::setClipData(ref<android::content::ClipData> clip) { return call_method<SCAPIX_META_STRING("setClipData"), void>(clip); }
inline ref<android::content::ClipData> AssistContent::getClipData() { return call_method<SCAPIX_META_STRING("getClipData"), ref<android::content::ClipData>>(); }
inline void AssistContent::setStructuredData(ref<java::lang::String> structuredData) { return call_method<SCAPIX_META_STRING("setStructuredData"), void>(structuredData); }
inline ref<java::lang::String> AssistContent::getStructuredData() { return call_method<SCAPIX_META_STRING("getStructuredData"), ref<java::lang::String>>(); }
inline void AssistContent::setWebUri(ref<android::net::Uri> uri) { return call_method<SCAPIX_META_STRING("setWebUri"), void>(uri); }
inline ref<android::net::Uri> AssistContent::getWebUri() { return call_method<SCAPIX_META_STRING("getWebUri"), ref<android::net::Uri>>(); }
inline jboolean AssistContent::isAppProvidedWebUri() { return call_method<SCAPIX_META_STRING("isAppProvidedWebUri"), jboolean>(); }
inline ref<android::os::Bundle> AssistContent::getExtras() { return call_method<SCAPIX_META_STRING("getExtras"), ref<android::os::Bundle>>(); }
inline jint AssistContent::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void AssistContent::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }

} // namespace android::app::assist
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_ASSIST_ASSISTCONTENT_H
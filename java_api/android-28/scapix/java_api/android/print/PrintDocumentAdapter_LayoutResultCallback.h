// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_PRINT_PRINTDOCUMENTADAPTER_LAYOUTRESULTCALLBACK_H
#define SCAPIX_ANDROID_PRINT_PRINTDOCUMENTADAPTER_LAYOUTRESULTCALLBACK_H

namespace scapix::java_api {

namespace android::print { class PrintDocumentInfo; }
namespace java::lang { class CharSequence; }

namespace android::print {

class PrintDocumentAdapter_LayoutResultCallback : public object_base<SCAPIX_META_STRING("android/print/PrintDocumentAdapter$LayoutResultCallback"),
	java::lang::Object>
{
public:

	void onLayoutFinished(ref<android::print::PrintDocumentInfo> info, jboolean changed);
	void onLayoutFailed(ref<java::lang::CharSequence> error);
	void onLayoutCancelled();

protected:

	PrintDocumentAdapter_LayoutResultCallback(handle_type h) : base_(h) {}

};

} // namespace android::print
} // namespace scapix::java_api

#include <scapix/java_api/android/print/PrintDocumentInfo.h>
#include <scapix/java_api/java/lang/CharSequence.h>

namespace scapix::java_api {
namespace android::print {

inline void PrintDocumentAdapter_LayoutResultCallback::onLayoutFinished(ref<android::print::PrintDocumentInfo> info, jboolean changed) { return call_method<SCAPIX_META_STRING("onLayoutFinished"), void>(info, changed); }
inline void PrintDocumentAdapter_LayoutResultCallback::onLayoutFailed(ref<java::lang::CharSequence> error) { return call_method<SCAPIX_META_STRING("onLayoutFailed"), void>(error); }
inline void PrintDocumentAdapter_LayoutResultCallback::onLayoutCancelled() { return call_method<SCAPIX_META_STRING("onLayoutCancelled"), void>(); }

} // namespace android::print
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PRINT_PRINTDOCUMENTADAPTER_LAYOUTRESULTCALLBACK_H
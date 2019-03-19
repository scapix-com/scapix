// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_TEXTCLASSIFIER_TEXTLINKS_REQUEST_BUILDER_H
#define SCAPIX_ANDROID_VIEW_TEXTCLASSIFIER_TEXTLINKS_REQUEST_BUILDER_H

namespace scapix::java_api {

namespace android::os { class LocaleList; }
namespace android::view::textclassifier { class TextClassifier_EntityConfig; }
namespace android::view::textclassifier { class TextLinks_Request; }
namespace java::lang { class CharSequence; }

namespace android::view::textclassifier {

class TextLinks_Request_Builder : public object_base<SCAPIX_META_STRING("android/view/textclassifier/TextLinks$Request$Builder"),
	java::lang::Object>
{
public:

	static ref<TextLinks_Request_Builder> new_object(ref<java::lang::CharSequence> text);
	ref<android::view::textclassifier::TextLinks_Request_Builder> setDefaultLocales(ref<android::os::LocaleList> defaultLocales);
	ref<android::view::textclassifier::TextLinks_Request_Builder> setEntityConfig(ref<android::view::textclassifier::TextClassifier_EntityConfig> entityConfig);
	ref<android::view::textclassifier::TextLinks_Request> build();

protected:

	TextLinks_Request_Builder(handle_type h) : base_(h) {}

};

} // namespace android::view::textclassifier
} // namespace scapix::java_api

#include <scapix/java_api/android/os/LocaleList.h>
#include <scapix/java_api/android/view/textclassifier/TextClassifier_EntityConfig.h>
#include <scapix/java_api/android/view/textclassifier/TextLinks_Request.h>
#include <scapix/java_api/java/lang/CharSequence.h>

namespace scapix::java_api {
namespace android::view::textclassifier {

inline ref<TextLinks_Request_Builder> TextLinks_Request_Builder::new_object(ref<java::lang::CharSequence> text) { return base_::new_object(text); }
inline ref<android::view::textclassifier::TextLinks_Request_Builder> TextLinks_Request_Builder::setDefaultLocales(ref<android::os::LocaleList> defaultLocales) { return call_method<SCAPIX_META_STRING("setDefaultLocales"), ref<android::view::textclassifier::TextLinks_Request_Builder>>(defaultLocales); }
inline ref<android::view::textclassifier::TextLinks_Request_Builder> TextLinks_Request_Builder::setEntityConfig(ref<android::view::textclassifier::TextClassifier_EntityConfig> entityConfig) { return call_method<SCAPIX_META_STRING("setEntityConfig"), ref<android::view::textclassifier::TextLinks_Request_Builder>>(entityConfig); }
inline ref<android::view::textclassifier::TextLinks_Request> TextLinks_Request_Builder::build() { return call_method<SCAPIX_META_STRING("build"), ref<android::view::textclassifier::TextLinks_Request>>(); }

} // namespace android::view::textclassifier
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_TEXTCLASSIFIER_TEXTLINKS_REQUEST_BUILDER_H
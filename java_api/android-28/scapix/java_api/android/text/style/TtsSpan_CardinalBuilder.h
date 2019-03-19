// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/text/style/TtsSpan_SemioticClassBuilder.h>

#ifndef SCAPIX_ANDROID_TEXT_STYLE_TTSSPAN_CARDINALBUILDER_H
#define SCAPIX_ANDROID_TEXT_STYLE_TTSSPAN_CARDINALBUILDER_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::text::style {

class TtsSpan_CardinalBuilder : public object_base<SCAPIX_META_STRING("android/text/style/TtsSpan$CardinalBuilder"),
	android::text::style::TtsSpan_SemioticClassBuilder>
{
public:

	static ref<TtsSpan_CardinalBuilder> new_object();
	static ref<TtsSpan_CardinalBuilder> new_object(jlong number);
	static ref<TtsSpan_CardinalBuilder> new_object(ref<java::lang::String> number);
	ref<android::text::style::TtsSpan_CardinalBuilder> setNumber(jlong number);
	ref<android::text::style::TtsSpan_CardinalBuilder> setNumber(ref<java::lang::String> number);

protected:

	TtsSpan_CardinalBuilder(handle_type h) : base_(h) {}

};

} // namespace android::text::style
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::text::style {

inline ref<TtsSpan_CardinalBuilder> TtsSpan_CardinalBuilder::new_object() { return base_::new_object(); }
inline ref<TtsSpan_CardinalBuilder> TtsSpan_CardinalBuilder::new_object(jlong number) { return base_::new_object(number); }
inline ref<TtsSpan_CardinalBuilder> TtsSpan_CardinalBuilder::new_object(ref<java::lang::String> number) { return base_::new_object(number); }
inline ref<android::text::style::TtsSpan_CardinalBuilder> TtsSpan_CardinalBuilder::setNumber(jlong number) { return call_method<SCAPIX_META_STRING("setNumber"), ref<android::text::style::TtsSpan_CardinalBuilder>>(number); }
inline ref<android::text::style::TtsSpan_CardinalBuilder> TtsSpan_CardinalBuilder::setNumber(ref<java::lang::String> number) { return call_method<SCAPIX_META_STRING("setNumber"), ref<android::text::style::TtsSpan_CardinalBuilder>>(number); }

} // namespace android::text::style
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_TEXT_STYLE_TTSSPAN_CARDINALBUILDER_H
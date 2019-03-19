// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_APP_SLICE_SLICEITEM_H
#define SCAPIX_ANDROID_APP_SLICE_SLICEITEM_H

namespace scapix::java_api {

namespace android::app { class PendingIntent; }
namespace android::app { class RemoteInput; }
namespace android::app::slice { class Slice; }
namespace android::graphics::drawable { class Icon; }
namespace android::os { class Bundle; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::util { class List; }

namespace android::app::slice {

class SliceItem : public object_base<SCAPIX_META_STRING("android/app/slice/SliceItem"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static ref<java::lang::String> FORMAT_ACTION_();
	static ref<java::lang::String> FORMAT_BUNDLE_();
	static ref<java::lang::String> FORMAT_IMAGE_();
	static ref<java::lang::String> FORMAT_INT_();
	static ref<java::lang::String> FORMAT_LONG_();
	static ref<java::lang::String> FORMAT_REMOTE_INPUT_();
	static ref<java::lang::String> FORMAT_SLICE_();
	static ref<java::lang::String> FORMAT_TEXT_();

	ref<java::util::List> getHints();
	ref<java::lang::String> getFormat();
	ref<java::lang::String> getSubType();
	ref<java::lang::CharSequence> getText();
	ref<android::os::Bundle> getBundle();
	ref<android::graphics::drawable::Icon> getIcon();
	ref<android::app::PendingIntent> getAction();
	ref<android::app::RemoteInput> getRemoteInput();
	jint getInt();
	ref<android::app::slice::Slice> getSlice();
	jlong getLong();
	jboolean hasHint(ref<java::lang::String> hint);
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);

protected:

	SliceItem(handle_type h) : base_(h) {}

};

} // namespace android::app::slice
} // namespace scapix::java_api

#include <scapix/java_api/android/app/PendingIntent.h>
#include <scapix/java_api/android/app/RemoteInput.h>
#include <scapix/java_api/android/app/slice/Slice.h>
#include <scapix/java_api/android/graphics/drawable/Icon.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::app::slice {

inline ref<android::os::Parcelable_Creator> SliceItem::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_ACTION_() { return get_static_field<SCAPIX_META_STRING("FORMAT_ACTION"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_BUNDLE_() { return get_static_field<SCAPIX_META_STRING("FORMAT_BUNDLE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_IMAGE_() { return get_static_field<SCAPIX_META_STRING("FORMAT_IMAGE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_INT_() { return get_static_field<SCAPIX_META_STRING("FORMAT_INT"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_LONG_() { return get_static_field<SCAPIX_META_STRING("FORMAT_LONG"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_REMOTE_INPUT_() { return get_static_field<SCAPIX_META_STRING("FORMAT_REMOTE_INPUT"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_SLICE_() { return get_static_field<SCAPIX_META_STRING("FORMAT_SLICE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::FORMAT_TEXT_() { return get_static_field<SCAPIX_META_STRING("FORMAT_TEXT"), ref<java::lang::String>>(); }
inline ref<java::util::List> SliceItem::getHints() { return call_method<SCAPIX_META_STRING("getHints"), ref<java::util::List>>(); }
inline ref<java::lang::String> SliceItem::getFormat() { return call_method<SCAPIX_META_STRING("getFormat"), ref<java::lang::String>>(); }
inline ref<java::lang::String> SliceItem::getSubType() { return call_method<SCAPIX_META_STRING("getSubType"), ref<java::lang::String>>(); }
inline ref<java::lang::CharSequence> SliceItem::getText() { return call_method<SCAPIX_META_STRING("getText"), ref<java::lang::CharSequence>>(); }
inline ref<android::os::Bundle> SliceItem::getBundle() { return call_method<SCAPIX_META_STRING("getBundle"), ref<android::os::Bundle>>(); }
inline ref<android::graphics::drawable::Icon> SliceItem::getIcon() { return call_method<SCAPIX_META_STRING("getIcon"), ref<android::graphics::drawable::Icon>>(); }
inline ref<android::app::PendingIntent> SliceItem::getAction() { return call_method<SCAPIX_META_STRING("getAction"), ref<android::app::PendingIntent>>(); }
inline ref<android::app::RemoteInput> SliceItem::getRemoteInput() { return call_method<SCAPIX_META_STRING("getRemoteInput"), ref<android::app::RemoteInput>>(); }
inline jint SliceItem::getInt() { return call_method<SCAPIX_META_STRING("getInt"), jint>(); }
inline ref<android::app::slice::Slice> SliceItem::getSlice() { return call_method<SCAPIX_META_STRING("getSlice"), ref<android::app::slice::Slice>>(); }
inline jlong SliceItem::getLong() { return call_method<SCAPIX_META_STRING("getLong"), jlong>(); }
inline jboolean SliceItem::hasHint(ref<java::lang::String> hint) { return call_method<SCAPIX_META_STRING("hasHint"), jboolean>(hint); }
inline jint SliceItem::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void SliceItem::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }

} // namespace android::app::slice
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_SLICE_SLICEITEM_H
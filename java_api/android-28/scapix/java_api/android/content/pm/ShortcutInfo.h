// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_CONTENT_PM_SHORTCUTINFO_H
#define SCAPIX_ANDROID_CONTENT_PM_SHORTCUTINFO_H

namespace scapix::java_api {

namespace android::content { class ComponentName; }
namespace android::content { class Intent; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace android::os { class PersistableBundle; }
namespace android::os { class UserHandle; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::util { class Set; }
namespace android::content::pm { class ShortcutInfo_Builder; }

namespace android::content::pm {

class ShortcutInfo : public object_base<SCAPIX_META_STRING("android/content/pm/ShortcutInfo"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	using Builder = ShortcutInfo_Builder;

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint DISABLED_REASON_APP_CHANGED_();
	static jint DISABLED_REASON_BACKUP_NOT_SUPPORTED_();
	static jint DISABLED_REASON_BY_APP_();
	static jint DISABLED_REASON_NOT_DISABLED_();
	static jint DISABLED_REASON_OTHER_RESTORE_ISSUE_();
	static jint DISABLED_REASON_SIGNATURE_MISMATCH_();
	static jint DISABLED_REASON_UNKNOWN_();
	static jint DISABLED_REASON_VERSION_LOWER_();
	static ref<java::lang::String> SHORTCUT_CATEGORY_CONVERSATION_();

	ref<java::lang::String> getId();
	ref<java::lang::String> getPackage();
	ref<android::content::ComponentName> getActivity();
	ref<java::lang::CharSequence> getShortLabel();
	ref<java::lang::CharSequence> getLongLabel();
	ref<java::lang::CharSequence> getDisabledMessage();
	jint getDisabledReason();
	ref<java::util::Set> getCategories();
	ref<android::content::Intent> getIntent();
	ref<link::java::array<android::content::Intent>> getIntents();
	jint getRank();
	ref<android::os::PersistableBundle> getExtras();
	ref<android::os::UserHandle> getUserHandle();
	jlong getLastChangedTimestamp();
	jboolean isDynamic();
	jboolean isPinned();
	jboolean isDeclaredInManifest();
	jboolean isImmutable();
	jboolean isEnabled();
	jboolean hasKeyFieldsOnly();
	void writeToParcel(ref<android::os::Parcel> dest, jint flags);
	jint describeContents();
	ref<java::lang::String> toString();

protected:

	ShortcutInfo(handle_type h) : base_(h) {}

};

} // namespace android::content::pm
} // namespace scapix::java_api

#include <scapix/java_api/android/content/ComponentName.h>
#include <scapix/java_api/android/content/Intent.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/android/os/PersistableBundle.h>
#include <scapix/java_api/android/os/UserHandle.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Set.h>

namespace scapix::java_api {
namespace android::content::pm {

inline ref<android::os::Parcelable_Creator> ShortcutInfo::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint ShortcutInfo::DISABLED_REASON_APP_CHANGED_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_APP_CHANGED"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_BACKUP_NOT_SUPPORTED_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_BACKUP_NOT_SUPPORTED"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_BY_APP_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_BY_APP"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_NOT_DISABLED_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_NOT_DISABLED"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_OTHER_RESTORE_ISSUE_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_OTHER_RESTORE_ISSUE"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_SIGNATURE_MISMATCH_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_SIGNATURE_MISMATCH"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_UNKNOWN_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_UNKNOWN"), jint>(); }
inline jint ShortcutInfo::DISABLED_REASON_VERSION_LOWER_() { return get_static_field<SCAPIX_META_STRING("DISABLED_REASON_VERSION_LOWER"), jint>(); }
inline ref<java::lang::String> ShortcutInfo::SHORTCUT_CATEGORY_CONVERSATION_() { return get_static_field<SCAPIX_META_STRING("SHORTCUT_CATEGORY_CONVERSATION"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ShortcutInfo::getId() { return call_method<SCAPIX_META_STRING("getId"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ShortcutInfo::getPackage() { return call_method<SCAPIX_META_STRING("getPackage"), ref<java::lang::String>>(); }
inline ref<android::content::ComponentName> ShortcutInfo::getActivity() { return call_method<SCAPIX_META_STRING("getActivity"), ref<android::content::ComponentName>>(); }
inline ref<java::lang::CharSequence> ShortcutInfo::getShortLabel() { return call_method<SCAPIX_META_STRING("getShortLabel"), ref<java::lang::CharSequence>>(); }
inline ref<java::lang::CharSequence> ShortcutInfo::getLongLabel() { return call_method<SCAPIX_META_STRING("getLongLabel"), ref<java::lang::CharSequence>>(); }
inline ref<java::lang::CharSequence> ShortcutInfo::getDisabledMessage() { return call_method<SCAPIX_META_STRING("getDisabledMessage"), ref<java::lang::CharSequence>>(); }
inline jint ShortcutInfo::getDisabledReason() { return call_method<SCAPIX_META_STRING("getDisabledReason"), jint>(); }
inline ref<java::util::Set> ShortcutInfo::getCategories() { return call_method<SCAPIX_META_STRING("getCategories"), ref<java::util::Set>>(); }
inline ref<android::content::Intent> ShortcutInfo::getIntent() { return call_method<SCAPIX_META_STRING("getIntent"), ref<android::content::Intent>>(); }
inline ref<link::java::array<android::content::Intent>> ShortcutInfo::getIntents() { return call_method<SCAPIX_META_STRING("getIntents"), ref<link::java::array<android::content::Intent>>>(); }
inline jint ShortcutInfo::getRank() { return call_method<SCAPIX_META_STRING("getRank"), jint>(); }
inline ref<android::os::PersistableBundle> ShortcutInfo::getExtras() { return call_method<SCAPIX_META_STRING("getExtras"), ref<android::os::PersistableBundle>>(); }
inline ref<android::os::UserHandle> ShortcutInfo::getUserHandle() { return call_method<SCAPIX_META_STRING("getUserHandle"), ref<android::os::UserHandle>>(); }
inline jlong ShortcutInfo::getLastChangedTimestamp() { return call_method<SCAPIX_META_STRING("getLastChangedTimestamp"), jlong>(); }
inline jboolean ShortcutInfo::isDynamic() { return call_method<SCAPIX_META_STRING("isDynamic"), jboolean>(); }
inline jboolean ShortcutInfo::isPinned() { return call_method<SCAPIX_META_STRING("isPinned"), jboolean>(); }
inline jboolean ShortcutInfo::isDeclaredInManifest() { return call_method<SCAPIX_META_STRING("isDeclaredInManifest"), jboolean>(); }
inline jboolean ShortcutInfo::isImmutable() { return call_method<SCAPIX_META_STRING("isImmutable"), jboolean>(); }
inline jboolean ShortcutInfo::isEnabled() { return call_method<SCAPIX_META_STRING("isEnabled"), jboolean>(); }
inline jboolean ShortcutInfo::hasKeyFieldsOnly() { return call_method<SCAPIX_META_STRING("hasKeyFieldsOnly"), jboolean>(); }
inline void ShortcutInfo::writeToParcel(ref<android::os::Parcel> dest, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(dest, flags); }
inline jint ShortcutInfo::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline ref<java::lang::String> ShortcutInfo::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace android::content::pm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_CONTENT_PM_SHORTCUTINFO_H
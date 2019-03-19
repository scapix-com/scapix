// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/provider/ContactsContract_DataColumnsWithJoins.h>
#include <scapix/java_api/android/provider/ContactsContract_CommonDataKinds_CommonColumns.h>

#ifndef SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_COMMONDATAKINDS_PHONE_H
#define SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_COMMONDATAKINDS_PHONE_H

namespace scapix::java_api {

namespace android::content::res { class Resources; }
namespace android::net { class Uri; }
namespace java::lang { class CharSequence; }
namespace java::lang { class String; }

namespace android::provider {

class ContactsContract_CommonDataKinds_Phone : public object_base<SCAPIX_META_STRING("android/provider/ContactsContract$CommonDataKinds$Phone"),
	java::lang::Object,
	android::provider::ContactsContract_DataColumnsWithJoins,
	android::provider::ContactsContract_CommonDataKinds_CommonColumns>
{
public:

	static ref<android::net::Uri> CONTENT_FILTER_URI_();
	static ref<java::lang::String> CONTENT_ITEM_TYPE_();
	static ref<java::lang::String> CONTENT_TYPE_();
	static ref<android::net::Uri> CONTENT_URI_();
	static ref<android::net::Uri> ENTERPRISE_CONTENT_FILTER_URI_();
	static ref<java::lang::String> EXTRA_ADDRESS_BOOK_INDEX_();
	static ref<java::lang::String> EXTRA_ADDRESS_BOOK_INDEX_COUNTS_();
	static ref<java::lang::String> EXTRA_ADDRESS_BOOK_INDEX_TITLES_();
	static ref<java::lang::String> NORMALIZED_NUMBER_();
	static ref<java::lang::String> NUMBER_();
	static ref<java::lang::String> SEARCH_DISPLAY_NAME_KEY_();
	static ref<java::lang::String> SEARCH_PHONE_NUMBER_KEY_();
	static jint TYPE_ASSISTANT_();
	static jint TYPE_CALLBACK_();
	static jint TYPE_CAR_();
	static jint TYPE_COMPANY_MAIN_();
	static jint TYPE_FAX_HOME_();
	static jint TYPE_FAX_WORK_();
	static jint TYPE_HOME_();
	static jint TYPE_ISDN_();
	static jint TYPE_MAIN_();
	static jint TYPE_MMS_();
	static jint TYPE_MOBILE_();
	static jint TYPE_OTHER_();
	static jint TYPE_OTHER_FAX_();
	static jint TYPE_PAGER_();
	static jint TYPE_RADIO_();
	static jint TYPE_TELEX_();
	static jint TYPE_TTY_TDD_();
	static jint TYPE_WORK_();
	static jint TYPE_WORK_MOBILE_();
	static jint TYPE_WORK_PAGER_();

	static jint getTypeLabelResource(jint type);
	static ref<java::lang::CharSequence> getTypeLabel(ref<android::content::res::Resources> res, jint type, ref<java::lang::CharSequence> label);

protected:

	ContactsContract_CommonDataKinds_Phone(handle_type h) : base_(h) {}

};

} // namespace android::provider
} // namespace scapix::java_api

#include <scapix/java_api/android/content/res/Resources.h>
#include <scapix/java_api/android/net/Uri.h>
#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::provider {

inline ref<android::net::Uri> ContactsContract_CommonDataKinds_Phone::CONTENT_FILTER_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_FILTER_URI"), ref<android::net::Uri>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::CONTENT_ITEM_TYPE_() { return get_static_field<SCAPIX_META_STRING("CONTENT_ITEM_TYPE"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::CONTENT_TYPE_() { return get_static_field<SCAPIX_META_STRING("CONTENT_TYPE"), ref<java::lang::String>>(); }
inline ref<android::net::Uri> ContactsContract_CommonDataKinds_Phone::CONTENT_URI_() { return get_static_field<SCAPIX_META_STRING("CONTENT_URI"), ref<android::net::Uri>>(); }
inline ref<android::net::Uri> ContactsContract_CommonDataKinds_Phone::ENTERPRISE_CONTENT_FILTER_URI_() { return get_static_field<SCAPIX_META_STRING("ENTERPRISE_CONTENT_FILTER_URI"), ref<android::net::Uri>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::EXTRA_ADDRESS_BOOK_INDEX_() { return get_static_field<SCAPIX_META_STRING("EXTRA_ADDRESS_BOOK_INDEX"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::EXTRA_ADDRESS_BOOK_INDEX_COUNTS_() { return get_static_field<SCAPIX_META_STRING("EXTRA_ADDRESS_BOOK_INDEX_COUNTS"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::EXTRA_ADDRESS_BOOK_INDEX_TITLES_() { return get_static_field<SCAPIX_META_STRING("EXTRA_ADDRESS_BOOK_INDEX_TITLES"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::NORMALIZED_NUMBER_() { return get_static_field<SCAPIX_META_STRING("NORMALIZED_NUMBER"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::NUMBER_() { return get_static_field<SCAPIX_META_STRING("NUMBER"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::SEARCH_DISPLAY_NAME_KEY_() { return get_static_field<SCAPIX_META_STRING("SEARCH_DISPLAY_NAME_KEY"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ContactsContract_CommonDataKinds_Phone::SEARCH_PHONE_NUMBER_KEY_() { return get_static_field<SCAPIX_META_STRING("SEARCH_PHONE_NUMBER_KEY"), ref<java::lang::String>>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_ASSISTANT_() { return get_static_field<SCAPIX_META_STRING("TYPE_ASSISTANT"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_CALLBACK_() { return get_static_field<SCAPIX_META_STRING("TYPE_CALLBACK"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_CAR_() { return get_static_field<SCAPIX_META_STRING("TYPE_CAR"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_COMPANY_MAIN_() { return get_static_field<SCAPIX_META_STRING("TYPE_COMPANY_MAIN"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_FAX_HOME_() { return get_static_field<SCAPIX_META_STRING("TYPE_FAX_HOME"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_FAX_WORK_() { return get_static_field<SCAPIX_META_STRING("TYPE_FAX_WORK"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_HOME_() { return get_static_field<SCAPIX_META_STRING("TYPE_HOME"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_ISDN_() { return get_static_field<SCAPIX_META_STRING("TYPE_ISDN"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_MAIN_() { return get_static_field<SCAPIX_META_STRING("TYPE_MAIN"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_MMS_() { return get_static_field<SCAPIX_META_STRING("TYPE_MMS"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_MOBILE_() { return get_static_field<SCAPIX_META_STRING("TYPE_MOBILE"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_OTHER_() { return get_static_field<SCAPIX_META_STRING("TYPE_OTHER"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_OTHER_FAX_() { return get_static_field<SCAPIX_META_STRING("TYPE_OTHER_FAX"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_PAGER_() { return get_static_field<SCAPIX_META_STRING("TYPE_PAGER"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_RADIO_() { return get_static_field<SCAPIX_META_STRING("TYPE_RADIO"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_TELEX_() { return get_static_field<SCAPIX_META_STRING("TYPE_TELEX"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_TTY_TDD_() { return get_static_field<SCAPIX_META_STRING("TYPE_TTY_TDD"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_WORK_() { return get_static_field<SCAPIX_META_STRING("TYPE_WORK"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_WORK_MOBILE_() { return get_static_field<SCAPIX_META_STRING("TYPE_WORK_MOBILE"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::TYPE_WORK_PAGER_() { return get_static_field<SCAPIX_META_STRING("TYPE_WORK_PAGER"), jint>(); }
inline jint ContactsContract_CommonDataKinds_Phone::getTypeLabelResource(jint type) { return call_static_method<SCAPIX_META_STRING("getTypeLabelResource"), jint>(type); }
inline ref<java::lang::CharSequence> ContactsContract_CommonDataKinds_Phone::getTypeLabel(ref<android::content::res::Resources> res, jint type, ref<java::lang::CharSequence> label) { return call_static_method<SCAPIX_META_STRING("getTypeLabel"), ref<java::lang::CharSequence>>(res, type, label); }

} // namespace android::provider
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_PROVIDER_CONTACTSCONTRACT_COMMONDATAKINDS_PHONE_H
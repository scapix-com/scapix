// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_APP_ADMIN_SECURITYLOG_H
#define SCAPIX_ANDROID_APP_ADMIN_SECURITYLOG_H

namespace scapix::java_api {

namespace android::app::admin { class SecurityLog_SecurityEvent; }

namespace android::app::admin {

class SecurityLog : public object_base<SCAPIX_META_STRING("android/app/admin/SecurityLog"),
	java::lang::Object>
{
public:

	using SecurityEvent = SecurityLog_SecurityEvent;

	static jint LEVEL_ERROR_();
	static jint LEVEL_INFO_();
	static jint LEVEL_WARNING_();
	static jint TAG_ADB_SHELL_CMD_();
	static jint TAG_ADB_SHELL_INTERACTIVE_();
	static jint TAG_APP_PROCESS_START_();
	static jint TAG_CERT_AUTHORITY_INSTALLED_();
	static jint TAG_CERT_AUTHORITY_REMOVED_();
	static jint TAG_CERT_VALIDATION_FAILURE_();
	static jint TAG_CRYPTO_SELF_TEST_COMPLETED_();
	static jint TAG_KEYGUARD_DISABLED_FEATURES_SET_();
	static jint TAG_KEYGUARD_DISMISSED_();
	static jint TAG_KEYGUARD_DISMISS_AUTH_ATTEMPT_();
	static jint TAG_KEYGUARD_SECURED_();
	static jint TAG_KEY_DESTRUCTION_();
	static jint TAG_KEY_GENERATED_();
	static jint TAG_KEY_IMPORT_();
	static jint TAG_KEY_INTEGRITY_VIOLATION_();
	static jint TAG_LOGGING_STARTED_();
	static jint TAG_LOGGING_STOPPED_();
	static jint TAG_LOG_BUFFER_SIZE_CRITICAL_();
	static jint TAG_MAX_PASSWORD_ATTEMPTS_SET_();
	static jint TAG_MAX_SCREEN_LOCK_TIMEOUT_SET_();
	static jint TAG_MEDIA_MOUNT_();
	static jint TAG_MEDIA_UNMOUNT_();
	static jint TAG_OS_SHUTDOWN_();
	static jint TAG_OS_STARTUP_();
	static jint TAG_PASSWORD_COMPLEXITY_SET_();
	static jint TAG_PASSWORD_EXPIRATION_SET_();
	static jint TAG_PASSWORD_HISTORY_LENGTH_SET_();
	static jint TAG_REMOTE_LOCK_();
	static jint TAG_SYNC_RECV_FILE_();
	static jint TAG_SYNC_SEND_FILE_();
	static jint TAG_USER_RESTRICTION_ADDED_();
	static jint TAG_USER_RESTRICTION_REMOVED_();
	static jint TAG_WIPE_FAILURE_();

	static ref<SecurityLog> new_object();

protected:

	SecurityLog(handle_type h) : base_(h) {}

};

} // namespace android::app::admin
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::app::admin {

inline jint SecurityLog::LEVEL_ERROR_() { return get_static_field<SCAPIX_META_STRING("LEVEL_ERROR"), jint>(); }
inline jint SecurityLog::LEVEL_INFO_() { return get_static_field<SCAPIX_META_STRING("LEVEL_INFO"), jint>(); }
inline jint SecurityLog::LEVEL_WARNING_() { return get_static_field<SCAPIX_META_STRING("LEVEL_WARNING"), jint>(); }
inline jint SecurityLog::TAG_ADB_SHELL_CMD_() { return get_static_field<SCAPIX_META_STRING("TAG_ADB_SHELL_CMD"), jint>(); }
inline jint SecurityLog::TAG_ADB_SHELL_INTERACTIVE_() { return get_static_field<SCAPIX_META_STRING("TAG_ADB_SHELL_INTERACTIVE"), jint>(); }
inline jint SecurityLog::TAG_APP_PROCESS_START_() { return get_static_field<SCAPIX_META_STRING("TAG_APP_PROCESS_START"), jint>(); }
inline jint SecurityLog::TAG_CERT_AUTHORITY_INSTALLED_() { return get_static_field<SCAPIX_META_STRING("TAG_CERT_AUTHORITY_INSTALLED"), jint>(); }
inline jint SecurityLog::TAG_CERT_AUTHORITY_REMOVED_() { return get_static_field<SCAPIX_META_STRING("TAG_CERT_AUTHORITY_REMOVED"), jint>(); }
inline jint SecurityLog::TAG_CERT_VALIDATION_FAILURE_() { return get_static_field<SCAPIX_META_STRING("TAG_CERT_VALIDATION_FAILURE"), jint>(); }
inline jint SecurityLog::TAG_CRYPTO_SELF_TEST_COMPLETED_() { return get_static_field<SCAPIX_META_STRING("TAG_CRYPTO_SELF_TEST_COMPLETED"), jint>(); }
inline jint SecurityLog::TAG_KEYGUARD_DISABLED_FEATURES_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_KEYGUARD_DISABLED_FEATURES_SET"), jint>(); }
inline jint SecurityLog::TAG_KEYGUARD_DISMISSED_() { return get_static_field<SCAPIX_META_STRING("TAG_KEYGUARD_DISMISSED"), jint>(); }
inline jint SecurityLog::TAG_KEYGUARD_DISMISS_AUTH_ATTEMPT_() { return get_static_field<SCAPIX_META_STRING("TAG_KEYGUARD_DISMISS_AUTH_ATTEMPT"), jint>(); }
inline jint SecurityLog::TAG_KEYGUARD_SECURED_() { return get_static_field<SCAPIX_META_STRING("TAG_KEYGUARD_SECURED"), jint>(); }
inline jint SecurityLog::TAG_KEY_DESTRUCTION_() { return get_static_field<SCAPIX_META_STRING("TAG_KEY_DESTRUCTION"), jint>(); }
inline jint SecurityLog::TAG_KEY_GENERATED_() { return get_static_field<SCAPIX_META_STRING("TAG_KEY_GENERATED"), jint>(); }
inline jint SecurityLog::TAG_KEY_IMPORT_() { return get_static_field<SCAPIX_META_STRING("TAG_KEY_IMPORT"), jint>(); }
inline jint SecurityLog::TAG_KEY_INTEGRITY_VIOLATION_() { return get_static_field<SCAPIX_META_STRING("TAG_KEY_INTEGRITY_VIOLATION"), jint>(); }
inline jint SecurityLog::TAG_LOGGING_STARTED_() { return get_static_field<SCAPIX_META_STRING("TAG_LOGGING_STARTED"), jint>(); }
inline jint SecurityLog::TAG_LOGGING_STOPPED_() { return get_static_field<SCAPIX_META_STRING("TAG_LOGGING_STOPPED"), jint>(); }
inline jint SecurityLog::TAG_LOG_BUFFER_SIZE_CRITICAL_() { return get_static_field<SCAPIX_META_STRING("TAG_LOG_BUFFER_SIZE_CRITICAL"), jint>(); }
inline jint SecurityLog::TAG_MAX_PASSWORD_ATTEMPTS_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_MAX_PASSWORD_ATTEMPTS_SET"), jint>(); }
inline jint SecurityLog::TAG_MAX_SCREEN_LOCK_TIMEOUT_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_MAX_SCREEN_LOCK_TIMEOUT_SET"), jint>(); }
inline jint SecurityLog::TAG_MEDIA_MOUNT_() { return get_static_field<SCAPIX_META_STRING("TAG_MEDIA_MOUNT"), jint>(); }
inline jint SecurityLog::TAG_MEDIA_UNMOUNT_() { return get_static_field<SCAPIX_META_STRING("TAG_MEDIA_UNMOUNT"), jint>(); }
inline jint SecurityLog::TAG_OS_SHUTDOWN_() { return get_static_field<SCAPIX_META_STRING("TAG_OS_SHUTDOWN"), jint>(); }
inline jint SecurityLog::TAG_OS_STARTUP_() { return get_static_field<SCAPIX_META_STRING("TAG_OS_STARTUP"), jint>(); }
inline jint SecurityLog::TAG_PASSWORD_COMPLEXITY_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_PASSWORD_COMPLEXITY_SET"), jint>(); }
inline jint SecurityLog::TAG_PASSWORD_EXPIRATION_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_PASSWORD_EXPIRATION_SET"), jint>(); }
inline jint SecurityLog::TAG_PASSWORD_HISTORY_LENGTH_SET_() { return get_static_field<SCAPIX_META_STRING("TAG_PASSWORD_HISTORY_LENGTH_SET"), jint>(); }
inline jint SecurityLog::TAG_REMOTE_LOCK_() { return get_static_field<SCAPIX_META_STRING("TAG_REMOTE_LOCK"), jint>(); }
inline jint SecurityLog::TAG_SYNC_RECV_FILE_() { return get_static_field<SCAPIX_META_STRING("TAG_SYNC_RECV_FILE"), jint>(); }
inline jint SecurityLog::TAG_SYNC_SEND_FILE_() { return get_static_field<SCAPIX_META_STRING("TAG_SYNC_SEND_FILE"), jint>(); }
inline jint SecurityLog::TAG_USER_RESTRICTION_ADDED_() { return get_static_field<SCAPIX_META_STRING("TAG_USER_RESTRICTION_ADDED"), jint>(); }
inline jint SecurityLog::TAG_USER_RESTRICTION_REMOVED_() { return get_static_field<SCAPIX_META_STRING("TAG_USER_RESTRICTION_REMOVED"), jint>(); }
inline jint SecurityLog::TAG_WIPE_FAILURE_() { return get_static_field<SCAPIX_META_STRING("TAG_WIPE_FAILURE"), jint>(); }
inline ref<SecurityLog> SecurityLog::new_object() { return base_::new_object(); }

} // namespace android::app::admin
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_ADMIN_SECURITYLOG_H

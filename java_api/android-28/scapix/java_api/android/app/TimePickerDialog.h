// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/app/AlertDialog.h>
#include <scapix/java_api/android/content/DialogInterface_OnClickListener.h>
#include <scapix/java_api/android/widget/TimePicker_OnTimeChangedListener.h>

#ifndef SCAPIX_ANDROID_APP_TIMEPICKERDIALOG_H
#define SCAPIX_ANDROID_APP_TIMEPICKERDIALOG_H

namespace scapix::java_api {

namespace android::app { class TimePickerDialog_OnTimeSetListener; }
namespace android::content { class Context; }
namespace android::content { class DialogInterface; }
namespace android::os { class Bundle; }
namespace android::widget { class TimePicker; }

namespace android::app {

class TimePickerDialog : public object_base<SCAPIX_META_STRING("android/app/TimePickerDialog"),
	android::app::AlertDialog,
	android::content::DialogInterface_OnClickListener,
	android::widget::TimePicker_OnTimeChangedListener>
{
public:

	using OnTimeSetListener = TimePickerDialog_OnTimeSetListener;

	static ref<TimePickerDialog> new_object(ref<android::content::Context> context, ref<android::app::TimePickerDialog_OnTimeSetListener> listener, jint hourOfDay, jint minute, jboolean is24HourView);
	static ref<TimePickerDialog> new_object(ref<android::content::Context> context, jint themeResId, ref<android::app::TimePickerDialog_OnTimeSetListener> listener, jint hourOfDay, jint minute, jboolean is24HourView);
	void onTimeChanged(ref<android::widget::TimePicker> view, jint hourOfDay, jint minute);
	void show();
	void onClick(ref<android::content::DialogInterface> dialog, jint which);
	void updateTime(jint hourOfDay, jint minuteOfHour);
	ref<android::os::Bundle> onSaveInstanceState();
	void onRestoreInstanceState(ref<android::os::Bundle> savedInstanceState);

protected:

	TimePickerDialog(handle_type h) : base_(h) {}

};

} // namespace android::app
} // namespace scapix::java_api

#include <scapix/java_api/android/app/TimePickerDialog_OnTimeSetListener.h>
#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/content/DialogInterface.h>
#include <scapix/java_api/android/os/Bundle.h>
#include <scapix/java_api/android/widget/TimePicker.h>

namespace scapix::java_api {
namespace android::app {

inline ref<TimePickerDialog> TimePickerDialog::new_object(ref<android::content::Context> context, ref<android::app::TimePickerDialog_OnTimeSetListener> listener, jint hourOfDay, jint minute, jboolean is24HourView) { return base_::new_object(context, listener, hourOfDay, minute, is24HourView); }
inline ref<TimePickerDialog> TimePickerDialog::new_object(ref<android::content::Context> context, jint themeResId, ref<android::app::TimePickerDialog_OnTimeSetListener> listener, jint hourOfDay, jint minute, jboolean is24HourView) { return base_::new_object(context, themeResId, listener, hourOfDay, minute, is24HourView); }
inline void TimePickerDialog::onTimeChanged(ref<android::widget::TimePicker> view, jint hourOfDay, jint minute) { return call_method<SCAPIX_META_STRING("onTimeChanged"), void>(view, hourOfDay, minute); }
inline void TimePickerDialog::show() { return call_method<SCAPIX_META_STRING("show"), void>(); }
inline void TimePickerDialog::onClick(ref<android::content::DialogInterface> dialog, jint which) { return call_method<SCAPIX_META_STRING("onClick"), void>(dialog, which); }
inline void TimePickerDialog::updateTime(jint hourOfDay, jint minuteOfHour) { return call_method<SCAPIX_META_STRING("updateTime"), void>(hourOfDay, minuteOfHour); }
inline ref<android::os::Bundle> TimePickerDialog::onSaveInstanceState() { return call_method<SCAPIX_META_STRING("onSaveInstanceState"), ref<android::os::Bundle>>(); }
inline void TimePickerDialog::onRestoreInstanceState(ref<android::os::Bundle> savedInstanceState) { return call_method<SCAPIX_META_STRING("onRestoreInstanceState"), void>(savedInstanceState); }

} // namespace android::app
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_APP_TIMEPICKERDIALOG_H
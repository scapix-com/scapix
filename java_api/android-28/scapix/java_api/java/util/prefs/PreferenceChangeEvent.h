// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/EventObject.h>

#ifndef SCAPIX_JAVA_UTIL_PREFS_PREFERENCECHANGEEVENT_H
#define SCAPIX_JAVA_UTIL_PREFS_PREFERENCECHANGEEVENT_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::util::prefs { class Preferences; }

namespace java::util::prefs {

class PreferenceChangeEvent : public object_base<SCAPIX_META_STRING("java/util/prefs/PreferenceChangeEvent"),
	java::util::EventObject>
{
public:

	static ref<PreferenceChangeEvent> new_object(ref<java::util::prefs::Preferences> node, ref<java::lang::String> key, ref<java::lang::String> newValue);
	ref<java::util::prefs::Preferences> getNode();
	ref<java::lang::String> getKey();
	ref<java::lang::String> getNewValue();

protected:

	PreferenceChangeEvent(handle_type h) : base_(h) {}

};

} // namespace java::util::prefs
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/prefs/Preferences.h>

namespace scapix::java_api {
namespace java::util::prefs {

inline ref<PreferenceChangeEvent> PreferenceChangeEvent::new_object(ref<java::util::prefs::Preferences> node, ref<java::lang::String> key, ref<java::lang::String> newValue) { return base_::new_object(node, key, newValue); }
inline ref<java::util::prefs::Preferences> PreferenceChangeEvent::getNode() { return call_method<SCAPIX_META_STRING("getNode"), ref<java::util::prefs::Preferences>>(); }
inline ref<java::lang::String> PreferenceChangeEvent::getKey() { return call_method<SCAPIX_META_STRING("getKey"), ref<java::lang::String>>(); }
inline ref<java::lang::String> PreferenceChangeEvent::getNewValue() { return call_method<SCAPIX_META_STRING("getNewValue"), ref<java::lang::String>>(); }

} // namespace java::util::prefs
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_PREFS_PREFERENCECHANGEEVENT_H
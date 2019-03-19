// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_GESTURE_GESTURESTORE_H
#define SCAPIX_ANDROID_GESTURE_GESTURESTORE_H

namespace scapix::java_api {

namespace android::gesture { class Gesture; }
namespace java::io { class InputStream; }
namespace java::io { class OutputStream; }
namespace java::lang { class String; }
namespace java::util { class ArrayList; }
namespace java::util { class Set; }

namespace android::gesture {

class GestureStore : public object_base<SCAPIX_META_STRING("android/gesture/GestureStore"),
	java::lang::Object>
{
public:

	static jint ORIENTATION_INVARIANT_();
	static jint ORIENTATION_SENSITIVE_();
	static jint SEQUENCE_INVARIANT_();
	static jint SEQUENCE_SENSITIVE_();

	static ref<GestureStore> new_object();
	void setOrientationStyle(jint style);
	jint getOrientationStyle();
	void setSequenceType(jint type);
	jint getSequenceType();
	ref<java::util::Set> getGestureEntries();
	ref<java::util::ArrayList> recognize(ref<android::gesture::Gesture> gesture);
	void addGesture(ref<java::lang::String> entryName, ref<android::gesture::Gesture> gesture);
	void removeGesture(ref<java::lang::String> entryName, ref<android::gesture::Gesture> gesture);
	void removeEntry(ref<java::lang::String> entryName);
	ref<java::util::ArrayList> getGestures(ref<java::lang::String> entryName);
	jboolean hasChanged();
	void save(ref<java::io::OutputStream> stream);
	void save(ref<java::io::OutputStream> stream, jboolean closeStream);
	void load(ref<java::io::InputStream> stream);
	void load(ref<java::io::InputStream> stream, jboolean closeStream);

protected:

	GestureStore(handle_type h) : base_(h) {}

};

} // namespace android::gesture
} // namespace scapix::java_api

#include <scapix/java_api/android/gesture/Gesture.h>
#include <scapix/java_api/java/io/InputStream.h>
#include <scapix/java_api/java/io/OutputStream.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/ArrayList.h>
#include <scapix/java_api/java/util/Set.h>

namespace scapix::java_api {
namespace android::gesture {

inline jint GestureStore::ORIENTATION_INVARIANT_() { return get_static_field<SCAPIX_META_STRING("ORIENTATION_INVARIANT"), jint>(); }
inline jint GestureStore::ORIENTATION_SENSITIVE_() { return get_static_field<SCAPIX_META_STRING("ORIENTATION_SENSITIVE"), jint>(); }
inline jint GestureStore::SEQUENCE_INVARIANT_() { return get_static_field<SCAPIX_META_STRING("SEQUENCE_INVARIANT"), jint>(); }
inline jint GestureStore::SEQUENCE_SENSITIVE_() { return get_static_field<SCAPIX_META_STRING("SEQUENCE_SENSITIVE"), jint>(); }
inline ref<GestureStore> GestureStore::new_object() { return base_::new_object(); }
inline void GestureStore::setOrientationStyle(jint style) { return call_method<SCAPIX_META_STRING("setOrientationStyle"), void>(style); }
inline jint GestureStore::getOrientationStyle() { return call_method<SCAPIX_META_STRING("getOrientationStyle"), jint>(); }
inline void GestureStore::setSequenceType(jint type) { return call_method<SCAPIX_META_STRING("setSequenceType"), void>(type); }
inline jint GestureStore::getSequenceType() { return call_method<SCAPIX_META_STRING("getSequenceType"), jint>(); }
inline ref<java::util::Set> GestureStore::getGestureEntries() { return call_method<SCAPIX_META_STRING("getGestureEntries"), ref<java::util::Set>>(); }
inline ref<java::util::ArrayList> GestureStore::recognize(ref<android::gesture::Gesture> gesture) { return call_method<SCAPIX_META_STRING("recognize"), ref<java::util::ArrayList>>(gesture); }
inline void GestureStore::addGesture(ref<java::lang::String> entryName, ref<android::gesture::Gesture> gesture) { return call_method<SCAPIX_META_STRING("addGesture"), void>(entryName, gesture); }
inline void GestureStore::removeGesture(ref<java::lang::String> entryName, ref<android::gesture::Gesture> gesture) { return call_method<SCAPIX_META_STRING("removeGesture"), void>(entryName, gesture); }
inline void GestureStore::removeEntry(ref<java::lang::String> entryName) { return call_method<SCAPIX_META_STRING("removeEntry"), void>(entryName); }
inline ref<java::util::ArrayList> GestureStore::getGestures(ref<java::lang::String> entryName) { return call_method<SCAPIX_META_STRING("getGestures"), ref<java::util::ArrayList>>(entryName); }
inline jboolean GestureStore::hasChanged() { return call_method<SCAPIX_META_STRING("hasChanged"), jboolean>(); }
inline void GestureStore::save(ref<java::io::OutputStream> stream) { return call_method<SCAPIX_META_STRING("save"), void>(stream); }
inline void GestureStore::save(ref<java::io::OutputStream> stream, jboolean closeStream) { return call_method<SCAPIX_META_STRING("save"), void>(stream, closeStream); }
inline void GestureStore::load(ref<java::io::InputStream> stream) { return call_method<SCAPIX_META_STRING("load"), void>(stream); }
inline void GestureStore::load(ref<java::io::InputStream> stream, jboolean closeStream) { return call_method<SCAPIX_META_STRING("load"), void>(stream, closeStream); }

} // namespace android::gesture
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GESTURE_GESTURESTORE_H
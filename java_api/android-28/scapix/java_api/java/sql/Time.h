// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/Date.h>

#ifndef SCAPIX_JAVA_SQL_TIME_H
#define SCAPIX_JAVA_SQL_TIME_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace java::sql {

class Time : public object_base<SCAPIX_META_STRING("java/sql/Time"),
	java::util::Date>
{
public:

	static ref<Time> new_object(jint hour, jint minute, jint second);
	static ref<Time> new_object(jlong time);
	void setTime(jlong time);
	static ref<java::sql::Time> valueOf(ref<java::lang::String> s);
	ref<java::lang::String> toString();
	jint getYear();
	jint getMonth();
	jint getDay();
	jint getDate();
	void setYear(jint i);
	void setMonth(jint i);
	void setDate(jint i);

protected:

	Time(handle_type h) : base_(h) {}

};

} // namespace java::sql
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace java::sql {

inline ref<Time> Time::new_object(jint hour, jint minute, jint second) { return base_::new_object(hour, minute, second); }
inline ref<Time> Time::new_object(jlong time) { return base_::new_object(time); }
inline void Time::setTime(jlong time) { return call_method<SCAPIX_META_STRING("setTime"), void>(time); }
inline ref<java::sql::Time> Time::valueOf(ref<java::lang::String> s) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<java::sql::Time>>(s); }
inline ref<java::lang::String> Time::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jint Time::getYear() { return call_method<SCAPIX_META_STRING("getYear"), jint>(); }
inline jint Time::getMonth() { return call_method<SCAPIX_META_STRING("getMonth"), jint>(); }
inline jint Time::getDay() { return call_method<SCAPIX_META_STRING("getDay"), jint>(); }
inline jint Time::getDate() { return call_method<SCAPIX_META_STRING("getDate"), jint>(); }
inline void Time::setYear(jint i) { return call_method<SCAPIX_META_STRING("setYear"), void>(i); }
inline void Time::setMonth(jint i) { return call_method<SCAPIX_META_STRING("setMonth"), void>(i); }
inline void Time::setDate(jint i) { return call_method<SCAPIX_META_STRING("setDate"), void>(i); }

} // namespace java::sql
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_SQL_TIME_H
// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/Cloneable.h>

#ifndef SCAPIX_JAVAX_XML_DATATYPE_XMLGREGORIANCALENDAR_H
#define SCAPIX_JAVAX_XML_DATATYPE_XMLGREGORIANCALENDAR_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::math { class BigDecimal; }
namespace java::math { class BigInteger; }
namespace java::util { class GregorianCalendar; }
namespace java::util { class Locale; }
namespace java::util { class TimeZone; }
namespace javax::xml::datatype { class Duration; }
namespace javax::xml::namespace { class QName; }

namespace javax::xml::datatype {

class XMLGregorianCalendar : public object_base<SCAPIX_META_STRING("javax/xml/datatype/XMLGregorianCalendar"),
	java::lang::Object,
	java::lang::Cloneable>
{
public:

	static ref<XMLGregorianCalendar> new_object();
	void clear();
	void reset();
	void setYear(ref<java::math::BigInteger> p1);
	void setYear(jint p1);
	void setMonth(jint p1);
	void setDay(jint p1);
	void setTimezone(jint p1);
	void setTime(jint hour, jint minute, jint second);
	void setHour(jint p1);
	void setMinute(jint p1);
	void setSecond(jint p1);
	void setMillisecond(jint p1);
	void setFractionalSecond(ref<java::math::BigDecimal> p1);
	void setTime(jint hour, jint minute, jint second, ref<java::math::BigDecimal> fractional);
	void setTime(jint hour, jint minute, jint second, jint millisecond);
	ref<java::math::BigInteger> getEon();
	jint getYear();
	ref<java::math::BigInteger> getEonAndYear();
	jint getMonth();
	jint getDay();
	jint getTimezone();
	jint getHour();
	jint getMinute();
	jint getSecond();
	jint getMillisecond();
	ref<java::math::BigDecimal> getFractionalSecond();
	jint compare(ref<javax::xml::datatype::XMLGregorianCalendar> p1);
	ref<javax::xml::datatype::XMLGregorianCalendar> normalize();
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toXMLFormat();
	ref<javax::xml::namespace::QName> getXMLSchemaType();
	ref<java::lang::String> toString();
	jboolean isValid();
	void add(ref<javax::xml::datatype::Duration> p1);
	ref<java::util::GregorianCalendar> toGregorianCalendar();
	ref<java::util::GregorianCalendar> toGregorianCalendar(ref<java::util::TimeZone> p1, ref<java::util::Locale> p2, ref<javax::xml::datatype::XMLGregorianCalendar> p3);
	ref<java::util::TimeZone> getTimeZone(jint p1);
	ref<java::lang::Object> clone();

protected:

	XMLGregorianCalendar(handle_type h) : base_(h) {}

};

} // namespace javax::xml::datatype
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/math/BigDecimal.h>
#include <scapix/java_api/java/math/BigInteger.h>
#include <scapix/java_api/java/util/GregorianCalendar.h>
#include <scapix/java_api/java/util/Locale.h>
#include <scapix/java_api/java/util/TimeZone.h>
#include <scapix/java_api/javax/xml/datatype/Duration.h>
#include <scapix/java_api/javax/xml/namespace/QName.h>

namespace scapix::java_api {
namespace javax::xml::datatype {

inline ref<XMLGregorianCalendar> XMLGregorianCalendar::new_object() { return base_::new_object(); }
inline void XMLGregorianCalendar::clear() { return call_method<SCAPIX_META_STRING("clear"), void>(); }
inline void XMLGregorianCalendar::reset() { return call_method<SCAPIX_META_STRING("reset"), void>(); }
inline void XMLGregorianCalendar::setYear(ref<java::math::BigInteger> p1) { return call_method<SCAPIX_META_STRING("setYear"), void>(p1); }
inline void XMLGregorianCalendar::setYear(jint p1) { return call_method<SCAPIX_META_STRING("setYear"), void>(p1); }
inline void XMLGregorianCalendar::setMonth(jint p1) { return call_method<SCAPIX_META_STRING("setMonth"), void>(p1); }
inline void XMLGregorianCalendar::setDay(jint p1) { return call_method<SCAPIX_META_STRING("setDay"), void>(p1); }
inline void XMLGregorianCalendar::setTimezone(jint p1) { return call_method<SCAPIX_META_STRING("setTimezone"), void>(p1); }
inline void XMLGregorianCalendar::setTime(jint hour, jint minute, jint second) { return call_method<SCAPIX_META_STRING("setTime"), void>(hour, minute, second); }
inline void XMLGregorianCalendar::setHour(jint p1) { return call_method<SCAPIX_META_STRING("setHour"), void>(p1); }
inline void XMLGregorianCalendar::setMinute(jint p1) { return call_method<SCAPIX_META_STRING("setMinute"), void>(p1); }
inline void XMLGregorianCalendar::setSecond(jint p1) { return call_method<SCAPIX_META_STRING("setSecond"), void>(p1); }
inline void XMLGregorianCalendar::setMillisecond(jint p1) { return call_method<SCAPIX_META_STRING("setMillisecond"), void>(p1); }
inline void XMLGregorianCalendar::setFractionalSecond(ref<java::math::BigDecimal> p1) { return call_method<SCAPIX_META_STRING("setFractionalSecond"), void>(p1); }
inline void XMLGregorianCalendar::setTime(jint hour, jint minute, jint second, ref<java::math::BigDecimal> fractional) { return call_method<SCAPIX_META_STRING("setTime"), void>(hour, minute, second, fractional); }
inline void XMLGregorianCalendar::setTime(jint hour, jint minute, jint second, jint millisecond) { return call_method<SCAPIX_META_STRING("setTime"), void>(hour, minute, second, millisecond); }
inline ref<java::math::BigInteger> XMLGregorianCalendar::getEon() { return call_method<SCAPIX_META_STRING("getEon"), ref<java::math::BigInteger>>(); }
inline jint XMLGregorianCalendar::getYear() { return call_method<SCAPIX_META_STRING("getYear"), jint>(); }
inline ref<java::math::BigInteger> XMLGregorianCalendar::getEonAndYear() { return call_method<SCAPIX_META_STRING("getEonAndYear"), ref<java::math::BigInteger>>(); }
inline jint XMLGregorianCalendar::getMonth() { return call_method<SCAPIX_META_STRING("getMonth"), jint>(); }
inline jint XMLGregorianCalendar::getDay() { return call_method<SCAPIX_META_STRING("getDay"), jint>(); }
inline jint XMLGregorianCalendar::getTimezone() { return call_method<SCAPIX_META_STRING("getTimezone"), jint>(); }
inline jint XMLGregorianCalendar::getHour() { return call_method<SCAPIX_META_STRING("getHour"), jint>(); }
inline jint XMLGregorianCalendar::getMinute() { return call_method<SCAPIX_META_STRING("getMinute"), jint>(); }
inline jint XMLGregorianCalendar::getSecond() { return call_method<SCAPIX_META_STRING("getSecond"), jint>(); }
inline jint XMLGregorianCalendar::getMillisecond() { return call_method<SCAPIX_META_STRING("getMillisecond"), jint>(); }
inline ref<java::math::BigDecimal> XMLGregorianCalendar::getFractionalSecond() { return call_method<SCAPIX_META_STRING("getFractionalSecond"), ref<java::math::BigDecimal>>(); }
inline jint XMLGregorianCalendar::compare(ref<javax::xml::datatype::XMLGregorianCalendar> p1) { return call_method<SCAPIX_META_STRING("compare"), jint>(p1); }
inline ref<javax::xml::datatype::XMLGregorianCalendar> XMLGregorianCalendar::normalize() { return call_method<SCAPIX_META_STRING("normalize"), ref<javax::xml::datatype::XMLGregorianCalendar>>(); }
inline jboolean XMLGregorianCalendar::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint XMLGregorianCalendar::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> XMLGregorianCalendar::toXMLFormat() { return call_method<SCAPIX_META_STRING("toXMLFormat"), ref<java::lang::String>>(); }
inline ref<javax::xml::namespace::QName> XMLGregorianCalendar::getXMLSchemaType() { return call_method<SCAPIX_META_STRING("getXMLSchemaType"), ref<javax::xml::namespace::QName>>(); }
inline ref<java::lang::String> XMLGregorianCalendar::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline jboolean XMLGregorianCalendar::isValid() { return call_method<SCAPIX_META_STRING("isValid"), jboolean>(); }
inline void XMLGregorianCalendar::add(ref<javax::xml::datatype::Duration> p1) { return call_method<SCAPIX_META_STRING("add"), void>(p1); }
inline ref<java::util::GregorianCalendar> XMLGregorianCalendar::toGregorianCalendar() { return call_method<SCAPIX_META_STRING("toGregorianCalendar"), ref<java::util::GregorianCalendar>>(); }
inline ref<java::util::GregorianCalendar> XMLGregorianCalendar::toGregorianCalendar(ref<java::util::TimeZone> p1, ref<java::util::Locale> p2, ref<javax::xml::datatype::XMLGregorianCalendar> p3) { return call_method<SCAPIX_META_STRING("toGregorianCalendar"), ref<java::util::GregorianCalendar>>(p1, p2, p3); }
inline ref<java::util::TimeZone> XMLGregorianCalendar::getTimeZone(jint p1) { return call_method<SCAPIX_META_STRING("getTimeZone"), ref<java::util::TimeZone>>(p1); }
inline ref<java::lang::Object> XMLGregorianCalendar::clone() { return call_method<SCAPIX_META_STRING("clone"), ref<java::lang::Object>>(); }

} // namespace javax::xml::datatype
} // namespace scapix::java_api

#endif // SCAPIX_JAVAX_XML_DATATYPE_XMLGREGORIANCALENDAR_H
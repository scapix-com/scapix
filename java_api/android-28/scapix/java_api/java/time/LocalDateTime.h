// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/time/temporal/Temporal.h>
#include <scapix/java_api/java/time/temporal/TemporalAdjuster.h>
#include <scapix/java_api/java/time/chrono/ChronoLocalDateTime.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_TIME_LOCALDATETIME_H
#define SCAPIX_JAVA_TIME_LOCALDATETIME_H

namespace scapix::java_api {

namespace java::lang { class CharSequence; }
namespace java::lang { class String; }
namespace java::time { class Clock; }
namespace java::time { class DayOfWeek; }
namespace java::time { class Instant; }
namespace java::time { class LocalDate; }
namespace java::time { class LocalTime; }
namespace java::time { class Month; }
namespace java::time { class OffsetDateTime; }
namespace java::time { class ZoneId; }
namespace java::time { class ZoneOffset; }
namespace java::time { class ZonedDateTime; }
namespace java::time::format { class DateTimeFormatter; }
namespace java::time::temporal { class TemporalAccessor; }
namespace java::time::temporal { class TemporalAmount; }
namespace java::time::temporal { class TemporalField; }
namespace java::time::temporal { class TemporalQuery; }
namespace java::time::temporal { class TemporalUnit; }
namespace java::time::temporal { class ValueRange; }

namespace java::time {

class LocalDateTime : public object_base<SCAPIX_META_STRING("java/time/LocalDateTime"),
	java::lang::Object,
	java::time::temporal::Temporal,
	java::time::temporal::TemporalAdjuster,
	java::time::chrono::ChronoLocalDateTime,
	java::io::Serializable>
{
public:

	static ref<java::time::LocalDateTime> MAX_();
	static ref<java::time::LocalDateTime> MIN_();

	static ref<java::time::LocalDateTime> now();
	static ref<java::time::LocalDateTime> now(ref<java::time::ZoneId> zone);
	static ref<java::time::LocalDateTime> now(ref<java::time::Clock> clock);
	static ref<java::time::LocalDateTime> of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute);
	static ref<java::time::LocalDateTime> of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute, jint second);
	static ref<java::time::LocalDateTime> of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute, jint second, jint nanoOfSecond);
	static ref<java::time::LocalDateTime> of(jint year, jint month, jint dayOfMonth, jint hour, jint minute);
	static ref<java::time::LocalDateTime> of(jint year, jint month, jint dayOfMonth, jint hour, jint minute, jint second);
	static ref<java::time::LocalDateTime> of(jint year, jint month, jint dayOfMonth, jint hour, jint minute, jint second, jint nanoOfSecond);
	static ref<java::time::LocalDateTime> of(ref<java::time::LocalDate> date, ref<java::time::LocalTime> time);
	static ref<java::time::LocalDateTime> ofInstant(ref<java::time::Instant> instant, ref<java::time::ZoneId> zone);
	static ref<java::time::LocalDateTime> ofEpochSecond(jlong epochSecond, jint p2, ref<java::time::ZoneOffset> nanoOfSecond);
	static ref<java::time::LocalDateTime> from(ref<java::time::temporal::TemporalAccessor> temporal);
	static ref<java::time::LocalDateTime> parse(ref<java::lang::CharSequence> text);
	static ref<java::time::LocalDateTime> parse(ref<java::lang::CharSequence> text, ref<java::time::format::DateTimeFormatter> formatter);
	jboolean isSupported(ref<java::time::temporal::TemporalField> field);
	jboolean isSupported(ref<java::time::temporal::TemporalUnit> unit);
	ref<java::time::temporal::ValueRange> range(ref<java::time::temporal::TemporalField> field);
	jint get(ref<java::time::temporal::TemporalField> field);
	jlong getLong(ref<java::time::temporal::TemporalField> field);
	ref<java::time::LocalDate> toLocalDate();
	jint getYear();
	jint getMonthValue();
	ref<java::time::Month> getMonth();
	jint getDayOfMonth();
	jint getDayOfYear();
	ref<java::time::DayOfWeek> getDayOfWeek();
	ref<java::time::LocalTime> toLocalTime();
	jint getHour();
	jint getMinute();
	jint getSecond();
	jint getNano();
	ref<java::time::LocalDateTime> with(ref<java::time::temporal::TemporalAdjuster> adjuster);
	ref<java::time::LocalDateTime> with(ref<java::time::temporal::TemporalField> field, jlong newValue);
	ref<java::time::LocalDateTime> withYear(jint year);
	ref<java::time::LocalDateTime> withMonth(jint month);
	ref<java::time::LocalDateTime> withDayOfMonth(jint dayOfMonth);
	ref<java::time::LocalDateTime> withDayOfYear(jint dayOfYear);
	ref<java::time::LocalDateTime> withHour(jint hour);
	ref<java::time::LocalDateTime> withMinute(jint minute);
	ref<java::time::LocalDateTime> withSecond(jint second);
	ref<java::time::LocalDateTime> withNano(jint nanoOfSecond);
	ref<java::time::LocalDateTime> truncatedTo(ref<java::time::temporal::TemporalUnit> unit);
	ref<java::time::LocalDateTime> plus(ref<java::time::temporal::TemporalAmount> amountToAdd);
	ref<java::time::LocalDateTime> plus(jlong amountToAdd, ref<java::time::temporal::TemporalUnit> p2);
	ref<java::time::LocalDateTime> plusYears(jlong years);
	ref<java::time::LocalDateTime> plusMonths(jlong months);
	ref<java::time::LocalDateTime> plusWeeks(jlong weeks);
	ref<java::time::LocalDateTime> plusDays(jlong days);
	ref<java::time::LocalDateTime> plusHours(jlong hours);
	ref<java::time::LocalDateTime> plusMinutes(jlong minutes);
	ref<java::time::LocalDateTime> plusSeconds(jlong seconds);
	ref<java::time::LocalDateTime> plusNanos(jlong nanos);
	ref<java::time::LocalDateTime> minus(ref<java::time::temporal::TemporalAmount> amountToSubtract);
	ref<java::time::LocalDateTime> minus(jlong amountToSubtract, ref<java::time::temporal::TemporalUnit> p2);
	ref<java::time::LocalDateTime> minusYears(jlong years);
	ref<java::time::LocalDateTime> minusMonths(jlong months);
	ref<java::time::LocalDateTime> minusWeeks(jlong weeks);
	ref<java::time::LocalDateTime> minusDays(jlong days);
	ref<java::time::LocalDateTime> minusHours(jlong hours);
	ref<java::time::LocalDateTime> minusMinutes(jlong minutes);
	ref<java::time::LocalDateTime> minusSeconds(jlong seconds);
	ref<java::time::LocalDateTime> minusNanos(jlong nanos);
	ref<java::lang::Object> query(ref<java::time::temporal::TemporalQuery> query);
	ref<java::time::temporal::Temporal> adjustInto(ref<java::time::temporal::Temporal> temporal);
	jlong until(ref<java::time::temporal::Temporal> endExclusive, ref<java::time::temporal::TemporalUnit> unit);
	ref<java::lang::String> format(ref<java::time::format::DateTimeFormatter> formatter);
	ref<java::time::OffsetDateTime> atOffset(ref<java::time::ZoneOffset> offset);
	ref<java::time::ZonedDateTime> atZone(ref<java::time::ZoneId> zone);
	jint compareTo(ref<java::time::chrono::ChronoLocalDateTime> other);
	jboolean isAfter(ref<java::time::chrono::ChronoLocalDateTime> other);
	jboolean isBefore(ref<java::time::chrono::ChronoLocalDateTime> other);
	jboolean isEqual(ref<java::time::chrono::ChronoLocalDateTime> other);
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	LocalDateTime(handle_type h) : base_(h) {}

};

} // namespace java::time
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/CharSequence.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/time/Clock.h>
#include <scapix/java_api/java/time/DayOfWeek.h>
#include <scapix/java_api/java/time/Instant.h>
#include <scapix/java_api/java/time/LocalDate.h>
#include <scapix/java_api/java/time/LocalTime.h>
#include <scapix/java_api/java/time/Month.h>
#include <scapix/java_api/java/time/OffsetDateTime.h>
#include <scapix/java_api/java/time/ZoneId.h>
#include <scapix/java_api/java/time/ZoneOffset.h>
#include <scapix/java_api/java/time/ZonedDateTime.h>
#include <scapix/java_api/java/time/format/DateTimeFormatter.h>
#include <scapix/java_api/java/time/temporal/TemporalAccessor.h>
#include <scapix/java_api/java/time/temporal/TemporalAmount.h>
#include <scapix/java_api/java/time/temporal/TemporalField.h>
#include <scapix/java_api/java/time/temporal/TemporalQuery.h>
#include <scapix/java_api/java/time/temporal/TemporalUnit.h>
#include <scapix/java_api/java/time/temporal/ValueRange.h>

namespace scapix::java_api {
namespace java::time {

inline ref<java::time::LocalDateTime> LocalDateTime::MAX_() { return get_static_field<SCAPIX_META_STRING("MAX"), ref<java::time::LocalDateTime>>(); }
inline ref<java::time::LocalDateTime> LocalDateTime::MIN_() { return get_static_field<SCAPIX_META_STRING("MIN"), ref<java::time::LocalDateTime>>(); }
inline ref<java::time::LocalDateTime> LocalDateTime::now() { return call_static_method<SCAPIX_META_STRING("now"), ref<java::time::LocalDateTime>>(); }
inline ref<java::time::LocalDateTime> LocalDateTime::now(ref<java::time::ZoneId> zone) { return call_static_method<SCAPIX_META_STRING("now"), ref<java::time::LocalDateTime>>(zone); }
inline ref<java::time::LocalDateTime> LocalDateTime::now(ref<java::time::Clock> clock) { return call_static_method<SCAPIX_META_STRING("now"), ref<java::time::LocalDateTime>>(clock); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute, jint second) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute, second); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, ref<java::time::Month> month, jint dayOfMonth, jint hour, jint minute, jint second, jint nanoOfSecond) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute, second, nanoOfSecond); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, jint month, jint dayOfMonth, jint hour, jint minute) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, jint month, jint dayOfMonth, jint hour, jint minute, jint second) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute, second); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(jint year, jint month, jint dayOfMonth, jint hour, jint minute, jint second, jint nanoOfSecond) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(year, month, dayOfMonth, hour, minute, second, nanoOfSecond); }
inline ref<java::time::LocalDateTime> LocalDateTime::of(ref<java::time::LocalDate> date, ref<java::time::LocalTime> time) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::LocalDateTime>>(date, time); }
inline ref<java::time::LocalDateTime> LocalDateTime::ofInstant(ref<java::time::Instant> instant, ref<java::time::ZoneId> zone) { return call_static_method<SCAPIX_META_STRING("ofInstant"), ref<java::time::LocalDateTime>>(instant, zone); }
inline ref<java::time::LocalDateTime> LocalDateTime::ofEpochSecond(jlong epochSecond, jint p2, ref<java::time::ZoneOffset> nanoOfSecond) { return call_static_method<SCAPIX_META_STRING("ofEpochSecond"), ref<java::time::LocalDateTime>>(epochSecond, p2, nanoOfSecond); }
inline ref<java::time::LocalDateTime> LocalDateTime::from(ref<java::time::temporal::TemporalAccessor> temporal) { return call_static_method<SCAPIX_META_STRING("from"), ref<java::time::LocalDateTime>>(temporal); }
inline ref<java::time::LocalDateTime> LocalDateTime::parse(ref<java::lang::CharSequence> text) { return call_static_method<SCAPIX_META_STRING("parse"), ref<java::time::LocalDateTime>>(text); }
inline ref<java::time::LocalDateTime> LocalDateTime::parse(ref<java::lang::CharSequence> text, ref<java::time::format::DateTimeFormatter> formatter) { return call_static_method<SCAPIX_META_STRING("parse"), ref<java::time::LocalDateTime>>(text, formatter); }
inline jboolean LocalDateTime::isSupported(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("isSupported"), jboolean>(field); }
inline jboolean LocalDateTime::isSupported(ref<java::time::temporal::TemporalUnit> unit) { return call_method<SCAPIX_META_STRING("isSupported"), jboolean>(unit); }
inline ref<java::time::temporal::ValueRange> LocalDateTime::range(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("range"), ref<java::time::temporal::ValueRange>>(field); }
inline jint LocalDateTime::get(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("get"), jint>(field); }
inline jlong LocalDateTime::getLong(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("getLong"), jlong>(field); }
inline ref<java::time::LocalDate> LocalDateTime::toLocalDate() { return call_method<SCAPIX_META_STRING("toLocalDate"), ref<java::time::LocalDate>>(); }
inline jint LocalDateTime::getYear() { return call_method<SCAPIX_META_STRING("getYear"), jint>(); }
inline jint LocalDateTime::getMonthValue() { return call_method<SCAPIX_META_STRING("getMonthValue"), jint>(); }
inline ref<java::time::Month> LocalDateTime::getMonth() { return call_method<SCAPIX_META_STRING("getMonth"), ref<java::time::Month>>(); }
inline jint LocalDateTime::getDayOfMonth() { return call_method<SCAPIX_META_STRING("getDayOfMonth"), jint>(); }
inline jint LocalDateTime::getDayOfYear() { return call_method<SCAPIX_META_STRING("getDayOfYear"), jint>(); }
inline ref<java::time::DayOfWeek> LocalDateTime::getDayOfWeek() { return call_method<SCAPIX_META_STRING("getDayOfWeek"), ref<java::time::DayOfWeek>>(); }
inline ref<java::time::LocalTime> LocalDateTime::toLocalTime() { return call_method<SCAPIX_META_STRING("toLocalTime"), ref<java::time::LocalTime>>(); }
inline jint LocalDateTime::getHour() { return call_method<SCAPIX_META_STRING("getHour"), jint>(); }
inline jint LocalDateTime::getMinute() { return call_method<SCAPIX_META_STRING("getMinute"), jint>(); }
inline jint LocalDateTime::getSecond() { return call_method<SCAPIX_META_STRING("getSecond"), jint>(); }
inline jint LocalDateTime::getNano() { return call_method<SCAPIX_META_STRING("getNano"), jint>(); }
inline ref<java::time::LocalDateTime> LocalDateTime::with(ref<java::time::temporal::TemporalAdjuster> adjuster) { return call_method<SCAPIX_META_STRING("with"), ref<java::time::LocalDateTime>>(adjuster); }
inline ref<java::time::LocalDateTime> LocalDateTime::with(ref<java::time::temporal::TemporalField> field, jlong newValue) { return call_method<SCAPIX_META_STRING("with"), ref<java::time::LocalDateTime>>(field, newValue); }
inline ref<java::time::LocalDateTime> LocalDateTime::withYear(jint year) { return call_method<SCAPIX_META_STRING("withYear"), ref<java::time::LocalDateTime>>(year); }
inline ref<java::time::LocalDateTime> LocalDateTime::withMonth(jint month) { return call_method<SCAPIX_META_STRING("withMonth"), ref<java::time::LocalDateTime>>(month); }
inline ref<java::time::LocalDateTime> LocalDateTime::withDayOfMonth(jint dayOfMonth) { return call_method<SCAPIX_META_STRING("withDayOfMonth"), ref<java::time::LocalDateTime>>(dayOfMonth); }
inline ref<java::time::LocalDateTime> LocalDateTime::withDayOfYear(jint dayOfYear) { return call_method<SCAPIX_META_STRING("withDayOfYear"), ref<java::time::LocalDateTime>>(dayOfYear); }
inline ref<java::time::LocalDateTime> LocalDateTime::withHour(jint hour) { return call_method<SCAPIX_META_STRING("withHour"), ref<java::time::LocalDateTime>>(hour); }
inline ref<java::time::LocalDateTime> LocalDateTime::withMinute(jint minute) { return call_method<SCAPIX_META_STRING("withMinute"), ref<java::time::LocalDateTime>>(minute); }
inline ref<java::time::LocalDateTime> LocalDateTime::withSecond(jint second) { return call_method<SCAPIX_META_STRING("withSecond"), ref<java::time::LocalDateTime>>(second); }
inline ref<java::time::LocalDateTime> LocalDateTime::withNano(jint nanoOfSecond) { return call_method<SCAPIX_META_STRING("withNano"), ref<java::time::LocalDateTime>>(nanoOfSecond); }
inline ref<java::time::LocalDateTime> LocalDateTime::truncatedTo(ref<java::time::temporal::TemporalUnit> unit) { return call_method<SCAPIX_META_STRING("truncatedTo"), ref<java::time::LocalDateTime>>(unit); }
inline ref<java::time::LocalDateTime> LocalDateTime::plus(ref<java::time::temporal::TemporalAmount> amountToAdd) { return call_method<SCAPIX_META_STRING("plus"), ref<java::time::LocalDateTime>>(amountToAdd); }
inline ref<java::time::LocalDateTime> LocalDateTime::plus(jlong amountToAdd, ref<java::time::temporal::TemporalUnit> p2) { return call_method<SCAPIX_META_STRING("plus"), ref<java::time::LocalDateTime>>(amountToAdd, p2); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusYears(jlong years) { return call_method<SCAPIX_META_STRING("plusYears"), ref<java::time::LocalDateTime>>(years); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusMonths(jlong months) { return call_method<SCAPIX_META_STRING("plusMonths"), ref<java::time::LocalDateTime>>(months); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusWeeks(jlong weeks) { return call_method<SCAPIX_META_STRING("plusWeeks"), ref<java::time::LocalDateTime>>(weeks); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusDays(jlong days) { return call_method<SCAPIX_META_STRING("plusDays"), ref<java::time::LocalDateTime>>(days); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusHours(jlong hours) { return call_method<SCAPIX_META_STRING("plusHours"), ref<java::time::LocalDateTime>>(hours); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusMinutes(jlong minutes) { return call_method<SCAPIX_META_STRING("plusMinutes"), ref<java::time::LocalDateTime>>(minutes); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusSeconds(jlong seconds) { return call_method<SCAPIX_META_STRING("plusSeconds"), ref<java::time::LocalDateTime>>(seconds); }
inline ref<java::time::LocalDateTime> LocalDateTime::plusNanos(jlong nanos) { return call_method<SCAPIX_META_STRING("plusNanos"), ref<java::time::LocalDateTime>>(nanos); }
inline ref<java::time::LocalDateTime> LocalDateTime::minus(ref<java::time::temporal::TemporalAmount> amountToSubtract) { return call_method<SCAPIX_META_STRING("minus"), ref<java::time::LocalDateTime>>(amountToSubtract); }
inline ref<java::time::LocalDateTime> LocalDateTime::minus(jlong amountToSubtract, ref<java::time::temporal::TemporalUnit> p2) { return call_method<SCAPIX_META_STRING("minus"), ref<java::time::LocalDateTime>>(amountToSubtract, p2); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusYears(jlong years) { return call_method<SCAPIX_META_STRING("minusYears"), ref<java::time::LocalDateTime>>(years); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusMonths(jlong months) { return call_method<SCAPIX_META_STRING("minusMonths"), ref<java::time::LocalDateTime>>(months); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusWeeks(jlong weeks) { return call_method<SCAPIX_META_STRING("minusWeeks"), ref<java::time::LocalDateTime>>(weeks); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusDays(jlong days) { return call_method<SCAPIX_META_STRING("minusDays"), ref<java::time::LocalDateTime>>(days); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusHours(jlong hours) { return call_method<SCAPIX_META_STRING("minusHours"), ref<java::time::LocalDateTime>>(hours); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusMinutes(jlong minutes) { return call_method<SCAPIX_META_STRING("minusMinutes"), ref<java::time::LocalDateTime>>(minutes); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusSeconds(jlong seconds) { return call_method<SCAPIX_META_STRING("minusSeconds"), ref<java::time::LocalDateTime>>(seconds); }
inline ref<java::time::LocalDateTime> LocalDateTime::minusNanos(jlong nanos) { return call_method<SCAPIX_META_STRING("minusNanos"), ref<java::time::LocalDateTime>>(nanos); }
inline ref<java::lang::Object> LocalDateTime::query(ref<java::time::temporal::TemporalQuery> query) { return call_method<SCAPIX_META_STRING("query"), ref<java::lang::Object>>(query); }
inline ref<java::time::temporal::Temporal> LocalDateTime::adjustInto(ref<java::time::temporal::Temporal> temporal) { return call_method<SCAPIX_META_STRING("adjustInto"), ref<java::time::temporal::Temporal>>(temporal); }
inline jlong LocalDateTime::until(ref<java::time::temporal::Temporal> endExclusive, ref<java::time::temporal::TemporalUnit> unit) { return call_method<SCAPIX_META_STRING("until"), jlong>(endExclusive, unit); }
inline ref<java::lang::String> LocalDateTime::format(ref<java::time::format::DateTimeFormatter> formatter) { return call_method<SCAPIX_META_STRING("format"), ref<java::lang::String>>(formatter); }
inline ref<java::time::OffsetDateTime> LocalDateTime::atOffset(ref<java::time::ZoneOffset> offset) { return call_method<SCAPIX_META_STRING("atOffset"), ref<java::time::OffsetDateTime>>(offset); }
inline ref<java::time::ZonedDateTime> LocalDateTime::atZone(ref<java::time::ZoneId> zone) { return call_method<SCAPIX_META_STRING("atZone"), ref<java::time::ZonedDateTime>>(zone); }
inline jint LocalDateTime::compareTo(ref<java::time::chrono::ChronoLocalDateTime> other) { return call_method<SCAPIX_META_STRING("compareTo"), jint>(other); }
inline jboolean LocalDateTime::isAfter(ref<java::time::chrono::ChronoLocalDateTime> other) { return call_method<SCAPIX_META_STRING("isAfter"), jboolean>(other); }
inline jboolean LocalDateTime::isBefore(ref<java::time::chrono::ChronoLocalDateTime> other) { return call_method<SCAPIX_META_STRING("isBefore"), jboolean>(other); }
inline jboolean LocalDateTime::isEqual(ref<java::time::chrono::ChronoLocalDateTime> other) { return call_method<SCAPIX_META_STRING("isEqual"), jboolean>(other); }
inline jboolean LocalDateTime::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint LocalDateTime::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> LocalDateTime::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::time
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TIME_LOCALDATETIME_H
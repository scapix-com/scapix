// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_JAVA_TIME_FORMAT_DATETIMEFORMATTERBUILDER_H
#define SCAPIX_JAVA_TIME_FORMAT_DATETIMEFORMATTERBUILDER_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::time::chrono { class ChronoLocalDate; }
namespace java::time::chrono { class Chronology; }
namespace java::time::format { class DateTimeFormatter; }
namespace java::time::format { class FormatStyle; }
namespace java::time::format { class SignStyle; }
namespace java::time::format { class TextStyle; }
namespace java::time::temporal { class TemporalField; }
namespace java::util { class Locale; }
namespace java::util { class Map; }
namespace java::util { class Set; }

namespace java::time::format {

class DateTimeFormatterBuilder : public object_base<SCAPIX_META_STRING("java/time/format/DateTimeFormatterBuilder"),
	java::lang::Object>
{
public:

	static ref<DateTimeFormatterBuilder> new_object();
	static ref<java::lang::String> getLocalizedDateTimePattern(ref<java::time::format::FormatStyle> dateStyle, ref<java::time::format::FormatStyle> timeStyle, ref<java::time::chrono::Chronology> chrono, ref<java::util::Locale> locale);
	ref<java::time::format::DateTimeFormatterBuilder> parseCaseSensitive();
	ref<java::time::format::DateTimeFormatterBuilder> parseCaseInsensitive();
	ref<java::time::format::DateTimeFormatterBuilder> parseStrict();
	ref<java::time::format::DateTimeFormatterBuilder> parseLenient();
	ref<java::time::format::DateTimeFormatterBuilder> parseDefaulting(ref<java::time::temporal::TemporalField> field, jlong value);
	ref<java::time::format::DateTimeFormatterBuilder> appendValue(ref<java::time::temporal::TemporalField> field);
	ref<java::time::format::DateTimeFormatterBuilder> appendValue(ref<java::time::temporal::TemporalField> field, jint width);
	ref<java::time::format::DateTimeFormatterBuilder> appendValue(ref<java::time::temporal::TemporalField> field, jint minWidth, jint maxWidth, ref<java::time::format::SignStyle> signStyle);
	ref<java::time::format::DateTimeFormatterBuilder> appendValueReduced(ref<java::time::temporal::TemporalField> field, jint width, jint maxWidth, jint baseValue);
	ref<java::time::format::DateTimeFormatterBuilder> appendValueReduced(ref<java::time::temporal::TemporalField> field, jint width, jint maxWidth, ref<java::time::chrono::ChronoLocalDate> baseDate);
	ref<java::time::format::DateTimeFormatterBuilder> appendFraction(ref<java::time::temporal::TemporalField> field, jint minWidth, jint maxWidth, jboolean decimalPoint);
	ref<java::time::format::DateTimeFormatterBuilder> appendText(ref<java::time::temporal::TemporalField> field);
	ref<java::time::format::DateTimeFormatterBuilder> appendText(ref<java::time::temporal::TemporalField> field, ref<java::time::format::TextStyle> textStyle);
	ref<java::time::format::DateTimeFormatterBuilder> appendText(ref<java::time::temporal::TemporalField> field, ref<java::util::Map> textLookup);
	ref<java::time::format::DateTimeFormatterBuilder> appendInstant();
	ref<java::time::format::DateTimeFormatterBuilder> appendInstant(jint fractionalDigits);
	ref<java::time::format::DateTimeFormatterBuilder> appendOffsetId();
	ref<java::time::format::DateTimeFormatterBuilder> appendOffset(ref<java::lang::String> pattern, ref<java::lang::String> noOffsetText);
	ref<java::time::format::DateTimeFormatterBuilder> appendLocalizedOffset(ref<java::time::format::TextStyle> style);
	ref<java::time::format::DateTimeFormatterBuilder> appendZoneId();
	ref<java::time::format::DateTimeFormatterBuilder> appendZoneRegionId();
	ref<java::time::format::DateTimeFormatterBuilder> appendZoneOrOffsetId();
	ref<java::time::format::DateTimeFormatterBuilder> appendZoneText(ref<java::time::format::TextStyle> textStyle);
	ref<java::time::format::DateTimeFormatterBuilder> appendZoneText(ref<java::time::format::TextStyle> textStyle, ref<java::util::Set> preferredZones);
	ref<java::time::format::DateTimeFormatterBuilder> appendChronologyId();
	ref<java::time::format::DateTimeFormatterBuilder> appendChronologyText(ref<java::time::format::TextStyle> textStyle);
	ref<java::time::format::DateTimeFormatterBuilder> appendLocalized(ref<java::time::format::FormatStyle> dateStyle, ref<java::time::format::FormatStyle> timeStyle);
	ref<java::time::format::DateTimeFormatterBuilder> appendLiteral(jchar literal);
	ref<java::time::format::DateTimeFormatterBuilder> appendLiteral(ref<java::lang::String> literal);
	ref<java::time::format::DateTimeFormatterBuilder> append(ref<java::time::format::DateTimeFormatter> formatter);
	ref<java::time::format::DateTimeFormatterBuilder> appendOptional(ref<java::time::format::DateTimeFormatter> formatter);
	ref<java::time::format::DateTimeFormatterBuilder> appendPattern(ref<java::lang::String> pattern);
	ref<java::time::format::DateTimeFormatterBuilder> padNext(jint padWidth);
	ref<java::time::format::DateTimeFormatterBuilder> padNext(jint padWidth, jchar padChar);
	ref<java::time::format::DateTimeFormatterBuilder> optionalStart();
	ref<java::time::format::DateTimeFormatterBuilder> optionalEnd();
	ref<java::time::format::DateTimeFormatter> toFormatter();
	ref<java::time::format::DateTimeFormatter> toFormatter(ref<java::util::Locale> locale);

protected:

	DateTimeFormatterBuilder(handle_type h) : base_(h) {}

};

} // namespace java::time::format
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/time/chrono/ChronoLocalDate.h>
#include <scapix/java_api/java/time/chrono/Chronology.h>
#include <scapix/java_api/java/time/format/DateTimeFormatter.h>
#include <scapix/java_api/java/time/format/FormatStyle.h>
#include <scapix/java_api/java/time/format/SignStyle.h>
#include <scapix/java_api/java/time/format/TextStyle.h>
#include <scapix/java_api/java/time/temporal/TemporalField.h>
#include <scapix/java_api/java/util/Locale.h>
#include <scapix/java_api/java/util/Map.h>
#include <scapix/java_api/java/util/Set.h>

namespace scapix::java_api {
namespace java::time::format {

inline ref<DateTimeFormatterBuilder> DateTimeFormatterBuilder::new_object() { return base_::new_object(); }
inline ref<java::lang::String> DateTimeFormatterBuilder::getLocalizedDateTimePattern(ref<java::time::format::FormatStyle> dateStyle, ref<java::time::format::FormatStyle> timeStyle, ref<java::time::chrono::Chronology> chrono, ref<java::util::Locale> locale) { return call_static_method<SCAPIX_META_STRING("getLocalizedDateTimePattern"), ref<java::lang::String>>(dateStyle, timeStyle, chrono, locale); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::parseCaseSensitive() { return call_method<SCAPIX_META_STRING("parseCaseSensitive"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::parseCaseInsensitive() { return call_method<SCAPIX_META_STRING("parseCaseInsensitive"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::parseStrict() { return call_method<SCAPIX_META_STRING("parseStrict"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::parseLenient() { return call_method<SCAPIX_META_STRING("parseLenient"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::parseDefaulting(ref<java::time::temporal::TemporalField> field, jlong value) { return call_method<SCAPIX_META_STRING("parseDefaulting"), ref<java::time::format::DateTimeFormatterBuilder>>(field, value); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendValue(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("appendValue"), ref<java::time::format::DateTimeFormatterBuilder>>(field); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendValue(ref<java::time::temporal::TemporalField> field, jint width) { return call_method<SCAPIX_META_STRING("appendValue"), ref<java::time::format::DateTimeFormatterBuilder>>(field, width); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendValue(ref<java::time::temporal::TemporalField> field, jint minWidth, jint maxWidth, ref<java::time::format::SignStyle> signStyle) { return call_method<SCAPIX_META_STRING("appendValue"), ref<java::time::format::DateTimeFormatterBuilder>>(field, minWidth, maxWidth, signStyle); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendValueReduced(ref<java::time::temporal::TemporalField> field, jint width, jint maxWidth, jint baseValue) { return call_method<SCAPIX_META_STRING("appendValueReduced"), ref<java::time::format::DateTimeFormatterBuilder>>(field, width, maxWidth, baseValue); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendValueReduced(ref<java::time::temporal::TemporalField> field, jint width, jint maxWidth, ref<java::time::chrono::ChronoLocalDate> baseDate) { return call_method<SCAPIX_META_STRING("appendValueReduced"), ref<java::time::format::DateTimeFormatterBuilder>>(field, width, maxWidth, baseDate); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendFraction(ref<java::time::temporal::TemporalField> field, jint minWidth, jint maxWidth, jboolean decimalPoint) { return call_method<SCAPIX_META_STRING("appendFraction"), ref<java::time::format::DateTimeFormatterBuilder>>(field, minWidth, maxWidth, decimalPoint); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendText(ref<java::time::temporal::TemporalField> field) { return call_method<SCAPIX_META_STRING("appendText"), ref<java::time::format::DateTimeFormatterBuilder>>(field); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendText(ref<java::time::temporal::TemporalField> field, ref<java::time::format::TextStyle> textStyle) { return call_method<SCAPIX_META_STRING("appendText"), ref<java::time::format::DateTimeFormatterBuilder>>(field, textStyle); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendText(ref<java::time::temporal::TemporalField> field, ref<java::util::Map> textLookup) { return call_method<SCAPIX_META_STRING("appendText"), ref<java::time::format::DateTimeFormatterBuilder>>(field, textLookup); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendInstant() { return call_method<SCAPIX_META_STRING("appendInstant"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendInstant(jint fractionalDigits) { return call_method<SCAPIX_META_STRING("appendInstant"), ref<java::time::format::DateTimeFormatterBuilder>>(fractionalDigits); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendOffsetId() { return call_method<SCAPIX_META_STRING("appendOffsetId"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendOffset(ref<java::lang::String> pattern, ref<java::lang::String> noOffsetText) { return call_method<SCAPIX_META_STRING("appendOffset"), ref<java::time::format::DateTimeFormatterBuilder>>(pattern, noOffsetText); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendLocalizedOffset(ref<java::time::format::TextStyle> style) { return call_method<SCAPIX_META_STRING("appendLocalizedOffset"), ref<java::time::format::DateTimeFormatterBuilder>>(style); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendZoneId() { return call_method<SCAPIX_META_STRING("appendZoneId"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendZoneRegionId() { return call_method<SCAPIX_META_STRING("appendZoneRegionId"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendZoneOrOffsetId() { return call_method<SCAPIX_META_STRING("appendZoneOrOffsetId"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendZoneText(ref<java::time::format::TextStyle> textStyle) { return call_method<SCAPIX_META_STRING("appendZoneText"), ref<java::time::format::DateTimeFormatterBuilder>>(textStyle); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendZoneText(ref<java::time::format::TextStyle> textStyle, ref<java::util::Set> preferredZones) { return call_method<SCAPIX_META_STRING("appendZoneText"), ref<java::time::format::DateTimeFormatterBuilder>>(textStyle, preferredZones); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendChronologyId() { return call_method<SCAPIX_META_STRING("appendChronologyId"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendChronologyText(ref<java::time::format::TextStyle> textStyle) { return call_method<SCAPIX_META_STRING("appendChronologyText"), ref<java::time::format::DateTimeFormatterBuilder>>(textStyle); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendLocalized(ref<java::time::format::FormatStyle> dateStyle, ref<java::time::format::FormatStyle> timeStyle) { return call_method<SCAPIX_META_STRING("appendLocalized"), ref<java::time::format::DateTimeFormatterBuilder>>(dateStyle, timeStyle); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendLiteral(jchar literal) { return call_method<SCAPIX_META_STRING("appendLiteral"), ref<java::time::format::DateTimeFormatterBuilder>>(literal); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendLiteral(ref<java::lang::String> literal) { return call_method<SCAPIX_META_STRING("appendLiteral"), ref<java::time::format::DateTimeFormatterBuilder>>(literal); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::append(ref<java::time::format::DateTimeFormatter> formatter) { return call_method<SCAPIX_META_STRING("append"), ref<java::time::format::DateTimeFormatterBuilder>>(formatter); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendOptional(ref<java::time::format::DateTimeFormatter> formatter) { return call_method<SCAPIX_META_STRING("appendOptional"), ref<java::time::format::DateTimeFormatterBuilder>>(formatter); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::appendPattern(ref<java::lang::String> pattern) { return call_method<SCAPIX_META_STRING("appendPattern"), ref<java::time::format::DateTimeFormatterBuilder>>(pattern); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::padNext(jint padWidth) { return call_method<SCAPIX_META_STRING("padNext"), ref<java::time::format::DateTimeFormatterBuilder>>(padWidth); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::padNext(jint padWidth, jchar padChar) { return call_method<SCAPIX_META_STRING("padNext"), ref<java::time::format::DateTimeFormatterBuilder>>(padWidth, padChar); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::optionalStart() { return call_method<SCAPIX_META_STRING("optionalStart"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatterBuilder> DateTimeFormatterBuilder::optionalEnd() { return call_method<SCAPIX_META_STRING("optionalEnd"), ref<java::time::format::DateTimeFormatterBuilder>>(); }
inline ref<java::time::format::DateTimeFormatter> DateTimeFormatterBuilder::toFormatter() { return call_method<SCAPIX_META_STRING("toFormatter"), ref<java::time::format::DateTimeFormatter>>(); }
inline ref<java::time::format::DateTimeFormatter> DateTimeFormatterBuilder::toFormatter(ref<java::util::Locale> locale) { return call_method<SCAPIX_META_STRING("toFormatter"), ref<java::time::format::DateTimeFormatter>>(locale); }

} // namespace java::time::format
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TIME_FORMAT_DATETIMEFORMATTERBUILDER_H
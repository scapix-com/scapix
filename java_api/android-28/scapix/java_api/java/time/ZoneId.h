// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/io/Serializable.h>

#ifndef SCAPIX_JAVA_TIME_ZONEID_H
#define SCAPIX_JAVA_TIME_ZONEID_H

namespace scapix::java_api {

namespace java::lang { class String; }
namespace java::time { class ZoneOffset; }
namespace java::time::format { class TextStyle; }
namespace java::time::temporal { class TemporalAccessor; }
namespace java::time::zone { class ZoneRules; }
namespace java::util { class Locale; }
namespace java::util { class Map; }
namespace java::util { class Set; }

namespace java::time {

class ZoneId : public object_base<SCAPIX_META_STRING("java/time/ZoneId"),
	java::lang::Object,
	java::io::Serializable>
{
public:

	static ref<java::util::Map> SHORT_IDS_();

	static ref<java::time::ZoneId> systemDefault();
	static ref<java::util::Set> getAvailableZoneIds();
	static ref<java::time::ZoneId> of(ref<java::lang::String> zoneId, ref<java::util::Map> aliasMap);
	static ref<java::time::ZoneId> of(ref<java::lang::String> zoneId);
	static ref<java::time::ZoneId> ofOffset(ref<java::lang::String> prefix, ref<java::time::ZoneOffset> offset);
	static ref<java::time::ZoneId> from(ref<java::time::temporal::TemporalAccessor> temporal);
	ref<java::lang::String> getId();
	ref<java::lang::String> getDisplayName(ref<java::time::format::TextStyle> style, ref<java::util::Locale> locale);
	ref<java::time::zone::ZoneRules> getRules();
	ref<java::time::ZoneId> normalized();
	jboolean equals(ref<java::lang::Object> obj);
	jint hashCode();
	ref<java::lang::String> toString();

protected:

	ZoneId(handle_type h) : base_(h) {}

};

} // namespace java::time
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/time/ZoneOffset.h>
#include <scapix/java_api/java/time/format/TextStyle.h>
#include <scapix/java_api/java/time/temporal/TemporalAccessor.h>
#include <scapix/java_api/java/time/zone/ZoneRules.h>
#include <scapix/java_api/java/util/Locale.h>
#include <scapix/java_api/java/util/Map.h>
#include <scapix/java_api/java/util/Set.h>

namespace scapix::java_api {
namespace java::time {

inline ref<java::util::Map> ZoneId::SHORT_IDS_() { return get_static_field<SCAPIX_META_STRING("SHORT_IDS"), ref<java::util::Map>>(); }
inline ref<java::time::ZoneId> ZoneId::systemDefault() { return call_static_method<SCAPIX_META_STRING("systemDefault"), ref<java::time::ZoneId>>(); }
inline ref<java::util::Set> ZoneId::getAvailableZoneIds() { return call_static_method<SCAPIX_META_STRING("getAvailableZoneIds"), ref<java::util::Set>>(); }
inline ref<java::time::ZoneId> ZoneId::of(ref<java::lang::String> zoneId, ref<java::util::Map> aliasMap) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::ZoneId>>(zoneId, aliasMap); }
inline ref<java::time::ZoneId> ZoneId::of(ref<java::lang::String> zoneId) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::time::ZoneId>>(zoneId); }
inline ref<java::time::ZoneId> ZoneId::ofOffset(ref<java::lang::String> prefix, ref<java::time::ZoneOffset> offset) { return call_static_method<SCAPIX_META_STRING("ofOffset"), ref<java::time::ZoneId>>(prefix, offset); }
inline ref<java::time::ZoneId> ZoneId::from(ref<java::time::temporal::TemporalAccessor> temporal) { return call_static_method<SCAPIX_META_STRING("from"), ref<java::time::ZoneId>>(temporal); }
inline ref<java::lang::String> ZoneId::getId() { return call_method<SCAPIX_META_STRING("getId"), ref<java::lang::String>>(); }
inline ref<java::lang::String> ZoneId::getDisplayName(ref<java::time::format::TextStyle> style, ref<java::util::Locale> locale) { return call_method<SCAPIX_META_STRING("getDisplayName"), ref<java::lang::String>>(style, locale); }
inline ref<java::time::zone::ZoneRules> ZoneId::getRules() { return call_method<SCAPIX_META_STRING("getRules"), ref<java::time::zone::ZoneRules>>(); }
inline ref<java::time::ZoneId> ZoneId::normalized() { return call_method<SCAPIX_META_STRING("normalized"), ref<java::time::ZoneId>>(); }
inline jboolean ZoneId::equals(ref<java::lang::Object> obj) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(obj); }
inline jint ZoneId::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline ref<java::lang::String> ZoneId::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }

} // namespace java::time
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_TIME_ZONEID_H

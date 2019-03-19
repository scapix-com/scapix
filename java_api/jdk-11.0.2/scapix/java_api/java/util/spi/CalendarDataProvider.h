// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/spi/LocaleServiceProvider.h>

#ifndef SCAPIX_JAVA_UTIL_SPI_CALENDARDATAPROVIDER_H
#define SCAPIX_JAVA_UTIL_SPI_CALENDARDATAPROVIDER_H

namespace scapix::java_api {

namespace java::util { class Locale; }

namespace java::util::spi {

class CalendarDataProvider : public object_base<SCAPIX_META_STRING("java/util/spi/CalendarDataProvider"),
	java::util::spi::LocaleServiceProvider>
{
public:

	jint getFirstDayOfWeek(ref<java::util::Locale> p1);
	jint getMinimalDaysInFirstWeek(ref<java::util::Locale> p1);

protected:

	CalendarDataProvider(handle_type h) : base_(h) {}

};

} // namespace java::util::spi
} // namespace scapix::java_api

#include <scapix/java_api/java/util/Locale.h>

namespace scapix::java_api {
namespace java::util::spi {

inline jint CalendarDataProvider::getFirstDayOfWeek(ref<java::util::Locale> p1) { return call_method<SCAPIX_META_STRING("getFirstDayOfWeek"), jint>(p1); }
inline jint CalendarDataProvider::getMinimalDaysInFirstWeek(ref<java::util::Locale> p1) { return call_method<SCAPIX_META_STRING("getMinimalDaysInFirstWeek"), jint>(p1); }

} // namespace java::util::spi
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_SPI_CALENDARDATAPROVIDER_H
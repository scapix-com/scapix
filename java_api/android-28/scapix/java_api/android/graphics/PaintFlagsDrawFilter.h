// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/graphics/DrawFilter.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_PAINTFLAGSDRAWFILTER_H
#define SCAPIX_ANDROID_GRAPHICS_PAINTFLAGSDRAWFILTER_H

namespace scapix::java_api {
namespace android::graphics {

class PaintFlagsDrawFilter : public object_base<SCAPIX_META_STRING("android/graphics/PaintFlagsDrawFilter"),
	android::graphics::DrawFilter>
{
public:

	static ref<PaintFlagsDrawFilter> new_object(jint clearBits, jint setBits);

protected:

	PaintFlagsDrawFilter(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::graphics {

inline ref<PaintFlagsDrawFilter> PaintFlagsDrawFilter::new_object(jint clearBits, jint setBits) { return base_::new_object(clearBits, setBits); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_PAINTFLAGSDRAWFILTER_H
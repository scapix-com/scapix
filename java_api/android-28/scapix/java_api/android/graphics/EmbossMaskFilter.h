// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/graphics/MaskFilter.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_EMBOSSMASKFILTER_H
#define SCAPIX_ANDROID_GRAPHICS_EMBOSSMASKFILTER_H

namespace scapix::java_api {
namespace android::graphics {

class EmbossMaskFilter : public object_base<SCAPIX_META_STRING("android/graphics/EmbossMaskFilter"),
	android::graphics::MaskFilter>
{
public:

	static ref<EmbossMaskFilter> new_object(ref<link::java::array<jfloat>> direction, jfloat ambient, jfloat specular, jfloat blurRadius);

protected:

	EmbossMaskFilter(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::graphics {

inline ref<EmbossMaskFilter> EmbossMaskFilter::new_object(ref<link::java::array<jfloat>> direction, jfloat ambient, jfloat specular, jfloat blurRadius) { return base_::new_object(direction, ambient, specular, blurRadius); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_EMBOSSMASKFILTER_H
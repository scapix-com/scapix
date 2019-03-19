// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_COLORSPACE_RENDERINTENT_H
#define SCAPIX_ANDROID_GRAPHICS_COLORSPACE_RENDERINTENT_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::graphics {

class ColorSpace_RenderIntent : public object_base<SCAPIX_META_STRING("android/graphics/ColorSpace$RenderIntent"),
	java::lang::Enum>
{
public:

	static ref<android::graphics::ColorSpace_RenderIntent> PERCEPTUAL_();
	static ref<android::graphics::ColorSpace_RenderIntent> RELATIVE_();
	static ref<android::graphics::ColorSpace_RenderIntent> SATURATION_();
	static ref<android::graphics::ColorSpace_RenderIntent> ABSOLUTE_();

	static ref<link::java::array<android::graphics::ColorSpace_RenderIntent>> values();
	static ref<android::graphics::ColorSpace_RenderIntent> valueOf(ref<java::lang::String> name);

protected:

	ColorSpace_RenderIntent(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::graphics {

inline ref<android::graphics::ColorSpace_RenderIntent> ColorSpace_RenderIntent::PERCEPTUAL_() { return get_static_field<SCAPIX_META_STRING("PERCEPTUAL"), ref<android::graphics::ColorSpace_RenderIntent>>(); }
inline ref<android::graphics::ColorSpace_RenderIntent> ColorSpace_RenderIntent::RELATIVE_() { return get_static_field<SCAPIX_META_STRING("RELATIVE"), ref<android::graphics::ColorSpace_RenderIntent>>(); }
inline ref<android::graphics::ColorSpace_RenderIntent> ColorSpace_RenderIntent::SATURATION_() { return get_static_field<SCAPIX_META_STRING("SATURATION"), ref<android::graphics::ColorSpace_RenderIntent>>(); }
inline ref<android::graphics::ColorSpace_RenderIntent> ColorSpace_RenderIntent::ABSOLUTE_() { return get_static_field<SCAPIX_META_STRING("ABSOLUTE"), ref<android::graphics::ColorSpace_RenderIntent>>(); }
inline ref<link::java::array<android::graphics::ColorSpace_RenderIntent>> ColorSpace_RenderIntent::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::graphics::ColorSpace_RenderIntent>>>(); }
inline ref<android::graphics::ColorSpace_RenderIntent> ColorSpace_RenderIntent::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::graphics::ColorSpace_RenderIntent>>(name); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_COLORSPACE_RENDERINTENT_H
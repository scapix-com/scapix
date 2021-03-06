// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_CANVAS_EDGETYPE_H
#define SCAPIX_ANDROID_GRAPHICS_CANVAS_EDGETYPE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::graphics {

class Canvas_EdgeType : public object_base<SCAPIX_META_STRING("android/graphics/Canvas$EdgeType"),
	java::lang::Enum>
{
public:

	static ref<android::graphics::Canvas_EdgeType> BW_();
	static ref<android::graphics::Canvas_EdgeType> AA_();

	static ref<link::java::array<android::graphics::Canvas_EdgeType>> values();
	static ref<android::graphics::Canvas_EdgeType> valueOf(ref<java::lang::String> name);

protected:

	Canvas_EdgeType(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::graphics {

inline ref<android::graphics::Canvas_EdgeType> Canvas_EdgeType::BW_() { return get_static_field<SCAPIX_META_STRING("BW"), ref<android::graphics::Canvas_EdgeType>>(); }
inline ref<android::graphics::Canvas_EdgeType> Canvas_EdgeType::AA_() { return get_static_field<SCAPIX_META_STRING("AA"), ref<android::graphics::Canvas_EdgeType>>(); }
inline ref<link::java::array<android::graphics::Canvas_EdgeType>> Canvas_EdgeType::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::graphics::Canvas_EdgeType>>>(); }
inline ref<android::graphics::Canvas_EdgeType> Canvas_EdgeType::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::graphics::Canvas_EdgeType>>(name); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_CANVAS_EDGETYPE_H

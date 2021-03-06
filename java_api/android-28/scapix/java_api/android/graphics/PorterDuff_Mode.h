// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Enum.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_PORTERDUFF_MODE_H
#define SCAPIX_ANDROID_GRAPHICS_PORTERDUFF_MODE_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::graphics {

class PorterDuff_Mode : public object_base<SCAPIX_META_STRING("android/graphics/PorterDuff$Mode"),
	java::lang::Enum>
{
public:

	static ref<android::graphics::PorterDuff_Mode> CLEAR_();
	static ref<android::graphics::PorterDuff_Mode> SRC_();
	static ref<android::graphics::PorterDuff_Mode> DST_();
	static ref<android::graphics::PorterDuff_Mode> SRC_OVER_();
	static ref<android::graphics::PorterDuff_Mode> DST_OVER_();
	static ref<android::graphics::PorterDuff_Mode> SRC_IN_();
	static ref<android::graphics::PorterDuff_Mode> DST_IN_();
	static ref<android::graphics::PorterDuff_Mode> SRC_OUT_();
	static ref<android::graphics::PorterDuff_Mode> DST_OUT_();
	static ref<android::graphics::PorterDuff_Mode> SRC_ATOP_();
	static ref<android::graphics::PorterDuff_Mode> DST_ATOP_();
	static ref<android::graphics::PorterDuff_Mode> XOR_();
	static ref<android::graphics::PorterDuff_Mode> DARKEN_();
	static ref<android::graphics::PorterDuff_Mode> LIGHTEN_();
	static ref<android::graphics::PorterDuff_Mode> MULTIPLY_();
	static ref<android::graphics::PorterDuff_Mode> SCREEN_();
	static ref<android::graphics::PorterDuff_Mode> ADD_();
	static ref<android::graphics::PorterDuff_Mode> OVERLAY_();

	static ref<link::java::array<android::graphics::PorterDuff_Mode>> values();
	static ref<android::graphics::PorterDuff_Mode> valueOf(ref<java::lang::String> name);

protected:

	PorterDuff_Mode(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::graphics {

inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::CLEAR_() { return get_static_field<SCAPIX_META_STRING("CLEAR"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SRC_() { return get_static_field<SCAPIX_META_STRING("SRC"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DST_() { return get_static_field<SCAPIX_META_STRING("DST"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SRC_OVER_() { return get_static_field<SCAPIX_META_STRING("SRC_OVER"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DST_OVER_() { return get_static_field<SCAPIX_META_STRING("DST_OVER"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SRC_IN_() { return get_static_field<SCAPIX_META_STRING("SRC_IN"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DST_IN_() { return get_static_field<SCAPIX_META_STRING("DST_IN"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SRC_OUT_() { return get_static_field<SCAPIX_META_STRING("SRC_OUT"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DST_OUT_() { return get_static_field<SCAPIX_META_STRING("DST_OUT"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SRC_ATOP_() { return get_static_field<SCAPIX_META_STRING("SRC_ATOP"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DST_ATOP_() { return get_static_field<SCAPIX_META_STRING("DST_ATOP"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::XOR_() { return get_static_field<SCAPIX_META_STRING("XOR"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::DARKEN_() { return get_static_field<SCAPIX_META_STRING("DARKEN"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::LIGHTEN_() { return get_static_field<SCAPIX_META_STRING("LIGHTEN"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::MULTIPLY_() { return get_static_field<SCAPIX_META_STRING("MULTIPLY"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::SCREEN_() { return get_static_field<SCAPIX_META_STRING("SCREEN"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::ADD_() { return get_static_field<SCAPIX_META_STRING("ADD"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::OVERLAY_() { return get_static_field<SCAPIX_META_STRING("OVERLAY"), ref<android::graphics::PorterDuff_Mode>>(); }
inline ref<link::java::array<android::graphics::PorterDuff_Mode>> PorterDuff_Mode::values() { return call_static_method<SCAPIX_META_STRING("values"), ref<link::java::array<android::graphics::PorterDuff_Mode>>>(); }
inline ref<android::graphics::PorterDuff_Mode> PorterDuff_Mode::valueOf(ref<java::lang::String> name) { return call_static_method<SCAPIX_META_STRING("valueOf"), ref<android::graphics::PorterDuff_Mode>>(name); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_PORTERDUFF_MODE_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/android/os/Parcelable.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_BITMAP_H
#define SCAPIX_ANDROID_GRAPHICS_BITMAP_H

namespace scapix::java_api {

namespace android::graphics { class Bitmap_CompressFormat; }
namespace android::graphics { class Bitmap_Config; }
namespace android::graphics { class Canvas; }
namespace android::graphics { class ColorSpace; }
namespace android::graphics { class Matrix; }
namespace android::graphics { class Paint; }
namespace android::graphics { class Picture; }
namespace android::os { class Parcel; }
namespace android::os { class Parcelable_Creator; }
namespace android::util { class DisplayMetrics; }
namespace java::io { class OutputStream; }
namespace java::nio { class Buffer; }

namespace android::graphics {

class Bitmap : public object_base<SCAPIX_META_STRING("android/graphics/Bitmap"),
	java::lang::Object,
	android::os::Parcelable>
{
public:

	using Config = Bitmap_Config;
	using CompressFormat = Bitmap_CompressFormat;

	static ref<android::os::Parcelable_Creator> CREATOR_();
	static jint DENSITY_NONE_();

	jint getDensity();
	void setDensity(jint density);
	void reconfigure(jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	void setWidth(jint width);
	void setHeight(jint height);
	void setConfig(ref<android::graphics::Bitmap_Config> config);
	void recycle();
	jboolean isRecycled();
	jint getGenerationId();
	void copyPixelsToBuffer(ref<java::nio::Buffer> dst);
	void copyPixelsFromBuffer(ref<java::nio::Buffer> src);
	ref<android::graphics::Bitmap> copy(ref<android::graphics::Bitmap_Config> config, jboolean isMutable);
	static ref<android::graphics::Bitmap> createScaledBitmap(ref<android::graphics::Bitmap> src, jint dstWidth, jint dstHeight, jboolean filter);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::graphics::Bitmap> src);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::graphics::Bitmap> source, jint x, jint y, jint width, jint height);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::graphics::Bitmap> source, jint x, jint y, jint width, jint height, ref<android::graphics::Matrix> m, jboolean filter);
	static ref<android::graphics::Bitmap> createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha);
	static ref<android::graphics::Bitmap> createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha, ref<android::graphics::ColorSpace> colorSpace);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha, ref<android::graphics::ColorSpace> colorSpace);
	static ref<android::graphics::Bitmap> createBitmap(ref<link::java::array<jint>> colors, jint offset, jint stride, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::util::DisplayMetrics> display, ref<link::java::array<jint>> colors, jint offset, jint stride, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(ref<link::java::array<jint>> colors, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::util::DisplayMetrics> display, ref<link::java::array<jint>> colors, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::graphics::Picture> source);
	static ref<android::graphics::Bitmap> createBitmap(ref<android::graphics::Picture> source, jint width, jint height, ref<android::graphics::Bitmap_Config> config);
	ref<link::java::array<jbyte>> getNinePatchChunk();
	jboolean compress(ref<android::graphics::Bitmap_CompressFormat> format, jint quality, ref<java::io::OutputStream> stream);
	jboolean isMutable();
	jboolean isPremultiplied();
	void setPremultiplied(jboolean premultiplied);
	jint getWidth();
	jint getHeight();
	jint getScaledWidth(ref<android::graphics::Canvas> canvas);
	jint getScaledHeight(ref<android::graphics::Canvas> canvas);
	jint getScaledWidth(ref<android::util::DisplayMetrics> metrics);
	jint getScaledHeight(ref<android::util::DisplayMetrics> metrics);
	jint getScaledWidth(jint targetDensity);
	jint getScaledHeight(jint targetDensity);
	jint getRowBytes();
	jint getByteCount();
	jint getAllocationByteCount();
	ref<android::graphics::Bitmap_Config> getConfig();
	jboolean hasAlpha();
	void setHasAlpha(jboolean hasAlpha);
	jboolean hasMipMap();
	void setHasMipMap(jboolean hasMipMap);
	ref<android::graphics::ColorSpace> getColorSpace();
	void eraseColor(jint c);
	jint getPixel(jint x, jint y);
	void getPixels(ref<link::java::array<jint>> pixels, jint offset, jint stride, jint x, jint y, jint width, jint height);
	void setPixel(jint x, jint y, jint color);
	void setPixels(ref<link::java::array<jint>> pixels, jint offset, jint stride, jint x, jint y, jint width, jint height);
	jint describeContents();
	void writeToParcel(ref<android::os::Parcel> p, jint flags);
	ref<android::graphics::Bitmap> extractAlpha();
	ref<android::graphics::Bitmap> extractAlpha(ref<android::graphics::Paint> paint, ref<link::java::array<jint>> offsetXY);
	jboolean sameAs(ref<android::graphics::Bitmap> other);
	void prepareToDraw();

protected:

	Bitmap(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/android/graphics/Bitmap_CompressFormat.h>
#include <scapix/java_api/android/graphics/Bitmap_Config.h>
#include <scapix/java_api/android/graphics/Canvas.h>
#include <scapix/java_api/android/graphics/ColorSpace.h>
#include <scapix/java_api/android/graphics/Matrix.h>
#include <scapix/java_api/android/graphics/Paint.h>
#include <scapix/java_api/android/graphics/Picture.h>
#include <scapix/java_api/android/os/Parcel.h>
#include <scapix/java_api/android/os/Parcelable_Creator.h>
#include <scapix/java_api/android/util/DisplayMetrics.h>
#include <scapix/java_api/java/io/OutputStream.h>
#include <scapix/java_api/java/nio/Buffer.h>

namespace scapix::java_api {
namespace android::graphics {

inline ref<android::os::Parcelable_Creator> Bitmap::CREATOR_() { return get_static_field<SCAPIX_META_STRING("CREATOR"), ref<android::os::Parcelable_Creator>>(); }
inline jint Bitmap::DENSITY_NONE_() { return get_static_field<SCAPIX_META_STRING("DENSITY_NONE"), jint>(); }
inline jint Bitmap::getDensity() { return call_method<SCAPIX_META_STRING("getDensity"), jint>(); }
inline void Bitmap::setDensity(jint density) { return call_method<SCAPIX_META_STRING("setDensity"), void>(density); }
inline void Bitmap::reconfigure(jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_method<SCAPIX_META_STRING("reconfigure"), void>(width, height, config); }
inline void Bitmap::setWidth(jint width) { return call_method<SCAPIX_META_STRING("setWidth"), void>(width); }
inline void Bitmap::setHeight(jint height) { return call_method<SCAPIX_META_STRING("setHeight"), void>(height); }
inline void Bitmap::setConfig(ref<android::graphics::Bitmap_Config> config) { return call_method<SCAPIX_META_STRING("setConfig"), void>(config); }
inline void Bitmap::recycle() { return call_method<SCAPIX_META_STRING("recycle"), void>(); }
inline jboolean Bitmap::isRecycled() { return call_method<SCAPIX_META_STRING("isRecycled"), jboolean>(); }
inline jint Bitmap::getGenerationId() { return call_method<SCAPIX_META_STRING("getGenerationId"), jint>(); }
inline void Bitmap::copyPixelsToBuffer(ref<java::nio::Buffer> dst) { return call_method<SCAPIX_META_STRING("copyPixelsToBuffer"), void>(dst); }
inline void Bitmap::copyPixelsFromBuffer(ref<java::nio::Buffer> src) { return call_method<SCAPIX_META_STRING("copyPixelsFromBuffer"), void>(src); }
inline ref<android::graphics::Bitmap> Bitmap::copy(ref<android::graphics::Bitmap_Config> config, jboolean isMutable) { return call_method<SCAPIX_META_STRING("copy"), ref<android::graphics::Bitmap>>(config, isMutable); }
inline ref<android::graphics::Bitmap> Bitmap::createScaledBitmap(ref<android::graphics::Bitmap> src, jint dstWidth, jint dstHeight, jboolean filter) { return call_static_method<SCAPIX_META_STRING("createScaledBitmap"), ref<android::graphics::Bitmap>>(src, dstWidth, dstHeight, filter); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::graphics::Bitmap> src) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(src); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::graphics::Bitmap> source, jint x, jint y, jint width, jint height) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(source, x, y, width, height); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::graphics::Bitmap> source, jint x, jint y, jint width, jint height, ref<android::graphics::Matrix> m, jboolean filter) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(source, x, y, width, height, m, filter); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(display, width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(width, height, config, hasAlpha); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha, ref<android::graphics::ColorSpace> colorSpace) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(width, height, config, hasAlpha, colorSpace); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(display, width, height, config, hasAlpha); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::util::DisplayMetrics> display, jint width, jint height, ref<android::graphics::Bitmap_Config> config, jboolean hasAlpha, ref<android::graphics::ColorSpace> colorSpace) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(display, width, height, config, hasAlpha, colorSpace); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<link::java::array<jint>> colors, jint offset, jint stride, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(colors, offset, stride, width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::util::DisplayMetrics> display, ref<link::java::array<jint>> colors, jint offset, jint stride, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(display, colors, offset, stride, width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<link::java::array<jint>> colors, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(colors, width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::util::DisplayMetrics> display, ref<link::java::array<jint>> colors, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(display, colors, width, height, config); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::graphics::Picture> source) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(source); }
inline ref<android::graphics::Bitmap> Bitmap::createBitmap(ref<android::graphics::Picture> source, jint width, jint height, ref<android::graphics::Bitmap_Config> config) { return call_static_method<SCAPIX_META_STRING("createBitmap"), ref<android::graphics::Bitmap>>(source, width, height, config); }
inline ref<link::java::array<jbyte>> Bitmap::getNinePatchChunk() { return call_method<SCAPIX_META_STRING("getNinePatchChunk"), ref<link::java::array<jbyte>>>(); }
inline jboolean Bitmap::compress(ref<android::graphics::Bitmap_CompressFormat> format, jint quality, ref<java::io::OutputStream> stream) { return call_method<SCAPIX_META_STRING("compress"), jboolean>(format, quality, stream); }
inline jboolean Bitmap::isMutable() { return call_method<SCAPIX_META_STRING("isMutable"), jboolean>(); }
inline jboolean Bitmap::isPremultiplied() { return call_method<SCAPIX_META_STRING("isPremultiplied"), jboolean>(); }
inline void Bitmap::setPremultiplied(jboolean premultiplied) { return call_method<SCAPIX_META_STRING("setPremultiplied"), void>(premultiplied); }
inline jint Bitmap::getWidth() { return call_method<SCAPIX_META_STRING("getWidth"), jint>(); }
inline jint Bitmap::getHeight() { return call_method<SCAPIX_META_STRING("getHeight"), jint>(); }
inline jint Bitmap::getScaledWidth(ref<android::graphics::Canvas> canvas) { return call_method<SCAPIX_META_STRING("getScaledWidth"), jint>(canvas); }
inline jint Bitmap::getScaledHeight(ref<android::graphics::Canvas> canvas) { return call_method<SCAPIX_META_STRING("getScaledHeight"), jint>(canvas); }
inline jint Bitmap::getScaledWidth(ref<android::util::DisplayMetrics> metrics) { return call_method<SCAPIX_META_STRING("getScaledWidth"), jint>(metrics); }
inline jint Bitmap::getScaledHeight(ref<android::util::DisplayMetrics> metrics) { return call_method<SCAPIX_META_STRING("getScaledHeight"), jint>(metrics); }
inline jint Bitmap::getScaledWidth(jint targetDensity) { return call_method<SCAPIX_META_STRING("getScaledWidth"), jint>(targetDensity); }
inline jint Bitmap::getScaledHeight(jint targetDensity) { return call_method<SCAPIX_META_STRING("getScaledHeight"), jint>(targetDensity); }
inline jint Bitmap::getRowBytes() { return call_method<SCAPIX_META_STRING("getRowBytes"), jint>(); }
inline jint Bitmap::getByteCount() { return call_method<SCAPIX_META_STRING("getByteCount"), jint>(); }
inline jint Bitmap::getAllocationByteCount() { return call_method<SCAPIX_META_STRING("getAllocationByteCount"), jint>(); }
inline ref<android::graphics::Bitmap_Config> Bitmap::getConfig() { return call_method<SCAPIX_META_STRING("getConfig"), ref<android::graphics::Bitmap_Config>>(); }
inline jboolean Bitmap::hasAlpha() { return call_method<SCAPIX_META_STRING("hasAlpha"), jboolean>(); }
inline void Bitmap::setHasAlpha(jboolean hasAlpha) { return call_method<SCAPIX_META_STRING("setHasAlpha"), void>(hasAlpha); }
inline jboolean Bitmap::hasMipMap() { return call_method<SCAPIX_META_STRING("hasMipMap"), jboolean>(); }
inline void Bitmap::setHasMipMap(jboolean hasMipMap) { return call_method<SCAPIX_META_STRING("setHasMipMap"), void>(hasMipMap); }
inline ref<android::graphics::ColorSpace> Bitmap::getColorSpace() { return call_method<SCAPIX_META_STRING("getColorSpace"), ref<android::graphics::ColorSpace>>(); }
inline void Bitmap::eraseColor(jint c) { return call_method<SCAPIX_META_STRING("eraseColor"), void>(c); }
inline jint Bitmap::getPixel(jint x, jint y) { return call_method<SCAPIX_META_STRING("getPixel"), jint>(x, y); }
inline void Bitmap::getPixels(ref<link::java::array<jint>> pixels, jint offset, jint stride, jint x, jint y, jint width, jint height) { return call_method<SCAPIX_META_STRING("getPixels"), void>(pixels, offset, stride, x, y, width, height); }
inline void Bitmap::setPixel(jint x, jint y, jint color) { return call_method<SCAPIX_META_STRING("setPixel"), void>(x, y, color); }
inline void Bitmap::setPixels(ref<link::java::array<jint>> pixels, jint offset, jint stride, jint x, jint y, jint width, jint height) { return call_method<SCAPIX_META_STRING("setPixels"), void>(pixels, offset, stride, x, y, width, height); }
inline jint Bitmap::describeContents() { return call_method<SCAPIX_META_STRING("describeContents"), jint>(); }
inline void Bitmap::writeToParcel(ref<android::os::Parcel> p, jint flags) { return call_method<SCAPIX_META_STRING("writeToParcel"), void>(p, flags); }
inline ref<android::graphics::Bitmap> Bitmap::extractAlpha() { return call_method<SCAPIX_META_STRING("extractAlpha"), ref<android::graphics::Bitmap>>(); }
inline ref<android::graphics::Bitmap> Bitmap::extractAlpha(ref<android::graphics::Paint> paint, ref<link::java::array<jint>> offsetXY) { return call_method<SCAPIX_META_STRING("extractAlpha"), ref<android::graphics::Bitmap>>(paint, offsetXY); }
inline jboolean Bitmap::sameAs(ref<android::graphics::Bitmap> other) { return call_method<SCAPIX_META_STRING("sameAs"), jboolean>(other); }
inline void Bitmap::prepareToDraw() { return call_method<SCAPIX_META_STRING("prepareToDraw"), void>(); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_BITMAP_H
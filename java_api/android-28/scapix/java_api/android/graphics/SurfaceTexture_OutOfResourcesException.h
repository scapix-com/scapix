// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Exception.h>

#ifndef SCAPIX_ANDROID_GRAPHICS_SURFACETEXTURE_OUTOFRESOURCESEXCEPTION_H
#define SCAPIX_ANDROID_GRAPHICS_SURFACETEXTURE_OUTOFRESOURCESEXCEPTION_H

namespace scapix::java_api {

namespace java::lang { class String; }

namespace android::graphics {

class SurfaceTexture_OutOfResourcesException : public object_base<SCAPIX_META_STRING("android/graphics/SurfaceTexture$OutOfResourcesException"),
	java::lang::Exception>
{
public:

	static ref<SurfaceTexture_OutOfResourcesException> new_object();
	static ref<SurfaceTexture_OutOfResourcesException> new_object(ref<java::lang::String> name);

protected:

	SurfaceTexture_OutOfResourcesException(handle_type h) : base_(h) {}

};

} // namespace android::graphics
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::graphics {

inline ref<SurfaceTexture_OutOfResourcesException> SurfaceTexture_OutOfResourcesException::new_object() { return base_::new_object(); }
inline ref<SurfaceTexture_OutOfResourcesException> SurfaceTexture_OutOfResourcesException::new_object(ref<java::lang::String> name) { return base_::new_object(name); }

} // namespace android::graphics
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_GRAPHICS_SURFACETEXTURE_OUTOFRESOURCESEXCEPTION_H
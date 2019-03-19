// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_DRM_DRMUTILS_H
#define SCAPIX_ANDROID_DRM_DRMUTILS_H

namespace scapix::java_api {

namespace android::drm { class DrmUtils_ExtendedMetadataParser; }

namespace android::drm {

class DrmUtils : public object_base<SCAPIX_META_STRING("android/drm/DrmUtils"),
	java::lang::Object>
{
public:

	using ExtendedMetadataParser = DrmUtils_ExtendedMetadataParser;

	static ref<DrmUtils> new_object();
	static ref<android::drm::DrmUtils_ExtendedMetadataParser> getExtendedMetadataParser(ref<link::java::array<jbyte>> extendedMetadata);

protected:

	DrmUtils(handle_type h) : base_(h) {}

};

} // namespace android::drm
} // namespace scapix::java_api

#include <scapix/java_api/android/drm/DrmUtils_ExtendedMetadataParser.h>

namespace scapix::java_api {
namespace android::drm {

inline ref<DrmUtils> DrmUtils::new_object() { return base_::new_object(); }
inline ref<android::drm::DrmUtils_ExtendedMetadataParser> DrmUtils::getExtendedMetadataParser(ref<link::java::array<jbyte>> extendedMetadata) { return call_static_method<SCAPIX_META_STRING("getExtendedMetadataParser"), ref<android::drm::DrmUtils_ExtendedMetadataParser>>(extendedMetadata); }

} // namespace android::drm
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_DRM_DRMUTILS_H
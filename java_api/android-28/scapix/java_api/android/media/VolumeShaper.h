// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/AutoCloseable.h>

#ifndef SCAPIX_ANDROID_MEDIA_VOLUMESHAPER_H
#define SCAPIX_ANDROID_MEDIA_VOLUMESHAPER_H

namespace scapix::java_api {

namespace android::media { class VolumeShaper_Configuration; }
namespace android::media { class VolumeShaper_Operation; }

namespace android::media {

class VolumeShaper : public object_base<SCAPIX_META_STRING("android/media/VolumeShaper"),
	java::lang::Object,
	java::lang::AutoCloseable>
{
public:

	using Operation = VolumeShaper_Operation;
	using Configuration = VolumeShaper_Configuration;

	void apply(ref<android::media::VolumeShaper_Operation> operation);
	void replace(ref<android::media::VolumeShaper_Configuration> configuration, ref<android::media::VolumeShaper_Operation> operation, jboolean join);
	jfloat getVolume();
	void close();

protected:

	VolumeShaper(handle_type h) : base_(h) {}

};

} // namespace android::media
} // namespace scapix::java_api

#include <scapix/java_api/android/media/VolumeShaper_Configuration.h>
#include <scapix/java_api/android/media/VolumeShaper_Operation.h>

namespace scapix::java_api {
namespace android::media {

inline void VolumeShaper::apply(ref<android::media::VolumeShaper_Operation> operation) { return call_method<SCAPIX_META_STRING("apply"), void>(operation); }
inline void VolumeShaper::replace(ref<android::media::VolumeShaper_Configuration> configuration, ref<android::media::VolumeShaper_Operation> operation, jboolean join) { return call_method<SCAPIX_META_STRING("replace"), void>(configuration, operation, join); }
inline jfloat VolumeShaper::getVolume() { return call_method<SCAPIX_META_STRING("getVolume"), jfloat>(); }
inline void VolumeShaper::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }

} // namespace android::media
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_MEDIA_VOLUMESHAPER_H
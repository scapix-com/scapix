// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_DALVIK_SYSTEM_DEXFILE_H
#define SCAPIX_DALVIK_SYSTEM_DEXFILE_H

namespace scapix::java_api {

namespace java::io { class File; }
namespace java::lang { class Class; }
namespace java::lang { class ClassLoader; }
namespace java::lang { class String; }
namespace java::util { class Enumeration; }

namespace dalvik::system {

class DexFile : public object_base<SCAPIX_META_STRING("dalvik/system/DexFile"),
	java::lang::Object>
{
public:

	static ref<DexFile> new_object(ref<java::io::File> file);
	static ref<DexFile> new_object(ref<java::lang::String> fileName);
	static ref<dalvik::system::DexFile> loadDex(ref<java::lang::String> sourcePathName, ref<java::lang::String> outputPathName, jint flags);
	ref<java::lang::String> getName();
	ref<java::lang::String> toString();
	void close();
	ref<java::lang::Class> loadClass(ref<java::lang::String> name, ref<java::lang::ClassLoader> loader);
	ref<java::util::Enumeration> entries();
	static jboolean isDexOptNeeded(ref<java::lang::String> p1);

protected:

	DexFile(handle_type h) : base_(h) {}

};

} // namespace dalvik::system
} // namespace scapix::java_api

#include <scapix/java_api/java/io/File.h>
#include <scapix/java_api/java/lang/Class.h>
#include <scapix/java_api/java/lang/ClassLoader.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Enumeration.h>

namespace scapix::java_api {
namespace dalvik::system {

inline ref<DexFile> DexFile::new_object(ref<java::io::File> file) { return base_::new_object(file); }
inline ref<DexFile> DexFile::new_object(ref<java::lang::String> fileName) { return base_::new_object(fileName); }
inline ref<dalvik::system::DexFile> DexFile::loadDex(ref<java::lang::String> sourcePathName, ref<java::lang::String> outputPathName, jint flags) { return call_static_method<SCAPIX_META_STRING("loadDex"), ref<dalvik::system::DexFile>>(sourcePathName, outputPathName, flags); }
inline ref<java::lang::String> DexFile::getName() { return call_method<SCAPIX_META_STRING("getName"), ref<java::lang::String>>(); }
inline ref<java::lang::String> DexFile::toString() { return call_method<SCAPIX_META_STRING("toString"), ref<java::lang::String>>(); }
inline void DexFile::close() { return call_method<SCAPIX_META_STRING("close"), void>(); }
inline ref<java::lang::Class> DexFile::loadClass(ref<java::lang::String> name, ref<java::lang::ClassLoader> loader) { return call_method<SCAPIX_META_STRING("loadClass"), ref<java::lang::Class>>(name, loader); }
inline ref<java::util::Enumeration> DexFile::entries() { return call_method<SCAPIX_META_STRING("entries"), ref<java::util::Enumeration>>(); }
inline jboolean DexFile::isDexOptNeeded(ref<java::lang::String> p1) { return call_static_method<SCAPIX_META_STRING("isDexOptNeeded"), jboolean>(p1); }

} // namespace dalvik::system
} // namespace scapix::java_api

#endif // SCAPIX_DALVIK_SYSTEM_DEXFILE_H
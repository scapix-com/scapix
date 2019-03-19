// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/util/zip/ZipFile.h>

#ifndef SCAPIX_JAVA_UTIL_JAR_JARFILE_H
#define SCAPIX_JAVA_UTIL_JAR_JARFILE_H

namespace scapix::java_api {

namespace java::io { class File; }
namespace java::io { class InputStream; }
namespace java::lang { class Runtime_Version; }
namespace java::lang { class String; }
namespace java::util { class Enumeration; }
namespace java::util::jar { class JarEntry; }
namespace java::util::jar { class Manifest; }
namespace java::util::stream { class Stream; }
namespace java::util::zip { class ZipEntry; }

namespace java::util::jar {

class JarFile : public object_base<SCAPIX_META_STRING("java/util/jar/JarFile"),
	java::util::zip::ZipFile>
{
public:

	static ref<java::lang::String> MANIFEST_NAME_();

	static ref<java::lang::Runtime_Version> baseVersion();
	static ref<java::lang::Runtime_Version> runtimeVersion();
	static ref<JarFile> new_object(ref<java::lang::String> name);
	static ref<JarFile> new_object(ref<java::lang::String> name, jboolean verify);
	static ref<JarFile> new_object(ref<java::io::File> file);
	static ref<JarFile> new_object(ref<java::io::File> file, jboolean verify);
	static ref<JarFile> new_object(ref<java::io::File> file, jboolean verify, jint mode);
	static ref<JarFile> new_object(ref<java::io::File> file, jboolean verify, jint mode, ref<java::lang::Runtime_Version> version);
	ref<java::lang::Runtime_Version> getVersion();
	jboolean isMultiRelease();
	ref<java::util::jar::Manifest> getManifest();
	ref<java::util::jar::JarEntry> getJarEntry(ref<java::lang::String> name);
	ref<java::util::zip::ZipEntry> getEntry(ref<java::lang::String> name);
	ref<java::util::Enumeration> entries();
	ref<java::util::stream::Stream> stream();
	ref<java::util::stream::Stream> versionedStream();
	ref<java::io::InputStream> getInputStream(ref<java::util::zip::ZipEntry> ze);

protected:

	JarFile(handle_type h) : base_(h) {}

};

} // namespace java::util::jar
} // namespace scapix::java_api

#include <scapix/java_api/java/io/File.h>
#include <scapix/java_api/java/io/InputStream.h>
#include <scapix/java_api/java/lang/Runtime_Version.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/Enumeration.h>
#include <scapix/java_api/java/util/jar/JarEntry.h>
#include <scapix/java_api/java/util/jar/Manifest.h>
#include <scapix/java_api/java/util/stream/Stream.h>
#include <scapix/java_api/java/util/zip/ZipEntry.h>

namespace scapix::java_api {
namespace java::util::jar {

inline ref<java::lang::String> JarFile::MANIFEST_NAME_() { return get_static_field<SCAPIX_META_STRING("MANIFEST_NAME"), ref<java::lang::String>>(); }
inline ref<java::lang::Runtime_Version> JarFile::baseVersion() { return call_static_method<SCAPIX_META_STRING("baseVersion"), ref<java::lang::Runtime_Version>>(); }
inline ref<java::lang::Runtime_Version> JarFile::runtimeVersion() { return call_static_method<SCAPIX_META_STRING("runtimeVersion"), ref<java::lang::Runtime_Version>>(); }
inline ref<JarFile> JarFile::new_object(ref<java::lang::String> name) { return base_::new_object(name); }
inline ref<JarFile> JarFile::new_object(ref<java::lang::String> name, jboolean verify) { return base_::new_object(name, verify); }
inline ref<JarFile> JarFile::new_object(ref<java::io::File> file) { return base_::new_object(file); }
inline ref<JarFile> JarFile::new_object(ref<java::io::File> file, jboolean verify) { return base_::new_object(file, verify); }
inline ref<JarFile> JarFile::new_object(ref<java::io::File> file, jboolean verify, jint mode) { return base_::new_object(file, verify, mode); }
inline ref<JarFile> JarFile::new_object(ref<java::io::File> file, jboolean verify, jint mode, ref<java::lang::Runtime_Version> version) { return base_::new_object(file, verify, mode, version); }
inline ref<java::lang::Runtime_Version> JarFile::getVersion() { return call_method<SCAPIX_META_STRING("getVersion"), ref<java::lang::Runtime_Version>>(); }
inline jboolean JarFile::isMultiRelease() { return call_method<SCAPIX_META_STRING("isMultiRelease"), jboolean>(); }
inline ref<java::util::jar::Manifest> JarFile::getManifest() { return call_method<SCAPIX_META_STRING("getManifest"), ref<java::util::jar::Manifest>>(); }
inline ref<java::util::jar::JarEntry> JarFile::getJarEntry(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("getJarEntry"), ref<java::util::jar::JarEntry>>(name); }
inline ref<java::util::zip::ZipEntry> JarFile::getEntry(ref<java::lang::String> name) { return call_method<SCAPIX_META_STRING("getEntry"), ref<java::util::zip::ZipEntry>>(name); }
inline ref<java::util::Enumeration> JarFile::entries() { return call_method<SCAPIX_META_STRING("entries"), ref<java::util::Enumeration>>(); }
inline ref<java::util::stream::Stream> JarFile::stream() { return call_method<SCAPIX_META_STRING("stream"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> JarFile::versionedStream() { return call_method<SCAPIX_META_STRING("versionedStream"), ref<java::util::stream::Stream>>(); }
inline ref<java::io::InputStream> JarFile::getInputStream(ref<java::util::zip::ZipEntry> ze) { return call_method<SCAPIX_META_STRING("getInputStream"), ref<java::io::InputStream>>(ze); }

} // namespace java::util::jar
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_UTIL_JAR_JARFILE_H
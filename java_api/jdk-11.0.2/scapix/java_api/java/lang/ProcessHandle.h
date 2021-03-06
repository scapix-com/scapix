// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/Comparable.h>

#ifndef SCAPIX_JAVA_LANG_PROCESSHANDLE_H
#define SCAPIX_JAVA_LANG_PROCESSHANDLE_H

namespace scapix::java_api {

namespace java::lang { class ProcessHandle_Info; }
namespace java::util { class Optional; }
namespace java::util::concurrent { class CompletableFuture; }
namespace java::util::stream { class Stream; }

namespace java::lang {

class ProcessHandle : public object_base<SCAPIX_META_STRING("java/lang/ProcessHandle"),
	java::lang::Object,
	java::lang::Comparable>
{
public:

	using Info = ProcessHandle_Info;

	jlong pid();
	static ref<java::util::Optional> of(jlong pid);
	static ref<java::lang::ProcessHandle> current();
	ref<java::util::Optional> parent();
	ref<java::util::stream::Stream> children();
	ref<java::util::stream::Stream> descendants();
	static ref<java::util::stream::Stream> allProcesses();
	ref<java::lang::ProcessHandle_Info> info();
	ref<java::util::concurrent::CompletableFuture> onExit();
	jboolean supportsNormalTermination();
	jboolean destroy();
	jboolean destroyForcibly();
	jboolean isAlive();
	jint hashCode();
	jboolean equals(ref<java::lang::Object> p1);
	jint compareTo(ref<java::lang::ProcessHandle> p1);

protected:

	ProcessHandle(handle_type h) : base_(h) {}

};

} // namespace java::lang
} // namespace scapix::java_api

#include <scapix/java_api/java/lang/ProcessHandle_Info.h>
#include <scapix/java_api/java/util/Optional.h>
#include <scapix/java_api/java/util/concurrent/CompletableFuture.h>
#include <scapix/java_api/java/util/stream/Stream.h>

namespace scapix::java_api {
namespace java::lang {

inline jlong ProcessHandle::pid() { return call_method<SCAPIX_META_STRING("pid"), jlong>(); }
inline ref<java::util::Optional> ProcessHandle::of(jlong pid) { return call_static_method<SCAPIX_META_STRING("of"), ref<java::util::Optional>>(pid); }
inline ref<java::lang::ProcessHandle> ProcessHandle::current() { return call_static_method<SCAPIX_META_STRING("current"), ref<java::lang::ProcessHandle>>(); }
inline ref<java::util::Optional> ProcessHandle::parent() { return call_method<SCAPIX_META_STRING("parent"), ref<java::util::Optional>>(); }
inline ref<java::util::stream::Stream> ProcessHandle::children() { return call_method<SCAPIX_META_STRING("children"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> ProcessHandle::descendants() { return call_method<SCAPIX_META_STRING("descendants"), ref<java::util::stream::Stream>>(); }
inline ref<java::util::stream::Stream> ProcessHandle::allProcesses() { return call_static_method<SCAPIX_META_STRING("allProcesses"), ref<java::util::stream::Stream>>(); }
inline ref<java::lang::ProcessHandle_Info> ProcessHandle::info() { return call_method<SCAPIX_META_STRING("info"), ref<java::lang::ProcessHandle_Info>>(); }
inline ref<java::util::concurrent::CompletableFuture> ProcessHandle::onExit() { return call_method<SCAPIX_META_STRING("onExit"), ref<java::util::concurrent::CompletableFuture>>(); }
inline jboolean ProcessHandle::supportsNormalTermination() { return call_method<SCAPIX_META_STRING("supportsNormalTermination"), jboolean>(); }
inline jboolean ProcessHandle::destroy() { return call_method<SCAPIX_META_STRING("destroy"), jboolean>(); }
inline jboolean ProcessHandle::destroyForcibly() { return call_method<SCAPIX_META_STRING("destroyForcibly"), jboolean>(); }
inline jboolean ProcessHandle::isAlive() { return call_method<SCAPIX_META_STRING("isAlive"), jboolean>(); }
inline jint ProcessHandle::hashCode() { return call_method<SCAPIX_META_STRING("hashCode"), jint>(); }
inline jboolean ProcessHandle::equals(ref<java::lang::Object> p1) { return call_method<SCAPIX_META_STRING("equals"), jboolean>(p1); }
inline jint ProcessHandle::compareTo(ref<java::lang::ProcessHandle> p1) { return call_method<SCAPIX_META_STRING("compareTo"), jint>(p1); }

} // namespace java::lang
} // namespace scapix::java_api

#endif // SCAPIX_JAVA_LANG_PROCESSHANDLE_H

// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_VIEW_VIEWDEBUG_H
#define SCAPIX_ANDROID_VIEW_VIEWDEBUG_H

namespace scapix::java_api {

namespace android::view { class View; }
namespace android::view { class ViewDebug_HierarchyTraceType; }
namespace android::view { class ViewDebug_RecyclerTraceType; }
namespace java::lang { class String; }
namespace android::view { class ViewDebug_IntToString; }
namespace android::view { class ViewDebug_FlagToString; }
namespace android::view { class ViewDebug_ExportedProperty; }
namespace android::view { class ViewDebug_CapturedViewProperty; }

namespace android::view {

class ViewDebug : public object_base<SCAPIX_META_STRING("android/view/ViewDebug"),
	java::lang::Object>
{
public:

	using RecyclerTraceType = ViewDebug_RecyclerTraceType;
	using IntToString = ViewDebug_IntToString;
	using HierarchyTraceType = ViewDebug_HierarchyTraceType;
	using FlagToString = ViewDebug_FlagToString;
	using ExportedProperty = ViewDebug_ExportedProperty;
	using CapturedViewProperty = ViewDebug_CapturedViewProperty;

	static jboolean TRACE_HIERARCHY_();
	static jboolean TRACE_RECYCLER_();

	static ref<ViewDebug> new_object();
	static void trace(ref<android::view::View> view, ref<android::view::ViewDebug_RecyclerTraceType> type, ref<link::java::array<jint>> parameters);
	static void startRecyclerTracing(ref<java::lang::String> prefix, ref<android::view::View> view);
	static void stopRecyclerTracing();
	static void trace(ref<android::view::View> view, ref<android::view::ViewDebug_HierarchyTraceType> type);
	static void startHierarchyTracing(ref<java::lang::String> prefix, ref<android::view::View> view);
	static void stopHierarchyTracing();
	static void dumpCapturedView(ref<java::lang::String> tag, ref<java::lang::Object> view);

protected:

	ViewDebug(handle_type h) : base_(h) {}

};

} // namespace android::view
} // namespace scapix::java_api

#include <scapix/java_api/android/view/View.h>
#include <scapix/java_api/android/view/ViewDebug_HierarchyTraceType.h>
#include <scapix/java_api/android/view/ViewDebug_RecyclerTraceType.h>
#include <scapix/java_api/java/lang/String.h>

namespace scapix::java_api {
namespace android::view {

inline jboolean ViewDebug::TRACE_HIERARCHY_() { return get_static_field<SCAPIX_META_STRING("TRACE_HIERARCHY"), jboolean>(); }
inline jboolean ViewDebug::TRACE_RECYCLER_() { return get_static_field<SCAPIX_META_STRING("TRACE_RECYCLER"), jboolean>(); }
inline ref<ViewDebug> ViewDebug::new_object() { return base_::new_object(); }
inline void ViewDebug::trace(ref<android::view::View> view, ref<android::view::ViewDebug_RecyclerTraceType> type, ref<link::java::array<jint>> parameters) { return call_static_method<SCAPIX_META_STRING("trace"), void>(view, type, parameters); }
inline void ViewDebug::startRecyclerTracing(ref<java::lang::String> prefix, ref<android::view::View> view) { return call_static_method<SCAPIX_META_STRING("startRecyclerTracing"), void>(prefix, view); }
inline void ViewDebug::stopRecyclerTracing() { return call_static_method<SCAPIX_META_STRING("stopRecyclerTracing"), void>(); }
inline void ViewDebug::trace(ref<android::view::View> view, ref<android::view::ViewDebug_HierarchyTraceType> type) { return call_static_method<SCAPIX_META_STRING("trace"), void>(view, type); }
inline void ViewDebug::startHierarchyTracing(ref<java::lang::String> prefix, ref<android::view::View> view) { return call_static_method<SCAPIX_META_STRING("startHierarchyTracing"), void>(prefix, view); }
inline void ViewDebug::stopHierarchyTracing() { return call_static_method<SCAPIX_META_STRING("stopHierarchyTracing"), void>(); }
inline void ViewDebug::dumpCapturedView(ref<java::lang::String> tag, ref<java::lang::Object> view) { return call_static_method<SCAPIX_META_STRING("dumpCapturedView"), void>(tag, view); }

} // namespace android::view
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_VIEW_VIEWDEBUG_H
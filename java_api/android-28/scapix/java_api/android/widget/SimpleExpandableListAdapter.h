// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/android/widget/BaseExpandableListAdapter.h>

#ifndef SCAPIX_ANDROID_WIDGET_SIMPLEEXPANDABLELISTADAPTER_H
#define SCAPIX_ANDROID_WIDGET_SIMPLEEXPANDABLELISTADAPTER_H

namespace scapix::java_api {

namespace android::content { class Context; }
namespace android::view { class View; }
namespace android::view { class ViewGroup; }
namespace java::lang { class Object; }
namespace java::lang { class String; }
namespace java::util { class List; }

namespace android::widget {

class SimpleExpandableListAdapter : public object_base<SCAPIX_META_STRING("android/widget/SimpleExpandableListAdapter"),
	android::widget::BaseExpandableListAdapter>
{
public:

	static ref<SimpleExpandableListAdapter> new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint groupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo);
	static ref<SimpleExpandableListAdapter> new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint expandedGroupLayout, jint collapsedGroupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo);
	static ref<SimpleExpandableListAdapter> new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint expandedGroupLayout, jint collapsedGroupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, jint lastChildLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo);
	ref<java::lang::Object> getChild(jint groupPosition, jint childPosition);
	jlong getChildId(jint groupPosition, jint childPosition);
	ref<android::view::View> getChildView(jint groupPosition, jint childPosition, jboolean isLastChild, ref<android::view::View> convertView, ref<android::view::ViewGroup> parent);
	ref<android::view::View> newChildView(jboolean isLastChild, ref<android::view::ViewGroup> parent);
	jint getChildrenCount(jint groupPosition);
	ref<java::lang::Object> getGroup(jint groupPosition);
	jint getGroupCount();
	jlong getGroupId(jint groupPosition);
	ref<android::view::View> getGroupView(jint groupPosition, jboolean isExpanded, ref<android::view::View> convertView, ref<android::view::ViewGroup> parent);
	ref<android::view::View> newGroupView(jboolean isExpanded, ref<android::view::ViewGroup> parent);
	jboolean isChildSelectable(jint groupPosition, jint childPosition);
	jboolean hasStableIds();

protected:

	SimpleExpandableListAdapter(handle_type h) : base_(h) {}

};

} // namespace android::widget
} // namespace scapix::java_api

#include <scapix/java_api/android/content/Context.h>
#include <scapix/java_api/android/view/View.h>
#include <scapix/java_api/android/view/ViewGroup.h>
#include <scapix/java_api/java/lang/Object.h>
#include <scapix/java_api/java/lang/String.h>
#include <scapix/java_api/java/util/List.h>

namespace scapix::java_api {
namespace android::widget {

inline ref<SimpleExpandableListAdapter> SimpleExpandableListAdapter::new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint groupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo) { return base_::new_object(context, groupData, groupLayout, groupFrom, groupTo, childData, childLayout, childFrom, childTo); }
inline ref<SimpleExpandableListAdapter> SimpleExpandableListAdapter::new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint expandedGroupLayout, jint collapsedGroupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo) { return base_::new_object(context, groupData, expandedGroupLayout, collapsedGroupLayout, groupFrom, groupTo, childData, childLayout, childFrom, childTo); }
inline ref<SimpleExpandableListAdapter> SimpleExpandableListAdapter::new_object(ref<android::content::Context> context, ref<java::util::List> groupData, jint expandedGroupLayout, jint collapsedGroupLayout, ref<link::java::array<java::lang::String>> groupFrom, ref<link::java::array<jint>> groupTo, ref<java::util::List> childData, jint childLayout, jint lastChildLayout, ref<link::java::array<java::lang::String>> childFrom, ref<link::java::array<jint>> childTo) { return base_::new_object(context, groupData, expandedGroupLayout, collapsedGroupLayout, groupFrom, groupTo, childData, childLayout, lastChildLayout, childFrom, childTo); }
inline ref<java::lang::Object> SimpleExpandableListAdapter::getChild(jint groupPosition, jint childPosition) { return call_method<SCAPIX_META_STRING("getChild"), ref<java::lang::Object>>(groupPosition, childPosition); }
inline jlong SimpleExpandableListAdapter::getChildId(jint groupPosition, jint childPosition) { return call_method<SCAPIX_META_STRING("getChildId"), jlong>(groupPosition, childPosition); }
inline ref<android::view::View> SimpleExpandableListAdapter::getChildView(jint groupPosition, jint childPosition, jboolean isLastChild, ref<android::view::View> convertView, ref<android::view::ViewGroup> parent) { return call_method<SCAPIX_META_STRING("getChildView"), ref<android::view::View>>(groupPosition, childPosition, isLastChild, convertView, parent); }
inline ref<android::view::View> SimpleExpandableListAdapter::newChildView(jboolean isLastChild, ref<android::view::ViewGroup> parent) { return call_method<SCAPIX_META_STRING("newChildView"), ref<android::view::View>>(isLastChild, parent); }
inline jint SimpleExpandableListAdapter::getChildrenCount(jint groupPosition) { return call_method<SCAPIX_META_STRING("getChildrenCount"), jint>(groupPosition); }
inline ref<java::lang::Object> SimpleExpandableListAdapter::getGroup(jint groupPosition) { return call_method<SCAPIX_META_STRING("getGroup"), ref<java::lang::Object>>(groupPosition); }
inline jint SimpleExpandableListAdapter::getGroupCount() { return call_method<SCAPIX_META_STRING("getGroupCount"), jint>(); }
inline jlong SimpleExpandableListAdapter::getGroupId(jint groupPosition) { return call_method<SCAPIX_META_STRING("getGroupId"), jlong>(groupPosition); }
inline ref<android::view::View> SimpleExpandableListAdapter::getGroupView(jint groupPosition, jboolean isExpanded, ref<android::view::View> convertView, ref<android::view::ViewGroup> parent) { return call_method<SCAPIX_META_STRING("getGroupView"), ref<android::view::View>>(groupPosition, isExpanded, convertView, parent); }
inline ref<android::view::View> SimpleExpandableListAdapter::newGroupView(jboolean isExpanded, ref<android::view::ViewGroup> parent) { return call_method<SCAPIX_META_STRING("newGroupView"), ref<android::view::View>>(isExpanded, parent); }
inline jboolean SimpleExpandableListAdapter::isChildSelectable(jint groupPosition, jint childPosition) { return call_method<SCAPIX_META_STRING("isChildSelectable"), jboolean>(groupPosition, childPosition); }
inline jboolean SimpleExpandableListAdapter::hasStableIds() { return call_method<SCAPIX_META_STRING("hasStableIds"), jboolean>(); }

} // namespace android::widget
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_WIDGET_SIMPLEEXPANDABLELISTADAPTER_H
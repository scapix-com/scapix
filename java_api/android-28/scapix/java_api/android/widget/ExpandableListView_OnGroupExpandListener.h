// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_WIDGET_EXPANDABLELISTVIEW_ONGROUPEXPANDLISTENER_H
#define SCAPIX_ANDROID_WIDGET_EXPANDABLELISTVIEW_ONGROUPEXPANDLISTENER_H

namespace scapix::java_api {


namespace android::widget {

class ExpandableListView_OnGroupExpandListener : public object_base<SCAPIX_META_STRING("android/widget/ExpandableListView$OnGroupExpandListener"),
	java::lang::Object>
{
public:

	void onGroupExpand(jint p1);

protected:

	ExpandableListView_OnGroupExpandListener(handle_type h) : base_(h) {}

};

} // namespace android::widget
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::widget {

inline void ExpandableListView_OnGroupExpandListener::onGroupExpand(jint p1) { return call_method<SCAPIX_META_STRING("onGroupExpand"), void>(p1); }

} // namespace android::widget
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_WIDGET_EXPANDABLELISTVIEW_ONGROUPEXPANDLISTENER_H

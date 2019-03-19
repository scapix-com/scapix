// Generated by Scapix Java API
// https://www.scapix.com

#include <scapix/java_api/java/lang/Object.h>

#ifndef SCAPIX_ANDROID_DATABASE_DATASETOBSERVER_H
#define SCAPIX_ANDROID_DATABASE_DATASETOBSERVER_H

namespace scapix::java_api {
namespace android::database {

class DataSetObserver : public object_base<SCAPIX_META_STRING("android/database/DataSetObserver"),
	java::lang::Object>
{
public:

	static ref<DataSetObserver> new_object();
	void onChanged();
	void onInvalidated();

protected:

	DataSetObserver(handle_type h) : base_(h) {}

};

} // namespace android::database
} // namespace scapix::java_api


namespace scapix::java_api {
namespace android::database {

inline ref<DataSetObserver> DataSetObserver::new_object() { return base_::new_object(); }
inline void DataSetObserver::onChanged() { return call_method<SCAPIX_META_STRING("onChanged"), void>(); }
inline void DataSetObserver::onInvalidated() { return call_method<SCAPIX_META_STRING("onInvalidated"), void>(); }

} // namespace android::database
} // namespace scapix::java_api

#endif // SCAPIX_ANDROID_DATABASE_DATASETOBSERVER_H
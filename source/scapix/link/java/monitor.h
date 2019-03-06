/*
	scapix/link/java/monitor.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_MONITOR_H
#define SCAPIX_LINK_JAVA_MONITOR_H

#include <utility>
#include <scapix/link/java/ref.h>
#include <scapix/link/java/detail/env.h>

namespace scapix {
namespace link {
namespace java {

class monitor
{
public:

	monitor(local_ref& ptr)
	{
		if (detail::env()->MonitorEnter(ptr.get()) == 0)
			object = ptr.get();
		else
			object = 0;
	}

	monitor(global_ref& ptr)
	{
		if (detail::env()->MonitorEnter(ptr.get()) == 0)
			object = ptr.get();
		else
			object = 0;
	}

	~monitor()
	{
		if (object)
			detail::env()->MonitorExit(object);
	}

	void reset()
	{
		monitor().swap(*this);
	}

	monitor(const monitor&) = delete;
	monitor& operator = (const monitor&) = delete;

	monitor(monitor&& source) :
		object(source.object)
	{
		source.object = 0;
	}

	monitor& operator = (monitor&& source)
	{
		monitor(std::move(source)).swap(*this);
		return *this;
	}

	void swap(monitor& source)
	{
		using std::swap;
		swap(object, source.object);
	}

private:

	monitor() : object(0) {}

	jobject object;

};

inline void swap(monitor& a, monitor& b)
{
	a.swap(b);
}

} // namespace java
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_JAVA_MONITOR_H

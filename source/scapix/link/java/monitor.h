/*
	scapix/link/java/monitor.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_JAVA_MONITOR_H
#define SCAPIX_LINK_JAVA_MONITOR_H

#include <utility>
#include <cassert>
#include <scapix/link/java/ref.h>

namespace scapix::link::java {

template <typename T>
class monitor
{
public:

	// Generally, caller is responsible to insure the reference (not only the object) is alive while monitor is active.
	// But if an owning reference is moved here, monitor will take ownership.

	monitor(ref<T> obj)
		: object(std::move(obj))
	{
		[[maybe_unused]] auto result = detail::env()->MonitorEnter(object.handle());
		assert(result == 0);
	}

	monitor(const monitor&) = delete;
	monitor& operator = (const monitor&) = delete;

	monitor(monitor&& source) :
		object(source.release())
	{
	}

	monitor& operator = (monitor&& source)
	{
		monitor(std::move(source)).swap(*this);
		return *this;
	}

	~monitor()
	{
		if (object)
		{
			[[maybe_unused]] auto result = detail::env()->MonitorExit(object.handle());
			assert(result == 0);
		}
	}

	explicit operator bool() const { return bool(object); }
	ref<T> get() const { return object; }

	void reset()
	{
		monitor().swap(*this);
	}

	void swap(monitor& source)
	{
		using std::swap;
		swap(object, source.object);
	}

private:

	monitor() {}
	ref<T> release() { return std::move(object); }

	ref<T> object;

};

template <typename T>
inline void swap(monitor<T>& a, monitor<T>& b)
{
	a.swap(b);
}

} // namespace scapix::link::java

#endif // SCAPIX_LINK_JAVA_MONITOR_H

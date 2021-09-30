// this file should be compiled with: -fno-objc-arc

#include <scapix/bridge/objc/object.h>
#import "BridgeObjectPrivate.h"

@implementation BridgeObject

-(void)attachObject:(std::shared_ptr<scapix::bridge::objc::object_base>)ptr
{
	weak = ptr;
	shared = ptr;
}

-(BOOL)retainWeakReference
{
	// from NSObject.mm:
	// _objc_rootTryRetain() is called exclusively by _objc_loadWeak(),
	// which already acquired the lock on our behalf.

	std::lock_guard<std::recursive_mutex> lock(mutex);

	if (!shared)
	{
		shared = weak.lock();

		if (!shared)
			return NO;
	}

	// We know this will always return YES since at this point
	// we are holding strong reference to scapix::bridge::objc::object_base,
	// which is holding strong reference to us.

	return [super retainWeakReference];
}

-(instancetype)retain
{
	{
		std::lock_guard<std::recursive_mutex> lock(mutex);

		if (!shared)
			// This can only happen from object<T>::get_wrapper()
			// and we know weak.lock() will succeed.
			shared = weak.lock();
	}

	return [super retain];
}

-(oneway void)release
{
	// Since retainWeakReference already holds some lock that [super release] will try to acquire,
	// we cannot call [super release] while holding our mutex.

	{
		std::unique_lock<std::recursive_mutex> lock(mutex);

		if ([super retainCount] == 2)
		{
			if (!shared)
			{
				// We have entered release recursively.
				// Can't call [super release] here because frame above also holds the mutex.
				// Set the flag for frame above to call [super release] twice.

				second_release_call = true;
				return;
			}

			// This may lead to recursive release.

			shared.reset();

			if (second_release_call)
			{
				lock.unlock();
				[super release];
			}
		}
	}

	[super release];
}

@end

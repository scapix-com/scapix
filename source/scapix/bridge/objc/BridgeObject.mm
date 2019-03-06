// this file should be compiled with: -fno-objc-arc

#ifdef __OBJC__

#include <scapix/bridge/objc/object.h>

@implementation BridgeObject

-(void)attachObject:(scapix::bridge::objc::object_base*)ptr
{
    weak = ptr->weak_from_this();
    shared = ptr->shared_from_this();
}

- (BOOL)retainWeakReference
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

#endif // __OBJC__

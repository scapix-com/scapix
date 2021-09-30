#import "BridgeObject.h"

#include <memory>
#include <mutex>

namespace scapix {
namespace bridge {
namespace objc {

class object_base;

} // namespace objc
} // namespace bridge
} // namespace scapix


@interface BridgeObject ()
{
	std::recursive_mutex mutex;

	// to do: only need one at a time, worth storing in boost::variant?

	bool second_release_call;
	std::weak_ptr<scapix::bridge::objc::object_base> weak;
	@public
	std::shared_ptr<scapix::bridge::objc::object_base> shared;
}

-(void)attachObject:(std::shared_ptr<scapix::bridge::objc::object_base>)ptr;

@end

/*
	scapix/link/cs/ref_type.h

	Copyright (c) 2020 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_REF_TYPE_H
#define SCAPIX_LINK_CS_REF_TYPE_H

namespace scapix {
namespace link {
namespace cs {

enum class ref_type
{
	weak,
	weak_track_resurrection,
	normal,
	pinned,
};

} // namespace cs
} // namespace link
} // namespace scapix

#endif // SCAPIX_LINK_CS_REF_TYPE_H

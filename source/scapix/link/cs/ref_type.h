/*
	scapix/link/cs/ref_type.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_LINK_CS_REF_TYPE_H
#define SCAPIX_LINK_CS_REF_TYPE_H

namespace scapix::link::cs {

enum class ref_type
{
	weak,
	weak_track_resurrection,
	normal,
	pinned,
};

} // namespace scapix::link::cs

#endif // SCAPIX_LINK_CS_REF_TYPE_H

/*
	scapix/config.h

	Copyright (c) 2019 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_CONFIG_H
#define SCAPIX_CONFIG_H

#define SCAPIX_INCLUDE(a,b,c) <a/b/c>

#define SCAPIX_PLATFORM_INCLUDE(file) SCAPIX_INCLUDE(scapix/platform, SCAPIX_PLATFORM, file)
#define SCAPIX_BRIDGE_INCLUDE(file) SCAPIX_INCLUDE(scapix/bridge, SCAPIX_BRIDGE, file)

#ifndef SCAPIX_PLATFORM
#define SCAPIX_PLATFORM generic
#endif

// SCAPIX_BRIDGE: cpp, java, objc, python

#ifndef SCAPIX_BRIDGE
#define SCAPIX_BRIDGE cpp
#endif

#endif // SCAPIX_CONFIG_H

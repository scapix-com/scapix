/*
	scapix/bridge/java/on_load.h

	Copyright (c) 2019-2023 Boris Rasin (boris@scapix.com)
*/

#ifndef SCAPIX_BRIDGE_JAVA_ON_LOAD_H
#define SCAPIX_BRIDGE_JAVA_ON_LOAD_H

#include <jni.h>

/*

By default Scapix generates JNI_OnLoad() function for target library.
You can also use your own JNI_OnLoad(), which then needs to call scapix_JNI_OnLoad().

```CMake
target_compile_definitions(scapix PUBLIC SCAPIX_CUSTOM_JNI_ONLOAD)
```

```C
#include <scapix/bridge/java/on_load.h>

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	// ... your additional JNI init code ...

	return scapix_JNI_OnLoad(vm, reserved);
}
```

*/

#ifdef __cplusplus
extern "C"
#endif
jint scapix_JNI_OnLoad(JavaVM* vm, void* reserved);

#endif // SCAPIX_BRIDGE_JAVA_ON_LOAD_H

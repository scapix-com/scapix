# Scapix Language Bridge

[![Tweet](https://img.shields.io/twitter/url/http/shields.io.svg?style=social)](https://twitter.com/intent/tweet?text=Automatic%20bindings%20from%20C%2B%2B%20to%20Java%2C%20Objective-C%2C%20Swift%2C%20Python%2C%20JavaScript%20%28WebAssembly%29%20and%20C%23&url=https://github.com/scapix-com/scapix)

Automatic, on the fly bindings from C++ to `Java`, `Objective-C`, `Swift`, `Python`, `JavaScript` (WebAssembly) and `C#`.
Bridge code automatically generated directly from C++ header files, no need to manually maintain IDL definitions or bindings.

![Scapix Bridge Intro](https://www.scapix.com/img/scapix_intro.png)

## Integrating in CMake project

```cmake
include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.22.tar.gz"
  URL_HASH SHA256=f331d227ae1be52677833baf4fd4728a7c6ee66ec570db6e60d22db0ae43854f
)
FetchContent_MakeAvailable(cmodule)

find_package(Scapix REQUIRED)

scapix_bridge_headers(
    chatlib
    "com.example.chat"
    "source/chat/contact.h"
    "source/chat/session.h"
    "source/chat/model.h"
)
```

[Documentation](https://www.scapix.com/)\
[Minimal Example](https://github.com/scapix-com/tiny_bridge)\
[Extended Example](https://github.com/scapix-com/example1)

## Java Link

Modern C++17 wrapper for JNI:
- type-safe APIs
- automatic resource management
- ZERO runtime overhead compared to manually written JNI code
- automatic C++/Java type conversion for many standard types (std::string, std::vector, etc.)
- automatic C++/Java exception tunneling
- comes with pre-generated C++ headers for all JDK and Android Java APIs
- automatically generate C++ headers for any Java code, including your own

```cpp
#include <scapix/java_api/java/lang/System.h>
#include <scapix/java_api/java/util/Locale.h>
#include <scapix/java_api/java/text/DateFormatSymbols.h>

using namespace scapix::link::java;
using namespace scapix::java_api;

void test()
{
    // C++ objects are automatically converted to and from corresponding Java types.
    // This works for any type supported by scapix::link::java::convert<> interface,
    // which supports many STL types and can be extended for your own types.

    std::string version = java::lang::System::getProperty("java.version");
    std::vector<std::string> languages = java::util::Locale::getISOLanguages();
    std::vector<std::vector<std::string>> zone_strings = java::text::DateFormatSymbols::getInstance()->getZoneStrings();
    std::map<std::string, std::string> properties = java::lang::System::getProperties();
}
```

[Java Link Documentation](https://www.scapix.com/documentation/java_link)\
[Java Link Example](https://github.com/scapix-com/example2)

## License

Please carefully read [license agreement](LICENSE.txt).

**In short:**
If you comply with [license agreement](LICENSE.txt), you may use [Scapix Language Bridge](https://www.scapix.com) free of charge to build commercial and/or open source applications.
You may NOT modify and/or redistribute the [Scapix Language Bridge](https://www.scapix.com) product itself.

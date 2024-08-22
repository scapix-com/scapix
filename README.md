# Scapix Language Bridge

🇺🇦 If you like this project, please consider donating to one of the funds helping victims of russian aggression against Ukraine: [ukraine.ua](https://war.ukraine.ua/donate/)

Automatic, on the fly bindings from C++ to `Java`, `Objective-C`, `Swift`, `Python`, `JavaScript` (WebAssembly) and `C#`.
Bridge code automatically generated directly from C++ header files, no need to manually maintain IDL definitions or bindings.

![Scapix Bridge Intro](https://www.scapix.com/img/scapix_intro.png)

## Integrating in CMake project

```cmake
include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v2.0.1.tar.gz"
  URL_HASH SHA256=a9477bbefb43b6fabdc2dc044207fe42cca63999c60b6baf06ba0c62fa116ec5
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

[Documentation](https://www.scapix.com/)

Examples:

- [tiny_bridge](https://github.com/scapix-com/tiny_bridge) - minimal example
- [scapix_example_objc](https://github.com/scapix-com/scapix_example_objc) - minimal example, ObjC/Swift, XCode integration
- [example1](https://github.com/scapix-com/example1) - extended example, all languages

## License

Please carefully read [license agreement](LICENSE.txt).

**In short:**
If you comply with [license agreement](LICENSE.txt), you may use [Scapix Language Bridge](https://www.scapix.com) free of charge to build commercial and/or open source applications.
You may NOT modify and/or redistribute the [Scapix Language Bridge](https://www.scapix.com) product itself.

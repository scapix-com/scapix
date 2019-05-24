# Scapix Language Bridge

Automatic, on the fly code generation to bridge C++ code to Java, Objective-C, Swift and Python (with more languages coming soon).
Bridge code automatically generated directly from C++ header files, no need to manually maintain IDL definitions or bindings.

### 1. Derive your C++ class from scapix::bridge::object

```cpp
#include <scapix/bridge/object.h>

class contact : public scapix::bridge::object<contact>
{
};
```

### 2. Add or change any public function

```cpp
#include <scapix/bridge/object.h>

class contact : public scapix::bridge::object<contact>
{
public:
    std::string name();
    void send_message(const std::string& msg, std::shared_ptr<contact> from);
    void add_tags(const std::vector<std::string>& tags);
    void add_friends(std::vector<std::shared_ptr<contact>> friends);
};
```

### 3. Press 'Build' in whatever IDE you are using

Every time you press 'Build' Scapix instantly generates bridge code for all changed classes derived from scapix::bridge::object.

### 4. Call new functions from UI code

Java

```java
class View {
    private contact = new Contact;

    public void send(Contact friend) {
        contact.sendMessage("Hello", friend);
        contact.addTags({"a","b","c"});
        contact.addFriends({friend});
    }
}
```

Objective C

```objc
@implementation ViewController

-(void) send:(Contact*)friend {
    Contact* c = [Contact new];

    [c sendMessage:@"hello", friend];
    [s addTags:@["a","b","c"]];
    [s addFriends:@[friend]];
}

@end
```

Swift

```swift
class ViewController: UIViewController {
    func send(friend: Contact) {
        let c = Contact()

        contact.sendMessage("Hello", friend)
        contact.addTags(["a","b","c"])
        contact.addFriends([friend])
    }
}
```

### 5. Callbacks supported too

```cpp
#include <scapix/bridge/object.h>

class contact : public scapix::bridge::object<contact>
{
public:
    void notify(std::function<bool(std::shared_ptr<contact>)>);
};
```

Java

```java
class View
{
    public void send(Contact friend) {
        friend.notify((Contact c) -> {
            //...
            return true;
        });
    }
}
```

Objective C

```objc
@implementation ViewController

-(void) send:(Contact*)friend {
    [friend notify:^ (Contact* c) {
        //...
        return TRUE;
    }];
}

@end
```

Swift

```swift
class ViewController: UIViewController {
    func send(friend: Contact) {
        friend.notify() {
            (c: Contact) in
            //...
            return true
        }
    }
}
```

Automatically bridged types

```cpp
classes derived from scapix::bridge::object
bool
std::int8_t  (char)
std::int16_t (short)
std::int32_t (int)
std::int64_t (long long)
float
double
std::string (UTF-8 encoding)
std::vector<value>
std::map<key,value>
std::set<key>
std::unordered_map<key,value>
std::unordered_set<key>
std::function<type>
std::shared_ptr<type>
```

Arbitrary nesting is supported.
Classes derived from [`scapix::bridge::object`](https://www.scapix.com/documentation/bridge_object) are bridged by reference and can only be passed as `std::shared_ptr<type>`.
All other types are bridged by copy.

Example:

```cpp
#include <scapix/bridge/object.h>

class test : public scapix::bridge::object<test>
{
public:

    // these functions are bridged: all parameter and return value types are supported

    void func1(const std::vector<std::shared_ptr<test>>&);
    void func2(std::function<void(std::vector<std::shared_ptr<test>)>);
    std::map<std::string, std::shared_ptr<test>> func3();

    // these functions are not bridged: not all parameter and return value types are supported

    void func10(void*);

};
```

## Documentation

[Scapix Language Bridge](https://www.scapix.com)

## Example

[example1](https://github.com/scapix-com/example1)

## Development platform

Develop on any platform (MacOS, Windows, Linux), using any IDE with CMake support.

## Installation

Add Scapix as git submodule to your project:

```bash
$ git submodule add https://github.com/scapix-com/scapix
```

Or clone anywhere on your computer:

```bash
$ git clone https://github.com/scapix-com/scapix
```

Add to your project CMakeLists.txt file:

```cmake
set(SCAPIX_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/scapix) // path to Scapix folder
include(${SCAPIX_ROOT}/project/cmake/modules/scapix.cmake)

// must come after all calls to target_include_directories() and target_link_libraries() for the target
scapix_bridge_headers(
    target
    "com.YourCompanyName.YourProjectName"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/header1.h" // list all headers with scapix::bridge::object classes
    "${CMAKE_CURRENT_SOURCE_DIR}/source/header2.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/header3.h"
)
```

When running CMake, specify scapix_bridge (cpp, java, objc, python):

```bash
$ cmake -Dscapix_bridge=python
```

This will build shared library with all your C++ classes derived from **scapix::bridge::object** exposed to python.

## [`scapix::link::java`](https://www.scapix.com/documentation/java_link)

[`scapix::link::java`](https://www.scapix.com/documentation/java_link) library provides C++ interface to JNI (Java Native Interface) API.
It may be used on it's own in any application, or it may be used in a platform dependent part of an application utilizing [Scapix Language Bridge](https://www.scapix.com).

Example using generic API (without generated headers):

```cpp
#include <scapix/link/java/object.h>

using namespace scapix::link::java;

void test_string()
{
    auto str = object<SCAPIX_META_STRING("java/lang/String")>::new_object();
    auto length = str->call_method<SCAPIX_META_STRING("length"), jint()>();
}
```

Same code using headers generated by [scapix_java](https://www.scapix.com/documentation/java_link/java_api) utility:

```cpp
#include <scapix/java_api/java/lang/String.h>

using namespace scapix::java_api;

void test_string()
{
    auto str = java::lang::String::new_object();
    auto length = str->length();
}
```

In both cases, [`scapix::link::java`](https://www.scapix.com/documentation/java_link) library automatically takes care of all JNI resource management and JVM exceptions processing.
See full [example](https://github.com/scapix-com/example2).

## License

Please carefully read [license agreement](LICENSE.txt).

**In short:**
If you comply with [license agreement](LICENSE.txt), you may use [Scapix Language Bridge](https://www.scapix.com) free of charge to build commercial and/or open source applications.
You may NOT modify and/or redistribute the [Scapix Language Bridge](https://www.scapix.com) product itself.

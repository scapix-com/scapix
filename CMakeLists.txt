cmake_minimum_required(VERSION 3.14)

project(scapix CXX)

find_package(ScapixBin REQUIRED)

set(SCAPIX_BRIDGE "cpp" CACHE STRING "cpp, java, objc, python, js, cs")
set(SCAPIX_PLATFORM "generic" CACHE STRING "subfolder of 'platform' folder: generic, ios, android, macos, windows, linux, etc.")
set(SCAPIX_JAVA_API "jdk-11.0.2" CACHE STRING "subfolder of 'scapix/java_api' folder: jdk-11.0.2, android-28, etc.")

set(SCAPIX_ROOT ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${SCAPIX_ROOT}/source/*)
source_group(TREE ${SCAPIX_ROOT}/source PREFIX "source" FILES ${sources})

if(${SCAPIX_BRIDGE} STREQUAL java)
    file(GLOB_RECURSE java_api_sources CONFIGURE_DEPENDS ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API}/scapix/java_api/*)
    source_group(TREE ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API}/scapix/java_api PREFIX "java_api" FILES ${java_api_sources})
endif()

add_library(scapix INTERFACE ${sources} ${java_api_sources})

if(${SCAPIX_BRIDGE} STREQUAL java)
    file(GLOB_RECURSE interface_sources CONFIGURE_DEPENDS ${SCAPIX_ROOT}/source/*/*.java)
elseif(${SCAPIX_BRIDGE} STREQUAL cs)
    file(GLOB_RECURSE interface_sources CONFIGURE_DEPENDS ${SCAPIX_ROOT}/source/*/*.cs)
endif()

target_sources(scapix INTERFACE ${interface_sources})

set(bridges
    "cpp"
    "java"
    "objc"
    "python"
    "js"
    "cs"
#   "swift"
)

foreach(bridge ${bridges})
    if(NOT ${SCAPIX_BRIDGE} STREQUAL ${bridge})
        file(GLOB_RECURSE bridge_sources CONFIGURE_DEPENDS
            ${SCAPIX_ROOT}/source/scapix/link/${bridge}/*.*
            ${SCAPIX_ROOT}/source/scapix/bridge/${bridge}/*.*
        )
        set_source_files_properties(${bridge_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
    endif()
endforeach()

if(${SCAPIX_BRIDGE} STREQUAL objc)
    target_compile_options(scapix INTERFACE "-fobjc-arc")
    set_source_files_properties(${SCAPIX_ROOT}/source/scapix/bridge/objc/BridgeObject.mm PROPERTIES COMPILE_OPTIONS "-fno-objc-arc")
endif()

if(MSVC)
    target_compile_options(scapix INTERFACE /permissive-)
endif()

target_compile_features(scapix INTERFACE cxx_std_17)

target_include_directories(scapix INTERFACE ${SCAPIX_ROOT}/source)
target_include_directories(scapix INTERFACE ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API})
target_compile_definitions(scapix INTERFACE SCAPIX_BRIDGE=${SCAPIX_BRIDGE} SCAPIX_BRIDGE_${SCAPIX_BRIDGE} SCAPIX_PLATFORM=${SCAPIX_PLATFORM})

if(${SCAPIX_BRIDGE} STREQUAL java)
    find_package(Boost REQUIRED)
    target_link_libraries(scapix INTERFACE Boost::headers)
endif()

if(${SCAPIX_BRIDGE} STREQUAL java AND NOT ANDROID)
    # Save CMAKE_FIND_FRAMEWORK
    if(DEFINED CMAKE_FIND_FRAMEWORK)
        set(SCAPIX_CMAKE_FIND_FRAMEWORK ${CMAKE_FIND_FRAMEWORK})
    else()
        unset(SCAPIX_CMAKE_FIND_FRAMEWORK)
    endif()

    set(CMAKE_FIND_FRAMEWORK LAST)
    find_package(JNI REQUIRED)

    # Restore CMAKE_FIND_FRAMEWORK
    if(DEFINED SCAPIX_CMAKE_FIND_FRAMEWORK)
        set(CMAKE_FIND_FRAMEWORK ${SCAPIX_CMAKE_FIND_FRAMEWORK})
        unset(SCAPIX_CMAKE_FIND_FRAMEWORK)
    else()
        unset(CMAKE_FIND_FRAMEWORK)
    endif()

    target_include_directories(scapix INTERFACE ${JNI_INCLUDE_DIRS})
    target_link_libraries(scapix INTERFACE ${JNI_LIBRARIES})
endif()

function(camel_case source target)
    set(up true)
    set(res "")

    string(LENGTH ${source} source_length)
    math(EXPR last_char_index "${source_length} - 1")

    foreach(char_index RANGE ${last_char_index})
        string(SUBSTRING "${source}" "${char_index}" "1" char)
        if(char STREQUAL "_")
            set(up true)
        else()
            if(up)
                string(TOUPPER ${char} char)
                set(up false)
            endif()
            string(APPEND res ${char})
        endif()
    endforeach()
    set(${target} ${res} PARENT_SCOPE)
endfunction(camel_case)

function(scapix_bridge_headers target domain)
    scapix_bridge(TARGET ${target} DOMAIN ${domain} HEADERS ${ARGN})
endfunction()

function(scapix_bridge)
cmake_parse_arguments(SCAPIX "" "TARGET;DOMAIN" "HEADERS;IMPORT_TARGETS" ${ARGN})
set(target ${SCAPIX_TARGET})
set(domain ${SCAPIX_DOMAIN})
set(bridge_headers ${SCAPIX_HEADERS})

string(REPLACE "." "/" domain_path ${domain})

foreach(import_target ${SCAPIX_IMPORT_TARGETS})
    get_property(headers TARGET ${import_target} PROPERTY SCAPIX_BRIDGE_HEADERS)
    list(APPEND bridge_headers ${headers})
endforeach()
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

# to do: remove duplication
set(bridges
    "cpp"
    "java"
    "objc"
    "python"
    "js"
    "cs"
#   "swift"
)

set_target_properties(${target} PROPERTIES SCAPIX_BRIDGE_HEADERS "${bridge_headers}")

# extract scapix_project_name from domain

string(FIND ${domain} "." scapix_domain_pos REVERSE)
math(EXPR scapix_domain_pos "${scapix_domain_pos}+1")
string(SUBSTRING ${domain} ${scapix_domain_pos} -1 scapix_project_name)

get_target_property(scapix_output_name ${target} OUTPUT_NAME)
if(NOT scapix_output_name)
  set(scapix_output_name ${target})
endif()

if(XCODE)
    # to do: could also generate objc-swift bridge header.
    file(WRITE "${CMAKE_BINARY_DIR}/scapix_${target}.xcconfig"
        "// Generated by Scapix Language Bridge\n"
        "\n"
        "HEADER_SEARCH_PATHS = $(inherited) \"${PROJECT_ROOT}/generated/bridge/objc\" \"${SCAPIX_ROOT}/source\"\n"
        "OTHER_LDFLAGS = $(inherited) -l${scapix_output_name} -lscapix -lc++\n")
endif()

if(${SCAPIX_BRIDGE} STREQUAL java)
    file(COPY "${SCAPIX_ROOT}/source/com" DESTINATION "${PROJECT_ROOT}/generated/bridge/java")
endif()

get_target_property(scapix_position_independent_code ${target} POSITION_INDEPENDENT_CODE)
set_target_properties(scapix PROPERTIES POSITION_INDEPENDENT_CODE ${scapix_position_independent_code})

if(${SCAPIX_BRIDGE} STREQUAL python)
    set(PYBIND11_FINDPYTHON ON)
    find_package(Pybind11 REQUIRED)
    target_link_libraries(${target} PRIVATE pybind11::module)
    set_target_properties(${target} PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}" SUFFIX "${PYTHON_MODULE_EXTENSION}")
endif()

target_link_libraries(${target} PUBLIC scapix)

# JVM on macOS looks for native libs with .dylib extension
if(APPLE AND ${SCAPIX_BRIDGE} STREQUAL java)
    set_target_properties(${target} PROPERTIES SUFFIX ".dylib")
endif()

# generated_java_cpp

set(generated_java_cpp
    "${PROJECT_ROOT}/generated/bridge/java/${scapix_project_name}.cpp"
)

file(REMOVE "${generated_java_cpp}")
file(APPEND "${generated_java_cpp}"
"// Generated by Scapix Language Bridge

#include <scapix/bridge/java/object.h>

")

foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_java_cpp}" "void scapix_java_export_${name}();\n")
endforeach(filename)

file(APPEND "${generated_java_cpp}" "
jint scapix_JNI_OnLoad(JavaVM* vm, void* reserved)
{
\treturn scapix::bridge::java::on_load(vm, reserved, []
\t{
")
foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_java_cpp}" "\t\tscapix_java_export_${name}();\n")
endforeach(filename)
file(APPEND "${generated_java_cpp}"
"\t});
}

#ifndef SCAPIX_CUSTOM_JNI_ONLOAD

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
\treturn scapix_JNI_OnLoad(vm, reserved);
}

#endif
")

set(generated_sources_java_private ${generated_java_cpp})

# generated_java_java

set(generated_java_java
    "${PROJECT_ROOT}/generated/bridge/java/${domain_path}/ScapixConfig.java"
)

file(REMOVE "${generated_java_java}")
file(APPEND "${generated_java_java}"
"// Generated by Scapix Language Bridge

package ${domain};

public class ScapixConfig
{
	public static void Init() {}
	static { System.loadLibrary(\"${scapix_output_name}\"); }
}
")

set(generated_sources_java_interface ${generated_java_java})

# generated_python_cpp

set(generated_python_cpp
    "${PROJECT_ROOT}/generated/bridge/python/${scapix_project_name}.cpp"
)

file(REMOVE "${generated_python_cpp}")
file(APPEND "${generated_python_cpp}"
"// Generated by Scapix Language Bridge

")

file(APPEND "${generated_python_cpp}" "#include <pybind11/pybind11.h>\n\n")

foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_python_cpp}" "void scapix_python_export_${name}(pybind11::module& m);\n")
endforeach(filename)
file(APPEND "${generated_python_cpp}" "
PYBIND11_MODULE(${scapix_output_name}, m)
{
    m.doc() = \"${domain}\";
")
foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_python_cpp}" "    scapix_python_export_${name}(m);\n")
endforeach(filename)
file(APPEND "${generated_python_cpp}" "}\n")

set(generated_sources_python_private ${generated_python_cpp})

# generated_cs_cpp

set(generated_cs_cpp
    "${PROJECT_ROOT}/generated/bridge/cs/${scapix_project_name}.cpp"
)

file(REMOVE "${generated_cs_cpp}")
file(APPEND "${generated_cs_cpp}"
"// Generated by Scapix Language Bridge

#include <scapix/bridge/cs/init.h>

")
foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_cs_cpp}" "void scapix_cs_export_${name}();\n")
endforeach(filename)
file(APPEND "${generated_cs_cpp}" "
extern \"C\" SCAPIX_EXPORT
const scapix::link::cs::api::cpp_api* SCAPIX_CALL ScapixInit(const scapix::link::cs::api::cs_api* funcs)
{
    auto ret = scapix::link::cs::api::init(funcs);

")
foreach(filename ${bridge_headers})
    get_filename_component(name ${filename} NAME_WLE)
    file(APPEND "${generated_cs_cpp}" "    scapix_cs_export_${name}();\n")
endforeach(filename)
file(APPEND "${generated_cs_cpp}"
"
    return ret;
}
")

set(generated_sources_cs_private ${generated_cs_cpp})

# generated_cs_cs

camel_case(${scapix_project_name} scapix_project_name_camel)

set(generated_cs_cs
    "${PROJECT_ROOT}/generated/bridge/cs/${scapix_project_name_camel}.cs"
)

file(REMOVE "${generated_cs_cs}")
file(APPEND "${generated_cs_cs}"
"// Generated by Scapix Language Bridge

namespace ${scapix_project_name_camel} {

    public static class ScapixConfig
    {
        [System.Runtime.InteropServices.DllImport(\"${scapix_output_name}\")]
        static extern System.IntPtr ScapixInit(Scapix.Link.API.CsApi funcTable);
")

foreach(import_target ${SCAPIX_IMPORT_TARGETS})
    get_target_property(import_target_output_name ${import_target} OUTPUT_NAME)
    if(NOT import_target_output_name)
      set(import_target_output_name ${import_target})
    endif()
    camel_case(${import_target_output_name} import_target_output_name_camel)
    file(APPEND "${generated_cs_cs}"
"
        [System.Runtime.InteropServices.DllImport(\"${import_target_output_name}\", EntryPoint = \"ScapixInit\")]
        static extern System.IntPtr ${import_target_output_name_camel}Init(Scapix.Link.API.CsApi funcTable);
")
endforeach()

file(APPEND "${generated_cs_cs}"
"
        static ScapixConfig() { Scapix.Link.API.Init(ScapixInit); ")

foreach(import_target ${SCAPIX_IMPORT_TARGETS})
    get_target_property(import_target_output_name ${import_target} OUTPUT_NAME)
    if(NOT import_target_output_name)
      set(import_target_output_name ${import_target})
    endif()
    camel_case(${import_target_output_name} import_target_output_name_camel)
    file(APPEND "${generated_cs_cs}"
"Scapix.Link.API.Init(${import_target_output_name_camel}Init); ")
endforeach()

file(APPEND "${generated_cs_cs}"
 "}
        public static void Init() {}
    }

} // namespace ${scapix_project_name_camel}
")

set(generated_sources_cs_interface ${generated_cs_cs})

set(generated_sources_private)
set(generated_sources_interface)

foreach(bridge ${bridges})
    list(APPEND generated_sources_private ${generated_sources_${bridge}_private})
    list(APPEND generated_sources_interface ${generated_sources_${bridge}_interface})
    set(generated_sources_${bridge} ${generated_sources_${bridge}_private} ${generated_sources_${bridge}_interface})
endforeach()

set(generated_sources
    ${generated_sources_private}
    ${generated_sources_interface}
)

set_source_files_properties(${generated_sources} PROPERTIES GENERATED TRUE)

#set_source_files_properties(${generated_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
#set_source_files_properties(${generated_sources_${SCAPIX_BRIDGE}} PROPERTIES HEADER_FILE_ONLY FALSE)
#target_sources(${target} PRIVATE ${generated_sources_private})
#target_sources(${target} INTERFACE ${generated_sources_interface})

target_sources(${target} PRIVATE ${generated_sources_${SCAPIX_BRIDGE}_private})
target_sources(${target} INTERFACE ${generated_sources_${SCAPIX_BRIDGE}_interface})
source_group(TREE ${PROJECT_ROOT}/generated PREFIX "generated" FILES ${generated_sources})

set(all_generated_sources)

foreach(bridge_header ${bridge_headers})

    get_filename_component(bridge_header_name ${bridge_header} NAME_WLE)
    if(IS_ABSOLUTE bridge_header)
        file(RELATIVE_PATH bridge_header_relative ${PROJECT_ROOT} ${bridge_header})
        set(bridge_header_absolute ${bridge_header})
    else()
        set(bridge_header_relative ${bridge_header})
        get_filename_component(bridge_header_absolute ${bridge_header} ABSOLUTE BASE_DIR ${PROJECT_ROOT})
    endif()
    camel_case(${bridge_header_name} bridge_header_name_camel)

    set(generated_sources_java_private
        "${PROJECT_ROOT}/generated/bridge/java/${bridge_header_name}.cpp"
    )

    set(generated_sources_java_interface
        "${PROJECT_ROOT}/generated/bridge/java/${domain_path}/${bridge_header_name_camel}.java"
    )

    set(generated_sources_objc_private
        "${PROJECT_ROOT}/generated/bridge/objc/${scapix_project_name}/bridge/${bridge_header_name_camel}.h"
        "${PROJECT_ROOT}/generated/bridge/objc/${scapix_project_name}/bridge/${bridge_header_name_camel}.mm"
    )

    set_source_files_properties("${PROJECT_ROOT}/generated/bridge/objc/${scapix_project_name}/bridge/${bridge_header_name_camel}.mm" PROPERTIES COMPILE_OPTIONS "-Wno-objc-designated-initializers")

    set(generated_sources_python_private
        "${PROJECT_ROOT}/generated/bridge/python/${bridge_header_name}.cpp"
    )

    set(generated_sources_js_private
        "${PROJECT_ROOT}/generated/bridge/js/${bridge_header_name}.cpp"
    )

    set(generated_sources_cs_private
        "${PROJECT_ROOT}/generated/bridge/cs/${bridge_header_name}.cpp"
    )

    set(generated_sources_cs_interface
        "${PROJECT_ROOT}/generated/bridge/cs/${bridge_header_name_camel}.cs"
    )

    set(generated_sources_private)
    set(generated_sources_interface)

    foreach(bridge ${bridges})
        list(APPEND generated_sources_private ${generated_sources_${bridge}_private})
        list(APPEND generated_sources_interface ${generated_sources_${bridge}_interface})
        set(generated_sources_${bridge} ${generated_sources_${bridge}_private} ${generated_sources_${bridge}_interface})
    endforeach()

    set(generated_sources
        ${generated_sources_private}
        ${generated_sources_interface}
    )

    # GENERATED property implicitly set for OUTPUT arguments of add_custom_command()
    #set_source_files_properties(${generated_sources} PROPERTIES GENERATED TRUE)

    #set_source_files_properties(${generated_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
    #set_source_files_properties(${generated_sources_${SCAPIX_BRIDGE}} PROPERTIES HEADER_FILE_ONLY FALSE)
    #target_sources(${target} PRIVATE ${generated_sources_private})
    #target_sources(${target} INTERFACE ${generated_sources_interface})

    target_sources(${target} PRIVATE ${generated_sources_${SCAPIX_BRIDGE}_private})
    target_sources(${target} INTERFACE ${generated_sources_${SCAPIX_BRIDGE}_interface})
    source_group(TREE ${PROJECT_ROOT}/generated PREFIX "generated" FILES ${generated_sources})

    set(scapix_clang_config)

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(scapix_clang_config ${scapix_clang_config} -nobuiltininc)
    endif()

    if(ANDROID)
        set(scapix_clang_config ${scapix_clang_config} -DANDROID -target ${ANDROID_LLVM_TRIPLE})
    elseif(APPLE)
        if(NOT CMAKE_SYSTEM_NAME STREQUAL "Darwin")
            set(scapix_clang_config ${scapix_clang_config} -arch arm64)
        endif()
    elseif(EMSCRIPTEN)
        set(scapix_clang_config ${scapix_clang_config} -target wasm32-unknown-emscripten --sysroot $ENV{EMSDK}/upstream/emscripten/cache/sysroot -iwithsysroot /include/compat)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND CMAKE_CXX_COMPILER_TARGET)
        set(scapix_clang_config ${scapix_clang_config} -target ${CMAKE_CXX_COMPILER_TARGET})
    endif()

    set(scapix_clang_env)

    if(APPLE AND NOT XCODE)
        set(scapix_clang_env ${scapix_clang_env} SDKROOT=${CMAKE_OSX_SYSROOT})
    endif()

    add_custom_command(
            OUTPUT ${generated_sources}
            COMMAND ${CMAKE_COMMAND} -E env "${scapix_clang_env}" "${SCAPIX_EXE_DIR}/${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}/scapix" -scapix-domain=${domain} ${bridge_header} -- -xc++ -std=$<IF:$<IN_LIST:cxx_std_23,$<TARGET_PROPERTY:${target},COMPILE_FEATURES>>,c++2b,$<IF:$<IN_LIST:cxx_std_20,$<TARGET_PROPERTY:${target},COMPILE_FEATURES>>,c++20,c++17>> ${scapix_clang_config} "$<$<BOOL:${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}>:-I$<JOIN:${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES},;-I>>" "$<$<BOOL:$<TARGET_PROPERTY:${target},INCLUDE_DIRECTORIES>>:-I$<JOIN:$<TARGET_PROPERTY:${target},INCLUDE_DIRECTORIES>,;-I>>" "$<$<BOOL:$<TARGET_PROPERTY:${target},COMPILE_DEFINITIONS>>:-D$<JOIN:$<TARGET_PROPERTY:${target},COMPILE_DEFINITIONS>,;-D>>"
            DEPENDS "${bridge_header_absolute}" # "${SCAPIX_EXE}"
            IMPLICIT_DEPENDS CXX "${bridge_header_absolute}"
            WORKING_DIRECTORY "${PROJECT_ROOT}"
            COMMENT "Running Scapix Bridge for ${bridge_header_relative}"
            COMMAND_EXPAND_LISTS
            VERBATIM
    )

    # GENERATED property implicitly set for OUTPUT arguments of add_custom_command(), so we generally wouldn't need this.
    # In CMake 3.18 we can make GENERATED property visible also in target directory.
    # cmake_minimum_required(VERSION 3.20) makes GENERATED property visible in all directories.
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.18)
        set_source_files_properties(${generated_sources} TARGET_DIRECTORY ${target} PROPERTIES GENERATED TRUE)
    endif()

    set(all_generated_sources ${all_generated_sources} ${generated_sources})

endforeach(bridge_header)

# when add_library() and scapix_bridge_headers() are in different directories:
# add_custom_command: A target created in the same directory (CMakeLists.txt file) that specifies any output of the custom command as a source file is given a rule to generate the file using the command at build time.
add_custom_target(${target}_scapix_generated DEPENDS ${all_generated_sources})
add_dependencies(${target} ${target}_scapix_generated)

endfunction(scapix_bridge)

function(scapix_add_target target domain)
    set(bridge_headers ${ARGN})
    if(EMSCRIPTEN)
        add_executable(${target})
        target_link_options(${target} PRIVATE --bind)
    #   target_link_options(${target} PRIVATE --emrun)
    else()
        if(${SCAPIX_BRIDGE} STREQUAL java OR ${SCAPIX_BRIDGE} STREQUAL python OR ${SCAPIX_BRIDGE} STREQUAL cs)
            set(LIBRARY_TYPE SHARED)
        endif()
        add_library(${target} ${LIBRARY_TYPE})
    endif()
    scapix_bridge_headers(${target} ${domain} ${bridge_headers})
endfunction(scapix_add_target)

# workaround for CMake's 'Source file properties are visible only to targets added in the same directory'

function(scapix_fix_sources target)
    get_target_property(sources ${target} INTERFACE_SOURCES)
    set_source_files_properties(${sources} PROPERTIES GENERATED TRUE)
    source_group(TREE ${CMAKE_SOURCE_DIR}/generated PREFIX "generated" FILES ${sources})
    #set_source_files_properties(${sources} PROPERTIES HEADER_FILE_ONLY TRUE)

    #get_target_property(sources scapix INTERFACE_SOURCES)
    #source_group(TREE ${SCAPIX_ROOT}/source PREFIX "scapix" FILES ${sources})
endfunction()

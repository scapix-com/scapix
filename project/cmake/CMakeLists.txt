cmake_minimum_required(VERSION 3.14)

include("modules/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
    SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(scapix CXX)

if(NOT SCAPIX_BRIDGE)
    set(SCAPIX_BRIDGE cpp)
endif()

if(NOT SCAPIX_PLATFORM)
    set(SCAPIX_PLATFORM generic)
endif()

if(NOT SCAPIX_JAVA_API)
    set(SCAPIX_JAVA_API jdk-11.0.2)
endif()

set(SCAPIX_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
get_filename_component(SCAPIX_ROOT ${SCAPIX_ROOT} ABSOLUTE)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    ${SCAPIX_ROOT}/source/*.*
)

file(GLOB_RECURSE java_api_sources CONFIGURE_DEPENDS
    ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API}/scapix/java_api/*.*
)

file(GLOB_RECURSE doc_sources CONFIGURE_DEPENDS
    ${SCAPIX_ROOT}/doc/*.*
)

add_library(scapix ${sources} ${java_api_sources} ${doc_sources})

# https://github.com/ruslo/hunter/issues/542
set_target_properties(scapix PROPERTIES DEBUG_POSTFIX "")

source_group(TREE ${SCAPIX_ROOT}/source PREFIX "source" FILES ${sources})
source_group(TREE ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API}/scapix/java_api PREFIX "java_api" FILES ${java_api_sources})
source_group(TREE ${SCAPIX_ROOT}/doc PREFIX "doc" FILES ${doc_sources})

set(bridges
    "cpp"
    "java"
    "objc"
    "python"
    "js"
#   "cs"
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
    target_compile_options(scapix PUBLIC "-fobjc-arc")
    set_source_files_properties(${SCAPIX_ROOT}/source/scapix/bridge/objc/BridgeObject.mm PROPERTIES COMPILE_FLAGS -fno-objc-arc)
endif()

set_target_properties(scapix PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(scapix PUBLIC ${SCAPIX_ROOT}/source)
target_include_directories(scapix PUBLIC ${SCAPIX_ROOT}/java_api/${SCAPIX_JAVA_API})
target_compile_definitions(scapix PUBLIC SCAPIX_BRIDGE=${SCAPIX_BRIDGE} SCAPIX_BRIDGE_${SCAPIX_BRIDGE} SCAPIX_PLATFORM=${SCAPIX_PLATFORM})

hunter_add_package(Boost)
find_package(Boost REQUIRED)
target_link_libraries(scapix PUBLIC Boost::boost)

if(${SCAPIX_BRIDGE} STREQUAL java AND NOT ANDROID)
    find_package(JNI REQUIRED)
    target_include_directories(scapix PUBLIC ${JNI_INCLUDE_DIRS})
    target_link_libraries(scapix PUBLIC ${JNI_LIBRARIES})
endif()

if(MSVC)
    target_compile_options(scapix PUBLIC /MP /wd4584)

    if (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
        target_compile_options(scapix PUBLIC /permissive-)
        #target_compile_definitions(scapix PUBLIC BOOST_USE_CONSTEXPR)
    elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
        #target_compile_definitions(scapix PUBLIC _HAS_VARIABLE_TEMPLATES=1)
    endif()
endif()

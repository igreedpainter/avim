cmake_minimum_required(VERSION 2.8.9)

project(avim)

option(RUN_PROTOC "run protoc to generate protobuf protocol parser" OFF)

find_package(Threads REQUIRED)
find_package(Boost 1.54 REQUIRED thread system coroutine context regex)
find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
#find_package(PkgConfig REQUIRED)

#pkg_check_modules(PKCS11 REQUIRED libpkcs11-helper-1 )

include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})
#include_directories(${PKCS11_INCLUDE_DIRS})
include_directories(libavproto/include)
include_directories(.)

link_libraries(${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${PKCS11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_libraries(${PROTOBUF_LIBRARIES})

add_subdirectory(protocol)

link_libraries(avimproto-base)

add_subdirectory(libavproto)

link_libraries(avprotocol)

add_executable(avrouter router.cpp)

add_executable(simple_im simple_im.cpp)

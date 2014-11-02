cmake_minimum_required(VERSION 2.8)

project(avim)

option(RUN_PROTOC "run protoc to generate protobuf protocol parser" OFF)

find_package(Threads REQUIRED)
find_package(Boost 1.54 REQUIRED thread system coroutine context)
find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(libavproto/include)
include_directories(.)

link_libraries(${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(protocol)

add_subdirectory(libavproto)
link_libraries(avprotocol)

add_executable(avrouter router.cpp)

add_executable(testim simple_im.cpp)

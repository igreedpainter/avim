cmake_minimum_required(VERSION 2.6)

project(avim)

option(RUN_PROTOC "run protoc to generate protobuf protocol parser" OFF)

find_package(Boost 1.48 REQUIRED thread system)
find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(avproxy/include/)
include_directories(.)

link_libraries(${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(protocol)
add_subdirectory(lib)

add_subdirectory(server)
add_subdirectory(log)
add_subdirectory(db)

add_subdirectory(client)

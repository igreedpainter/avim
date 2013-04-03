cmake_minimum_required(VERSION 2.6)

project(avim)

find_package(Boost 1.48 REQUIRED thread system)

include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})



add_subdirectory(protocol)
add_subdirectory(lib)

add_subdirectory(server)
add_subdirectory(log)
add_subdirectory(db)

add_subdirectory(client)

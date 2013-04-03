cmake_minimum_required(VERSION 2.6)

project(avim)

add_subdirectory(protocol)
add_subdirectory(lib)

add_subdirectory(server)
add_subdirectory(log)
add_subdirectory(db)

add_subdirectory(client)

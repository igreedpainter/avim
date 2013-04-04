
include_directories(..)
add_executable(simpleclient main.cpp)
target_link_libraries(simpleclient avim-base-client)

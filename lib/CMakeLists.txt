
add_library(avim-base-client base_client.cpp)

target_link_libraries(avim-base-client ${Boost_LIBRARIES})

add_library(avim-base-server base_server.cpp)

target_link_libraries(avim-base-server ${Boost_LIBRARIES})

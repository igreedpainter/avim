


# include(./FindProtobuf.cmake)

find_package(Protobuf REQUIRED)

include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

PROTOBUF_GENERATE_CPP(PROTO_BASE PROTO_BASE_HDRS avim-base.proto)
PROTOBUF_GENERATE_CPP(PROTO_IM PROTO_IN_HDRS avim-im.proto)


add_library(avimproto-base STATIC avim-base.pb.cc)
target_link_libraries(avimproto-base ${PROTOBUF_LIBRARIES})

add_library(avimproto-im STATIC avim-im.pb.cc)
target_link_libraries(avimproto-base ${PROTOBUF_LIBRARIES})

# include(./FindProtobuf.cmake)
if(RUN_PROTOC)
PROTOBUF_GENERATE_CPP(PROTO_BASE PROTO_BASE_HDRS avim-base.proto)
PROTOBUF_GENERATE_CPP(PROTO_IM PROTO_IN_HDRS avim-im.proto)
else()
set(PROTO_BASE "avim-base.pb.cc")
set(PROTO_IM "avim-im.pb.cc" )
endif()

add_library(avimproto-base STATIC ${PROTO_BASE})
target_link_libraries(avimproto-base ${PROTOBUF_LIBRARIES})

add_library(avimproto-im STATIC ${PROTO_IM})
target_link_libraries(avimproto-base ${PROTOBUF_LIBRARIES})

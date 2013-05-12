
add_executable(avim main.cpp)

include_directories(..)

install(TARGETS avim RUNTIME DESTINATION bin)


cmake_minimum_required(VERSION 3.20.0)
project(payload_debug_server)

add_executable(PayloadDebugServer main.cpp)

target_link_libraries(PayloadDebugServer sockpp pthread)

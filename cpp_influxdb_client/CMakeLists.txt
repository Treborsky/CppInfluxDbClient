cmake_minimum_required(VERSION 3.20)
project(cpp_influxdb_client)

add_library(cpphttp STATIC cpp_httplib/httplib.cpp)
target_link_libraries(cpphttp pthread)

include_directories(cpp_httplib)
add_executable(CppInfluxDbClient main.cpp)
target_link_libraries(CppInfluxDbClient PRIVATE cpphttp)

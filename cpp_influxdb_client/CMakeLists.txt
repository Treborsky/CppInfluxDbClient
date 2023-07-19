cmake_minimum_required(VERSION 3.20)
project(cpp_influxdb_client)

find_package(OpenSSL REQUIRED)

add_executable(CppInfluxDbClient main.cpp)
target_link_libraries(CppInfluxDbClient OpenSSL::SSL OpenSSL::Crypto)
set(cpphttp_SOURCES httplib.cpp)

find_package(pthread REQUIRED)

add_library(cpphttp STATIC ${cpphttplib_SOURCES})

target_link_libraries(cpphttp pthread)
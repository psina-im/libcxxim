project(libcxxim)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

add_library(json INTERFACE)
target_include_directories(json INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/json/include")

add_subdirectory(libcxxmv)
add_subdirectory(cxxim)

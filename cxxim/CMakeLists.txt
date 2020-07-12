
add_library(cxxim STATIC cxxim.cpp)
target_include_directories(cxxim PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(cxxim PUBLIC cxxmv)

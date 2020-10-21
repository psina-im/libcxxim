
add_executable(cxximtest
               test.cpp
               account_list_test.cpp
               account_test.cpp)
target_link_libraries(cxximtest PRIVATE cxxim)

add_test(NAME cxximtest COMMAND cxximtest)
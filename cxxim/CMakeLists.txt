
add_library(cxxim STATIC
            account.cpp
            account.hpp
            account_list.cpp
            account_list.hpp
            application.cpp
            application.hpp
            client.cpp
            client.hpp
            cxxim.cpp
            json.hpp
            json_fwd.hpp
            runtime_error.hpp
            settings.cpp
            settings.hpp
            strings.cpp
            strings.hpp
            )

target_include_directories(cxxim PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(cxxim PUBLIC cxxmv json)

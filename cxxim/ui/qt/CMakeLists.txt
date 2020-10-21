
find_package(Qt5 COMPONENTS "Widgets")

add_library(cxxim-ui-qt STATIC
            accounts_dialog.cpp
            accounts_dialog.hpp
            main_window.cpp
            main_window.hpp
            qt_application.cpp
            qt_application.hpp)
target_link_libraries(cxxim-ui-qt PUBLIC cxxim)
target_link_libraries(cxxim-ui-qt PUBLIC Qt5::Widgets)


/// \file main_window.hpp
/// Contains definition of the main_window class.

#include <QMainWindow>


namespace im::ui {

class qt_application;


/// Main client application window
class main_window: public QMainWindow {
public:
    /// Constructs main window with specified reference to application object
    main_window(qt_application & app);

private:
    /// Makes main menu
    void make_menu();

    qt_application & app_;          ///< Reference to application object
};


}

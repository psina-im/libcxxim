
/// \file qt_application.hpp
/// Contains definition of the qt_application class.

#pragma once

#include "../../application.hpp"
#include <QApplication>


namespace im::ui {


/// Main Qt application class.
class qt_application: public application, public QApplication {
public:
    /// Constructs application object
    qt_application(int & argc, char * argv[]);
};


}

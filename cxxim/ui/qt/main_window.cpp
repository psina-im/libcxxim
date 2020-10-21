
/// \file main_window.cpp
/// Contains implementation of the main_window class.

#include "main_window.hpp"
#include "accounts_dialog.hpp"
#include "qt_application.hpp"
#include <QMenuBar>


namespace im::ui {


main_window::main_window(qt_application & app):
app_{app} {
    setWindowTitle(tr("Psina IM"));

    make_menu();
}


void main_window::make_menu() {
    auto file = menuBar()->addMenu(tr("File"));

    auto exit = file->addAction(tr("Exit"));
    exit->setShortcut(QKeySequence{"ALT+F4"});
    connect(exit, &QAction::triggered, [this] { close(); });


    auto tools = menuBar()->addMenu(tr("Tools"));

    auto accounts = tools->addAction(tr("Accounts..."));
    connect(accounts, &QAction::triggered, [this] {
        accounts_dialog dlg{app_.accounts(), this};
        dlg.exec();
    });

    auto settings = tools->addAction(tr("Settings..."));
    connect(settings, &QAction::triggered, [this] {
    });
}


}

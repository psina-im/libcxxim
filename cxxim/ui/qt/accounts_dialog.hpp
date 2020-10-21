
/// \file accounts_dialog.hpp
/// Contains definition of the accounts_dialog class.

#pragma once

#include <QDialog>


class QListWidget;


namespace im {
    class account_list;
}


namespace im::ui {


/// Dialog for editing list of accounts
class accounts_dialog: public QDialog {
public:
    /// Constructs dialog with specified refrence to account list and parent
    accounts_dialog(account_list & acc_list, QWidget * parent = nullptr);

private:
    account_list & accounts_;                   ///< List of accounts
    QListWidget * accounts_list_ = nullptr;     ///< Accounts list widget
};


}

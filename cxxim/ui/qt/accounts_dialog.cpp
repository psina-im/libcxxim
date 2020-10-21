
/// \file accounts_dialog.cpp
/// Contains implementation of the accounts_dialog class.

#include "accounts_dialog.hpp"
#include "../../account_list.hpp"
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <qt5/QtWidgets/qdialog.h>


Q_DECLARE_METATYPE(const im::account*);


namespace im::ui {


accounts_dialog::accounts_dialog(account_list & acc_list, QWidget * parent):
QDialog{parent},
accounts_{acc_list} {
    setWindowTitle(tr("Accounts"));

    auto layout = new QVBoxLayout{this};

    // account list
    accounts_list_ = new QListWidget;
    layout->addWidget(accounts_list_);
    for (auto && acc : accounts_.all()) {
        auto item = new QListWidgetItem{QString::fromStdWString(acc->user_id())};
        item->setData(Qt::UserRole, acc);
        accounts_list_->addItem(item);
    }

    auto buttons_layout = new QHBoxLayout;
    layout->addLayout(buttons_layout);

    auto add_button = new QPushButton{tr("Add...")};
    buttons_layout->addWidget(add_button);

    auto edit_button = new QPushButton{tr("Edit...")};
    buttons_layout->addWidget(edit_button);

    auto delete_button = new QPushButton{tr("Remove")};
    buttons_layout->addWidget(delete_button);

    buttons_layout->addStretch(1);

    auto ok_button = new QPushButton{tr("Ok")};
    buttons_layout->addWidget(ok_button);
    connect(ok_button, &QPushButton::clicked, [this] { accept(); });
    ok_button->setDefault(true);
    ok_button->setAutoDefault(true);
}


}

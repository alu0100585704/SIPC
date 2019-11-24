/********************************************************************************
** Form generated from reading UI file 'playlisteditordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTEDITORDIALOG_H
#define UI_PLAYLISTEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlayListEditorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlayListEditorDialog)
    {
        if (PlayListEditorDialog->objectName().isEmpty())
            PlayListEditorDialog->setObjectName(QString::fromUtf8("PlayListEditorDialog"));
        PlayListEditorDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PlayListEditorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(PlayListEditorDialog);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setDragDropMode(QAbstractItemView::InternalMove);
        listView->setMovement(QListView::Snap);

        horizontalLayout->addWidget(listView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        addButton = new QPushButton(PlayListEditorDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        deleteButton = new QPushButton(PlayListEditorDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setCheckable(false);

        verticalLayout_2->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(PlayListEditorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PlayListEditorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PlayListEditorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PlayListEditorDialog, SLOT(reject()));

        deleteButton->setDefault(false);


        QMetaObject::connectSlotsByName(PlayListEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayListEditorDialog)
    {
        PlayListEditorDialog->setWindowTitle(QApplication::translate("PlayListEditorDialog", "Dialog", nullptr));
        addButton->setText(QApplication::translate("PlayListEditorDialog", "+", nullptr));
        deleteButton->setText(QApplication::translate("PlayListEditorDialog", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayListEditorDialog: public Ui_PlayListEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTEDITORDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'playlistremote.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTREMOTE_H
#define UI_PLAYLISTREMOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlayListRemote
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *okPushButton;
    QPushButton *publishPushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlayListRemote)
    {
        if (PlayListRemote->objectName().isEmpty())
            PlayListRemote->setObjectName(QString::fromUtf8("PlayListRemote"));
        PlayListRemote->resize(691, 526);
        horizontalLayout = new QHBoxLayout(PlayListRemote);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableWidget = new QTableWidget(PlayListRemote);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okPushButton = new QPushButton(PlayListRemote);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        verticalLayout->addWidget(okPushButton);

        publishPushButton = new QPushButton(PlayListRemote);
        publishPushButton->setObjectName(QString::fromUtf8("publishPushButton"));

        verticalLayout->addWidget(publishPushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(PlayListRemote);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(PlayListRemote);
        QObject::connect(buttonBox, SIGNAL(accepted()), PlayListRemote, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PlayListRemote, SLOT(reject()));

        QMetaObject::connectSlotsByName(PlayListRemote);
    } // setupUi

    void retranslateUi(QDialog *PlayListRemote)
    {
        PlayListRemote->setWindowTitle(QApplication::translate("PlayListRemote", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PlayListRemote", "Usuario", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PlayListRemote", "Reproduciendo . . .", nullptr));
        okPushButton->setText(QApplication::translate("PlayListRemote", "Ok", nullptr));
        publishPushButton->setText(QApplication::translate("PlayListRemote", "Publicar", nullptr));
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QApplication::translate("PlayListRemote", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class PlayListRemote: public Ui_PlayListRemote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTREMOTE_H

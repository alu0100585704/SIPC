/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *iniciarCamara;
    QPushButton *capturarMano;
    QPushButton *reconocerMano;
    QPushButton *salir;
    QCheckBox *checkBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(412, 332);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        iniciarCamara = new QPushButton(centralWidget);
        iniciarCamara->setObjectName(QStringLiteral("iniciarCamara"));

        gridLayout->addWidget(iniciarCamara, 0, 0, 1, 1);

        capturarMano = new QPushButton(centralWidget);
        capturarMano->setObjectName(QStringLiteral("capturarMano"));

        gridLayout->addWidget(capturarMano, 1, 0, 1, 1);

        reconocerMano = new QPushButton(centralWidget);
        reconocerMano->setObjectName(QStringLiteral("reconocerMano"));

        gridLayout->addWidget(reconocerMano, 2, 0, 1, 1);

        salir = new QPushButton(centralWidget);
        salir->setObjectName(QStringLiteral("salir"));

        gridLayout->addWidget(salir, 0, 1, 1, 1);

        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 412, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        iniciarCamara->setText(QApplication::translate("MainWindow", "Iniciar Camara", Q_NULLPTR));
        capturarMano->setText(QApplication::translate("MainWindow", "Capturar Mano", Q_NULLPTR));
        reconocerMano->setText(QApplication::translate("MainWindow", "Reconocimiento", Q_NULLPTR));
        salir->setText(QApplication::translate("MainWindow", "Salir", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "Media Total", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

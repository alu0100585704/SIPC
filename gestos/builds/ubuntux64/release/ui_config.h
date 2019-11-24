/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *modeClientRadioButton;
    QLabel *label_8;
    QLineEdit *userNameLineEdit;
    QLabel *label;
    QLineEdit *ipClientLineEdit;
    QLabel *label_2;
    QLineEdit *portServerLineEdit;
    QLabel *label_11;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *modeServerRadioButton;
    QLabel *label_9;
    QLineEdit *serverNameLineEdit_2;
    QLabel *label_3;
    QLineEdit *ipServerLineEdit;
    QLabel *label_4;
    QLineEdit *portListenLineEdit;
    QLabel *label_10;
    QLineEdit *portPublisherLineEdit;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QFrame *line_2;
    QLabel *label_6;
    QFrame *line_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_7;
    QLineEdit *saveFileNameLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(747, 572);
        verticalLayout = new QVBoxLayout(Config);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(Config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setTextFormat(Qt::RichText);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);


        verticalLayout->addLayout(verticalLayout_5);

        line = new QFrame(Config);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        modeClientRadioButton = new QRadioButton(Config);
        modeClientRadioButton->setObjectName(QString::fromUtf8("modeClientRadioButton"));
        modeClientRadioButton->setChecked(false);

        verticalLayout_4->addWidget(modeClientRadioButton);

        label_8 = new QLabel(Config);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        userNameLineEdit = new QLineEdit(Config);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        verticalLayout_4->addWidget(userNameLineEdit);

        label = new QLabel(Config);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        ipClientLineEdit = new QLineEdit(Config);
        ipClientLineEdit->setObjectName(QString::fromUtf8("ipClientLineEdit"));
        ipClientLineEdit->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(ipClientLineEdit);

        label_2 = new QLabel(Config);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        portServerLineEdit = new QLineEdit(Config);
        portServerLineEdit->setObjectName(QString::fromUtf8("portServerLineEdit"));
        portServerLineEdit->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(portServerLineEdit);

        label_11 = new QLabel(Config);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        passwordLineEdit = new QLineEdit(Config);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        passwordLineEdit->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(passwordLineEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        modeServerRadioButton = new QRadioButton(Config);
        modeServerRadioButton->setObjectName(QString::fromUtf8("modeServerRadioButton"));

        verticalLayout_2->addWidget(modeServerRadioButton);

        label_9 = new QLabel(Config);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        serverNameLineEdit_2 = new QLineEdit(Config);
        serverNameLineEdit_2->setObjectName(QString::fromUtf8("serverNameLineEdit_2"));

        verticalLayout_2->addWidget(serverNameLineEdit_2);

        label_3 = new QLabel(Config);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        ipServerLineEdit = new QLineEdit(Config);
        ipServerLineEdit->setObjectName(QString::fromUtf8("ipServerLineEdit"));
        ipServerLineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(ipServerLineEdit);

        label_4 = new QLabel(Config);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        portListenLineEdit = new QLineEdit(Config);
        portListenLineEdit->setObjectName(QString::fromUtf8("portListenLineEdit"));
        portListenLineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(portListenLineEdit);

        label_10 = new QLabel(Config);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        portPublisherLineEdit = new QLineEdit(Config);
        portPublisherLineEdit->setObjectName(QString::fromUtf8("portPublisherLineEdit"));
        portPublisherLineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(portPublisherLineEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        line_2 = new QFrame(Config);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        label_6 = new QLabel(Config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setTextFormat(Qt::RichText);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_6);

        line_3 = new QFrame(Config);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_3);

        checkBox = new QCheckBox(Config);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        checkBox_2 = new QCheckBox(Config);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_6->addWidget(checkBox_2);

        label_7 = new QLabel(Config);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        saveFileNameLineEdit = new QLineEdit(Config);
        saveFileNameLineEdit->setObjectName(QString::fromUtf8("saveFileNameLineEdit"));

        verticalLayout_6->addWidget(saveFileNameLineEdit);


        verticalLayout->addLayout(verticalLayout_6);

        buttonBox = new QDialogButtonBox(Config);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Config);
        QObject::connect(buttonBox, SIGNAL(accepted()), Config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Config, SLOT(reject()));

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Form", nullptr));
        label_5->setText(QApplication::translate("Config", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Configuraci\303\263n de Red</span></p></body></html>", nullptr));
        modeClientRadioButton->setText(QApplication::translate("Config", "Modo Cliente", nullptr));
        label_8->setText(QApplication::translate("Config", "Nombre de Usuario:", nullptr));
        label->setText(QApplication::translate("Config", "IP Servidor:", nullptr));
        ipClientLineEdit->setInputMask(QString());
        ipClientLineEdit->setText(QString());
        label_2->setText(QApplication::translate("Config", "Puerto Servidor:", nullptr));
        portServerLineEdit->setInputMask(QString());
        portServerLineEdit->setText(QString());
        label_11->setText(QApplication::translate("Config", "Password:", nullptr));
        passwordLineEdit->setText(QString());
        modeServerRadioButton->setText(QApplication::translate("Config", "Modo _Servidor", nullptr));
        label_9->setText(QApplication::translate("Config", "Nombre Servidor:", nullptr));
        label_3->setText(QApplication::translate("Config", "IP Escucha:", nullptr));
        ipServerLineEdit->setInputMask(QString());
        ipServerLineEdit->setText(QString());
        label_4->setText(QApplication::translate("Config", "Puerto Escucha Reply:", nullptr));
        portListenLineEdit->setInputMask(QString());
        portListenLineEdit->setText(QString());
        label_10->setText(QApplication::translate("Config", "Puerto Escucha Publicador:", nullptr));
        portPublisherLineEdit->setText(QString());
        label_6->setText(QApplication::translate("Config", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Otras Opciones</span></p></body></html>", nullptr));
        checkBox->setText(QApplication::translate("Config", "Salvar PlayList Autom\303\241ticamente", nullptr));
        checkBox_2->setText(QApplication::translate("Config", "C\303\241mara", nullptr));
        label_7->setText(QApplication::translate("Config", "Ruta por Defecto fichero con PlayList:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H

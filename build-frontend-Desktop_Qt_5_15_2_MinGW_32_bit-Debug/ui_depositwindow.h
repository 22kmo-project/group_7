/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QPushButton *button_20e;
    QPushButton *button_ok;
    QLabel *label_client_name;
    QPushButton *button_40e;
    QLabel *label_3;
    QLabel *label_1;
    QLabel *label_balance;
    QLabel *label_2;
    QPushButton *button_100e;
    QPushButton *button_200e;
    QPushButton *button_500e;
    QPushButton *button_60e;
    QLabel *label_info;
    QPushButton *button_exit;
    QPushButton *button_300e;
    QPushButton *button_400e;

    void setupUi(QDialog *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(800, 600);
        button_20e = new QPushButton(DepositWindow);
        button_20e->setObjectName(QString::fromUtf8("button_20e"));
        button_20e->setGeometry(QRect(60, 410, 121, 61));
        QFont font;
        font.setPointSize(15);
        button_20e->setFont(font);
        button_ok = new QPushButton(DepositWindow);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setGeometry(QRect(590, 410, 121, 61));
        button_ok->setFont(font);
        button_ok->setStyleSheet(QString::fromUtf8("background: green;\n"
"color: black;"));
        label_client_name = new QLabel(DepositWindow);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(340, 60, 421, 61));
        QFont font1;
        font1.setPointSize(20);
        label_client_name->setFont(font1);
        button_40e = new QPushButton(DepositWindow);
        button_40e->setObjectName(QString::fromUtf8("button_40e"));
        button_40e->setGeometry(QRect(190, 410, 121, 61));
        button_40e->setFont(font);
        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 330, 571, 61));
        label_3->setFont(font1);
        label_1 = new QLabel(DepositWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(110, 60, 191, 61));
        label_1->setFont(font1);
        label_balance = new QLabel(DepositWindow);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(340, 110, 421, 61));
        label_balance->setFont(font1);
        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 110, 191, 61));
        label_2->setFont(font1);
        button_100e = new QPushButton(DepositWindow);
        button_100e->setObjectName(QString::fromUtf8("button_100e"));
        button_100e->setGeometry(QRect(450, 410, 121, 61));
        button_100e->setFont(font);
        button_200e = new QPushButton(DepositWindow);
        button_200e->setObjectName(QString::fromUtf8("button_200e"));
        button_200e->setGeometry(QRect(60, 480, 121, 61));
        button_200e->setFont(font);
        button_500e = new QPushButton(DepositWindow);
        button_500e->setObjectName(QString::fromUtf8("button_500e"));
        button_500e->setGeometry(QRect(450, 480, 121, 61));
        button_500e->setFont(font);
        button_60e = new QPushButton(DepositWindow);
        button_60e->setObjectName(QString::fromUtf8("button_60e"));
        button_60e->setGeometry(QRect(320, 410, 121, 61));
        button_60e->setFont(font);
        label_info = new QLabel(DepositWindow);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(110, 190, 571, 111));
        label_info->setFont(font);
        button_exit = new QPushButton(DepositWindow);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        button_exit->setGeometry(QRect(590, 480, 121, 61));
        button_exit->setFont(font);
        button_exit->setStyleSheet(QString::fromUtf8("background: red;\n"
"color: black;"));
        button_300e = new QPushButton(DepositWindow);
        button_300e->setObjectName(QString::fromUtf8("button_300e"));
        button_300e->setGeometry(QRect(190, 480, 121, 61));
        button_300e->setFont(font);
        button_400e = new QPushButton(DepositWindow);
        button_400e->setObjectName(QString::fromUtf8("button_400e"));
        button_400e->setGeometry(QRect(320, 480, 121, 61));
        button_400e->setFont(font);

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QDialog *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Dialog", nullptr));
        button_20e->setText(QCoreApplication::translate("DepositWindow", "20 \342\202\254", nullptr));
        button_ok->setText(QCoreApplication::translate("DepositWindow", "OK", nullptr));
        label_client_name->setText(QCoreApplication::translate("DepositWindow", "Text", nullptr));
        button_40e->setText(QCoreApplication::translate("DepositWindow", "40 \342\202\254", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "Valitse talletettava rahasumma:", nullptr));
        label_1->setText(QCoreApplication::translate("DepositWindow", "Asiakas:", nullptr));
        label_balance->setText(QCoreApplication::translate("DepositWindow", "Text", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "Tilin saldo:", nullptr));
        button_100e->setText(QCoreApplication::translate("DepositWindow", "100 \342\202\254", nullptr));
        button_200e->setText(QCoreApplication::translate("DepositWindow", "200 \342\202\254", nullptr));
        button_500e->setText(QCoreApplication::translate("DepositWindow", "500 \342\202\254", nullptr));
        button_60e->setText(QCoreApplication::translate("DepositWindow", "60 \342\202\254", nullptr));
        label_info->setText(QString());
        button_exit->setText(QCoreApplication::translate("DepositWindow", "Sulje", nullptr));
        button_300e->setText(QCoreApplication::translate("DepositWindow", "300 \342\202\254", nullptr));
        button_400e->setText(QCoreApplication::translate("DepositWindow", "400 \342\202\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H

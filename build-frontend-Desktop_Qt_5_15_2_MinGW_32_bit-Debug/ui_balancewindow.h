/********************************************************************************
** Form generated from reading UI file 'balancewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEWINDOW_H
#define UI_BALANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BalanceWindow
{
public:
    QPushButton *Button_close;
    QLabel *label_transactions;
    QLabel *label_client_name;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_balance;
    QLabel *label_3;

    void setupUi(QDialog *BalanceWindow)
    {
        if (BalanceWindow->objectName().isEmpty())
            BalanceWindow->setObjectName(QString::fromUtf8("BalanceWindow"));
        BalanceWindow->resize(838, 523);
        Button_close = new QPushButton(BalanceWindow);
        Button_close->setObjectName(QString::fromUtf8("Button_close"));
        Button_close->setGeometry(QRect(700, 440, 121, 61));
        QFont font;
        font.setPointSize(15);
        Button_close->setFont(font);
        Button_close->setStyleSheet(QString::fromUtf8("background: red;\n"
"color: black;"));
        label_transactions = new QLabel(BalanceWindow);
        label_transactions->setObjectName(QString::fromUtf8("label_transactions"));
        label_transactions->setGeometry(QRect(60, 280, 571, 221));
        QFont font1;
        font1.setPointSize(12);
        label_transactions->setFont(font1);
        label_transactions->setStyleSheet(QString::fromUtf8("background: white;\n"
"color: black;"));
        label_client_name = new QLabel(BalanceWindow);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(210, 30, 391, 101));
        QFont font2;
        font2.setPointSize(18);
        label_client_name->setFont(font2);
        label = new QLabel(BalanceWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 111, 101));
        label->setFont(font2);
        label_2 = new QLabel(BalanceWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 131, 101));
        label_2->setFont(font2);
        label_balance = new QLabel(BalanceWindow);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(210, 100, 391, 101));
        label_balance->setFont(font2);
        label_3 = new QLabel(BalanceWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 190, 321, 101));
        label_3->setFont(font2);

        retranslateUi(BalanceWindow);

        QMetaObject::connectSlotsByName(BalanceWindow);
    } // setupUi

    void retranslateUi(QDialog *BalanceWindow)
    {
        BalanceWindow->setWindowTitle(QCoreApplication::translate("BalanceWindow", "Dialog", nullptr));
        Button_close->setText(QCoreApplication::translate("BalanceWindow", "Sulje", nullptr));
        label_transactions->setText(QCoreApplication::translate("BalanceWindow", "TextLabel", nullptr));
        label_client_name->setText(QCoreApplication::translate("BalanceWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("BalanceWindow", "Nimi:", nullptr));
        label_2->setText(QCoreApplication::translate("BalanceWindow", "Tilin saldo:", nullptr));
        label_balance->setText(QCoreApplication::translate("BalanceWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("BalanceWindow", "Viimeisimm\303\244t tilitapahtumat: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BalanceWindow: public Ui_BalanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEWINDOW_H

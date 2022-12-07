/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QLabel *label_id_card;
    QPushButton *button_nayta_saldo;
    QPushButton *button_withdraw;
    QPushButton *button_deposit;
    QPushButton *button_exit;
    QPushButton *pushButtonTrans;
    QPushButton *button_transfer;

    void setupUi(QDialog *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(800, 600);
        label_id_card = new QLabel(ClientWindow);
        label_id_card->setObjectName(QString::fromUtf8("label_id_card"));
        label_id_card->setGeometry(QRect(30, 60, 111, 41));
        QFont font;
        font.setPointSize(20);
        label_id_card->setFont(font);
        button_nayta_saldo = new QPushButton(ClientWindow);
        button_nayta_saldo->setObjectName(QString::fromUtf8("button_nayta_saldo"));
        button_nayta_saldo->setGeometry(QRect(40, 140, 151, 31));
        button_withdraw = new QPushButton(ClientWindow);
        button_withdraw->setObjectName(QString::fromUtf8("button_withdraw"));
        button_withdraw->setGeometry(QRect(40, 220, 151, 31));
        button_deposit = new QPushButton(ClientWindow);
        button_deposit->setObjectName(QString::fromUtf8("button_deposit"));
        button_deposit->setGeometry(QRect(40, 260, 151, 31));
        button_exit = new QPushButton(ClientWindow);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        button_exit->setGeometry(QRect(640, 510, 121, 61));
        QFont font1;
        font1.setPointSize(15);
        button_exit->setFont(font1);
        button_exit->setStyleSheet(QString::fromUtf8("background: red;\n"
"color: black;"));
        pushButtonTrans = new QPushButton(ClientWindow);
        pushButtonTrans->setObjectName(QString::fromUtf8("pushButtonTrans"));
        pushButtonTrans->setGeometry(QRect(40, 180, 151, 29));
        button_transfer = new QPushButton(ClientWindow);
        button_transfer->setObjectName(QString::fromUtf8("button_transfer"));
        button_transfer->setGeometry(QRect(40, 300, 151, 31));

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QDialog *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "Dialog", nullptr));
        label_id_card->setText(QCoreApplication::translate("ClientWindow", "TextLabel", nullptr));
        button_nayta_saldo->setText(QCoreApplication::translate("ClientWindow", "N\303\244yt\303\244 saldo", nullptr));
        button_withdraw->setText(QCoreApplication::translate("ClientWindow", "Nosta rahaa", nullptr));
        button_deposit->setText(QCoreApplication::translate("ClientWindow", "Talleta rahaa", nullptr));
        button_exit->setText(QCoreApplication::translate("ClientWindow", "Lopeta", nullptr));
        pushButtonTrans->setText(QCoreApplication::translate("ClientWindow", "N\303\244yt\303\244 tilitapahtumat", nullptr));
        button_transfer->setText(QCoreApplication::translate("ClientWindow", "Siirr\303\244 rahaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H

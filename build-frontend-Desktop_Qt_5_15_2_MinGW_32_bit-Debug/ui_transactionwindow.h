/********************************************************************************
** Form generated from reading UI file 'transactionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONWINDOW_H
#define UI_TRANSACTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TransactionWindow
{
public:
    QLabel *label_2_client_2;
    QLabel *label_2_balance;
    QPushButton *pushButtonClose;
    QLabel *label_transact;

    void setupUi(QDialog *TransactionWindow)
    {
        if (TransactionWindow->objectName().isEmpty())
            TransactionWindow->setObjectName(QString::fromUtf8("TransactionWindow"));
        TransactionWindow->resize(800, 600);
        label_2_client_2 = new QLabel(TransactionWindow);
        label_2_client_2->setObjectName(QString::fromUtf8("label_2_client_2"));
        label_2_client_2->setGeometry(QRect(40, 30, 191, 20));
        QFont font;
        font.setPointSize(14);
        label_2_client_2->setFont(font);
        label_2_balance = new QLabel(TransactionWindow);
        label_2_balance->setObjectName(QString::fromUtf8("label_2_balance"));
        label_2_balance->setGeometry(QRect(40, 70, 191, 20));
        label_2_balance->setFont(font);
        pushButtonClose = new QPushButton(TransactionWindow);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(670, 530, 93, 29));
        label_transact = new QLabel(TransactionWindow);
        label_transact->setObjectName(QString::fromUtf8("label_transact"));
        label_transact->setGeometry(QRect(40, 130, 671, 351));

        retranslateUi(TransactionWindow);

        QMetaObject::connectSlotsByName(TransactionWindow);
    } // setupUi

    void retranslateUi(QDialog *TransactionWindow)
    {
        TransactionWindow->setWindowTitle(QCoreApplication::translate("TransactionWindow", "Dialog", nullptr));
        label_2_client_2->setText(QCoreApplication::translate("TransactionWindow", "TextLabel", nullptr));
        label_2_balance->setText(QCoreApplication::translate("TransactionWindow", "TextLabel", nullptr));
        pushButtonClose->setText(QCoreApplication::translate("TransactionWindow", "Sulje", nullptr));
        label_transact->setText(QCoreApplication::translate("TransactionWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransactionWindow: public Ui_TransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONWINDOW_H

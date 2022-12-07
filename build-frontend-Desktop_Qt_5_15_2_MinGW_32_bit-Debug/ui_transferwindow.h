/********************************************************************************
** Form generated from reading UI file 'transferwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERWINDOW_H
#define UI_TRANSFERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TransferWindow
{
public:
    QPushButton *btn_0;
    QPushButton *btn_1;
    QLabel *label_info;
    QPushButton *btn_3;
    QPushButton *btn_5;
    QPushButton *btn_9;
    QPushButton *btn_clear;
    QPushButton *btn_8;
    QPushButton *btn_close;
    QPushButton *btn_2;
    QPushButton *btn_6;
    QPushButton *btn_4;
    QPushButton *btn_7;
    QPushButton *btn_ok;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TransferWindow)
    {
        if (TransferWindow->objectName().isEmpty())
            TransferWindow->setObjectName(QString::fromUtf8("TransferWindow"));
        TransferWindow->resize(800, 600);
        btn_0 = new QPushButton(TransferWindow);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(320, 440, 41, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        btn_0->setFont(font);
        btn_1 = new QPushButton(TransferWindow);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(270, 290, 41, 41));
        btn_1->setFont(font);
        label_info = new QLabel(TransferWindow);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(200, 120, 361, 111));
        QFont font1;
        font1.setPointSize(12);
        label_info->setFont(font1);
        label_info->setStyleSheet(QString::fromUtf8("background: rgb(204, 204, 204);\n"
"color: black"));
        label_info->setFrameShape(QFrame::NoFrame);
        label_info->setFrameShadow(QFrame::Plain);
        label_info->setAlignment(Qt::AlignCenter);
        btn_3 = new QPushButton(TransferWindow);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(370, 290, 41, 41));
        btn_3->setFont(font);
        btn_5 = new QPushButton(TransferWindow);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(320, 340, 41, 41));
        btn_5->setFont(font);
        btn_9 = new QPushButton(TransferWindow);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(370, 390, 41, 41));
        btn_9->setFont(font);
        btn_clear = new QPushButton(TransferWindow);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(440, 340, 71, 41));
        btn_clear->setFont(font);
        btn_clear->setStyleSheet(QString::fromUtf8("background: yellow;\n"
"color: black"));
        btn_8 = new QPushButton(TransferWindow);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(320, 390, 41, 41));
        btn_8->setFont(font);
        btn_close = new QPushButton(TransferWindow);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(440, 390, 71, 41));
        btn_close->setFont(font);
        btn_close->setStyleSheet(QString::fromUtf8("background: red;\n"
"color: black"));
        btn_2 = new QPushButton(TransferWindow);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(320, 290, 41, 41));
        btn_2->setFont(font);
        btn_6 = new QPushButton(TransferWindow);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(370, 340, 41, 41));
        btn_6->setFont(font);
        btn_4 = new QPushButton(TransferWindow);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(270, 340, 41, 41));
        btn_4->setFont(font);
        btn_7 = new QPushButton(TransferWindow);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(270, 390, 41, 41));
        btn_7->setFont(font);
        btn_ok = new QPushButton(TransferWindow);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setGeometry(QRect(440, 290, 71, 41));
        btn_ok->setFont(font);
        btn_ok->setStyleSheet(QString::fromUtf8("background: green;\n"
"color: black"));
        lineEdit = new QLineEdit(TransferWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(280, 250, 113, 24));

        retranslateUi(TransferWindow);

        QMetaObject::connectSlotsByName(TransferWindow);
    } // setupUi

    void retranslateUi(QDialog *TransferWindow)
    {
        TransferWindow->setWindowTitle(QCoreApplication::translate("TransferWindow", "Dialog", nullptr));
        btn_0->setText(QCoreApplication::translate("TransferWindow", "0", nullptr));
        btn_1->setText(QCoreApplication::translate("TransferWindow", "1", nullptr));
        label_info->setText(QString());
        btn_3->setText(QCoreApplication::translate("TransferWindow", "3", nullptr));
        btn_5->setText(QCoreApplication::translate("TransferWindow", "5", nullptr));
        btn_9->setText(QCoreApplication::translate("TransferWindow", "9", nullptr));
        btn_clear->setText(QCoreApplication::translate("TransferWindow", "Peru", nullptr));
        btn_8->setText(QCoreApplication::translate("TransferWindow", "8", nullptr));
        btn_close->setText(QCoreApplication::translate("TransferWindow", "Sulje", nullptr));
        btn_2->setText(QCoreApplication::translate("TransferWindow", "2", nullptr));
        btn_6->setText(QCoreApplication::translate("TransferWindow", "6", nullptr));
        btn_4->setText(QCoreApplication::translate("TransferWindow", "4", nullptr));
        btn_7->setText(QCoreApplication::translate("TransferWindow", "7", nullptr));
        btn_ok->setText(QCoreApplication::translate("TransferWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferWindow: public Ui_TransferWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERWINDOW_H

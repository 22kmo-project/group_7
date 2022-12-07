/********************************************************************************
** Form generated from reading UI file 'drawwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWWINDOW_H
#define UI_DRAWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DrawWindow
{
public:
    QLabel *label_1;
    QPushButton *button_20e;
    QPushButton *button_40e;
    QPushButton *button_60e;
    QPushButton *button_100e;
    QPushButton *button_200e;
    QPushButton *button_500e;
    QPushButton *button_exit;
    QLabel *label_2;
    QLabel *label_info;
    QLabel *label_client_name;
    QLabel *label_balance;
    QLabel *label_3;
    QPushButton *button_ok;

    void setupUi(QDialog *DrawWindow)
    {
        if (DrawWindow->objectName().isEmpty())
            DrawWindow->setObjectName(QString::fromUtf8("DrawWindow"));
        DrawWindow->resize(800, 600);
        label_1 = new QLabel(DrawWindow);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(110, 60, 191, 61));
        QFont font;
        font.setPointSize(20);
        label_1->setFont(font);
        button_20e = new QPushButton(DrawWindow);
        button_20e->setObjectName(QString::fromUtf8("button_20e"));
        button_20e->setGeometry(QRect(100, 410, 121, 61));
        QFont font1;
        font1.setPointSize(15);
        button_20e->setFont(font1);
        button_40e = new QPushButton(DrawWindow);
        button_40e->setObjectName(QString::fromUtf8("button_40e"));
        button_40e->setGeometry(QRect(240, 410, 121, 61));
        button_40e->setFont(font1);
        button_60e = new QPushButton(DrawWindow);
        button_60e->setObjectName(QString::fromUtf8("button_60e"));
        button_60e->setGeometry(QRect(380, 410, 121, 61));
        button_60e->setFont(font1);
        button_100e = new QPushButton(DrawWindow);
        button_100e->setObjectName(QString::fromUtf8("button_100e"));
        button_100e->setGeometry(QRect(100, 490, 121, 61));
        button_100e->setFont(font1);
        button_200e = new QPushButton(DrawWindow);
        button_200e->setObjectName(QString::fromUtf8("button_200e"));
        button_200e->setGeometry(QRect(240, 490, 121, 61));
        button_200e->setFont(font1);
        button_500e = new QPushButton(DrawWindow);
        button_500e->setObjectName(QString::fromUtf8("button_500e"));
        button_500e->setGeometry(QRect(380, 490, 121, 61));
        button_500e->setFont(font1);
        button_exit = new QPushButton(DrawWindow);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        button_exit->setGeometry(QRect(520, 490, 121, 61));
        button_exit->setFont(font1);
        button_exit->setStyleSheet(QString::fromUtf8("background: red;\n"
"color: black;"));
        label_2 = new QLabel(DrawWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 110, 191, 61));
        label_2->setFont(font);
        label_info = new QLabel(DrawWindow);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(110, 190, 571, 111));
        label_info->setFont(font1);
        label_client_name = new QLabel(DrawWindow);
        label_client_name->setObjectName(QString::fromUtf8("label_client_name"));
        label_client_name->setGeometry(QRect(340, 60, 421, 61));
        label_client_name->setFont(font);
        label_balance = new QLabel(DrawWindow);
        label_balance->setObjectName(QString::fromUtf8("label_balance"));
        label_balance->setGeometry(QRect(340, 110, 421, 61));
        label_balance->setFont(font);
        label_3 = new QLabel(DrawWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 320, 571, 61));
        label_3->setFont(font);
        button_ok = new QPushButton(DrawWindow);
        button_ok->setObjectName(QString::fromUtf8("button_ok"));
        button_ok->setGeometry(QRect(520, 410, 121, 61));
        button_ok->setFont(font1);
        button_ok->setStyleSheet(QString::fromUtf8("background: green;\n"
"color: black;"));

        retranslateUi(DrawWindow);

        QMetaObject::connectSlotsByName(DrawWindow);
    } // setupUi

    void retranslateUi(QDialog *DrawWindow)
    {
        DrawWindow->setWindowTitle(QCoreApplication::translate("DrawWindow", "Dialog", nullptr));
        label_1->setText(QCoreApplication::translate("DrawWindow", "Asiakas:", nullptr));
        button_20e->setText(QCoreApplication::translate("DrawWindow", "20 \342\202\254", nullptr));
        button_40e->setText(QCoreApplication::translate("DrawWindow", "40 \342\202\254", nullptr));
        button_60e->setText(QCoreApplication::translate("DrawWindow", "60 \342\202\254", nullptr));
        button_100e->setText(QCoreApplication::translate("DrawWindow", "100 \342\202\254", nullptr));
        button_200e->setText(QCoreApplication::translate("DrawWindow", "200 \342\202\254", nullptr));
        button_500e->setText(QCoreApplication::translate("DrawWindow", "500 \342\202\254", nullptr));
        button_exit->setText(QCoreApplication::translate("DrawWindow", "Sulje", nullptr));
        label_2->setText(QCoreApplication::translate("DrawWindow", "Tilin saldo:", nullptr));
        label_info->setText(QString());
        label_client_name->setText(QCoreApplication::translate("DrawWindow", "Text", nullptr));
        label_balance->setText(QCoreApplication::translate("DrawWindow", "Text", nullptr));
        label_3->setText(QCoreApplication::translate("DrawWindow", "Valitse nostettava rahasumma:", nullptr));
        button_ok->setText(QCoreApplication::translate("DrawWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawWindow: public Ui_DrawWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWWINDOW_H

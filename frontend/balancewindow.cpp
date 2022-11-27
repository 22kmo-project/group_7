#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

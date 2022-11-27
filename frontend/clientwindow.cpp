#include "clientwindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "ui_clientwindow.h"
#include <myurl.h>
#include <QDebug>

ClientWindow::ClientWindow(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä
    ui->label_id_card->setText(id_card);
    myCardId=id_card;

}

ClientWindow::~ClientWindow()
{
    delete ui;

    delete objectDrawWindow;
    objectDrawWindow=nullptr;

    delete objectDepositWindow;
    objectDepositWindow=nullptr;
}

void ClientWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void ClientWindow::on_button_nayta_saldo_clicked()//ESSI
{
    objectBalanceWindow = new BalanceWindow(webToken,myCardId);
    objectBalanceWindow->setWebToken("Bearer "+response_data);
    objectBalanceWindow->show();

}

void ClientWindow::on_pushButtonTrans_clicked()
{
    TransactionWindow transWindow;
    transWindow.setModal(true);
    transWindow.exec();
}


void ClientWindow::on_button_withdraw_clicked()//Justiina
{
    objectDrawWindow = new DrawWindow(webToken,myCardId);
    objectDrawWindow->show();
}


void ClientWindow::on_button_deposit_clicked()//Justiina
{
    objectDepositWindow = new DepositWindow(webToken,myCardId);
    objectDepositWindow->show();
}

void ClientWindow::on_button_exit_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


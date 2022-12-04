#include "clientwindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "transferwindow.h"
#include "ui_clientwindow.h"
#include <myurl.h>
#include <QDebug>



ClientWindow::ClientWindow(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Etusivu");

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

    delete objectBalanceWindow;
    objectBalanceWindow=nullptr;

}

void ClientWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void ClientWindow::on_button_nayta_saldo_clicked()//ESSI
{

    BalanceWindow balanceWindow(webToken,myCardId);
    balanceWindow.setModal(true);
    balanceWindow.exec();

}

void ClientWindow::on_pushButtonTrans_clicked() //JENNI-MARIA
{
    TransactionWindow transWindow(webToken,myCardId);
    transWindow.setModal(true);
    transWindow.exec();

}


void ClientWindow::on_button_withdraw_clicked()//JUSTIINA
{

    DrawWindow drawWindow(webToken,myCardId);
    drawWindow.setModal(true);
    drawWindow.exec();
}


void ClientWindow::on_button_deposit_clicked()//JUSTIINA
{
    DepositWindow deppositWindow(webToken,myCardId);
    deppositWindow.setModal(true);
    deppositWindow.exec();
}

void ClientWindow::on_button_exit_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


void ClientWindow::on_button_transfer_clicked()//ESSI (backend) ja JUSTIINA (frontend)
{
    TransferWindow transferWindow(webToken,myCardId);
    transferWindow.setModal(true);
    transferWindow.exec();
}


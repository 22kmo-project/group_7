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
    s=0;
    pQTimer = new QTimer;
    myCardId=id_card;

    connect(pQTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    pQTimer->start(1000);

}

ClientWindow::~ClientWindow()
{
    delete ui;

}

void ClientWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

QByteArray ClientWindow::getWebToken()
{
    return webToken;
}

void ClientWindow::on_button_nayta_saldo_clicked()//ESSI
{

    pQTimer->stop();
    objectBalanceWindow = new BalanceWindow(webToken,myCardId, this);
    objectBalanceWindow->setModal(true);
    int a=objectBalanceWindow->exec();
    if(a==0){
        s=0;
        pQTimer->start(1000);
    }
}

void ClientWindow::on_pushButtonTrans_clicked() //JENNI-MARIA
{
    pQTimer->stop();
    objectTransactionWindow = new TransactionWindow (webToken,myCardId, this);
    objectTransactionWindow->setModal(true);
    int a=objectTransactionWindow->exec();
    if(a==0){
        s=0;
        pQTimer->start(1000);
    }
}


void ClientWindow::on_button_withdraw_clicked()//JUSTIINA
{

    pQTimer->stop();
    objectDrawWindow = new DrawWindow(webToken,myCardId, this);
    objectDrawWindow->setModal(true);    
    if(objectDrawWindow->exec()==0){
        s=0;
        pQTimer->start(1000);
    }
}


void ClientWindow::on_button_deposit_clicked()//JUSTIINA
{
    pQTimer->stop();
    objectDepositWindow = new DepositWindow(webToken,myCardId, this);
    objectDepositWindow->setModal(true);
    if(objectDepositWindow->exec()==0){
        s=0;
        pQTimer->start(1000);
    }
}

void ClientWindow::on_button_exit_clicked()
{
    pQTimer->stop();
    close();
}

void ClientWindow::handleTimeout()//ESSI
{
    s++;
    qDebug()<<s;
    if (s==30)
    {
        pQTimer->stop();
        close();

    }

}

void ClientWindow::on_button_transfer_clicked()//ESSI (backend) ja JUSTIINA (frontend)
{
    pQTimer->stop();
    objectTransferWindow = new TransferWindow(webToken,myCardId, this);
    objectTransferWindow->setModal(true);
    if(objectTransferWindow->exec()==0){
        s=0;
        pQTimer->start(1000);
    }
}


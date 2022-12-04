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
    ui->label_id_card->setText(id_card);
    myCardId=id_card;

    connect(pQTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    pQTimer->start(1000);

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

    pQTimer->stop();
    BalanceWindow balanceWindow(webToken,myCardId);
    balanceWindow.setModal(true);
    balanceWindow.exec();
}

void ClientWindow::on_pushButtonTrans_clicked() //JENNI-MARIA
{
    pQTimer->stop();
    TransactionWindow transWindow(webToken,myCardId);
    transWindow.setModal(true);
    transWindow.exec();

}


void ClientWindow::on_button_withdraw_clicked()//JUSTIINA
{

    pQTimer->stop();
    DrawWindow drawwWindow(webToken,myCardId);
    drawwWindow.setModal(true);
    drawwWindow.exec();
}


void ClientWindow::on_button_deposit_clicked()//JUSTIINA
{
    pQTimer->stop();
    DepositWindow deppositWindow(webToken,myCardId);
    deppositWindow.setModal(true);
    deppositWindow.exec();
}

void ClientWindow::on_button_exit_clicked()
{
    pQTimer->stop();
    //qDebug()<<s;
    //close();
    QApplication::closeAllWindows();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void ClientWindow::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==10)
    {
        pQTimer->stop();
        //close();
        QApplication::closeAllWindows();
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }

}

void ClientWindow::on_button_transfer_clicked()//ESSI (backend) ja JUSTIINA (frontend)
{
    pQTimer->stop();
    TransferWindow transferWindow(webToken,myCardId);
    transferWindow.setModal(true);
    transferWindow.exec();    
}


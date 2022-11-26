#include "clientwindow.h"
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


void ClientWindow::on_button_nayta_tilitapahtumat_clicked()
{

}


void ClientWindow::on_button_nosta_rahaa_clicked()
{
    objectDrawWindow = new DrawWindow(webToken,myCardId);
    objectDrawWindow->setWebToken("Bearer "+response_data);
    objectDrawWindow->show();
}


void ClientWindow::on_button_siirra_rahaa_clicked()
{

}

void ClientWindow::on_button_lopeta_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


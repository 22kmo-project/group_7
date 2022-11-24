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
}

/*
const QString &ClientWindow::getWebToken() const
{
    return webToken;
}
*/
void ClientWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}


void ClientWindow::on_button_nayta_saldo_clicked()
{
    /*
    QString wb=this->getWebToken();
    qDebug()<<wb;
    */
}


void ClientWindow::on_button_nayta_tilitapahtumat_clicked()
{

}


void ClientWindow::on_button_nosta_rahaa_clicked()
{
    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    balanceManager = new QNetworkAccessManager(this);

    connect(balanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));

    reply = balanceManager->get(request);
}


void ClientWindow::on_button_siirra_rahaa_clicked()
{


}

void ClientWindow::balanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
}


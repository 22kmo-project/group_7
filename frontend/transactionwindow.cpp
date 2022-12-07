#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>


TransactionWindow::TransactionWindow(QByteArray wt, QString id_card, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilitapahtumat");

    s=0;
    transactionTimer = new QTimer;
    connect(transactionTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    transactionTimer->start(1000);

    webToken=wt;
    myCardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/clienttransaction/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    transManager = new QNetworkAccessManager(this);
    connect(transManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransSlot(QNetworkReply*)));
    reply = transManager->get(request);
}
TransactionWindow::~TransactionWindow()
{
    delete ui;
        ui=nullptr;
}

void TransactionWindow::TransSlot (QNetworkReply *reply)
{

    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transaction1;
    QString transaction2;
    QString transaction3;
    QString transaction4;

    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       transaction1+=QString::number(json_obj["summa"].toInt())+"\n\n";
            ui->label_transact->setText(transaction1);
       transaction2+=json_obj["asiakkaan nimi"].toString()+"\n\n";
            ui->label_transact_2->setText(transaction2);
       transaction3+=json_obj["päivämäärä"].toString()+"\n\n";
            ui->label_transact_3->setText(transaction3);
       transaction4+=json_obj["tapahtuman laji"].toString()+"\n\n";
            ui->label_transact_4->setText(transaction4);

    }

        ui->label_2_client_2->setText(transaction2);

        reply->deleteLater();
        transManager->deleteLater();

        QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
        QNetworkRequest request((site_url));
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(webToken));
        //WEBTOKEN LOPPU
        transBalanceManager = new QNetworkAccessManager(this);
        connect(transBalanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransBalanceSlot(QNetworkReply*)));
        reply = transBalanceManager->get(request);
}

void TransactionWindow::TransBalanceSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    balance=QString::number(json_obj["balance"].toDouble());
    ui->label_2_balance->setText(balance);

    reply->deleteLater();
    transBalanceManager->deleteLater();
}

void TransactionWindow::on_pushButtonClose_clicked()
{
    close();
}
void TransactionWindow::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==10)
    {
        transactionTimer->stop();
         close();
    }

}

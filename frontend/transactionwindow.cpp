#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include <myurl.h>
#include <QDebug>
#include <QTimer>
#include <windows.h>

TransactionWindow::TransactionWindow(QByteArray wt, QString id_card, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilitapahtumat");

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(myfunction()));
    timer->start(1000);

    auto webToken=wt;
    auto myCardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
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
    QString transaction;

    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       transaction+="transaction_type:"+json_obj["tapahtuman laji"].toString()+","
       " clientName:"+json_obj["asiakkaan nimi"].toString()+","
       " transaction_date:"+json_obj["päivämäärä"].toString()+","
       " amount:"+QString::number(json_obj["summa"].toInt())+","
       " id_client:"+json_obj["ID"].toString()+"\n";
    }

    transaction=json_doc["client_name"].toString();
        ui->label_transact->setText(transaction);

    clientName=json_doc["client_name"].toString();
        ui->label_2_client_2->setText(clientName);

    balance=QString::number(json_doc["balance"].toDouble());
        ui->label_2_balance->setText(balance);

    reply->deleteLater();
    transManager->deleteLater();

}

void TransactionWindow::on_pushButtonClose_clicked()
{
    close();
}

/*void TransactionWindow::myfunction()
{
    int i=30;
    while(i<=30)
    {
        qDebug() << "" <<i;
        --i;
        Sleep(1000);
        system("cls");

    if(i==0)
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

    }
}*/





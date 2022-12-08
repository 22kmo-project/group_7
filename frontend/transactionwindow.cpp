#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>
#include <QStandardItemModel>


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
    QJsonObject json_obj = json_doc.object();
    QJsonArray json_array = json_doc.array();

    QStandardItemModel *model = new QStandardItemModel(0,3);
    int row = 0;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Tapahtuma"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Päivämäärä"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Summa"));

    foreach (const QJsonValue &value, json_array) {
        QJsonObject itemObj = value.toObject();
        QStandardItem *trType = new QStandardItem(itemObj.value("tapahtuman laji").toString());
        model->setItem(row, 0, trType);
        QStandardItem *trDate = new QStandardItem(itemObj.value("päivämäärä").toString());
        model->setItem(row, 1, trDate);
        QStandardItem *trAmount = new QStandardItem(QString::number(itemObj.value("summa").toInt()));
        model->setItem(row, 2, trAmount);
        row++;
    }

    ui->tableView->setModel(model);

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

    clientName=json_obj["client_name"].toString();
    balance=QString::number(json_obj["balance"].toDouble());

    ui->label_client_name->setText(clientName);
    ui->label_balance->setText(balance);

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



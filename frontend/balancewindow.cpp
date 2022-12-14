#include "balancewindow.h"
#include "ui_balancewindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>
#include <QStandardItemModel>

BalanceWindow::BalanceWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilin käyttövara");

    s=0;
    balanceTimer = new QTimer;
    connect(balanceTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    balanceTimer->start(1000);

    webToken=wt;
    myCardId=id_card;

    QString site_url=MyURL::getBaseUrl()+"/clientfivetransaction/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));
    reply = balanceManager->get(request);
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::on_Button_close_clicked()
{
    balanceTimer->stop();
    close();
}

void BalanceWindow::balanceSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QJsonArray json_array = json_doc.array();

    QStandardItemModel *model = new QStandardItemModel(0,3);
    row = 0;
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
    balanceManager->deleteLater();

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    clientManager = new QNetworkAccessManager(this);
    connect(clientManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(clientSlot(QNetworkReply*)));
    reply = clientManager->get(request);

}

void BalanceWindow::clientSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();


    QString clientName=json_obj["client_name"].toString();
    QString balance=QString::number(json_obj["balance"].toDouble());

    ui->label_client_name->setText(clientName);
    ui->label_balance->setText(balance);

    reply->deleteLater();
    clientManager->deleteLater();

}

void BalanceWindow::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==10)
    {
        balanceTimer->stop();
         close();
    }

}


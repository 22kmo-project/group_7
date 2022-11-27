#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include <transactionwindow.h>
#include <myurl.h>
#include <QDebug>

TransactionWindow::TransactionWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);

    /*QString site_url=MyURL::getBaseUrl()+"/accountclient/";
    QNetworkRequest request((site_url));
    transManager = new QNetworkAccessManager(this);
    connect(transManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(TransSlot(QNetworkReply*)));
    reply = transManager->get(request);*/
}

TransactionWindow::~TransactionWindow()
{
    delete ui;
    ui=nullptr;
}

void TransactionWindow::TransSlot (QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    id_transaction=json_obj["transaction_id"].toInt();
    id_account=json_obj["account_id"].toInt();
    id_card=json_obj["card_id"].toInt();
    amount=json_obj["amount"].toDouble();
    transaction_date=json_obj["date_of_transaction"].toString();
    transaction_type=json_obj["type_of_transaction"].toString();
}

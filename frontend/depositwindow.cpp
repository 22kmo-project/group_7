#include "depositwindow.h"
#include "ui_depositwindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>

DepositWindow::DepositWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Talleta varoja");

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(myfunction()));
    timer->start(1000);

    webToken=wt;
    myCardId=id_card;
    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    depositManager = new QNetworkAccessManager(this);
    connect(depositManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(depositSlot(QNetworkReply*)));
    reply = depositManager->get(request);
}

DepositWindow::~DepositWindow()
{
    delete ui;
}

void DepositWindow::depositSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    myClientId=QString::number(json_obj["id_client"].toInt());
    myAccountId=QString::number(json_obj["id_account"].toInt());

    clientName=json_obj["client_name"].toString();
    balance=QString::number(json_obj["balance"].toDouble());
    balanceValue=QString(balance).toDouble();

    ui->label_client_name->setText(clientName);
    ui->label_balance->setText(balance);

    reply->deleteLater();
    depositManager->deleteLater();

}

void DepositWindow::updateBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    updateManager->deleteLater();
    this->close();

}

void DepositWindow::postTransactionSlot(QNetworkReply *replyPost)
{
    response_data=replyPost->readAll();
    qDebug()<<response_data;
    replyPost->deleteLater();
    postManager->deleteLater();
    this->close();
}

void DepositWindow::on_button_ok_clicked()
{
    //Update account table
    amountValue=QString(amount).toDouble();
    balanceValue=balanceValue+amountValue;
    balance=QString::number(balanceValue);

    QJsonObject jsonObjUpdate;
    jsonObjUpdate.insert("id_client",myClientId);
    jsonObjUpdate.insert("balance",balance);

    QString site_url=MyURL::getBaseUrl()+"/account/"+myAccountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU

    updateManager = new QNetworkAccessManager(this);
    connect(updateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(updateBalanceSlot(QNetworkReply*)));

    reply = updateManager->put(request, QJsonDocument(jsonObjUpdate).toJson());

    //Add new transaction to transactin table
    QJsonObject jsonObjPost;
    jsonObjPost.insert("id_account",myAccountId);
    jsonObjPost.insert("id_card",myCardId);
    jsonObjPost.insert("transaction_date",QDate::currentDate().toString(Qt::ISODate));
    jsonObjPost.insert("transaction","Pano");
    jsonObjPost.insert("amount",amount);
    QString site_urlPost=MyURL::getBaseUrl()+"/transaction/";
    QNetworkRequest requestPost((site_urlPost));
    requestPost.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    requestPost.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU

    postManager=new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(postTransactionSlot(QNetworkReply*)));

    replyPost=postManager->post(requestPost, QJsonDocument(jsonObjPost).toJson());
}

void DepositWindow::on_button_20e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="20";
}


void DepositWindow::on_button_40e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="40";
}


void DepositWindow::on_button_60e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="60";
}


void DepositWindow::on_button_100e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="100";
}


void DepositWindow::on_button_200e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="200";
}


void DepositWindow::on_button_300e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="300";
}


void DepositWindow::on_button_400e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="400";
}


void DepositWindow::on_button_500e_clicked()
{
    ui->label_info->setText("Varmista talletus painamalla OK tai peruuta painamalla Sulje.");
    amount="500";
}



void DepositWindow::on_button_exit_clicked()
{
    close();
}



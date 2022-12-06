#include "drawwindow.h"
#include "ui_drawwindow.h"
#include <myurl.h>
#include <QDebug>
#include <QTimer>
#include <windows.h>

DrawWindow::DrawWindow(QByteArray wt,QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Nosta varoja");

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
    drawManager = new QNetworkAccessManager(this);
    connect(drawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(drawSlot(QNetworkReply*)));
    reply = drawManager->get(request);

}

DrawWindow::~DrawWindow()
{
    delete ui;
}

void DrawWindow::drawSlot(QNetworkReply *reply)
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
    drawManager->deleteLater();
}

void DrawWindow::checkMoney(double bal, double am)
{
    if(bal<am){
        ui->label_info->setText("Tilillä ei ole tarpeeksi rahaa,\nvalitse uusi summa tai paina Sulje.");
    }
    else{
        bal=bal-am;
        balance=QString::number(bal);
        ui->label_info->setText("Varmista nosto painamalla OK.\nTilillä on noston jälkeen "+balance+" euroa.");
    }
}

void DrawWindow::on_button_20e_clicked()
{
    checkMoney(balanceValue,20);
    amount="-20";
}


void DrawWindow::on_button_40e_clicked()
{
    checkMoney(balanceValue,40);
    amount="-40";
}


void DrawWindow::on_button_60e_clicked()
{
    checkMoney(balanceValue,60);
    amount="-60";
}


void DrawWindow::on_button_100e_clicked()
{
    checkMoney(balanceValue,100);
    amount="-100";
}


void DrawWindow::on_button_200e_clicked()
{
    checkMoney(balanceValue,200);
    amount="-200";
}


void DrawWindow::on_button_500e_clicked()
{
    checkMoney(balanceValue,500);
    amount="-500";
}

void DrawWindow::on_button_ok_clicked()
{
    //Update account table
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
    jsonObjPost.insert("transaction","Nosto");
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

void DrawWindow::on_button_exit_clicked()
{
    close();
}

void DrawWindow::updateBalanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    updateManager->deleteLater();
    this->close();
}

void DrawWindow::postTransactionSlot(QNetworkReply *replyPost)
{
    response_data=replyPost->readAll();
    qDebug()<<response_data;
    replyPost->deleteLater();
    postManager->deleteLater();
    this->close();
}






#include "balancewindow.h"
#include "ui_balancewindow.h"
#include <myurl.h>
#include <QDebug>
#include <windows.h>
#include <QTimer>

BalanceWindow::BalanceWindow(QByteArray wt, QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilin käyttövara");

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this,SLOT(myfunction()));
    timer->start(1000);

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

/*void BalanceWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}*/

void BalanceWindow::on_Button_close_clicked()
{
    close();
}

/*void BalanceWindow::myFunction()
{
    int i=30;
    while(i<=30)
    {
        qDebug() << "" <<i;
        --i;
        Sleep(1000);
        system("cls");

    if(i==0)
    break;

        //qApp->quit();
        //QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}*/

void BalanceWindow::balanceSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    //tietokannasta haku onnistuu!
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString transaction;
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       transaction+="Tapahtuman laji:"+json_obj["tapahtuman laji"].toString()+", päivämäärä:"+json_obj["päivämäärä"].toString()+", summa:"+QString::number(json_obj["summa"].toInt())+"\n";
    }
    //QJsonObject json_obj = json_doc.object();
    //QString clientName=json_obj["asiakkaan nimi"].toString();
    //myAccountId=QString::number(json_obj["id_account"].toInt());
    //clientName=json_obj["asiakkaan nimi"].toString();
    //balance=QString::number(json_obj["balance"].toDouble());
    //balanceValue=QString(balance).toDouble();

    //ui->label_client_name->setText(clientName);
    ui->label_transactions->setText(transaction);


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


#include "drawwindow.h"
#include "ui_drawwindow.h"
#include <myurl.h>
#include <QDebug>

DrawWindow::DrawWindow(QByteArray wt,QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä
    webToken=wt;

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+id_card;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    drawManager = new QNetworkAccessManager(this);
    connect(drawManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(drawSlot(QNetworkReply*)));
    reply = drawManager->get(request);

    //reply->deleteLater();
    //drawManager->deleteLater();
}

DrawWindow::~DrawWindow()
{
    delete ui;
}

void DrawWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void DrawWindow::drawSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    clientName=json_obj["client_name"].toString();
    balance=QString::number(json_obj["balance"].toDouble());
    balanceValue = QString(balance).toDouble();

    ui->label_client_name->setText(clientName);
    ui->label_balance->setText(balance);
}

void DrawWindow::checkMoney(double bal, double am)
{
    if(bal<am){
        ui->label_info->setText("Tilillä ei ole tarpeeksi rahaa, valitse uusi summa tai paina Sulje.");
    }
    else{
        bal=bal-am;
        balance=QString::number(bal);
        ui->label_info->setText("Ole hyvä ja ota rahat, tilillä on noston jälkeen "+balance+" euroa.");
    }
}

void DrawWindow::on_button_20e_clicked()
{
    checkMoney(balanceValue,20);
}


void DrawWindow::on_button_40e_clicked()
{
    checkMoney(balanceValue,40);
}


void DrawWindow::on_button_60e_clicked()
{
    checkMoney(balanceValue,60);
}


void DrawWindow::on_button_100e_clicked()
{
    checkMoney(balanceValue,100);
}


void DrawWindow::on_button_200e_clicked()
{
    checkMoney(balanceValue,200);
}


void DrawWindow::on_button_500e_clicked()
{
    checkMoney(balanceValue,500);
}


void DrawWindow::on_button_exit_clicked()
{
    close();
}


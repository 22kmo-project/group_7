#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_login_clicked()
{
    id_card=ui->text_id_card->text();
    pin=ui->text_pin->text();

    QJsonObject jsonObj;
    jsonObj.insert("id_card", id_card);
    jsonObj.insert("pin", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());

}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

   /* if (id_card=="1234"){
    objectClientWindow = new ClientWindow(id_card);
    objectClientWindow->show();
    }
    else {
        ui->text_id_card->clear();
        ui->text_pin->clear();
        ui->label_info->setText("Kortinnumero ja pin-koodi eivät täsmää!");
    }*/
}


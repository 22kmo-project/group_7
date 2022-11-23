#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä

}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectClientWindow;
    objectClientWindow=nullptr;
}


void MainWindow::on_button_login_clicked()
{
    id_card=ui->text_id_card->text();
    pin=ui->text_pin->text();

    QJsonObject jsonObj;
    jsonObj.insert("id_card", id_card);
    jsonObj.insert("pin", pin);

    QString site_url=MyURL::getBaseUrl()+"/login";
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


    int test=QString::compare(response_data, "false");
    qDebug()<<test;

    if(response_data.length()==0){
        ui->text_id_card->clear();
        ui->text_pin->clear();
        ui->label_info->setText("Palvelin ei vastaa!");
    }
    else{

    if(QString::compare(response_data,"-4078")==0){
        ui->text_id_card->clear();
        ui->text_pin->clear();
        ui->label_info->setText("Virhe tietokantayhteydessä!");
    }

    else{

        if(test==0){
            ui->text_id_card->clear();
            ui->text_pin->clear();
            ui->label_info->setText("Kortinnumero ja pin-koodi eivät täsmää!");
        }

        else {
            objectClientWindow = new ClientWindow(id_card);
            objectClientWindow->setWebToken(response_data);
            objectClientWindow->show();
        }
    }
    }



}


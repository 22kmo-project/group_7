#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QWidget::showMaximized(); //Näytetään ikkuna kokonäytöllä
    ui->label_info->setText("Anna kortin numero ja paina ok");
    ok_count=1;
    this->setWindowTitle("Pankkiautomaatti");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectClientWindow;
    objectClientWindow=nullptr;
}

void MainWindow::on_btn_ok_clicked()
{
    if(ok_count == 1) {
        id_card=ui->lineEdit->text();
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        ui->label_info->setText("Anna pin-koodi ja paina ok");
        ok_count++;
    } else {
        pin=ui->lineEdit->text();
        QJsonObject jsonObj;
        jsonObj.insert("id_card", id_card);
        jsonObj.insert("pin", pin);

        QString site_url=MyURL::getBaseUrl()+"/login";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

        reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
    }
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    int test=QString::compare(response_data, "false");
    qDebug()<<test;

    if(response_data.length()==0){
        ui->lineEdit->clear();
        ui->label_info->setText("Palvelin ei vastaa!");
    }
    else{

    if(QString::compare(response_data,"-4078")==0){
        ui->lineEdit->clear();
        ui->label_info->setText("Virhe tietokantayhteydessä!");
    }

    else{

        if(test==0){
            ui->lineEdit->clear();
            ui->label_info->setText("Kortin numero ja pin-koodi eivät täsmää!");
        }

        else {
            objectClientWindow = new ClientWindow(id_card);
            objectClientWindow->setWebToken("Bearer "+response_data);
            objectClientWindow->show();
        }
    }
    }

    reply->deleteLater();
    loginManager->deleteLater();

}

void MainWindow::on_btn_clear_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::on_btn_close_clicked()
{
    QApplication::closeAllWindows();
}

void MainWindow::on_btn_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}

void MainWindow::on_btn_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}

void MainWindow::on_btn_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}


void MainWindow::on_btn_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}

void MainWindow::on_btn_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}

void MainWindow::on_btn_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}

void MainWindow::on_btn_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}

void MainWindow::on_btn_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}

void MainWindow::on_btn_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

void MainWindow::on_btn_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}

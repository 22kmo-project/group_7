#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Pankkiautomaatti");
    //QWidget::showMaximized(); //Näytetään ikkuna kokonäytöllä
    pin_count=0;
    s=0;
    ok_count=0;
    check=false;
    Timer = new QTimer;
    connect(Timer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    ui->label_info->setText("Anna kortin numero ja paina OK");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_ok_clicked()
{
    ok_count++;
    if(ok_count == 1) {
        id_card=ui->lineEdit->text();
        ui->lineEdit->clear();
        ui->lineEdit->setEchoMode(QLineEdit::Password);

        ui->label_info->setText("Anna pin-koodi ja paina OK");
        ok_count++;
        check=false;
    }
    else {
        pin=ui->lineEdit->text();
        QJsonObject jsonObj;
        jsonObj.insert("id_card", id_card);
        jsonObj.insert("pin", pin);

        ui->lineEdit->clear();

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
        check=true;
        Timer->start(1000);
    }
    else{

    if(QString::compare(response_data,"-4078")==0){
        ui->lineEdit->clear();
        ui->label_info->setText("Virhe tietokantayhteydessä!");
        check=true;
        Timer->start(1000);
    }

    else{

        if(test==0){
            ui->lineEdit->clear();
            ui->label_info->setText("Kortin numero ja pin-koodi\n"
                                    "eivät täsmää tai kortti on lukittu.\n"
                                    "Palaat kohta alkuun.");
            pin_count++;
            Timer->start(1000);
        }

        else {
            ui->lineEdit->clear();
            ui->lineEdit->setEchoMode(QLineEdit::Normal);
            ok_count=0;
            ui->label_info->setText("Anna kortin numero ja paina OK");
            objectClientWindow = new ClientWindow(id_card, this);
            objectClientWindow->setWebToken("Bearer "+response_data);
            objectClientWindow->setModal(true);
            if(objectClientWindow->exec()==0){
                pin_count=0;
                s=0;
                id_card="";
                pin="";
                objectClientWindow->setWebToken("");

            }
        }
    }
    }

    reply->deleteLater();
    loginManager->deleteLater();


}

void MainWindow::lockedSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    int test=QString::compare(response_data, "false");
    qDebug()<<test;
}

void MainWindow::on_btn_clear_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_btn_close_clicked()
{
    QApplication::closeAllWindows();
    qApp->quit();
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

void MainWindow::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==10 && pin_count<3 && check==false)
    {
        Timer->stop();
        s=0;
        ui->lineEdit->clear();

        ui->label_info->setText("Anna pin-koodi ja paina ok");
        ok_count=1;
    }

    else if(s==10 && pin_count==3 && check==false){
        Timer->stop();
        s=0;
        ui->lineEdit->clear();
        ui->label_info->setText("Pin-koodi laitettu\n kolme kertaa väärin,\n kortti lukittu!");
        QJsonObject jsonObj;
        ui->lineEdit->clear();

        QString site_url_lock=MyURL::getBaseUrl()+"/cardlocked/"+id_card;
        QNetworkRequest request((site_url_lock));

        lockManager = new QNetworkAccessManager(this);
        connect(lockManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(lockedSlot(QNetworkReply*)));

        reply = lockManager->put(request, QJsonDocument().toJson());
        pin_count=0;
        check=true;
        Timer->start(1000);
    }
    else if(s==10 && pin_count<3 && check==true){
         Timer->stop();
         pin_count=0;
         s=0;
         id_card="";
         pin="";
         ok_count=0;
         ui->lineEdit->setEchoMode(QLineEdit::Normal);
         ui->label_info->setText("Anna kortin numero ja paina ok");

    }
}

#include "transferwindow.h"
#include "ui_transferwindow.h"

TransferWindow::TransferWindow(QByteArray wt,QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tilisiirto");

    webToken=wt;
    myCardId=id_card;

    s=0;
    transferTimer = new QTimer;
    connect(transferTimer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    transferTimer->start(1000);

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU

    getIdManager = new QNetworkAccessManager(this);
    connect(getIdManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getIdSlot(QNetworkReply*)));
    reply=getIdManager->get(request);
    ui->label_info->setText("Anna vastaanottajan tilinumero\n"
                            "ja paina OK");
    ok_count=1;

}

TransferWindow::~TransferWindow()
{
    delete ui;
}

void TransferWindow::on_btn_ok_clicked()
{
    switch(ok_count) {
    case 1:
        transferTimer->stop();
        s=0;
        myAccountIdReceiver=ui->lineEdit->text();
        myAccountIdReceiverInt=myAccountIdReceiver.toInt();
        ui->lineEdit->clear();
        ui->label_info->setText("Anna siirrettävä rahasumma\n"
                                "ja paina OK");
        ok_count++;
        transferTimer->start(1000);
        break;

    case 2:
        transferTimer->stop();
        s=0;
        amount=ui->lineEdit->text();
        amountValue=amount.toDouble();
        ui->lineEdit->clear();
        ui->label_info->setText("Vastaanottajan tilinumero: "
                                +myAccountIdReceiver+"\nSiirretävä summa: "
                                +amount+" €"+"\n\nVahvista siirto painamalla OK\n"
                                        "tai keskeytä painamalla Sulje");
        ok_count++;
        transferTimer->start(1000);
        break;

    default:
        transferTimer->stop();
        s=0;
        //Get account info from the database and transfer the money
        QJsonObject jsonObjTransfer;
        jsonObjTransfer.insert("id_account1", myAccountId);
        jsonObjTransfer.insert("id_account2", myAccountIdReceiverInt);
        jsonObjTransfer.insert("amount", amountValue);

        //Transfer the money
        QString site_url=MyURL::getBaseUrl()+"/accounttransfer/";
        QNetworkRequest requestTransfer((site_url));
        requestTransfer.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN ALKU
        requestTransfer.setRawHeader(QByteArray("Authorization"),(webToken));
        //WEBTOKEN LOPPU

        transferManager = new QNetworkAccessManager(this);
        connect(transferManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transferSlot(QNetworkReply*)));
        replyTransfer=transferManager->post(requestTransfer, QJsonDocument(jsonObjTransfer).toJson());
    }
}


void TransferWindow::getIdSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    myAccountId=QString::number(json_obj["id_account"].toInt());
    reply->deleteLater();
    getIdManager->deleteLater();
}

void TransferWindow::transferSlot(QNetworkReply *replyTransfer)
{
    response_data=replyTransfer->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    QString transferCheck=QString::number(json_obj["affectedRows"].toInt());
    int transferCheckInt=transferCheck.toInt();

    if(transferCheckInt==0) {
        ui->lineEdit->clear();
        ui->label_info->setText("Jokin meni vikaan. Tarkista\n"
                                "vastaanottajan tilinumero\n"
                                "ja siirrettävä summa\n"
                                "\n"
                                "Palaa edelliseen valikkoon\n"
                                "painamalla Sulje\n"
                                "ja yritä uudelleen.");
        transferTimer->start(1000);
    }

    else{
    ui->label_info->clear();
    ui->label_info->setText("Tilisiirto onnistui.\n"
                            "Palaa edelliseen valikkoon\n"
                            "painamalla Sulje.");
    transferTimer->start(1000);
    }

    replyTransfer->deleteLater();
    transferManager->deleteLater();
    //this->close();
}

void TransferWindow::handleTimeout()
{
    s++;
    qDebug()<<s;
    if (s==10)
    {
        transferTimer->stop();
         close();
    }

}

void TransferWindow::on_btn_clear_clicked()
{
    transferTimer->stop();
    ui->lineEdit->clear();

}

void TransferWindow::on_btn_close_clicked()
{
    transferTimer->stop();
    close();
}

void TransferWindow::on_btn_1_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_2_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_3_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_4_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_5_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_6_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_7_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_8_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_9_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
    transferTimer->start(1000);
}

void TransferWindow::on_btn_0_clicked()
{
    transferTimer->stop();
    s=0;
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
    transferTimer->start(1000);
}




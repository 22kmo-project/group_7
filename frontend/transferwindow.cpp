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

    QString site_url=MyURL::getBaseUrl()+"/accountclient/"+myCardId;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU

    getIdManager = new QNetworkAccessManager(this);
    connect(getIdManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getIdSlot(QNetworkReply*)));
    reply=getIdManager->get(request);
    ui->label_info->setText("Anna vastaanottajan tilinumero ja paina OK");
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
        myAccountIdReceiver=ui->lineEdit->text();
        myAccountIdReceiverInt=myAccountIdReceiver.toInt();
        ui->lineEdit->clear();
        ui->label_info->setText("Anna siirrettävä rahasumma ja paina OK");
        ok_count++;
        break;

    case 2:
        amount=ui->lineEdit->text();
        amountValue=amount.toDouble();
        ui->lineEdit->clear();
        ui->label_info->setText("Vastaanottajan tilinumero: "
                                +myAccountIdReceiver+"\nSiireetävä summa: "
                                +amount+"\nVahvista siirto painamalla OK "
                                        "\ntai keskeytä painamalla Sulje");
        ok_count++;
        break;

    default:
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
        ui->label_info->setText("Jokin meni vikaan. Tarkista vastaanottajan\n"
                                "tilinumero ja siirrettävä summa\n"
                                "\n"
                                "Palaa edelliseen valikkoon painamalla Sulje \n"
                                "ja yritä uudelleen.");
    } else {
        ui->label_info->setText("Tilisiirto onnistui.\n"
                                "Palaa edelliseen valikkoon painamalla Sulje");
    }
    replyTransfer->deleteLater();
    transferManager->deleteLater();
    //this->close();
}

void TransferWindow::on_btn_clear_clicked()
{
    ui->lineEdit->clear();
}

void TransferWindow::on_btn_close_clicked()
{
    close();
}

void TransferWindow::on_btn_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
}

void TransferWindow::on_btn_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
}

void TransferWindow::on_btn_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
}

void TransferWindow::on_btn_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
}

void TransferWindow::on_btn_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
}

void TransferWindow::on_btn_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
}

void TransferWindow::on_btn_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
}

void TransferWindow::on_btn_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
}

void TransferWindow::on_btn_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
}

void TransferWindow::on_btn_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "0");
}




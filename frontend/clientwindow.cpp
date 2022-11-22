#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();//Näytetään ikkuna kokonäytöllä
    ui->label_id_card->setText(id_card);

}

ClientWindow::~ClientWindow()
{
    delete ui;
}

const QString &ClientWindow::getWebToken() const
{
    return webToken;
}

void ClientWindow::setWebToken(const QString &newWebToken)
{
    webToken = newWebToken;
}

void ClientWindow::on_button_nayta_saldo_clicked()
{

}


void ClientWindow::on_button_nayta_tilitapahtumat_clicked()
{

}


void ClientWindow::on_button_nosta_rahaa_clicked()
{

}


void ClientWindow::on_button_siirra_rahaa_clicked()
{

}


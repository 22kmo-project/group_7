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

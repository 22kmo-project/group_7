#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionWindow(QWidget *parent = nullptr);
    ~TransactionWindow();
private slots:
    void TransSlot(QNetworkReply *reply);
private:
    Ui::TransactionWindow*ui;
    QNetworkAccessManager *transManager;
    QNetworkReply *reply;
    //QByteArray webToken;
    QByteArray response_data;
    QString transaction_date;
    QString transaction_type;
    int id_transaction;
    int id_account;
    int id_card;
    float amount;

};

#endif // TRANSACTIONWINDOW_H

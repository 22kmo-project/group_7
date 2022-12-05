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
    explicit TransactionWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~TransactionWindow();
    //const QString &getWebToken() const;
private slots:
    void TransSlot(QNetworkReply *reply);
    void on_pushButtonClose_clicked();
    //void myfunction();


private:
    Ui::TransactionWindow*ui;
    QNetworkAccessManager *transManager;
    QNetworkAccessManager *clientManager;
    QNetworkAccessManager *balanceManager;
    QNetworkReply *reply;
    QByteArray webToken;
    QByteArray response_data;
    QString transaction_date;
    QString transaction_type;
    int id_transaction;
    int id_account;
    int id_client;
    int id_card;
    float amount;
    QString clientName;
    QString balance;
    double balanceValue;
    QString myClientId;
    QTimer *timer;

};

#endif // TRANSACTIONWINDOW_H

#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "drawwindow.h"
#include "balancewindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "transferwindow.h"
#include <QTimer>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QString id_card, QWidget *parent = nullptr);
    ~ClientWindow();

    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_button_nayta_saldo_clicked();
    void on_pushButtonTrans_clicked();
    void on_button_withdraw_clicked();
    void on_button_deposit_clicked();
    void on_button_exit_clicked();
    void handleTimeout();

    void on_button_transfer_clicked();

private:
    Ui::ClientWindow *ui;
    QByteArray webToken;
    QString myCardId;
    DrawWindow *objectDrawWindow;
    QByteArray response_data;
    BalanceWindow *objectBalanceWindow;
    TransactionWindow *objectTransactionWindow;
    DepositWindow *objectDepositWindow;
    TransferWindow *objectTransferWindow;
    QTimer * pQTimer;
    short s;
};

#endif // CLIENTWINDOW_H

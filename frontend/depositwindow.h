#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DepositWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~DepositWindow();

private slots:
    void depositSlot (QNetworkReply *reply);
    void updateBalanceSlot (QNetworkReply *reply);
    void postTransactionSlot (QNetworkReply *reply);

    void on_button_ok_clicked();

    void on_button_exit_clicked();

    void on_button_20e_clicked();

    void on_button_40e_clicked();

    void on_button_60e_clicked();

    void on_button_100e_clicked();

    void on_button_200e_clicked();

    void on_button_300e_clicked();

    void on_button_400e_clicked();

    void on_button_500e_clicked();

private:
    Ui::DepositWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QString myClientId;
    QString myAccountId;

    QNetworkReply *reply;
    QNetworkReply *replyPost;
    QByteArray response_data;
    QString clientName;
    QString balance;
    QString amount;
    double amountValue;
    double balanceValue;
    QNetworkAccessManager *depositManager;
    QNetworkAccessManager *updateManager;
    QNetworkAccessManager *postManager;

};

#endif // DEPOSITWINDOW_H

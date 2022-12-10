#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <myurl.h>
#include <QStyle>
#include <QDesktopWidget>

namespace Ui {
class TransferWindow;
}

class TransferWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransferWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~TransferWindow();

private slots:
    void getIdSlot(QNetworkReply *reply);
    void transferSlot (QNetworkReply *reply);
    void handleTimeout();

    void on_btn_ok_clicked();
    void on_btn_clear_clicked();
    void on_btn_close_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_0_clicked();

private:
    Ui::TransferWindow *ui;
    QByteArray webToken;
    QByteArray response_data;
    QString myCardId;
    QString myAccountId;
    QString myAccountIdReceiver;
    QString amount;
    QString id_account;
    QNetworkReply *reply;
    QNetworkReply *replyTransfer;
    QNetworkAccessManager *getIdManager;
    QNetworkAccessManager *transferManager;
    QTimer *transferTimer;
    double amountValue;
    int myAccountIdReceiverInt;
    int ok_count;
    short s;
};

#endif // TRANSFERWINDOW_H

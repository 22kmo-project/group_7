#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BalanceWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~BalanceWindow();
    const QString &getWebToken() const;

private slots:
    void on_Button_close_clicked();
    void balanceSlot (QNetworkReply *reply);
    void clientSlot (QNetworkReply *reply);
    void handleTimeout();

private:
    Ui::BalanceWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QNetworkAccessManager *balanceManager;
    QNetworkAccessManager *clientManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString clientName;
    QString balance;
    double balanceValue;
    QTimer *balanceTimer;
    short s;
    int row;
};

#endif // BALANCEWINDOW_H

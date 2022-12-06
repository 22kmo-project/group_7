#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDate>

namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT


public:
    explicit DrawWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~DrawWindow();
    //const QString &getWebToken() const;

private slots:
    void drawSlot (QNetworkReply *reply);
    void updateBalanceSlot (QNetworkReply *reply);
    void postTransactionSlot (QNetworkReply *reply);
    void on_button_20e_clicked();
    void on_button_40e_clicked();
    void on_button_60e_clicked();
    void on_button_100e_clicked();
    void on_button_200e_clicked();
    void on_button_500e_clicked();
    void on_button_ok_clicked();
    void on_button_exit_clicked();
    void checkMoney(double bal, double am);
    void handleTimeout();

private:
    Ui::DrawWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QString myClientId;
    QString myAccountId;
    QTimer *drawTimer;
    short s;
    QNetworkReply *reply;
    QNetworkReply *replyPost;
    QByteArray response_data;
    QString clientName;
    QString balance;
    QString amount;
    double balanceValue;
    QNetworkAccessManager *drawManager;
    QNetworkAccessManager *updateManager;
    QNetworkAccessManager *postManager;
};

#endif // DRAWWINDOW_H

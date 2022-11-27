#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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
    void setWebToken(const QByteArray &newWebToken);

private:
    Ui::BalanceWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QNetworkAccessManager *balanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString clientName;
    QString balance;
    double balanceValue;
};

#endif // BALANCEWINDOW_H

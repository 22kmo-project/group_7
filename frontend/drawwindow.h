#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT


public:
    explicit DrawWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~DrawWindow();
    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);
    void checkMoney(double bal, double am);

private slots:
    void drawSlot (QNetworkReply *reply);
    void on_button_20e_clicked();

    void on_button_40e_clicked();

    void on_button_60e_clicked();

    void on_button_100e_clicked();

    void on_button_200e_clicked();

    void on_button_500e_clicked();

    void on_button_exit_clicked();

private:
    Ui::DrawWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QNetworkAccessManager *drawManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString clientName;
    QString balance;
    double balanceValue;

};

#endif // DRAWWINDOW_H

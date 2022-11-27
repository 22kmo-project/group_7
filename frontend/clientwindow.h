#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "drawwindow.h"
#include "balancewindow.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QString id_card, QWidget *parent = nullptr);
    ~ClientWindow();

    //const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_button_nayta_saldo_clicked();
    void on_button_nayta_tilitapahtumat_clicked();
    void on_button_nosta_rahaa_clicked();
    void on_button_siirra_rahaa_clicked();

    void on_button_lopeta_clicked();

private:
    Ui::ClientWindow *ui;
    QByteArray webToken;
    QString myCardId;
    DrawWindow *objectDrawWindow;
    QByteArray response_data;
    BalanceWindow *objectBalanceWindow;
};

#endif // CLIENTWINDOW_H

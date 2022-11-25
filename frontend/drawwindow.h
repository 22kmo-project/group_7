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

private slots:
    void drawSlot (QNetworkReply *reply);

private:
    Ui::DrawWindow *ui;
    QByteArray webToken;
    QString myCardId;
    QNetworkAccessManager *drawManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString clientName;
    QString balance;

};

#endif // DRAWWINDOW_H

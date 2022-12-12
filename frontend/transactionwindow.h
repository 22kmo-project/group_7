#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include "filter.h"

namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionWindow(QByteArray wt, QString id_card, QWidget *parent = nullptr);
    ~TransactionWindow();
    const QString &getWebToken() const;
private slots:
    void TransSlot(QNetworkReply *reply);
    void on_pushButtonClose_clicked();
    void TransBalanceSlot (QNetworkReply *reply);
    void handleTimeout();   
    void on_btn_next_clicked();
    void started();
    void finished();

private:
    Ui::TransactionWindow*ui;
    QNetworkAccessManager *transManager;
    QNetworkAccessManager *transBalanceManager;
    QNetworkReply *reply;
    QByteArray webToken;
    QByteArray response_data;
    QString clientName;
    QString balance;
    QString myCardId;
    QTimer *transactionTimer;
    int id_card;
    short s;
    QStandardItemModel model;
    Filter filter;
};

#endif // TRANSACTIONWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clientwindow.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <myurl.h>
#include <QStyle>
#include <QDesktopWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loginSlot (QNetworkReply *reply);
    void lockedSlot (QNetworkReply *reply);
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
    void handleTimeout();

private:
    Ui::MainWindow *ui;
    int ok_count;
    int pin_count;
    bool check;
    ClientWindow *objectClientWindow;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *lockManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString id_card;
    QString pin;
    QTimer * Timer;
    short s;

};
#endif // MAINWINDOW_H

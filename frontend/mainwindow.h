#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clientwindow.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <myurl.h>

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
    Ui::MainWindow *ui;
    int ok_count;
    ClientWindow *objectClientWindow;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString id_card;
    QString pin;

};
#endif // MAINWINDOW_H

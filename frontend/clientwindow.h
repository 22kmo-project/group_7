#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>


namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QString id_card, QWidget *parent = nullptr);
    ~ClientWindow();

    const QString &getWebToken() const;
    void setWebToken(const QString &newWebToken);

private slots:
    void on_button_nayta_saldo_clicked();

    void on_button_nayta_tilitapahtumat_clicked();

    void on_button_nosta_rahaa_clicked();

    void on_button_siirra_rahaa_clicked();

private:
    Ui::ClientWindow *ui;
    QString webToken;
};

#endif // CLIENTWINDOW_H

#include "clientwindow.h"
#include "transactionwindow.h"
#include "depositwindow.h"
#include "ui_clientwindow.h"
#include <myurl.h>
#include <QDebug>



ClientWindow::ClientWindow(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Etusivu");

    ui->label_id_card->setText(id_card);
    myCardId=id_card;

}

ClientWindow::~ClientWindow()
{
    delete ui;

    delete objectDrawWindow;
    objectDrawWindow=nullptr;

    delete objectDepositWindow;
    objectDepositWindow=nullptr;

    delete objectBalanceWindow;
    objectBalanceWindow=nullptr;

}

void ClientWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void ClientWindow::on_button_nayta_saldo_clicked()//ESSI
{

    BalanceWindow ballanceWindow(webToken,myCardId);
    ballanceWindow.setModal(true);
    ballanceWindow.exec();

}

void ClientWindow::on_pushButtonTrans_clicked() //JENNI-MARIA
{
    TransactionWindow transWindow(webToken,myCardId);
    transWindow.setModal(true);
    transWindow.exec();

}


void ClientWindow::on_button_withdraw_clicked()//Justiina
{

    DrawWindow drawwWindow(webToken,myCardId);
    drawwWindow.setModal(true);
    drawwWindow.exec();
}


void ClientWindow::on_button_deposit_clicked()//Justiina
{
    DepositWindow deppositWindow(webToken,myCardId);
    deppositWindow.setModal(true);
    deppositWindow.exec();
}

void ClientWindow::on_button_exit_clicked() //TÄMÄN PAINAMINEN SEKOITTAA IKKUNAN TOIMINNAN
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


void ClientWindow::on_button_transfer_clicked()
{
    /*
    Tällä proseduurilla tekee siirron ok sql workbenchissa

DELIMITER //
CREATE PROCEDURE debit_transfer1(IN account_id1 INT, IN account_id2 INT, IN amount DOUBLE )
BEGIN
  DECLARE test1, test2, id_card1, id_card2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE account SET balance=balance-amount WHERE id_account=account_id1 AND balance>=amount;
  SET test1=ROW_COUNT();
  UPDATE account SET balance=balance+amount WHERE id_account=account_id2;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN COMMIT;
        set id_card1=(select card.id_card from card where card.id_account=account_id1);
        set id_card2=(select card.id_card from card where card.id_account=account_id2);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.balance) VALUES(account_id1, id_card1,'rahan siirto', NOW(), amount*-1);
        INSERT INTO transaction(transaction.id_account, transaction.id_card, transaction.transaction, transaction.transaction_date, transaction.balance) VALUES(account_id2, id_card2,'vastaanotettu siirto',NOW(), amount);
    ELSE
      ROLLBACK;
  END IF;
END //
DELIMITER ;

    call debit_transfers(1,2,3000);
    */
}

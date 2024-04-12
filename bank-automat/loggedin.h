#ifndef LOGGEDIN_H
#define LOGGEDIN_H

#include <QDialog>
#include <QDebug>

#include "takemoney.h"
#include "balance.h"
#include "transactions.h"


namespace Ui {
class loggedIn;
}

class loggedIn : public QDialog
{
    Q_OBJECT

public:
    explicit loggedIn(QWidget *parent = nullptr);
    ~loggedIn();

private:
    Ui::loggedIn *ui;
    takeMoney * takeMoneyPtr;
    balance * balancePtr;
    transactions * transactionsPtr;

private slots:
    void handleTakeMoneyClick();
    void handleBalanceClick();
    void handleTransactionClick();
    void handleLogOutClick();
    void handleTakeMoneyReturnClick();
    void handleBalanceReturnClick();
    void handleTransactionsReturnClick();
signals:
    void sendLogOutSignalToMain();
};

#endif // LOGGEDIN_H

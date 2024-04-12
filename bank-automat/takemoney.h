#ifndef TAKEMONEY_H
#define TAKEMONEY_H

#include <QDialog>
#include <QDebug>

#include "otheramount.h"

namespace Ui {
class takeMoney;
}

class takeMoney : public QDialog
{
    Q_OBJECT

public:
    explicit takeMoney(QWidget *parent = nullptr);
    ~takeMoney();

private:
    Ui::takeMoney *ui;
    otherAmount * otherAmountPtr;

private slots:
    void handle20Click();
    void handle40Click();
    void handle60Click();
    void handle90Click();
    void handle140Click();
    void handle240Click();
    void handleReturnClick();
    void handleOtherAmountClick();


    void handleOtherAmountReturnClick();

signals:
    void sendTakeMoneyReturnSignalToLoggedIn();
};

#endif // TAKEMONEY_H

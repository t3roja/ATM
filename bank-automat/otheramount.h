#ifndef OTHERAMOUNT_H
#define OTHERAMOUNT_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class otherAmount;
}

class otherAmount : public QDialog
{
    Q_OBJECT

public:
    explicit otherAmount(QWidget *parent = nullptr);
    ~otherAmount();

private:
    Ui::otherAmount *ui;

    short OtherAmountSumma;

private slots:
    void handleOther1Click();
    void handleOther2Click();
    void handleOther3Click();
    void handleOther4Click();
    void handleOther5Click();
    void handleOther6Click();
    void handleOther7Click();
    void handleOther8Click();
    void handleOther9Click();
    void handleOther0Click();
    void handleOtherReturnClick();
    void handleOtherEraseClick();

    void handleAmountOkClick();
signals:
    void sendOtherAmountReturnSignalToTakeMoney();

};

#endif // OTHERAMOUNT_H

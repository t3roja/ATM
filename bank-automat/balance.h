#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>

namespace Ui {
class balance;
}

class balance : public QDialog
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

private:
    Ui::balance *ui;

private slots:
    void handleBalanceReturn();

signals:
    void sendBalanceReturnSignalToLoggedIn();
};

#endif // BALANCE_H

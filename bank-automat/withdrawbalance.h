#ifndef WITHDRAWBALANCE_H
#define WITHDRAWBALANCE_H

#include <QDialog>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <enviroment.h>

namespace Ui {
class withdrawBalance;
}

class withdrawBalance : public QDialog
{
    Q_OBJECT

public:
    explicit withdrawBalance(QWidget *parent = nullptr);
    ~withdrawBalance();
    QByteArray token;

    void setWebToken(const QByteArray &newWebToken);

private slots:

    void withdrawBalanceButtonClicked();
    void withdrawBalanceSlot(QNetworkReply *reply);

private:
    Ui::withdrawBalance *ui;
    QNetworkAccessManager *withdrawBalanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // WITHDRAWBALANCE_H

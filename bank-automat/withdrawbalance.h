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
    void setUsername(const QString &newUsername);

private slots:

    void withdrawBalanceButtonClicked();
    void withdrawBalanceSlot(QNetworkReply *reply);

    void handle1Click();
    void handle2Click();
    void handle3Click();
    void handle4Click();
    void handle5Click();
    void handle6Click();
    void handle7Click();
    void handle8Click();
    void handle9Click();
    void handle0Click();
    void handleEraseClick();
    void handleReturnClick();

private:
    Ui::withdrawBalance *ui;
    QNetworkAccessManager *withdrawBalanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
};

#endif // WITHDRAWBALANCE_H

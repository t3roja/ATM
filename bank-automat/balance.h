#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <enviroment.h>

namespace Ui {
class Balance;
}

class Balance : public QDialog , public enviroment
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();
    QByteArray token;
    void setUsername(const QString &newUsername);
    void setWebToken(const QByteArray &newWebToken);


private slots:

    void showBalanceButtonClicked();
    void balanceSlot(QNetworkReply *reply);
    void handleReturnClick();

private:

    Ui::Balance *ui;
    QString username;
    QNetworkAccessManager *transactionManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // BALANCE_H

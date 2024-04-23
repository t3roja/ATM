#ifndef DEPOSITBALANCE_H
#define DEPOSITBALANCE_H

#include <QDialog>
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <enviroment.h>

namespace Ui {
class depositBalance;
}

class depositBalance : public QDialog
{
    Q_OBJECT

public:
    explicit depositBalance(QWidget *parent = nullptr);
    ~depositBalance();
    QByteArray token;

    void setWebToken(const QByteArray &newToken);
    void setUsername(const QString &newUsername);
    QString getUsername() const;

private slots:

    void depositBalanceButtonClicked();
    void depositBalanceSlot(QNetworkReply *reply);
    void handleReturnClick();

private:
    Ui::depositBalance *ui;

    QNetworkAccessManager *depositBalanceManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString username;
};

#endif // DEPOSITBALANCE_H

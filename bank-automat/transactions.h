#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "enviroment.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class menu;
}

class transactions : public QDialog, public enviroment
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();
    void setUsername(const QString &newUsername);
    void setWebToken(const QByteArray &newWebToken);

private slots:

    void showTransactionsButtonClicked();
    void transactionsSlot(QNetworkReply *reply);
    void handleReturnClick();


private:
    Ui::menu *ui;
    QString username;

    QNetworkAccessManager *transactionManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

};

#endif // TRANSACTIONS_H

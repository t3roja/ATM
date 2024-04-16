#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class menu;
}

class transactions : public QDialog
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();

    void setWebToken(const QByteArray &newWebToken);

private slots:

    void showTransactionsButtonClicked();
    void transactionsSlot(QNetworkReply *reply);


private:
    Ui::menu *ui;
    QString username;


    QNetworkAccessManager *transactionManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

};

#endif // TRANSACTIONS_H

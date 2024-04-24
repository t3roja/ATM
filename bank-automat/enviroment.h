#ifndef ENVIROMENT_H
#define ENVIROMENT_H

#include <QDialog>


class enviroment
{
public:
    enviroment();

    static QString getBaseUrl();
    QString getAccountNumber();
    QString getAccountId();
    void setAccountNumber(QString un);
    void setCardType(QString);
    QString accountId;
    QString accountNumber;
    QString cardType;


    QString getCardType() const;
};



#endif // ENVIROMENT_H

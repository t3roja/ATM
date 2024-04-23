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

    QString accountId;
    QString accountNumber;
};



#endif // ENVIROMENT_H

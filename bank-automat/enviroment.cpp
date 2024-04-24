#include "enviroment.h"

enviroment::enviroment()
{

}

QString enviroment::getBaseUrl()
{
    //return "https://atm-xwja.onrender.com";
    return "http://localhost:3000";
}

QString enviroment::getAccountNumber()
{
    return accountNumber;
}

QString enviroment::getAccountId()
{
    return accountId;
}

void enviroment::setAccountNumber(QString un)
{
    accountNumber = un;
}

void enviroment::setCardType(QString cT)
{
    cardType = cT;
}

QString enviroment::getCardType() const
{
    return cardType;
}


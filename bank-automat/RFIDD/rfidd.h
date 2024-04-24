#ifndef RFIDD_H
#define RFIDD_H

#include "RFIDD_global.h"
#include <QDebug>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>



class RFIDD_EXPORT RFIDD : public QObject
{
    Q_OBJECT
public:
    RFIDD(QObject *parent);
    ~RFIDD();
    void openSerialPort(); //kaikki publicciin että käyttö onnistuu
    void returnCardID();
    QSerialPort * serialport;


signals:
    void cardRead(QByteArray data);
private:

};

#endif // RFIDD_H

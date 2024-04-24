#include "rfidd.h"
#include <QObject>
#include <QDialog>

RFIDD::RFIDD(QObject *parent) : QObject(parent)
{
    serialport = new QSerialPort; //sarjaportin määrittelyt
    serialport ->setPortName("COM13"); // Portti pitää olla oikeasti oikein
    serialport->setBaudRate(QSerialPort::Baud9600);
    serialport->setDataBits(QSerialPort::Data8);
    serialport->setParity(QSerialPort::NoParity);
    serialport->setStopBits(QSerialPort::OneStop);
    openSerialPort();
    connect(serialport, &QSerialPort::readyRead, this, RFIDD::returnCardID);
    returnCardID();

}

void RFIDD::openSerialPort()
{
    serialport->open(QIODevice::ReadWrite); //sarjaportin avaus
    qDebug()<< "sarjaportin avaus";
}


void RFIDD::returnCardID()
{
    QByteArray data = serialport->readAll();
    QByteArray newData = data.mid(3, data.length() - 4).trimmed(); //poistetaan extramerkit ja datan lähetys pankkiautomaattiin
    qDebug()<<newData<< "serialinlukeminen";
    emit cardRead(newData);
}

RFIDD::~RFIDD()
{
    delete serialport;
}

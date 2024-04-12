// mainwindow.cpp

#include "mainwindow.h"
#include "qobject.h"
#include "ui_mainwindow.h"

RFID::RIFD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RFID)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);

    // Find the serial port connected to the RFID reader
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("RFID")) {
            serial->setPort(info);
            break;
        }
    }

    if (!serial->isOpen()) {
        if (serial->open(QIODevice::ReadOnly)) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
        } else {
            qDebug() << "Failed to open serial port:" << serial->errorString();
        }
    }
}

RFID::~RFID()
{
    delete ui;
}

void RFID::readSerialData()
{
    QByteArray data = serial->readAll();
    QString cardID = QString::fromUtf8(data.trimmed());

    // Check if the card ID is already known
    if (!knownCardIDs.contains(cardID)) {
        // Store the new card ID
        knownCardIDs.insert(cardID);

        // Perform actions based on the detected card ID
        if (cardID == "0500CB87D2") {
            handleCard1(cardID);
        } else if (cardID == "0600064972") {
            handleCard2(cardID);
        } else if (cardID == "0B0032AD79") {
            handleCard3(cardID);
        }

    }
}

void RFID::handleCard1(const QString &cardID)
{
    // Actions to perform for CardID1
    qDebug() << "Card1 detected: " << cardID;
}

void RFID::handleCard2(const QString &cardID)
{
    // Actions to perform for CardID2
    qDebug() << "Card2 detected: " << cardID;
}

void RFID::handleCard3(const QString &cardID)
{
    // Actions to perform for CardID3
    qDebug() << "Card3 detected: " << cardID;
}

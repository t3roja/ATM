// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSet>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class RFID; }
QT_END_NAMESPACE

class RFID : public QMainWindow
{
    Q_OBJECT

public:
    RFID(QWidget *parent = nullptr);
    ~RFID();

private slots:
    void readSerialData();

private:
    Ui::RFID *ui;
    QSerialPort *serial;
    QSet<QString> knownCardIDs;


    void handleCard1(const QString &cardID);
    void handleCard2(const QString &cardID);
    void handleCard3(const QString &cardID);
};

#endif // MAINWINDOW_H

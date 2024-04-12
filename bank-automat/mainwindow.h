#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <image.h>
#include <QMessageBox>
#include <network.h>


#include <QMainWindow>
#include "cardreader.h"
#include "pinreader.h"
#include "loggedin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleInsertCardClick();
    void handleCardNumberRead(short);
    void handlePinNumberRead(short);
    void handleLoggedOutClick();

//(QNetworkReply *reply); kaikkiin joiden tarvii ottaa yhteys databaseen
   //  void loginNetwork(QNetworkReply *reply);


private:


    //card number rfid lukijalta lukemaan ja correctpin number tyhjäksi
    Ui::MainWindow *ui;
    short attemptsLeft=3;
    short cardNumber, pinNumber;
    short correctCardNumber= 1;
    short correctPinNumber=2;
    cardReader * cardReaderPtr;
    pinReader * pinReaderPtr;
    loggedIn * loggedInPtr;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    //QSqlDatabase db;
   /*
    QSqlDatabase db = QSqlDatabase::addDatabase("");
    db.setHostName("");
    db.setPort();
    db.setDatabaseName("");
    db.setUserName("");
    db.setPassword("");
    db.open();
    QList tilitapahtumat;


*/



};
#endif // MAINWINDOW_H

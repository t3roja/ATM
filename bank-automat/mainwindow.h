#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enviroment.h"
#include "rfidd.h"
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsonvalue.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public enviroment
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void pushButtonLoginHandler();
    void loginSlot(QNetworkReply *reply);
    void getIdSlot(QNetworkReply *reply);
    void handle1Click();
    void handle2Click();
    void handle3Click();
    void handle4Click();
    void handle5Click();
    void handle6Click();
    void handle7Click();
    void handle8Click();
    void handle9Click();
    void handle0Click();
    void handleEraseClick();

    void handleCardRead(QByteArray);
    void handleCardNumber(QByteArray);

private:
    Ui::MainWindow *ui;
    QString username;
    QByteArray webToken;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    void login(QString);
    QByteArray accountType;
    QString cardType;
    void getCardType(QString);


    RFIDD * ptr_dll;
};
#endif // MAINWINDOW_H

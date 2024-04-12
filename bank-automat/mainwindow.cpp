#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnInsertCard,SIGNAL(clicked(bool)),
            this, SLOT(handleInsertCardClick()));

}

MainWindow::~MainWindow()
{
    delete ui;
}





/*

login automaattiin
QString uname=ui->textUsername->text();
QString pincd=ui->textPincode->text();
QJsonObject jsonObj;
jsonObj.insert("username",uname);
jsonObj.insert("pincode","pincd");

QString site_url=network::getBaseUrl()+"/login";
QNetworkRequest request((site_url));
request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


loginManager = new QNetworkAccessManager(this);
connectloginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginFunktio(QNetworkReply*)));

reply = loginManager->put(request, QJsonDocument(jsonObj).toJson());





//WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
//WEBTOKEN LOPPU






*/

void MainWindow::handleInsertCardClick()
{
    qDebug()<<"InsertCard";

    cardReaderPtr = new cardReader(this);
    connect(cardReaderPtr,SIGNAL(sendCardNumToMain(short)),
               this,SLOT(handleCardNumberRead(short)));
    cardReaderPtr->show();
    //cardReaderPtr->open();

}

void MainWindow::handleCardNumberRead(short n)
{

    qDebug()<<"MainWindow CardNumberRead";

    qDebug()<<"kortin numero on ="<<n;
    cardNumber = n;
    ui->lineEditCurrentCardNumber->setText(QString::number(n));
    delete cardReaderPtr;

    //tähän rfid kortin luku
    //rfid luku otetaan talteen ja siirretään handlePinNumberRead funktioon käyttäjänimeksi

    //kortin numro on valittu aukeaa mahdollisuus syöttää pin koodi
    pinReaderPtr = new pinReader();
    connect(pinReaderPtr,SIGNAL(sendPinNumberToMain(short)),
            this,SLOT(handlePinNumberRead(short)));
    pinReaderPtr->show();

}

void MainWindow::handlePinNumberRead(short p)
{

    //short p tilalle QNetworkReply *reply kun vaihdetaan nettitarkistus

    //attempsLeft pitää muuttaa if lauseeksi joka resetoituu aina kun onnistunut kirjautuminen
    //ja kerää tiedon itselle talteen jos epäonnistuu

    //Tänne pitäisi päästä kun painaa read pin nappia
    qDebug()<<"MainWindow handlePinNumberRead funktiossa";
    qDebug()<<"pin numero on ="<<p;
    pinNumber = p;
    ui->lineEditCurrentPinNumber->setText(QString::number(p));

    if (pinNumber==correctPinNumber && cardNumber==correctCardNumber){
        qDebug()<<"salasana ja kortin numero oikein => sisäänkirjautuminen onnistui";

        attemptsLeft=3;

        loggedInPtr = new loggedIn();
        connect(loggedInPtr,SIGNAL(sendLogOutSignalToMain()),
                this,SLOT(handleLoggedOutClick()));
        loggedInPtr->show();
    } else {

        attemptsLeft--;
        qDebug()<<"salasana tai kortin numero väärin => sisäänkirjautuminen epäonnistui";
        //avaa pinReaderPtr jotta pin koodin voi syöttää uudelleen
        //jos yrityksiä ei ole jäljellä=>lukitse tili

    }
    delete pinReaderPtr;
    ui->lineEditPinAttemptsLeft->setText(QString::number(attemptsLeft));
}

void MainWindow::handleLoggedOutClick()
{

/*
void MainWindow::loginNetwork(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox msgbox;
    if(response_data=="error1"){
        msgbox.setText("ei internet yhteyttä");
            msgbox.exec();
    }
    else{
            if(response_data !="false"){
                msgbox.setText("toimii");
                    msgbox.exec();
            }
            else{
                    msgbox.setText("tunnus/pin ei täsmää");
                        msgbox.exec();
                    ui->textPin->clear();
            }
    }
}

*/

    qDebug()<<"--Uloskirjautuminen suoritettu--";
    delete loggedInPtr;
}


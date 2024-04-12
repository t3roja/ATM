#include "loggedin.h"
#include "ui_loggedin.h"

loggedIn::loggedIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loggedIn)
{
    ui->setupUi(this);

//database yhteys otetaan käyttöön

    connect(ui->btnTakeMoney,SIGNAL(clicked(bool)),
            this, SLOT(handleTakeMoneyClick()));
    connect(ui->btnBalance,SIGNAL(clicked(bool)),
            this, SLOT(handleBalanceClick()));
    connect(ui->btnTransaction,SIGNAL(clicked(bool)),
            this, SLOT(handleTransactionClick()));
    connect(ui->btnLogOut,SIGNAL(clicked(bool)),
            this, SLOT(handleLogOutClick()));
}

loggedIn::~loggedIn()
{
    delete ui;
}

void loggedIn::handleTakeMoneyClick()
{

    //http put metodi tänne
    // bugi ei palauta itsestään pois ikkunasta
    //bugi rahamäärä tililtä ei vähenen vaikka rahaa nostaa

    qDebug()<<"TakeMoney";

    takeMoneyPtr = new takeMoney();
    connect(takeMoneyPtr,SIGNAL(sendTakeMoneyReturnSignalToLoggedIn()),
            this, SLOT(handleTakeMoneyReturnClick()));
    takeMoneyPtr->show();
}

void loggedIn::handleBalanceClick()
{

    //http get metodi

    qDebug()<<"Balance";

    balancePtr = new balance();
    connect(balancePtr,SIGNAL(sendBalanceReturnSignalToLoggedIn()),
            this,SLOT(handleBalanceReturnClick()));
    balancePtr->show();
}

void loggedIn::handleTransactionClick()
{

    //http get metodi

    qDebug()<<"Transactions";

    transactionsPtr = new transactions();
    connect(transactionsPtr,SIGNAL(sendTransactionsReturnSignalToLoggedIn()),
            this,SLOT(handleTransactionsReturnClick()));
    transactionsPtr->show();
}

void loggedIn::handleLogOutClick()
{

    //datayhteyden katkaisu ja webtoken cancelointi

    qDebug()<<"LogOut";

    //Sulkee loggedIn ikkunan
    emit sendLogOutSignalToMain();
}

void loggedIn::handleTakeMoneyReturnClick()
{

    qDebug()<<"Return";

    takeMoneyPtr->close();
}

void loggedIn::handleBalanceReturnClick()
{

    qDebug()<<"BalanceReturn";

    balancePtr->close();
}

void loggedIn::handleTransactionsReturnClick()
{

    qDebug()<<"TransactionsReturn";

    transactionsPtr->close();
}



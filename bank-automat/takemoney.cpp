#include "takemoney.h"
#include "ui_takemoney.h"

takeMoney::takeMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::takeMoney)
{
    ui->setupUi(this);

    connect(ui->btn20,SIGNAL(clicked(bool)),
            this, SLOT(handle20Click()));
    connect(ui->btn40,SIGNAL(clicked(bool)),
            this, SLOT(handle40Click()));
    connect(ui->btn60,SIGNAL(clicked(bool)),
            this, SLOT(handle60Click()));
    connect(ui->btn90,SIGNAL(clicked(bool)),
            this, SLOT(handle90Click()));
    connect(ui->btn140,SIGNAL(clicked(bool)),
            this, SLOT(handle140Click()));
    connect(ui->btn240,SIGNAL(clicked(bool)),
            this, SLOT(handle240Click()));
    connect(ui->btnReturn,SIGNAL(clicked(bool)),
            this, SLOT(handleReturnClick()));
    connect(ui->btnOtherAmount,SIGNAL(clicked(bool)),
            this, SLOT(handleOtherAmountClick()));
}

takeMoney::~takeMoney()
{
    delete ui;
}

void takeMoney::handle20Click()
{

    qDebug()<<"----nostetaan 20e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handle40Click()
{

    qDebug()<<"----nostetaan 40e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handle60Click()
{

    qDebug()<<"----nostetaan 60e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handle90Click()
{

    qDebug()<<"----nostetaan 90e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handle140Click()
{

    qDebug()<<"----nostetaan 140e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handle240Click()
{

    qDebug()<<"----nostetaan 240e----";
    emit sendTakeMoneyReturnSignalToLoggedIn();

}

void takeMoney::handleReturnClick()
{

    qDebug()<<"Return";


    //lähetä signaali logged in ikkunan
    //slottifunktioon jossa poistetaan
    //take money pointteri

    emit sendTakeMoneyReturnSignalToLoggedIn();
}

void takeMoney::handleOtherAmountClick()
{

    qDebug()<<"OtherAmount";
    //Avaa Other amount ikkuna
    otherAmountPtr = new otherAmount();
    connect(otherAmountPtr,SIGNAL(sendOtherAmountReturnSignalToTakeMoney()),
            this, SLOT(handleOtherAmountReturnClick()));
    otherAmountPtr ->show();
}

void takeMoney::handleOtherAmountReturnClick()
{
    otherAmountPtr->close();
}

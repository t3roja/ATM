#include "balance.h"
#include "ui_balance.h"

balance::balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::balance)
{
    //labeliin kirjoitusfunktio
    //databasesta tietojen haku labeliin

    ui->setupUi(this);
    connect(ui->btnReturn,SIGNAL(clicked(bool)),
            this, SLOT(handleBalanceReturn()));

}

balance::~balance()
{
    delete ui;
}

void balance::handleBalanceReturn()
{

    qDebug()<<"Balance return";

emit sendBalanceReturnSignalToLoggedIn();
}

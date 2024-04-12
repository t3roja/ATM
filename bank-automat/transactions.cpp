#include "transactions.h"
#include "ui_transactions.h"

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
    connect(ui->btnTransactionReturn,SIGNAL(clicked(bool)),
            this,SLOT(handleTransactionsReturn()));
}

transactions::~transactions()
{
    delete ui;
}

void transactions::handleTransactionsReturn()
{
emit sendTransactionsReturnSignalToLoggedIn();
}

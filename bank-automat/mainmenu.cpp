#include "mainmenu.h"
#include "transactions.h"
#include "balance.h"
#include "depositbalance.h"
#include "ui_mainmenu.h"
#include "withdrawbalance.h"

mainMenu::mainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
    connect(ui->buttonBalance,SIGNAL(clicked(bool)),this,SLOT(balanceButtonSlot())); // Kytketään nappi slottiin
    connect(ui->buttonTransactions,SIGNAL(clicked(bool)),this,SLOT(transactionsSlot()));
    connect(ui->buttonDeposit,SIGNAL(clicked(bool)),this,SLOT(depositButtonSlot()));
    connect(ui->buttonWithdraw,SIGNAL(clicked(bool)),this,SLOT(withdrawButtonSlot()));
    connect(ui->btnLogout,SIGNAL(clicked(bool)), this,SLOT(handleLogoutClick()));
}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::transactionsSlot()
{
    transactions *objectTransactions = new transactions;
    objectTransactions->setWebToken(webToken);
    objectTransactions->setUsername(username);
    objectTransactions->show();
}

void mainMenu::balanceButtonSlot()
{
    Balance *objectBalance = new Balance;
    objectBalance->setWebToken(webToken);
    objectBalance->setUsername(username);
    objectBalance->show();
}

void mainMenu::depositButtonSlot()
{
    depositBalance *objectDeposit = new depositBalance;
    objectDeposit->setWebToken(webToken);
    objectDeposit->setUsername(username);
    objectDeposit->show();
}

void mainMenu::withdrawButtonSlot()
{
    withdrawBalance *objectWithdraw = new withdrawBalance;
    objectWithdraw->setWebToken(webToken);
    objectWithdraw->setUsername(username, enviroment::cardType);
    objectWithdraw->show();
}

void mainMenu::handleLogoutClick()
{
    QByteArray x=0;
    setWebToken(x);
    delete this;
}

void mainMenu::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug()<<"WebToken set to: " + webToken;
}


void mainMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    //ui->mainMenuWelcome->setText("Welcome " + username);
}

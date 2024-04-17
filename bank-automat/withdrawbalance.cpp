#include "withdrawbalance.h"
#include "ui_withdrawbalance.h"

withdrawBalance::withdrawBalance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdrawBalance)
{
    ui->setupUi(this);
    connect(ui->buttonWithdraw,SIGNAL(clicked(bool)),this,SLOT(withdrawBalanceButtonClicked())); // Kytketään nappi slottiin
    connect(ui->btn0,SIGNAL(clicked(bool)),
            this, SLOT(handle0Click()));
    connect(ui->btn1,SIGNAL(clicked(bool)),
            this, SLOT(handle1Click()));
    connect(ui->btn2,SIGNAL(clicked(bool)),
            this, SLOT(handle2Click()));
    connect(ui->btn3,SIGNAL(clicked(bool)),
            this, SLOT(handle3Click()));
    connect(ui->btn4,SIGNAL(clicked(bool)),
            this, SLOT(handle4Click()));
    connect(ui->btn5,SIGNAL(clicked(bool)),
            this, SLOT(handle5Click()));
    connect(ui->btn6,SIGNAL(clicked(bool)),
            this, SLOT(handle6Click()));
    connect(ui->btn7,SIGNAL(clicked(bool)),
            this, SLOT(handle7Click()));
    connect(ui->btn8,SIGNAL(clicked(bool)),
            this, SLOT(handle8Click()));
    connect(ui->btn9,SIGNAL(clicked(bool)),
            this, SLOT(handle9Click()));
    connect(ui->btnReturn,SIGNAL(clicked(bool)),
            this, SLOT(handleReturnClick()));
    connect(ui->btnErase,SIGNAL(clicked(bool)),
            this, SLOT(handleEraseClick()));
}


withdrawBalance::~withdrawBalance()
{
    delete ui;
}

void withdrawBalance::setWebToken(const QByteArray &newToken)
{
    token = newToken;
}

void withdrawBalance::withdrawBalanceButtonClicked()
{
    QJsonObject jsonObj;
    QString amount=ui->withdrawAmountText->text();
    qDebug()<<"WEBTOKEN: " << token;
    jsonObj.insert("id", "4"); // tähän pitää saada haluttu tili
    jsonObj.insert("amount",amount);
    QString url = enviroment::getBaseUrl() + "/transactions/withdrawBalance/";
    QNetworkRequest request((url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEB-TOKEN ALKU
    QByteArray myToken="Bearer "+ token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEB-TOkEN LOPPU
    withdrawBalanceManager = new QNetworkAccessManager(this);

    connect(withdrawBalanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(withdrawBalanceSlot(QNetworkReply*)));


    reply = withdrawBalanceManager->post(request, QJsonDocument(jsonObj).toJson());
}

void withdrawBalance::withdrawBalanceSlot(QNetworkReply *reply)
{
    qDebug()<<"withdraw balance slot";
}


void withdrawBalance::handle1Click()
{

    qDebug()<<"1";
    ui->withdrawAmountText->insert("1");
}

void withdrawBalance::handle2Click()
{

    qDebug()<<"2";

    ui->withdrawAmountText->insert("2");
}

void withdrawBalance::handle3Click()
{

    qDebug()<<"3";

    ui->withdrawAmountText->insert("3");
}

void withdrawBalance::handle4Click()
{

    qDebug()<<"4";

    ui->withdrawAmountText->insert("4");
}

void withdrawBalance::handle5Click()
{
    qDebug()<<"5";

    ui->withdrawAmountText->insert("5");
}

void withdrawBalance::handle6Click()
{

    qDebug()<<"6";

    ui->withdrawAmountText->insert("6");
}

void withdrawBalance::handle7Click()
{

    qDebug()<<"7";

    ui->withdrawAmountText->insert("7");
}

void withdrawBalance::handle8Click()
{

    qDebug()<<"8";

    ui->withdrawAmountText->insert("8");
}

void withdrawBalance::handle9Click()
{

    qDebug()<<"9";

    ui->withdrawAmountText->insert("9");
}

void withdrawBalance::handle0Click()
{

    qDebug()<<"0";

    ui->withdrawAmountText->insert("0");

}


void withdrawBalance::handleEraseClick()
{

    qDebug()<<"Erase";


    if (!ui->withdrawAmountText->text().isEmpty())
    {
        QString text =ui->withdrawAmountText->text();
        text.chop(1);
        ui->withdrawAmountText->setText(text);
    }
}

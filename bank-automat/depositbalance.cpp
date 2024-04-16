#include "depositbalance.h"
#include "ui_depositbalance.h"

depositBalance::depositBalance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depositBalance)
{
    ui->setupUi(this);
    connect(ui->buttonDeposit,SIGNAL(clicked(bool)),this,SLOT(depositBalanceButtonClicked())); // Kytketään nappi slottiin
}


depositBalance::~depositBalance()
{
    delete ui;
}

void depositBalance::setWebToken(const QByteArray &newToken)
{
    token = newToken;
}

void depositBalance::depositBalanceButtonClicked()
{
    QJsonObject jsonObj;
    QString amount=ui->depositAmountText->text();
    qDebug()<<"WEBTOKEN: " << token;
    jsonObj.insert("id", "4"); // tähän pitää saada haluttu tili
    jsonObj.insert("amount",amount);
    QString url = enviroment::getBaseUrl() + "/transactions/depositBalance/";
    QNetworkRequest request((url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEB-TOKEN ALKU
    QByteArray myToken="Bearer "+ token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEB-TOkEN LOPPU
    depositBalanceManager = new QNetworkAccessManager(this);

    connect(depositBalanceManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(depositBalanceSlot(QNetworkReply*)));


    reply = depositBalanceManager->post(request, QJsonDocument(jsonObj).toJson());
}

void depositBalance::depositBalanceSlot(QNetworkReply *reply)
{
    qDebug()<<"deposit balance slot";
}

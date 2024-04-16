#include "withdrawbalance.h"
#include "ui_withdrawbalance.h"

withdrawBalance::withdrawBalance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdrawBalance)
{
    ui->setupUi(this);
    connect(ui->buttonWithdraw,SIGNAL(clicked(bool)),this,SLOT(withdrawBalanceButtonClicked())); // Kytketään nappi slottiin
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


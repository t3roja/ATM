#include "depositbalance.h"
#include "ui_depositbalance.h"

depositBalance::depositBalance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depositBalance)
{
    ui->setupUi(this);
    connect(ui->buttonDeposit,SIGNAL(clicked(bool)),this,SLOT(depositBalanceButtonClicked())); // Kytketään nappi slottiin
    connect(ui->btnReturn,SIGNAL(clicked(bool)),this,SLOT(handleReturnClick()));
}


depositBalance::~depositBalance()
{
    delete ui;
}

void depositBalance::setWebToken(const QByteArray &newToken)
{
    token = newToken;
}

void depositBalance::setUsername(const QString &newUsername)
{
    username=newUsername;

}

void depositBalance::depositBalanceButtonClicked()
{
    QJsonObject jsonObj;
    QString amount=ui->depositAmountText->text();
    jsonObj.insert("id", username);
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

void depositBalance::handleReturnClick()
{
    delete this;
}

QString depositBalance::getUsername() const
{
    return username;
}

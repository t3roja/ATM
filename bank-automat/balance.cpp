#include "balance.h"
#include "ui_balance.h"

Balance::Balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
    connect(ui->showBalanceButton,SIGNAL(clicked(bool)),this,SLOT(showBalanceButtonClicked())); // Kytketään nappi slottiin
    connect(ui->btnReturn,SIGNAL(clicked(bool)),this,SLOT(handleReturnClick()));
}

Balance::~Balance()
{
    delete ui;
}

void Balance::setUsername(const QString &newUsername)
{
    username=newUsername;
}

void Balance::setWebToken(const QByteArray &newToken)
{
    token = newToken;
}

void Balance::showBalanceButtonClicked()
{
    qDebug()<<enviroment::cardType;
    QJsonObject jsonObj;
    jsonObj.insert("id",username);
    QString url = enviroment::getBaseUrl() + "/transactions/showBalance/";
    QNetworkRequest request((url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEB-TOKEN ALKU
    QByteArray myToken="Bearer "+ token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEB-TOkEN LOPPU
    transactionManager = new QNetworkAccessManager(this);

    connect(transactionManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(balanceSlot(QNetworkReply*)));


    reply = transactionManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Balance::balanceSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data); //siistitään vastausta
    QJsonObject jsonObject = jsonDoc.object();
    QString balance = jsonObject["balance"].toString();
    QString creditLimit = jsonObject["credit_limit"].toString();
    if(balance!=""){
        QString x = "Saldo : ";
        x += balance;
        ui->balanceText->setText(x+"\r");
    }
    if(creditLimit!=""){
        QString x = "Luottoraja : ";
        x+=creditLimit;
        ui->balanceText->append(x+"\r");
    }
}

void Balance::handleReturnClick()
{
    delete this;
}



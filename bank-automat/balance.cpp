#include "balance.h"
#include "ui_balance.h"

Balance::Balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
    connect(ui->showBalanceButton,SIGNAL(clicked(bool)),this,SLOT(showBalanceButtonClicked())); // Kytketään nappi slottiin
}

Balance::~Balance()
{
    delete ui;
}

void Balance::setWebToken(const QByteArray &newToken)
{
    token = newToken;
}

void Balance::showBalanceButtonClicked()
{
    QJsonObject jsonObj;
    qDebug()<<"WEBTOKEN: " << token;
    jsonObj.insert("id", "4"); // tähän pitää saada haluttu tili
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
    ui->balanceText->setText(balance);
}



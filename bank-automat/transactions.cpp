#include "enviroment.h"
#include "transactions.h"
#include "ui_menu.h"

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    connect(ui->showTransactionsButton,SIGNAL(clicked(bool)),this,SLOT(showTransactionsButtonClicked())); // Kytketään nappi slottiin
}
transactions::~transactions()
{
    delete ui;
}

void transactions::showTransactionsButtonClicked()
{
    QJsonObject jsonObj;
    qDebug()<<"WEBTOKEN: " << token;
    jsonObj.insert("id", "4");  // tähän pitää saada haluttu tili
    QString url = enviroment::getBaseUrl() + "/transactions/showTransactions/";
    QNetworkRequest request((url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEB-TOKEN ALKU
    QByteArray myToken="Bearer "+ token;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEB-TOkEN LOPPU
    transactionManager = new QNetworkAccessManager(this);

    connect(transactionManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionsSlot(QNetworkReply*)));


    reply = transactionManager->post(request, QJsonDocument(jsonObj).toJson());
}

void transactions::transactionsSlot(QNetworkReply *reply)
{
    qDebug()<<"transaction slot";
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
    QJsonArray jsonArray = jsonDoc.array();
    QString transactions =  "Transaction ID  |  Account ID  |  Amount  |  Transaction type  |  Date  \r";
    foreach (const QJsonValue &value, jsonArray){// järjestetään tulosta
        QJsonObject jsonObj = value.toObject();
        transactions+=QString::number(jsonObj["id_transaction"].toInt())+"  |  ";
        transactions+=QString::number(jsonObj["id_account"].toInt())+"  |  ";
        transactions+=QString::number(jsonObj["amount"].toInt())+"  |  ";
        transactions+=jsonObj["transaction_type"].toString()+"  |  ";
        transactions+=jsonObj["transaction_date"].toString()+"  |  ";
        transactions+="\r";
    }
    ui->textBrowser->setText(transactions);
}

void transactions::setWebToken(const QByteArray &newToken)
{
    token = newToken;
    qDebug()<<"Transaction token";
}


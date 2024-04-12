#include "network.h"

network::network()
{

}

QString network::getBaseUrl()
{
    return "http://localhost:3000";
}

void network::setWebtoken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void network::listaaTiliTapahtumat(QNetworkReply *reply0)
{
    /*


http get toteutus eli otetaan taulukosta dataa eli tilin rahamäärä
void MainWindow::tähän tilalle funktion nimi (QNetworkReply *reply)
{
 response_data0=reply->readAll();
 QJsonDocument json_doc = QJsonDocument::fromJson(response_data0);
 QJsonArray json_array = json_doc.array();
 QString tähän esim tilin rahamäärä;
 foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    tili+=QString::number(json_obj["database mitä haetaan"].toInt())+", "+json_obj["database mitä haetaan"].toString()+", "+json_obj["database mitä haetaan"].toString()+"\r";
 }

 ui->tähän line-editin nimi mihin data->setText(tähän esim tilin rahamäärä);

 reply->deleteLater();
 getManager0->deleteLater();
}

*/
}
/*
void MainWindow::on_login_clicked() // testi-ohjelman testattu ja toimiva versio
{
    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    getManager0 = new QNetworkAccessManager(this);
    connect(getManager0, SIGNAL(finished (QNetworkReply*)),this, SLOT(infoSlot(QNetworkReply*)));
    reply0 = getManager0->get(request);
}


void network::login_clicked()
{
    QString site_url=network::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //WEBTOKEN ALKU
    QString webToken;
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager0 = new QNetworkAccessManager (this);

    connect(getManager0, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply0 = getManager0->get(request);
}
//tilin rahamäärän muokkaus http put metodi
QJsonObject jsonObj;
jsonObj.insert("tili","rahamäärä");


    QString site_url="http://localhost:3000/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "/json");


    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));


    tiliManager = new QNetworkAccessManager(this);
    connect(tiliManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateTiliSlot(QNetworkReply*)));

    reply = tiliManager->put(request, QJsonDocument(jsonObj).toJson());







*/

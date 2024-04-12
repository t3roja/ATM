#ifndef NETWORK_H
#define NETWORK_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>



class network
{
public:
    network();
    static QString getBaseUrl();
    void setWebtoken(const QByteArray &newWebToken);
private slots:
    void listaaTiliTapahtumat(QNetworkReply *reply0);
    void login_clicked();
private:
    QByteArray webToken;
    QNetworkAccessManager *getManager0;
    QNetworkReply *reply0;
    QByteArray response_data0;

};

#endif // NETWORK_H

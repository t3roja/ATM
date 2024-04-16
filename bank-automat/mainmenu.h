#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"
#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class mainMenu;
}

class mainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = nullptr);
    ~mainMenu();
    void setUsername(const QString &newUsername);
    void setWebToken(const QByteArray &newWebToken);


private slots:

    void transactionsSlot();
    void balanceButtonSlot();
    void depositButtonSlot();
    void withdrawButtonSlot();

private:
    Ui::mainMenu *ui;
    QString username;
    QByteArray webToken;
    QNetworkAccessManager *menuManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // MAINMENU_H

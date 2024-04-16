#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "enviroment.h"
#include "mainmenu.h"
//0500CB87D2
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonLogin,SIGNAL(clicked(bool)),this,SLOT(pushButtonLoginHandler())); // Kytketään nappi slottiin
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::pushButtonLoginHandler()
{
    QString username=ui->lineEditUname->text();
    QString password=ui->lineEditPass->text();
    QJsonObject jsonObj;
    jsonObj.insert("idCard", username);
    jsonObj.insert("pin", password);

    QString site_url= enviroment::getBaseUrl() + "/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox msgBox;

    if(response_data=="-4078"){
        msgBox.setText("Database error");
        msgBox.exec();
    }
    else{
        if(response_data!="false"){
            QString uname=ui->lineEditUname->text();
            mainMenu *objectMenu = new mainMenu;
            objectMenu->setUsername(uname);
            objectMenu->setWebToken(response_data);
            objectMenu->show();

        }
        else{
            msgBox.setText("Wrong username or password");
            msgBox.exec();
        }
    }

}



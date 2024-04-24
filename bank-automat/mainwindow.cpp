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
    ptr_dll = new RFIDD(this);
    ptr_dll->openSerialPort();
    webToken=0;
    ui->setupUi(this);
    connect(ptr_dll,SIGNAL(cardRead(QByteArray)),this,SLOT(handleCardNumber(QByteArray)));



    connect(ui->pushButtonLogin,SIGNAL(clicked(bool)),this,SLOT(pushButtonLoginHandler())); // Kytketään nappi slottiin
    connect(ui->btn0,SIGNAL(clicked(bool)),
            this, SLOT(handle0Click()));
    connect(ui->btn1,SIGNAL(clicked(bool)),
            this, SLOT(handle1Click()));
    connect(ui->btn2,SIGNAL(clicked(bool)),
            this, SLOT(handle2Click()));
    connect(ui->btn3,SIGNAL(clicked(bool)),
            this, SLOT(handle3Click()));
    connect(ui->btn4,SIGNAL(clicked(bool)),
            this, SLOT(handle4Click()));
    connect(ui->btn5,SIGNAL(clicked(bool)),
            this, SLOT(handle5Click()));
    connect(ui->btn6,SIGNAL(clicked(bool)),
            this, SLOT(handle6Click()));
    connect(ui->btn7,SIGNAL(clicked(bool)),
            this, SLOT(handle7Click()));
    connect(ui->btn8,SIGNAL(clicked(bool)),
            this, SLOT(handle8Click()));
    connect(ui->btn9,SIGNAL(clicked(bool)),
            this, SLOT(handle9Click()));
    connect(ui->btnErase,SIGNAL(clicked(bool)),
            this, SLOT(handleEraseClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::pushButtonLoginHandler()
{
    QString accountNum = username;
    login(accountNum);
    getCardType(accountNum);
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox msgBox;

    if(response_data=="-4078"){
        msgBox.setText("Database error");
        msgBox.exec();
    }
    else if(response_data=="Login failed"){
        msgBox.setText("Väärä pin");
        msgBox.exec();
    }
    else{
        if(response_data!="false"){
            QString uname=ui->lineEditUname->text();
            getCardType(uname);
            mainMenu *objectMenu = new mainMenu;
            qDebug()<<enviroment::cardType<<"sadsad";
            objectMenu->setUsername(uname);
            objectMenu->setCardType(enviroment::cardType);
            objectMenu->setWebToken(response_data);
            objectMenu->show();
        }
        else{
            msgBox.setText("Wrong username or password");
            msgBox.exec();
        }
    }
}
void MainWindow::login(QString num)
{
    QString accountNum = num;
    enviroment::setAccountNumber(accountNum);
    QString password=ui->lineEditPass->text();
    QJsonObject jsonObj;
    jsonObj.insert("idCard", enviroment::getAccountNumber());
    jsonObj.insert("pin", password);
    QString site_url= enviroment::getBaseUrl() + "/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void MainWindow::getCardType(QString CT)
{
    QJsonObject jsonObj;
    jsonObj.insert("idCard", CT);
    QString site_url= enviroment::getBaseUrl() + "/idGetter/getCardType/" + CT;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getIdSlot(QNetworkReply*)));

    reply = loginManager->get(request);
}


void MainWindow::getIdSlot(QNetworkReply *reply)
{
    //tässä id_account id_cardista
    accountType=reply->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(accountType);
    QJsonObject jsonObj = jsonDoc.object();
    enviroment::cardType = (jsonObj["card_type"].toString());
    qDebug()<<"id slot cardType : " << enviroment::getCardType();
}


void MainWindow::handle1Click()
{

    qDebug()<<"1";
    ui->lineEditPass->insert("1");
}

void MainWindow::handle2Click()
{

    qDebug()<<"2";

    ui->lineEditPass->insert("2");
}

void MainWindow::handle3Click()
{

    qDebug()<<"3";

    ui->lineEditPass->insert("3");
}

void MainWindow::handle4Click()
{

    qDebug()<<"4";

    ui->lineEditPass->insert("4");
}

void MainWindow::handle5Click()
{
    qDebug()<<"5";

    ui->lineEditPass->insert("5");
}

void MainWindow::handle6Click()
{

    qDebug()<<"6";

    ui->lineEditPass->insert("6");
}

void MainWindow::handle7Click()
{

    qDebug()<<"7";

    ui->lineEditPass->insert("7");
}

void MainWindow::handle8Click()
{

    qDebug()<<"8";

    ui->lineEditPass->insert("8");
}

void MainWindow::handle9Click()
{

    qDebug()<<"9";

    ui->lineEditPass->insert("9");
}

void MainWindow::handle0Click()
{

    qDebug()<<"0";

    ui->lineEditPass->insert("0");

}


void MainWindow::handleEraseClick()
{

    qDebug()<<"Erase";


    if (!ui->lineEditPass->text().isEmpty())
    {
        QString text =ui->lineEditPass->text();
        text.chop(1);
        ui->lineEditPass->setText(text);
    }
}

void MainWindow::handleCardRead(QByteArray cr)
{
    qDebug()<< "handleCardRead funktio" << cr;

}

void MainWindow::handleCardNumber(QByteArray cn)
{
    qDebug()<< "handleCardNumber funktio" << cn;
    username = cn;
    ui->lineEditUname->setText(username);
}





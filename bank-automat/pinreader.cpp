#include "pinreader.h"
#include "ui_pinreader.h"
#include <QDebug>

pinReader::pinReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinReader)
{
    ui->setupUi(this);
    connect(ui->btnReadPin, SIGNAL(clicked(bool)),
            this, SLOT(handleReadPinClick()));
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
    connect(ui->btnReturn,SIGNAL(clicked(bool)),
            this, SLOT(handleReturnClick()));
    connect(ui->btnErase,SIGNAL(clicked(bool)),
            this, SLOT(handleEraseClick()));
}

pinReader::~pinReader()
{

    delete ui;
}

void pinReader::handleReadPinClick()
{

    qDebug()<<"ReadPin";

    QString pinNumber= ui->lineEditEnterPin->text();
    short pin=pinNumber.toShort();
    emit sendPinNumberToMain(pin);
}

void pinReader::handle1Click()
{

    qDebug()<<"1";
    ui->lineEditEnterPin->insert("1");
}

void pinReader::handle2Click()
{

    qDebug()<<"2";

    ui->lineEditEnterPin->insert("2");
}

void pinReader::handle3Click()
{

    qDebug()<<"3";

    ui->lineEditEnterPin->insert("3");
}

void pinReader::handle4Click()
{

    qDebug()<<"4";

    ui->lineEditEnterPin->insert("4");
}

void pinReader::handle5Click()
{
    qDebug()<<"5";

    ui->lineEditEnterPin->insert("5");
}

void pinReader::handle6Click()
{

    qDebug()<<"6";

    ui->lineEditEnterPin->insert("6");
}

void pinReader::handle7Click()
{

    qDebug()<<"7";

    ui->lineEditEnterPin->insert("7");
}

void pinReader::handle8Click()
{

    qDebug()<<"8";

    ui->lineEditEnterPin->insert("8");
}

void pinReader::handle9Click()
{

    qDebug()<<"9";

    ui->lineEditEnterPin->insert("9");
}

void pinReader::handle0Click()
{

    qDebug()<<"0";

    ui->lineEditEnterPin->insert("0");

}

void pinReader::handleReturnClick()
{

    qDebug()<<"Return";

}

void pinReader::handleEraseClick()
{

    qDebug()<<"Erase";


    if (!ui->lineEditEnterPin->text().isEmpty())
    {
        QString text =ui->lineEditEnterPin->text();
        text.chop(1);
        ui->lineEditEnterPin->setText(text);
    }
}

#include "otheramount.h"
#include "ui_otheramount.h"

otherAmount::otherAmount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::otherAmount)
{
    ui->setupUi(this);

    connect(ui->btnOther0,SIGNAL(clicked(bool)),
            this, SLOT(handleOther0Click()));
    connect(ui->btnOther1,SIGNAL(clicked(bool)),
            this, SLOT(handleOther1Click()));
    connect(ui->btnOther2,SIGNAL(clicked(bool)),
            this, SLOT(handleOther2Click()));
    connect(ui->btnOther3,SIGNAL(clicked(bool)),
            this, SLOT(handleOther3Click()));
    connect(ui->btnOther4,SIGNAL(clicked(bool)),
            this, SLOT(handleOther4Click()));
    connect(ui->btnOther5,SIGNAL(clicked(bool)),
            this, SLOT(handleOther5Click()));
    connect(ui->btnOther6,SIGNAL(clicked(bool)),
            this, SLOT(handleOther6Click()));
    connect(ui->btnOther7,SIGNAL(clicked(bool)),
            this, SLOT(handleOther7Click()));
    connect(ui->btnOther8,SIGNAL(clicked(bool)),
            this, SLOT(handleOther8Click()));
    connect(ui->btnOther9,SIGNAL(clicked(bool)),
            this, SLOT(handleOther9Click()));
    connect(ui->btnOtherReturn,SIGNAL(clicked(bool)),
            this, SLOT(handleOtherReturnClick()));
    connect(ui->btnOtherErase,SIGNAL(clicked(bool)),
            this, SLOT(handleOtherEraseClick()));

    connect(ui->btnAmountOk,SIGNAL(clicked(bool)),
            this, SLOT(handleAmountOkClick()));


}

otherAmount::~otherAmount()
{
    delete ui;

}

void otherAmount::handleOther1Click()
{

    qDebug()<<"1";

    ui->lineEditEnterAmount->insert("1");
}

void otherAmount::handleOther2Click()
{

    qDebug()<<"2";

    ui->lineEditEnterAmount->insert("2");

}

void otherAmount::handleOther3Click()
{

    qDebug()<<"3";

    ui->lineEditEnterAmount->insert("3");
}

void otherAmount::handleOther4Click()
{

    qDebug()<<"4";

    ui->lineEditEnterAmount->insert("4");
}

void otherAmount::handleOther5Click()
{

    qDebug()<<"5";

    ui->lineEditEnterAmount->insert("5");
}

void otherAmount::handleOther6Click()
{

    qDebug()<<"6";

    ui->lineEditEnterAmount->insert("6");
}

void otherAmount::handleOther7Click()
{

    qDebug()<<"7";

    ui->lineEditEnterAmount->insert("7");
}

void otherAmount::handleOther8Click()
{

    qDebug()<<"8";

    ui->lineEditEnterAmount->insert("8");
}

void otherAmount::handleOther9Click()
{

    qDebug()<<"9";

    ui->lineEditEnterAmount->insert("9");
}

void otherAmount::handleOther0Click()
{

    qDebug()<<"0";

    ui->lineEditEnterAmount->insert("0");
}

void otherAmount::handleOtherReturnClick()
{

    qDebug()<<"Return";
    emit sendOtherAmountReturnSignalToTakeMoney();

}

void otherAmount::handleOtherEraseClick()
{

    qDebug()<<"Erase";

    if (!ui->lineEditEnterAmount->text().isEmpty())
    {
        QString text =ui->lineEditEnterAmount->text();
        text.chop(1);
        ui->lineEditEnterAmount->setText(text);
    }
}


void otherAmount::handleAmountOkClick()
{
    QString OtherAmountSumma= ui->lineEditEnterAmount->text();
    int OAS=OtherAmountSumma.toInt();
    if(OAS %5 ==0){
        qDebug()<<"--nostetaan"<<OAS<<"e--";
        }
    else
    {
        qDebug()<<"nostoa ei voida suorittaa";
    }
emit sendOtherAmountReturnSignalToTakeMoney();
}

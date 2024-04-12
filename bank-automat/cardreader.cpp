#include "cardreader.h"
#include "ui_cardreader.h"
#include <QDebug>

cardReader::cardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardReader)
{
    ui->setupUi(this);

    connect(ui->btnReadCard,SIGNAL(clicked(bool)),
            this, SLOT(handleReadCardClick()));
}

cardReader::~cardReader()
{

    qDebug()<<"cardReader tuhoutui";

    delete ui;
}

void cardReader::handleReadCardClick()
{

   qDebug()<<"Read Card";
  
   QString number = ui->lineEditReadCard->text();
   short num=number.toShort();
   emit sendCardNumToMain(num);
}

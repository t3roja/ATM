#ifndef PINREADER_H
#define PINREADER_H

#include <QDialog>

namespace Ui {
class pinReader;
}

class pinReader : public QDialog
{
    Q_OBJECT

public:
    explicit pinReader(QWidget *parent = nullptr);
    ~pinReader();

private:
    Ui::pinReader *ui;

private slots:
    void handleReadPinClick();
    void handle1Click();
    void handle2Click();
    void handle3Click();
    void handle4Click();
    void handle5Click();
    void handle6Click();
    void handle7Click();
    void handle8Click();
    void handle9Click();
    void handle0Click();
    void handleReturnClick();
    void handleEraseClick();


signals:
    void sendPinNumberToMain(short);

};

#endif // PINREADER_H

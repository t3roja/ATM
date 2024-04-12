#ifndef CARDREADER_H
#define CARDREADER_H

#include <QDialog>
#include "pinreader.h"

namespace Ui {
class cardReader;
}

class cardReader : public QDialog
{
    Q_OBJECT

public:
    explicit cardReader(QWidget *parent = nullptr);
    ~cardReader();

private:
    Ui::cardReader *ui;

    pinReader * pinReaderPtr;
private slots:
    void handleReadCardClick();

signals:
    void sendCardNumToMain(short);


};

#endif // CARDREADER_H

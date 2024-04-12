#ifndef IMAGE_H
#define IMAGE_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QPixmap>
#include <QObject>

#include <QWidget>

namespace Ui {
class imageData;
}
class image
{
public:
    image();

    ~image();
    void showImage(QNetworkReply *reply2);

private:
    QNetworkAccessManager *imageManager;
    QNetworkReply *reply2;
    QByteArray response_data2;
};

#endif // IMAGE_H

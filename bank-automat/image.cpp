#include "image.h"

class imageData : public QSharedData
{
public:
   /*
    imageManager = new QNetworkAccessManager(this);
    connect(imageManager, SIGNAL(finished (QNetworkReply*)), this SLOT(showImage))
        reply2 = imageManager->get(request);
*/
};

image::image()
{

}





image::~image()
{

}

void image::showImage(QNetworkReply *reply2)
{
 /*   response data= reply2->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(response_data);
    ui->labelImage->setPixmap(pixmap);
    ui->labelImage->show();
*/
}

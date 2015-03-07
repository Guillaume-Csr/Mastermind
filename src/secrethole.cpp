#include "secrethole.h"

SecretHole::SecretHole(QGraphicsItem *parent) : BoardPart(parent)
{
    imageNumber = qrand() % 8;

    switch(imageNumber)
    {
    case 0:
        file = ":/images/rsz_circle-blue.png";
        break;
    case 1:
        file = ":/images/rsz_circle-green.png";
        break;
    case 2:
        file = ":/images/rsz_circle-grey.png";
        break;
    case 3:
        file = ":/images/rsz_circle-orange.png";
        break;
    case 4:
        file = ":/images/rsz_circle-purple.png";
        break;
    case 5:
        file = ":/images/rsz_circle-red.png";
        break;
    case 6:
        file = ":/images/rsz_circle-yellow.png";
        break;
    default:
        file = ":/images/rsz_circle-tan.png";
    }
}

QRectF SecretHole::boundingRect() const
{
    return QRectF(0, 0, 250, 125);
}

void SecretHole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QImage img(file);
    painter->drawImage(0, 0, img);
}

int SecretHole::getImageNumber()
{
    return imageNumber;
}

#include <QtWidgets>
#include "coloritem.h"

ColorItem::ColorItem()
{
    static int n = 0;
    switch(n)
    {
    case 0:
        QString(":/images/rsz_circle-blue.png");
        file = ":/images/rsz_circle-blue.png";
        break;
    case 1:
        QString(":/images/rsz_circle-green.png");
        file = ":/images/rsz_circle-green.png";
        break;
    case 2:
        QString(":/images/rsz_circle-grey.png");
        file = ":/images/rsz_circle-grey.png";
        break;
    case 3:
        QString(":/images/rsz_circle-orange.png");
        file = ":/images/rsz_circle-orange.png";
        break;
    case 4:
        QString(":/images/rsz_circle-purple.png");
        file = ":/images/rsz_circle-purple.png";
        break;
    case 5:
        QString(":/images/rsz_circle-red.png");
        file = ":/images/rsz_circle-red.png";
        break;
    case 6:
        QString(":/images/rsz_circle-yellow.png");
        file = ":/images/rsz_circle-yellow.png";
        break;
    default:
        QString(":/images/rsz_circle-tan.png");
        file = ":/images/rsz_circle-tan.png";
        n = -1; // Because n will increment the next instruction by one.
    }
    n++;

    setToolTip("Click and drag this circle onto one coding hole in the right large hole!");
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF ColorItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void ColorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QImage image(file);
    painter->drawImage(0, 0, image);
}

void ColorItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}

void ColorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}

void ColorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
        return;
    }

    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    QImage image(file);
    mime->setImageData(image);
    mime->setText(file);

    drag->setPixmap(QPixmap::fromImage(image).scaled(50, 50));
    drag->setHotSpot(QPoint(25, 30));

    drag->exec();
    setCursor(Qt::OpenHandCursor);
}

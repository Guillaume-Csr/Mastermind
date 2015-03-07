#include "boarddesign.h"

BoardDesign::BoardDesign(QGraphicsItem *parent) : BoardPart(parent)
{ }

QRectF BoardDesign::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void BoardDesign::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QImage image(":/images/rsz_black_arrow.png");
    painter->drawRoundedRect(250, 0, 50, 50, 0, 0, Qt::RelativeSize);
    painter->setPen(QPen(Qt::black, 1, Qt::DashLine));
    painter->drawLine(QPoint(0, -5), QPoint(230, -5));
    painter->setPen(QPen(Qt::black, 1, Qt::DashLine));
    painter->drawLine(QPoint(0, 55), QPoint(230, 55));

    painter->drawLine(QPoint(0, 55), QPoint(230, 55));
    painter->drawImage(-50, 0, image);
}

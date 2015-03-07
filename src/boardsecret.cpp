#include "boardsecret.h"

BoardSecret::BoardSecret(QGraphicsItem *parent) : BoardPart(parent), transparency(255)
{}

QRectF BoardSecret::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void BoardSecret::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Secret Zone

    painter->setBrush(QColor(0, 0, 0, transparency));
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter->drawRoundedRect(0, 600, 250, 100, 25, 25, Qt::RelativeSize);
}

void BoardSecret::setTransparency(int i)
{
    transparency = i;
}
